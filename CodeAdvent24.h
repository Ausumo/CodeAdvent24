#pragma once
#include <vector>
#include <string>

//day Four+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
bool isValidPosition(int x, int y, int rows, int cols);
int countXmas(const std::vector<std::string>& grid);
bool checkXpattern(const std::vector<std::string>& grid, int startX, int startY, int dirX, int dirY);

//Day Two++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
bool IsNeighbourValid(int current, int neighbour);
std::vector<std::string> SplitString(const std::string& string, const std::string& delimiter);
bool isLineValid(const std::vector<int>& line);
bool isLineSafeWithOneRemoval(const std::vector<int>& line);

//Day One++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//std::vector<size_t> leftCoords;
//std::vector<size_t> rightCoords;
std::vector<size_t> SortNumbers(std::vector<size_t> currentList);
std::vector<std::string> SortString(const std::string& input);
size_t stringToSizeT(const std::string& string);
int AmountInRightList(int num, std::vector<size_t> rightList);
int IsEuqualToRightList(std::vector<size_t> leftList, std::vector<size_t> rightList);