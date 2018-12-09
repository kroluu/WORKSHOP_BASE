#include <iostream>

#include "headers.hpp"
#include "class_bin.hpp"
#include "class_cmanager.hpp"
#include "class_workshop.hpp"
#include "class_del.hpp"
#include "sort.hpp"

#include <windows.h>
#include <vector>
#include <cctype>
#include <fstream>
#include <conio.h>

using std::cout;
using std::cin;
using std::endl;

CMANAGER cmanager;
WORKSHOP workshop;
CAR vehicle;
BIN trash;
DEL erase;

void CMANAGER::INSERT()
{

	int amount;
	system("cls");
	cout<<"Enter the number of cars you want to insert : "; cin>>amount;
	while(cin.fail())
	{
		cin.clear();
		while(cin.get()!='\n') continue;
		cout<<"\nEnter the number of cars you want to insert : "; cin>>amount;
	}
		for(int i=0;i<amount;i++)
			{
				cout<<"\nEnter brand name: "; cin.ignore(); getline(cin,vehicle.brand);
					for(auto & x: vehicle.brand) x=toupper(x);
				cout<<"Enter model: "; getline(cin,vehicle.model);
					for(auto & x: vehicle.model) x=toupper(x);
				cout<<"Enter year of manufacture: "; cin>>vehicle.year;
				while(cin.fail() || vehicle.year<=0)
					{
						cin.clear();
						while(cin.get()!='\n') continue;
						cout<<"Enter year of manufacture: "; cin>>vehicle.year;
					} 
				cout<<"Enter mileage: "; cin>>vehicle.mileage;
				while(cin.fail())
					{
						cin.clear();
						while(cin.get()!='\n') continue;
						cout<<"Enter mileage: "; cin>>vehicle.mileage;
					}
				cout<<"Did the car pass service (y or n): "; cin.ignore().get(vehicle.service);
				while(vehicle.service!='y' && vehicle.service!='n') 
					{
						cin.clear();
						while(cin.get()!='\n') continue;
						cout<<"Did the car pass service (y or n): "; cin.get(vehicle.service); 
					}
				vehicle.service=toupper(vehicle.service);
				workshop.INSERT(vehicle);		
			}	
	cout<<endl;
	system("PAUSE");	
	system("cls");	
}

