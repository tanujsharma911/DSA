/*

L: Liskov Substitution Principle

If S is a subtype of T, then objects of type T can be replaced with objects of type S without breaking the program.

*/

#include <iostream>

using namespace std;

class Bird
{
public:
   virtual void eat() = 0;
   virtual ~Bird() {}
};

class FlyingBird : public Bird
{
public:
   virtual void fly() = 0;
};

class Sparrow : public FlyingBird
{
public:
   void eat() override { cout << "Sparrow eats" << endl; }
   void fly() override { cout << "Sparrow flies" << endl; }
};

class Penguin : public Bird
{
public:
   void eat() override { cout << "Penguin eats" << endl; }
   void swim() { cout << "Penguin swims" << endl; }
};

void makeBirdFly(FlyingBird *b)
{
   b->fly();
}
void makeBirdEat(Bird *b)
{
   b->eat();
}

int main()
{
   Sparrow s;
   Penguin p;

   makeBirdEat(&s); // works
   makeBirdEat(&p); // works, any Bird is safe here

   makeBirdFly(&s); // works
}