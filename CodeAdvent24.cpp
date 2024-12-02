#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include "./CodeAdvent24.h"

int main()
{
    std::ifstream file("input.txt");
    std::string line;

    std::vector<std::string> lines;

    if (file.is_open())
        while (std::getline(file, line))
        {
            lines.push_back(line);
        }

//Day One++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //std::vector<std::string> result;
    //std::vector<size_t> numbers;

    ////split string
    //result = SortString(coords);

    ////all string numbers to size_t
    //for (std::string coord : result)
    //{
    //    numbers.push_back(stringToSizeT(coord));
    //}

    ////split in two Lists
    //for (size_t i = 0; i < numbers.size(); i++)
    //{
    //    if (i % 2 != 0) {    
    //        rightCoords.push_back(numbers[i]);
    //    }
    //    else {
    //        leftCoords.push_back(numbers[i]);
    //    }
    //}

    ////Sort list in the right way - smallest to highest
    //leftCoords = SortNumbers(leftCoords);
    //rightCoords = SortNumbers(rightCoords);

    ////check how much is the leftNumber in the rightList
    //
    //std::cout << "EqualNumber: \n";
    //std::cout << (IsEuqualToRightList(leftCoords, rightCoords));


    ////Check Coords
    //std::vector<int> distances;
    //for (int i = 0; i < leftCoords.size(); i++)
    //{
    //    int distance;
    //    distance = leftCoords[i] - rightCoords[i];
    //    distance = std::abs(distance);

    //    distances.push_back(distance);
    //}

    ////Addiere all Distances
    //size_t endResult = 0;
    //for (size_t number : distances)
    //{
    //    endResult += number;
    //}

    ////print leftSide
    //std::cout << "\n Left Coords: \n";
    //for (size_t coord : leftCoords)
    //{
    //    std::cout << coord << std::endl;
    //}
    ////print rightSide
    //std::cout << "Right Coords: \n";
    //for (size_t coord : rightCoords)
    //{
    //    std::cout << coord << std::endl;
    //}
    ////print distances
    //std::cout << "ALL DISTANCES: \n";
    //for (size_t coord : distances)
    //{
    //    std::cout << coord << std::endl;
    //}
    ////print endResult
    //std::cout << "RESULT: \n";
    //std::cout << endResult << std::endl;
    
//Day Two++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    std::vector<std::vector<int>> intResult;

    std::vector<int> numbers;

    int validLines = 0;

    //Make it to int
    for (const std::string& string : lines)
    {
        std::vector<std::string> finalString;
        finalString = SplitString(string, " ");
        for (const std::string& str : finalString) {
            numbers.push_back(stringToSizeT(str));
        }

        intResult.push_back(numbers);
        numbers.clear();

    }

    for (const auto& line : intResult) {
        if (isLineValid(line) || isLineSafeWithOneRemoval(line)) {
            validLines++; 
        } 
    }

    std::cout << std::to_string(validLines);
}
//Day Two++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
std::vector<std::string> SplitString(const std::string& string, const std::string& delimiter)
{
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = string.find(delimiter, pos_start)) != std::string::npos) {
        token = string.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + 1;
        res.push_back(token);
    }

    res.push_back(string.substr(pos_start));
    return res;
}

bool IsNeighbourValid(int current, int neighbour) {
    int diff = std::abs(current - neighbour); return diff >= 1 && diff <= 3;
}

bool isLineSafeWithOneRemoval(const std::vector<int>& line) {
    for (size_t i = 0; i < line.size(); ++i) {
        std::vector<int> modifiedLine = line;

        modifiedLine.erase(modifiedLine.begin() + i);

        if (isLineValid(modifiedLine)) {
            return true;
        }
    }
    return false;
}

bool isLineValid(const std::vector<int>& line) {
    bool increasing = true;
    bool decreasing = true;

    for (size_t i = 1; i < line.size(); i++)
    {
        if (!IsNeighbourValid(line[i - 1], line[i]))
            return false;

        if (line[i] > line[i - 1]) {
            decreasing = false;
        }
        if (line[i] < line[i - 1]) {
            increasing = false;
        }
    }

    return increasing || decreasing;
}



//Day One++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Funktion zur Umwandlung von std::string in size_t
size_t stringToSizeT(const std::string& string)
{
    return std::stoul(string);
}

//SortString in the right order
std::vector<std::string> SortString(const std::string& input) {

    std::vector<std::string> result;
    std::istringstream stream(input);
    std::string word;

    while (stream >> word) {
        result.push_back(word);
    }

    return result;
}

std::vector<size_t> SortNumbers(std::vector<size_t> currentList) {
    std::sort(currentList.begin(), currentList.end());

    return currentList;
}

int IsEuqualToRightList(std::vector<size_t> leftList, std::vector<size_t> rightList) {
    std::vector<int> resultList;
    int amount = 0;

    for (size_t i = 0; i < leftList.size(); i++)
    {
        resultList.push_back(AmountInRightList(leftList[i], rightList) * leftList[i]);
    }

    for (int num : resultList)
    {
        amount += num;
    }
    return amount;
}

int AmountInRightList(int num, std::vector<size_t> rightList) {
    int amount = 0;

    for (int number : rightList)
    {
        if (number == num) {
            amount++;
        }
    }

    return amount;
}
