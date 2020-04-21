#pragma once
#include <iostream>
#include <vector>

class Point
{
protected:
    std::vector<Point*> _buffer;
    int _x;
    int _y;
    int _z;

public:
    Point();
    Point(int x, int y, int z);
    Point(const Point& other);
    Point& operator = (const Point& other);
    ~Point();

    bool operator == (int value) const;
    bool operator == (int value);
    bool operator != (int value) const;
    bool operator != (int value);

    friend std::ostream& operator << (std::ostream& os, const Point& point);
    friend std::istream& operator >> (std::istream& is, Point& point);
};

std::ostream& operator << (std::ostream& os, const Point& point);
std::istream& operator >> (std::istream& is, Point& point);

