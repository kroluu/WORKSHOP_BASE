#include <iostream>

#include "headers.hpp"
#include "class_bin.hpp"
#include "class_workshop.hpp"

#include <windows.h>
#include <vector>
#include <conio.h>

using std::cout;
using std::cin;
using std::endl;

extern CAR vehicle;

const void BIN::LIST() const
{
	int tmp;
		if(bin.size()==0)
			cout<<"\nBIN IS EMPTY !\n";
		for(int i=0;i<bin.size();i++)
			{
			system("cls");
			cout<<"NUMBER OF CAR ["<<i+1<<"] (Press ESC to return)\n";
			cout<<"--------";
			cout<<"\nBrand: "<<bin[i].brand;
			cout<<"\nModel: "<<bin[i].model;
			cout<<"\nYear: "<<bin[i].year;
			cout<<"\nMileage: "<<bin[i].mileage;
			cout<<"\nService: "<<bin[i].service;
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
					if((tmp==75 && i==0) || (tmp==77 && i==bin.size()-1)) i--;
					else if(tmp==75) i-=2;
			}
}

void BIN::RESTORE(std::vector<CAR>& cars)
{
	for(int i=0;i<bin.size();i++)
		cars.push_back(bin[i]);
	bin.erase(bin.begin(),bin.end());
}

