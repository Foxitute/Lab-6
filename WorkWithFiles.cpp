#include "WorkWithFiles.h"
#include <algorithm>
#include <fstream>

bool is_zero_vector(std::vector<Point>& pointsVec) // return true if at least
{                                                  // one Point has not zero values
    std::for_each(pointsVec.begin(), pointsVec.end(), [](const Point& point) 
    {
        if (point != 0)
            return false;
    });        
    return true;
}

void save_points(std::string& PATH, std::vector<Point>& pointsVec)
{   // ::out | ::app - open file for writing at the eof
    std::fstream fs(PATH, std::fstream::out | std::fstream::app); 
    if (!fs.is_open())
    {
        throw std::exception("ERROR! Cannot open file for writing!\n");
    }

    if (is_zero_vector(pointsVec))
    {
        size_t SIZE;
        std::cout << std::endl << "How many Points do YOU want to save?" << std::endl;
        std::cin >> SIZE;
        pointsVec.resize(SIZE);

        std::for_each(pointsVec.begin(), pointsVec.end(), [](Point& point) 
        {
            std::cout << std::endl << "Enter x, y, z " << std::endl;
            std::cin >> point;
        });
    }

    std::for_each(pointsVec.begin(), pointsVec.end(), [&fs](const Point& point)
    {
        fs << point << "\n"; // input in file
    });
    fs.close();
    std::cout << std::endl << "Vector successfully saved!"
              << std::endl << std::endl;
}

std::vector<Point>& read_points(std::string& PATH, std::vector<Point>& pointsVec)
{
    std::fstream fs(PATH, std::fstream::in); // ::in - open file for reading
    if (!fs.is_open())
    {
        throw std::exception("ERROR! Cannot open file for reading!\n");
    }
    while (!fs.eof())
    {
        Point tmp;
        fs >> tmp; // read from file
        if (fs.eof())
            break;
        std::cout << tmp << std::endl;
        pointsVec.push_back(tmp);
    }
    fs.close();
    std::cout << std::endl << "Vector successfully readed!"
              << std::endl << std::endl;
    return pointsVec;
}