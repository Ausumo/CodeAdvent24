#pragma once
#include <vector>
#include <string>

std::vector<size_t> leftCoords;
std::vector<size_t> rightCoords;

std::vector<size_t> SortNumbers(std::vector<size_t> currentList);
std::vector<std::string> SortString(const std::string& input);
size_t stringToSizeT(const std::string& string);
int AmountInRightList(int num, std::vector<size_t> rightList);
int IsEuqualToRightList(std::vector<size_t> leftList, std::vector<size_t> rightList);