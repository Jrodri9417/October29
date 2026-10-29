// October29.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <iomanip>


void printSalesData(std::vector<std::vector<int>>salesData) 
{

    const int WIDEST_COLUMN = 10;


    for (int row = 0; row < salesData[0].size(); ++row)
    {
        for (int column = 0; column < salesData[0].size(); ++column) //Crazy
        {
            std::cout << std::setw(WIDEST_COLUMN);
            std::cout << std::left;
            std::cout << salesData[row][column];
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::vector<std::vector<int>> salesData =
    {
        {1,     2,      3},
        {4,     5,      6},
        {7,     8,      9},
        {10,    11,     12},
    };

    printSalesData(salesData);

    //dimensions of this array (also called a Matrix) are 3 x 3 (4 rows and 3 columns)


}

