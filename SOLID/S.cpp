/*

S: Single Responsibility Principle

A class should have one reason to change. If a class handles both user authentication and
sending emails, a change to either forces you to edit the same class. Split them.

*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*

Problem: Employee has three reasons to change:

The bonus rule changes, so you edit calculateSalary.
You want to save to a database instead of a file, so you edit saveToFile.
You want a different report format, so you edit printReport.

*/


class Employee
{
public:
   string name;
   double baseSalary;

   Employee(string n, double s) : name(n), baseSalary(s) {}
};

class SalaryCalculator
{
public:
   double calculate(const Employee& e)
   {
      return e.baseSalary + (e.baseSalary * 0.10);
   }
};

class EmployeeSaver
{
public:
   void save(const Employee &e, double salary)
   {
      ofstream file("employ.txt");
      file << e.name << " " << salary;
   }
};

class ReportPrinter
{
public:
   void print(const Employee &e, double salary)
   {
      cout << e.name << " earns " << salary << endl;
   }
};

int main()
{
   Employee emp("Tanuj", 10000);

   SalaryCalculator calc;
   EmployeeSaver saver;
   ReportPrinter printer;

   double salary = calc.calculate(emp); // calculate once
   saver.save(emp, salary);             // reuse the result
   printer.print(emp, salary);          // reuse the result

   cout << endl;
   return 0;
}