#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
using namespace std;

const int MAX_SIZE = 5;
int buffer[MAX_SIZE];
int item_count = 0; // items currently in buffer
int in_pos = 0;     // next write index
int out_pos = 0;    // next read index

mutex mtx;
condition_variable not_full;  // producer waits on this
condition_variable not_empty; // consumer waits on this

void producer()
{
   for (int i = 0; i < 20; i++)
   {
      {
         unique_lock<mutex> lock(mtx);

         // wait while buffer is full
         not_full.wait(lock, []{ return item_count < MAX_SIZE; });

         buffer[in_pos] = i;
         in_pos = (in_pos + 1) % MAX_SIZE;
         item_count++;
         
         cout << "Produced " << i << " (count=" << item_count << ")\n";
      } // lock released here

      not_empty.notify_one(); // wake the consumer
      this_thread::sleep_for(chrono::milliseconds(100));
   }
}

void consumer()
{
   for (int i = 0; i < 20; i++)
   {
      {
         unique_lock<mutex> lock(mtx);

         // wait while buffer is empty
         not_empty.wait(lock, []{ return item_count > 0; });

         int item = buffer[out_pos];
         out_pos = (out_pos + 1) % MAX_SIZE;
         item_count--;

         cout << "    Consumed " << item << " (count=" << item_count << ")\n";
      } // lock released here

      not_full.notify_one(); // wake the producer
      this_thread::sleep_for(chrono::milliseconds(300));
   }
}

int main()
{
   thread p(producer);
   thread c(consumer);

   p.join();
   c.join();

   cout << "Final count = " << item_count << " (expected 0)\n";
}