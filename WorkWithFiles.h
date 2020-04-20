#pragma once
#include "Point.h"

bool is_zero_vector(std::vector<Point>& pointsVec);
void save_points(std::string& PATH, std::vector<Point>& pointsVec);
std::vector<Point>& read_points(std::string& PATH, std::vector<Point>& pointsVec);
