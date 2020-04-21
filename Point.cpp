#include "Point.h"
#include <stack>

namespace
{
    std::stack<Point*> stack; // create stack available in this cpp file
}

Point::Point() : _x(0), _y(0), _z(0) {} // default ctor

Point::Point(int x, int y, int z) // ctror with int args
    : _x(x), _y(y), _z(z)
{
    if (!stack.empty()) // if stack is not empty
    {
        stack.top()->_buffer.push_back(this); // add new Point to the buffer 
    }
    stack.push(this); // add element at the begin of stack
}

Point::Point(const Point& other) 
    : _x(other._x), _y(other._y), _z(other._z) {}

Point& Point::operator = (const Point& other) 
{
    this->_x = other._x;
    this->_y = other._y;
    this->_z = other._z;
    return *this;
}

Point::~Point()
{
    if (!stack.empty())
    {
        stack.pop(); // delete first element of stack
    }
}


bool Point::operator==(int value) const
{
    return this->_x == value && this->_y == value && this->_z == value;
}

bool Point::operator == (int value)
{
    return this->_x == value && this->_y == value && this->_z == value;
}

bool Point::operator!=(int value) const
{
	return !(*this == value);
}

bool Point::operator != (int value)
{
    return !(*this==value);
}


std::ostream& operator << (std::ostream& os, const Point& point) // Overload << operator (cout <<, fs <<)[write in file]
{
    os << point._x << " " << point._y << " " << point._z;
    return os;
}

std::istream& operator >> (std::istream& is, Point& point) // Overload >> operator (cin >>, fs >>)[read from file]
{
    is >> point._x >> point._y >> point._z;
    return is;
}