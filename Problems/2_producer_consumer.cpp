/*

Using semaphore to implement a producer-consumer problem with a bounded buffer. 
The producer produces 20 items and the consumer consumes 20 items. 
The buffer has a maximum size of 5. 
The program uses counting semaphores to manage the number of empty and filled slots in the buffer, 
and a mutex to protect access to the buffer and printing.

Command:
g++ -std=c++20 2_producer_consumer.cpp -o 2_producer_consumer && ./2_producer_consumer

*/

#include <iostream>
#include <thread>
#include <mutex>
#include <semaphore>
#include <chrono>
using namespace std;

const int MAX_SIZE = 5;
int buffer[MAX_SIZE];
int item_count = 0; // only used for printing
int in_pos = 0;     // next write index
int out_pos = 0;    // next read index

counting_semaphore<MAX_SIZE> empty_slots(MAX_SIZE); // free slots, starts at 5
counting_semaphore<MAX_SIZE> filled_slots(0);       // items available, starts at 0
mutex mtx;                                          // protects buffer + printing

void producer()
{
   for (int i = 0; i < 20; i++)
   {
      empty_slots.acquire(); // wait for a free slot (blocks if full)

      {
         lock_guard<mutex> lock(mtx);

         // Safely insert an item
         buffer[in_pos] = i;
         in_pos = (in_pos + 1) % MAX_SIZE;
         item_count++;

         cout << "Produced " << i << " (count=" << item_count << ")\n";
      }

      filled_slots.release(); // one more item available
      this_thread::sleep_for(chrono::milliseconds(100));
   }
}

void consumer()
{
   for (int i = 0; i < 20; i++)
   {
      filled_slots.acquire(); // wait for an item (blocks if empty)

      {
         lock_guard<mutex> lock(mtx);

         // Safely remove an item
         int item = buffer[out_pos];
         out_pos = (out_pos + 1) % MAX_SIZE;
         item_count--;

         cout << "    Consumed " << item << " (count=" << item_count << ")\n";
      }

      empty_slots.release(); // one more free slot
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