void CMANAGER::FIND()
{
	auto& cars = workshop.GET_CARS();
	std::vector<int> tab_for_index;
	system("cls");
	if(cars.size()==0)
	{
		cout<<"\nNO DATA TO FIND !\n\n";
		system("pause");
		system("cls");
		return;
	}
	cout<<"PARAMETERS\n";
	cout<<"---------------\n";
	cout<<"1. In order of brand\n\n";
	cout<<"2. In order of model\n\n";
	cout<<"3. In order of year of manufacture\n\n";
	cout<<"4. In order of mileage\n\n";
	cout<<"5. In order of service\n\n";
	cout<<"6. Return\n\n";
	
	cout<<"Your choice --> ";
	short choice; cin>>choice;
	while(cin.fail())
	{
		cin.clear();
		while(cin.get()!='\n') continue;
		cout<<"Your choice --> "; cin>>choice;
	}
	
	switch(choice)
	{
		case 1:
			{
				cin.ignore();
				cout<<"Enter brand you seek --> ";
				std::string mark; getline(cin,mark);
					for( auto &x: mark) x=toupper(x);
				workshop.FIND_BRAND(mark,tab_for_index);
			}
			break;
		case 2:
			{
				cin.ignore();
				cout<<"Enter model you seek --> ";
				std::string mod; getline(cin,mod);
					for( auto &x: mod) x=toupper(x);
				workshop.FIND_MODEL(mod,tab_for_index);
			}
			break;
		case 3:
			{
				system("cls");
				cout<<"PARAMETERS\n";
				cout<<"---------------\n";
				cout<<"1. specific year\n\n";
				cout<<"2. younger than ...\n\n";
				cout<<"3. older than ...\n\n";
				cout<<"4. Return\n\n";
	
				cout<<"Your choice --> ";	cin>>choice;
				while(cin.fail())
				{
					cin.clear();
					while(cin.get()!='\n') continue;
					cout<<"Your choice --> "; cin>>choice;
				}
				
				switch(choice)
				{
					case 1:
						{
							cout<<"\nEnter year you seek --> ";
							int rok; cin>>rok;
							while(cin.fail())
							{
								cin.clear();
								while(cin.get()!='\n') continue;
								cout<<"\nEnter year you seek --> "; cin>>rok;
							}
							workshop.FIND_YEAR(rok,tab_for_index,choice);
						}
						break;
					case 2:
						{
							cout<<"\nSeek cars younger than --> ";
							int rok; cin>>rok;
							while(cin.fail())
							{
								cin.clear();
								while(cin.get()!='\n') continue;
								cout<<"\nSeek cars younger than --> "; cin>>rok;
							}
							workshop.FIND_YEAR(rok,tab_for_index,choice);
						}
						break;
					case 3:
						{
							cout<<"\nSeek cars older than --> ";
							int rok; cin>>rok;
							while(cin.fail())
							{
								cin.clear();
								while(cin.get()!='\n') continue;
								cout<<"\nSeek cars older than --> "; cin>>rok;
							}
							workshop.FIND_YEAR(rok,tab_for_index,choice);
						}
						break;
					case 4:
						{
							system("cls");
							return;		
						}
						break;
				}
			}
			break;
		case 4:
			{
				system("cls");
				cout<<"PARAMETERS\n";
				cout<<"---------------\n";
				cout<<"1. Specific mileage\n\n";
				cout<<"2. smaller than ...\n\n";
				cout<<"3. higher than ...\n\n";
				cout<<"4. Return\n\n";
	
				cout<<"Your choice --> "; cin>>choice;
				while(cin.fail())
				{
					cin.clear();
					while(cin.get()!='\n') continue;
					cout<<"Your choice --> "; cin>>choice;
				}
				
				switch(choice)
				{
					case 1:
						{
							cout<<"\nEnter mileage you seek --> ";
							int przeb; cin>>przeb;
							while(cin.fail())
							{
								cin.clear();
								while(cin.get()!='\n') continue;
								cout<<"\nEnter mileage you seek --> "; cin>>przeb;
							}
							workshop.FIND_MILEAGE(przeb,tab_for_index,choice);
						}
						break;
					case 2:
						{
							cout<<"\nSeek cars that has smaller mileage than  --> ";
							int przeb; cin>>przeb;
							while(cin.fail())
							{
								cin.clear();
								while(cin.get()!='\n') continue;
								cout<<"\nSeek cars that has smaller mileage than --> "; cin>>przeb;
							}
							workshop.FIND_MILEAGE(przeb,tab_for_index,choice);
						}
						break;
					case 3:
						{
							cout<<"\nSeek cars that has higher mileage than --> ";
							int przeb; cin>>przeb;
							while(cin.fail())
							{
								cin.clear();
								while(cin.get()!='\n') continue;
								cout<<"\nSeek cars that has higher mileage than --> "; cin>>przeb;
							}
							workshop.FIND_MILEAGE(przeb,tab_for_index,choice);
						}
						break;
					case 4:
						{
							system("cls");
							return;		
						}
						break;
				}
			}
			break;
		case 5:
			{
				cout<<"\nCars with pass service (y) or not (n) --> ";
				char sign; cin.ignore().get(sign);
				while(sign!='y' && sign!='n') 
					{
						cin.clear();
						while(cin.get()!='\n') continue;
						cout<<"\nCars with pass service (y) or not (n) --> "; cin.get(sign); 
					}
				sign=toupper(sign);
				workshop.FIND_SERVICE(sign,tab_for_index);
			}
			break;
		case 6:
			{
				system("cls");
				return;
			}
			break; 
		default:
				cout<<"No such option... Try again\n";
				getchar();getchar();
				system("cls");
	
	}
	system("cls");
	int tmp;
	if(tab_for_index.size()==0)
		cout<<"\nNO DATA FOUND !\n";
	for(int i=0;i<tab_for_index.size();i++)
		{
			system("cls");
			cout<<"NUMBER OF CAR ["<<i+1<<"] (Press ESC to return)\n";
			cout<<"--------";
			cout<<"\nBrand: "<<cars[tab_for_index[i]].brand;
			cout<<"\nModel: "<<cars[tab_for_index[i]].model;
			cout<<"\nYear: "<<cars[tab_for_index[i]].year;
			cout<<"\nMileage: "<<cars[tab_for_index[i]].mileage;
			cout<<"\nService: "<<cars[tab_for_index[i]].service;
			
			cout<<endl;	
			
			cout<<"\nCHOOSE <- || -> ";
			do
				{
					tmp=getch(); 
					if(tmp==27) 
					{
						cout<<endl<<endl;
						system("pause");
						system("cls");
						return;
					}
					if(isalnum((char)tmp))
						continue;
					tmp=getch();
				} while (tmp!=75 && tmp!=77 && tmp!=27);
					if((tmp==75 && i==0) || (tmp==77 && i==tab_for_index.size()-1)) i--;
					else if(tmp==75) i-=2;
		}
	cout<<endl<<endl;
	system("pause");
	system("cls");	
}

