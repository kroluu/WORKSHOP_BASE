#include <iostream>

#include "headers.hpp"
#include "class_workshop.hpp"
#include "class_del.hpp"

#include <windows.h>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

void DEL::ALL(std::vector<CAR> &cars, std::vector<CAR> &bin)
{
	for(int i=0;i<cars.size();i++)
			bin.push_back(cars[i]);
	cars.erase(cars.begin(),cars.end());
}

void DEL::YEAR(std::vector<CAR> &cars, std::vector<CAR> &bin, const int y)
{
	std::vector<int> tab_for_index;
	for(int i=cars.size()-1;i>=0;i--)
		if(cars[i].year<y)
		{
			bin.push_back(cars[i]);
			tab_for_index.push_back(i);
		}
	for(int i=0;i<tab_for_index.size();i++)
		cars.erase(cars.begin()+tab_for_index[i]);
			
	
}

void DEL::MILEAGE(std::vector<CAR> &cars, std::vector<CAR> &bin, const int l)
{
	std::vector<int> tab_for_index;
	for(int i=cars.size()-1;i>=0;i--)
		if(cars[i].mileage>l)
			{
				bin.push_back(cars[i]);
				tab_for_index.push_back(i);
			}	
			
	for(int i=0;i<tab_for_index.size();i++)
		cars.erase(cars.begin()+tab_for_index[i]);
}

void DEL::SERVICE(std::vector<CAR> &cars, std::vector<CAR> &bin, const char p)
{
	std::vector<int> tab_for_index;
	for(int i=cars.size()-1;i>=0;i--)
		if(cars[i].service==p)
			{
				bin.push_back(cars[i]);
				tab_for_index.push_back(i);
			}	
			
	for(int i=0;i<tab_for_index.size();i++)
		cars.erase(cars.begin()+tab_for_index[i]);
}
