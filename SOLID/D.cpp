/*

D: Dependency Inversion Principle

High-level modules should not depend on low-level modules. Both should depend on abstractions.
Abstractions should not depend on details. Details should depend on abstractions.

Before:   OrderService  ───►  MySQLDatabase

After:    OrderService  ───►  Database  ◄───  MySQLDatabase
                              (interface)  ◄───  PostgresDatabase

*/

#include <iostream>

using namespace std;

// Create an interface for that need
class Database
{
public:
   virtual void save(const string &data) = 0;
   virtual ~Database() {}
};

// Make the low-level class implement it
class MySQLDatabase : public Database
{
public:
   void save(const string &data) override
   {
      cout << "Saving to MySQL: " << data << endl;
   }
};

// Make OrderService depend on the interface
class OrderService
{
   Database *db; // the abstraction, not MySQL
public:
   OrderService(Database *d) : db(d) {}

   void placeOrder(const string &item)
   {
      db->save(item);
   }
};

int main()
{

   MySQLDatabase mysql;
   OrderService service(&mysql);
   service.placeOrder("Laptop");

   cout << endl;
   return 0;
}