#ifndef SORT_HPP
#define SORT_HPP

#include <iostream>
#include <cstring>
#include "headers.hpp"
#include <vector>

void sort_str(std::vector<CAR> &cars)
{
	for(int nr=0;nr<cars.size();nr++)
		for(int i=0;i<cars.size()-nr-1;i++)
			if(cars[i].brand.compare(cars[i+1].brand)>0)
				std::swap(cars[i],cars[i+1]);
}

void sort_num(std::vector<CAR>& cars)
{
	for(int nr=0;nr<cars.size();nr++)
		for(int i=0;i<cars.size()-nr-1;i++)
			if(cars[i].year>cars[i+1].year)	
				std::swap(cars[i],cars[i+1]);
}

#endif
	

