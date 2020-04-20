#pragma once
#include "Point.h"

bool zero_vector(std::vector<Point>& pointsVec);
void save_points(std::string& PATH, std::vector<Point>& pointsVec);
void read_points(std::string& PATH, std::vector<Point>& pointsVec);

