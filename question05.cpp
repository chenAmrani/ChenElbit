#define _CRT_SECURE_NO_WARNINGS
//Question 5 - Class Inheritance, const correctness and operator overloading

// Task 1 : Add a Circle class that has a center point and radius fields, create a base Shape class that both Circle and Rectangle inherit from, try to move as many common field/functions to the base class

// Task 2: Create an operator overload that will allow us to chain a point instance to a ostream (std::cout), for example:
////Point point1(5,7);
////std::cout << point1;
//The previous line should output "5/7" to the console

// Task 3: Review the const correctness of the Shape/Circle/Rectangle member functions and modify them where it's required

// Do not change the main function body - it should compile and run without any modifications after completion of all tasks  


#include <iostream>
#include <vector>
using namespace std;



struct Point {

	Point() :
		x(0),
		y(0)
	{}

	Point(int x_, int y_) :
		x(x_),
		y(y_)
	{}
	Point(const Point& p) : x(p.x), y(p.y) {}

	int x;
	int y;

	//Task2
	friend ostream& operator<<(ostream& os, const Point& p);
};
ostream& operator<<(ostream& os, const Point& p)
{
	os << p.x << '/' << p.y << endl;
	return os;
}

struct Size {

	Size() :
		width(0),
		height(0) {}

	Size(int width_, int height_) :
		width(width_),
		height(height_) {}

	int width;
	int height;
};

class Shape { //ADD BY ME
protected:
	char* _name;
	Point _center;

public:
	Shape() :_name(nullptr), _center(0, 0) { };
	Shape(char* name, const Point& center) :_name(nullptr) {
		SetName(name);
		SetCenter(center);
	}

	Shape(Shape& shape) : _name(nullptr) {
		SetName(shape.name());
		SetCenter(shape.center());
	}

	virtual ~Shape() {
		delete[] _name;
	}

	char* name()const {
		return _name;
	}

	void SetName(const char* name) {
		delete this->_name;
		this->_name = new char[strlen(name) + 1];
		strcpy(_name, name);
	}

	virtual void SetCenter(const  Point& center) {
		_center.x = center.x;
		_center.y = center.y;
	}

	Point center() const {
		return _center;
	}

	virtual double area() const = 0;
	virtual double calcPerimetr() const = 0;

};

class Circle :virtual public Shape {
private:
	int m_radius; /// TODO: Check if int

public:
	Circle() : Shape() {
		SetName("Circle");
		SetCenter(Point(0, 0));
		setRadius(0);
	}

	Circle(Circle& c) : Shape() {
		SetName(c.name());
		setRadius(c.GetRadius());
	}
	Circle(const Point& center, const int radius) :Shape(), m_radius(radius) {
		SetName("Circle");
		SetCenter(center);
	}
	~Circle() {};

	int GetRadius()
	{
		return m_radius;
	}
	void setRadius(int radius) {
		this->m_radius = radius;
	}
	int getRadius() {
		return m_radius;
	}

	virtual double area() const {
		return (3.14 * m_radius * m_radius);
	}

	virtual double calcPerimetr() const {
		return (2 * 3.14 * m_radius);
	}
};


class Rectangle :virtual public Shape {

public:

	Rectangle() : Shape() {
		SetName("Rectangle");
		SetHight(0);
		SetWidth(0);
	}

	Rectangle(Rectangle& r) {
		SetName("Rectangle");
		SetCenter(r.center());
		SetSize(r.Getsize());
	}


	Rectangle(const Point& center, const  Size s): Shape()
	{
		SetName("Rectangle");
		SetCenter(center);
		SetSize(s);
	}
	~Rectangle() {};

	Size Getsize()  const {
		return m_size;
	}

	void SetSize(Size s) {
		m_size.height = s.height;
		m_size.width = s.width;
	}
	void SetWidth(int width) {
		m_size.width = width;
	}

	void SetHight(int hight) {
		m_size.height = hight;
	}

	virtual double area() const {
		return (m_size.width * (size_t)m_size.height);
	}
	virtual double calcPerimetr() const {
		return 2 * m_size.width + 2 * m_size.height;
	}
	int GetWidth() const {
		return m_size.width;
	}
	int GetHight() const {
		return m_size.height;
	}



protected:
	Size m_size;
};



int main(int argc, char** argv)
{

	std::cout << "Check point print: " << Point(1, 2) << std::endl;

	/*Do not change anything in this function body - ok*/
	Circle circle1(Point(5, 5), 10);
	Rectangle rect1(Point(5, 5), Size(10, 10));
	Circle circle2(Point(8, 8), 4);

	std::vector<Shape*> shapes{ &circle1, &rect1, &circle2 };
	for (const Shape* shape : shapes) {
		std::cout << "Shape: " << shape->name() << " center: " << shape->center() << " area: " << shape->area() << std::endl;
	}

	std::cout << "Press enter to exit" << std::endl;
	getchar();
	return 0;
}