void CMANAGER::SORT()
{
	system("cls");
	auto& cars=workshop.GET_CARS();
	if(cars.size()==0)
	{
		cout<<"\nNO DATA TO SORT !\n\n";
		system("pause");
		system("cls");
		return;
	}
	cout<<"PARAMETERS\n";
	cout<<"---------------\n";
	cout<<"1. In order of brand\n\n";
	cout<<"2. In order of year\n\n";
	cout<<"3. Return\n\n";
	
	cout<<"Your choice --> ";
	short choice; cin>>choice;
	while(cin.fail())
	{
		cin.clear();
		while(cin.get()!='\n') continue;
		cout<<"Your choice --> "; cin>>choice;
	}
	
	switch(choice)
	{
		case 1:
			{	
				system("cls");
				workshop.SORT(sort_str);
				cout<<"\nSorting ";
				char sign='.';
				for(int i=0;i<3;i++) 
					{ 
						cout<<sign; 
						Sleep(1000); 
					}
				cout<<"\n\nSorting completed !\n\n";
				system("PAUSE");
				system("cls");
			}
			break;
		case 2:
			{
				system("cls");
				workshop.SORT(sort_num);
				cout<<"\nSorting ";
				char sign='.';
				for(int i=0;i<3;i++) 
					{ 
						cout<<sign; 
						Sleep(1000); 
					}
				cout<<"\n\nSorting completed !\n\n";
				system("PAUSE");
				system("cls");
			}
			break;
		case 3:
			{
				system("cls");
				return;		
			}
			break;
		default:
				cout<<"No such option... Try again\n";
				getchar();getchar();
				system("cls");
	}
}

const void CMANAGER::LIST()
{
	system("cls");	
	workshop.LIST();
	
	cout<<endl<<endl;
	
	system("PAUSE");	
	system("cls");
}

