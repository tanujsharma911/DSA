/*

O: Open/Closed Principle
Code should be open for extension but closed for modification. You should be able to add new behavior
without editing existing, working code. For example, instead of adding another if branch to a payment
function for each new payment type, define a PaymentMethod interface and add a new class for each type.

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Shape
{
public:
   virtual double area() = 0;
   virtual ~Shape() {}
};

class Circle : public Shape
{
   double radius;

public:
   Circle(double r) : radius(r) {}

   double area() override
   {
      return 3.14 * radius * radius;
   }
};

class Rectangle : public Shape
{
   double width, height;

public:
   Rectangle(double w, double h) : width(w), height(h) {}

   double area() override
   {
      return width * height;
   }
};

class AreaCalculator
{
public:
   double totalArea(const vector<Shape *> &shapes)
   {
      double area = 0;

      for (Shape *s : shapes)
         area += s->area();

      return area;
   }
};

int main()
{
   vector<Shape *> shapes;

   shapes.push_back(new Circle(5));
   shapes.push_back(new Rectangle(5, 5));

   AreaCalculator calc;

   cout << calc.totalArea(shapes) << endl;

   for (Shape *s : shapes)
      delete s;

   cout << endl;
   return 0;
}