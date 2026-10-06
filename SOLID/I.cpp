/*

I: Interface Segregation Principle
No client should be forced to depend on methods it does not use.

*/

#include <iostream>

using namespace std;

// Split the big interface into small ones
class Printer
{
public:
   virtual void print() = 0;
   virtual ~Printer() {}
};

class Scanner
{
public:
   virtual void scan() = 0;
   virtual ~Scanner() {}
};

class Fax
{
public:
   virtual void fax() = 0;
   virtual ~Fax() {}
};

// Combine interfaces for bigger devices
class AllInOnePrinter : public Printer, public Scanner, public Fax
{
public:
   void print() override { cout << "Printing" << endl; }
   void scan() override { cout << "Scanning" << endl; }
   void fax() override { cout << "Faxing" << endl; }
};

void doPrint(Printer *p) { p->print(); }
void doScan(Scanner *s) { s->scan(); }

int main()
{
   AllInOnePrinter a;

   doPrint(&a);
   doScan(&a);

   cout << endl;
   return 0;
}