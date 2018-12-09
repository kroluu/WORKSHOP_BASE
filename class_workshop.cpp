#include <iostream>

#include "headers.hpp"
#include "class_workshop.hpp"
#include "class_cmanager.hpp"
#include <windows.h>
#include <vector>
#include <fstream>
#include <string>
#include <conio.h>

using std::cout;
using std::cin;
using std::endl;

void WORKSHOP::FIND_BRAND(std::string find,std::vector<int> &tab_for_index) const
{
	for(int i=0;i<cars.size();i++)
		if(find==cars[i].brand)
			tab_for_index.push_back(i);
}
void WORKSHOP::FIND_MODEL(std::string find,std::vector<int> &tab_for_index) const
{
	for(int i=0;i<cars.size();i++)
		if(find==cars[i].model)
			tab_for_index.push_back(i);
}
void WORKSHOP::FIND_YEAR(int find,std::vector<int> &tab_for_index,int choice) const
{
	switch(choice)
	{
		case 1:
			{
				for(int i=0;i<cars.size();i++)
					if(find==cars[i].year)
						tab_for_index.push_back(i);
			}
			break;
		case 2:
			{
				for(int i=0;i<cars.size();i++)
					if(find<cars[i].year)
						tab_for_index.push_back(i);
			}
			break;
		case 3:
			{
				for(int i=0;i<cars.size();i++)
					if(find>cars[i].year)
						tab_for_index.push_back(i);
			}
			break;
	}
}
void WORKSHOP::FIND_MILEAGE(int find,std::vector<int> &tab_for_index,int choice) const
{
	switch(choice)
	{
		case 1:
			{
				for(int i=0;i<cars.size();i++)
					if(find==cars[i].mileage)
						tab_for_index.push_back(i);
			}
			break;
		case 2:
			{
				for(int i=0;i<cars.size();i++)
					if(find>cars[i].mileage)
						tab_for_index.push_back(i);
			}
			break;
		case 3:
			{
				for(int i=0;i<cars.size();i++)
					if(find<cars[i].mileage)
						tab_for_index.push_back(i);
			}
			break;
	}
}
void WORKSHOP::FIND_SERVICE(char find, std::vector<int> &tab_for_index) const
{
	for(int i=0;i<cars.size();i++)
		if(find==cars[i].service)
			tab_for_index.push_back(i);
}

void WORKSHOP::SORT(void (*pf)(std::vector<CAR>& cars))
{
	pf(cars);
	
} 


const void WORKSHOP::LIST() const
{		
		int tmp;
		if(cars.size()==0)
			cout<<"\nWORKSHOP'S BASE IS EMPTY !\n";
		for(int i=0;i<cars.size();i++)
			{
				system("cls");
				cout<<"NUMBER OF CAR ["<<i+1<<"] (Press ESC to return)\n";
				cout<<"--------";
				cout<<"\nBrand: "<<cars[i].brand;
				cout<<"\nModel: "<<cars[i].model;
				cout<<"\nYear: "<<cars[i].year;
				cout<<"\nMileage: "<<cars[i].mileage;
				cout<<"\nService: "<<cars[i].service;
				cout<<endl;	
			
				cout<<"\nCHOOSE <- || -> ";
				do
				{
					tmp=getch(); 
					if(tmp==27) return;
					if(isalnum((char)tmp))
						continue;
					tmp=getch();
				} while (tmp!=75 && tmp!=77 && tmp!=27);
					if((tmp==75 && i==0) || (tmp==77 && i==cars.size()-1)) i--;
					else if(tmp==75) i-=2;

			}
			
}

void WORKSHOP::WRITE(int &count,std::string &name)
{
	std::ofstream plik;
	plik.open(name,std::ios_base::app);
		
		for(int i=0;i<cars.size();i++)
		{
				plik<<cars[i].brand<<endl;
				plik<<cars[i].model<<endl;
				plik<<cars[i].year<<endl;
				plik<<cars[i].mileage<<endl;
				plik<<cars[i].service<<endl<<endl;
				
				count++;
		}
	plik.close();
	
	
}

void WORKSHOP::UPDATE(CAR & tmp, const int n) 
{	
	cars[n]=tmp;
}
