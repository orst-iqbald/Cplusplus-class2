#include <iostream>
using namespace std;

class Shape
{
   protected:
   	string name;
   	int sides;
   public:
	Shape();
	Shape(string name, int sides)//string sname, int ssides)
	{
	   setName("Blob");
	   setSides(0);
	};
	void setName(string n) {name= n;}
	void setSides(int s) {sides =s;}
	string getName() {return name;}
	int getSides() {return sides;}
};

class Rectangle: public Shape
{
   private:
	int degree;
   public:
	Rectangle():Shape()//int sides, int degree):Shape(name)// string rname, int rsides, int rdegree)
	{
	   name = "Rechangle";
	   sides =4;
	   degree = 90;
	};
	void setDegree(int d) {degree =d;}
	int getDegree() {return degree;}
};

void print(Shape s, Shape r);
int main (){

	Shape s;
	Rectangle r;
	print(s,r);


return 0;
}

void print(Shape s, Shape r)
{
	cout << "Name is " << s.getName() << endl;
	cout << "Sides are " << s.getSides() << endl;
        cout << "Name is " << r.getName() << endl;
        cout << "Sides are " << r.getSides() << endl;
}