void CMANAGER::WRITE_READ()
{
	system("cls");
	cout<<"PARAMETERS\n";
	cout<<"---------------\n";
	cout<<"1. Write to file\n\n";
	cout<<"2. Read from file\n\n";
	cout<<"3. Return\n\n";
	
	cout<<"Your choice --> ";
	short choice; cin>>choice;
	while(cin.fail())
	{
		cin.clear();
		while(cin.get()!='\n') continue;
		cout<<"Your choice --> "; cin>>choice;
	}
	
	switch(choice)
	{
		case 1:
			{
				int count=0;
				std::string name;
				auto &cars=workshop.GET_CARS();
				if(cars.size()==0)
				{
					system("cls");
					cout<<"\nNO DATA TO WRITE !\n\n";
					system("pause");
					system("cls");
					return;
				}
				auto &kosz=trash.GET_BIN();
				cout<<"\nEnter name of file --> "; cin.ignore(); getline(cin,name);
				name+=".txt";
				workshop.WRITE(count,name);
				system("cls");
				cout<<"\nWriting ";
				char sign='.';
				for(int i=0;i<3;i++) 
					{ 
						cout<<sign; 
						Sleep(1000); 
					}
				cout<<"\n\nSaved "<<count;
				(count==1)?cout<<" position successfully!\n":cout<<" positions successfully!\n";
					
				cout<<endl;
					
				cout<<"Clear workshop's base (y or n) ? ";
				char zn; cin.get(zn);
				while(zn!='y' && zn!='n')
					{
						while(cin.get()!='\n') continue;
						cout<<"Clear workshop's base (y or n) ? "; cin.get(zn);
					}
				if(zn=='y')	
				{	 
					erase.ALL(cars,kosz);
					system("cls");
					cout<<"\nErasing ";
					char sign='.';
					for(int i=0;i<3;i++) 
						{ 
							cout<<sign; 
							Sleep(1000); 
						}
				cout<<"\n\nData from workshop's base erased !\n";
				}
				
				cout<<endl;
				
				system("PAUSE");
				system("cls");
			}
			break;
		case 2:
			{
				std::string name;
				cout<<"\nEnter name of file --> "; cin.ignore(); getline(cin,name);
				name+=".txt";
				std::ifstream plik;
				plik.open(name);
				while(!plik)
					{
						cout<<"No such file...\n";
						cout<<"\nEnter name of file --> "; getline(cin,name);
						name+=".txt";
						plik.open(name);
					}
				CAR tmp;
				int count=0;
				while(plik>>tmp.brand>>tmp.model>>tmp.year>>tmp.mileage>>tmp.service)
					{	
						workshop.READ(tmp);
						count++;
					}
				plik.close();
				system("cls");
				cout<<"\nReading data from file ";
				char sign='.';
				for(int i=0;i<3;i++) 
					{ 
						cout<<sign; 
						Sleep(1000); 
					}
				cout<<"\n\nLoaded "<<count;
				(count==1)?cout<<" position successfully !\n":cout<<" positions successfully !\n";
				cout<<endl;
				system("PAUSE");
				system("cls");				
			}
			break;
		case 3:
			{
				system("cls");
				return;
			}
			break;
		default:
				cout<<"No such option... Try again\n";
				getchar();getchar();
				system("cls");
	}
				
}


 void CMANAGER::REMOVE()
{
	system("cls");
	auto& cars = workshop.GET_CARS();
	if(cars.size()==0)
	{
		cout<<"\nNO DATA TO REMOVE !\n\n";
		system("pause");
		system("cls");
		return;
	}
	auto& bin = trash.GET_BIN();	
	cout<<"PARAMETERS\n";
	cout<<"-------------------\n";
	cout<<"1. All base\n\n";
	cout<<"2. In order of year\n\n";
	cout<<"3. In order of mileage\n\n";
	cout<<"4. In order of service\n\n";
	cout<<"5. Return\n\n";
	
	cout<<"Your choice --> ";
	short choice; cin>>choice;
	while(cin.fail())
	{
		cin.clear();
		while(cin.get()!='\n') continue;
		cout<<"Your choice --> "; cin>>choice;
	}
	
	switch(choice)
	{
		case 1:
			{				
				system("cls");
				erase.ALL(cars,bin);
				cout<<"\nRemoving data from base ";
				char sign='.';
				for(int i=0;i<3;i++) 
					{ 
						cout<<sign; 
						Sleep(1000); 
					}	
				cout<<"\n\nRemoved successfully !\n\n";
				system("pause");
				system("cls");
			}
			break;
		case 2:
			{	
				cout<<"\nRemove cars older than --> ";
				int y; cin>>y;
				while(cin.fail())
					{
						cin.clear();
						while(cin.get()!='\n') continue;
						cout<<"\nRemove cars older than --> "; cin>>y;
					}
				erase.YEAR(cars,bin,y);
				system("cls");	
				cout<<"\nRemoving data from base ";
				char sign='.';
				for(int i=0;i<3;i++) 
					{ 
						cout<<sign; 
						Sleep(1000); 
					}
				cout<<"\n\nRemoved successfully !\n\n";
				system("pause");
				system("cls");
			}
			break;
		case 3:
			{				
				cout<<"\nRemove cars with higher mileage than --> ";
				int l; cin>>l;
				while(cin.fail())
					{
						cin.clear();
						while(cin.get()!='\n') continue;
						cout<<"\nRemove cars with higher mileage than --> "; cin>>l;
					}
				erase.MILEAGE(cars,bin,l);
				system("cls");
				cout<<"\nRemoving data from base ";
				char sign='.';
				for(int i=0;i<3;i++) 
					{ 
						cout<<sign; 
						Sleep(1000); 
					}
				cout<<"\n\nRemoved successfully !\n\n";
				system("pause");
				system("cls");
			}
			break;
		case 4:
			{
				cout<<"\nChoose (y) to remove cars with passed service or (n) that didnt pass --> ";
				char sign; cin.ignore(); cin.get(sign);
				while(sign!='y' && sign!='n')
					{
						while(cin.get()!='\n') continue;
						cout<<"\nChoose (y) to remove cars with passed service or (n) that didnt pass --> ";
						cin.get(sign);
					}
				erase.SERVICE(cars,bin,toupper(sign));
				system("cls");
				cout<<"\nRemoving data from base ";
				sign='.';
				for(int i=0;i<3;i++) 
					{ 
						cout<<sign; 
						Sleep(1000); 
					}
				cout<<"\n\nRemoved successfully !\n\n";
				system("pause");
				system("cls");
				
			}
			break;
		case 5: 
			{
				system("cls");
				return;
			}
			break;		
		default:
				cout<<"No such option... Try again\n";
				getchar();getchar();
				system("cls");
	}
	system("cls");	
	
}

