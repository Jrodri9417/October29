// October29.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <iomanip>


void printSalesData(std::vector<std::vector<int>>salesData) 
{

    const int WIDEST_COLUMN = 10;


    for (int row = 0; row < salesData.size(); ++row)
    {
        for (int column = 0; column < salesData[row].size(); ++column) //Crazy
        {
            std::cout << std::setw(WIDEST_COLUMN);
            std::cout << std::left;
            std::cout << salesData[row][column];
        }
        std::cout << std::endl;
    }
}

auto calculateAverageSales(std::vector<std::vector<int>> salesData)
{
	double averageSales = 0.0;

	//first, add up all the sales in all the rows and columns
    double sum = 0.0;
    for (int row = 0; row < salesData.size(); ++row)
    {
        for (int column = 0; column < salesData[row].size(); ++column)
        {
            sum = sum + salesData[row][column];
        }
    }

    std::cout << "Sum of all sales is: " << sum << std::endl;

	//How to divide by the total number of sales? number of rows * number of columns
	int totalDataPoints = salesData.size() * salesData[0].size();

    averageSales = sum / totalDataPoints;

	return averageSales;
}

//add a function that calculates max value in a certain row or column 
int findMaxSalesInCertainRow(std::vector<std::vector<int>> salesData, int rowNumber) 
{
   
    int maxSalesInCertainRow = 0;
	for (int column = 0; column < salesData[rowNumber].size(); ++column)
	{
		int currentSales = salesData[rowNumber][column];

		if (currentSales > maxSalesInCertainRow)
		{
			maxSalesInCertainRow = currentSales;

			std::cout << "Updated the max sale to: " << maxSalesInCertainRow << std::endl;
		}
	}
    
    return maxSalesInCertainRow;
}


int main()
{
    std::vector<std::vector<int>> salesData =
    {
        {1,     2,      3},//Alice
        {4,     5,      6},//Bob
        {7,     8,      9},//Charlie
        {7,     8,      9},//Carol
        {10,    11,     12},//Darth Vader
    };

	int maxSalesInRow1 = findMaxSalesInCertainRow(salesData, 1);


	std::cout << "Max sales in row 1: " << maxSalesInRow1 << std::endl;

    printSalesData(salesData);

    //dimensions of this array (also called a Matrix) are 3 x 3 (4 rows and 3 columns)

	double averageSales = calculateAverageSales(salesData);

    std::cout << "Average sales: " << averageSales << std::endl;

	return 0;
}