void CMANAGER::BIN()
{
	auto& bin=trash.GET_BIN();
	system("cls");
	cout<<"PARAMETERS\n";
	cout<<"-------------------\n";
	cout<<"1. List\n\n";
	cout<<"2. Restore\n\n";
	cout<<"3. Delete\n\n";
	cout<<"4. Return\n\n";
	
	cout<<"Your choice --> ";
	short choice; cin>>choice;
	while(cin.fail())
	{
		cin.clear();
		while(cin.get()!='\n') continue;
		cout<<"Your choice --> "; cin>>choice;
	}
	
	switch(choice)
	{
		case 1:
			{
				system("cls");
				trash.LIST();
				cout<<endl<<endl;
				system("PAUSE");
				system("cls");
			}
			break;
		case 2:
			{
				system("cls");
				if(bin.size()==0)
				{
					cout<<"\nNO DATA TO RESTORE !\n\n";
					system("pause");
					system("cls");
					return;
				}
				auto& cars = workshop.GET_CARS();
				trash.RESTORE(cars);
				cout<<"\nRestoring ";
				char sign='.';
				for(int i=0;i<3;i++) 
					{ 
						cout<<sign; 
						Sleep(1000); 
					}
				cout<<"\n\nRestored data from bin successfully !\n\n";
				system("pause");
				system("cls");
			}
			break;
		case 3:
			{
				system("cls");
				if(bin.size()==0)
				{
					cout<<"\nNO DATA TO REMOVE !\n\n";
					system("pause");
					system("cls");
					return;
				}
				trash.REMOVE();
				cout<<"\nRemoving data ";
				char sign='.';
				for(int i=0;i<3;i++) 
					{ 
						cout<<sign; 
						Sleep(1000); 
					}
				cout<<"\n\nRemoved data from bin successfully\n\n";
				system("pause");
				system("cls");
			}
			break;
		case 4:
			{
				system("cls");
				return;
			}
			break;
		default:
				cout<<"No such option... Try again\n";
				getchar();getchar();
				system("cls");
	}
	system("cls");	
	
}

void CMANAGER::UPDATE()
{
	system("cls");
	auto& cars = workshop.GET_CARS();
	if(cars.size()==0)
	{
		cout<<"\nNO DATA TO UPDATE !\n\n";
		system("pause");
		system("cls");
		return;
	}
	CAR tmp;
	
		cout<<"REMEMBER THE NUMBER OF CAR YOU WANT TO EDIT\n\n";
		Sleep(2000);
		workshop.LIST();
		cout<<"\nENTER CAR FROM 1 TO "<<cars.size()<<": ";
		int n; cin>>n;
		while(cin.fail() || n>cars.size() || n<1)
		{
			cin.clear();
			while(cin.get()!='\n') continue;
			cout<<"\nENTER CAR FROM 1 TO "<<cars.size()<<": "; cin>>n;
		}		
		system("cls");
		
		cout<<"\nEnter brand name: "; cin.ignore(); getline(cin,tmp.brand);
			for(auto & x: tmp.brand) x=toupper(x);
		cout<<"Enter model: "; getline(cin, tmp.model);
			for(auto & x: tmp.model) x=toupper(x);
		cout<<"Enter year of manufacture: "; cin>>tmp.year;
		while(cin.fail())
		{
			cin.clear();
			while(cin.get()!='\n') continue;
			cout<<"Enter yearof manufacture: "; cin>>tmp.year;
		}	
		cout<<"Enter mileage: "; cin>>tmp.mileage;
		while(cin.fail())
		{
			cin.clear();
			while(cin.get()!='\n') continue;
			cout<<"Enter mileage: "; cin>>tmp.mileage;
		}
		cout<<"Did the car pass service (y or n):"; cin.ignore(); cin.get(tmp.service);
		while(tmp.service!='y' && tmp.service!='n') 
		{
			cin.clear();
			while(cin.get()!='\n') continue;
			cout<<"Did the car pass service (y or n):"; cin.get(tmp.service); 
		}
		tmp.service=toupper(tmp.service); 
		workshop.UPDATE(tmp,n-1);
	
	
	cout<<endl;
	
	system("pause");
	system("cls");
}

const void CMANAGER::MENU()
{
	cout<<"MENU\n";
	cout<<"------------\n";
	cout<<"1. Insert data\n\n";
	cout<<"2. Find data\n\n";
	cout<<"3. Sort data\n\n";
	cout<<"4. List data\n\n";
	cout<<"5. Write/Read data\n\n";
	cout<<"6. Remove data\n\n";
	cout<<"7. Bin\n\n";
	cout<<"8. Update data\n\n";
	cout<<"9. Exit\n\n";
}

const void CMANAGER::RUN()
{
	short choice;
	cout<<"WELCOME TO WORKSHOP'S BASE !\n\n";
	Sleep(1000);
	do
	{
		cmanager.MENU();
		cout<<"Your choice --> ";
		cin>>choice;
		if(!isdigit(choice))
		{
			cin.clear();
			while(cin.get()!='\n') continue;
		}
		
		switch(choice)
		{
			case 1:
					cmanager.INSERT();		
					break;
			case 2:
					cmanager.FIND();
					break;
			case 3:
					cmanager.SORT();
					break;
			case 4:	
					cmanager.LIST();
					break;
			case 5:
					cmanager.WRITE_READ();
					break;
				
			case 6:
					cmanager.REMOVE();
					break; 
			case 7:
					cmanager.BIN();
					break;
				
			case 8:
					cmanager.UPDATE();
					break;
				
			case 9:
				{
					cout<<"\nWorkshop's base is shutting down ";
					char sign='.';
					for(int i=0;i<3;i++) 
					{ 
						cout<<sign; 
						Sleep(1000); 
					}
							
				}
				break;
			default: 
					cout<<"\nNo such option... Try again\n\n";
					system("pause");
					system("cls");
		}
	} while (choice!=9);
}
