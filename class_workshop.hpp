#ifndef CLASS_WORKSHOP_HPP_
#define CLASS_WORKSHOP_HPP_
#include <iostream>
#include <vector>
#include "class_cmanager.hpp"



class WORKSHOP
{
	protected: 
			std::vector<CAR> cars;
	public:
			inline void INSERT(CAR &tmp) { cars.push_back(tmp);};
			void FIND_BRAND(std::string find,std::vector<int> &tab_for_index) const;
			void FIND_MODEL(std::string find,std::vector<int> &tab_for_index) const;
			void FIND_YEAR(int find,std::vector<int> &tab_for_index,int choice) const;
			void FIND_MILEAGE(int find,std::vector<int> &tab_for_index,int choice) const;
			void FIND_SERVICE(char find, std::vector<int> &tab_for_index) const;
			void SORT(void (*pf)(std::vector<CAR>& cars)); 
			const void LIST() const;
			void WRITE(int &count, std::string &name);
			inline void READ(CAR& sam) { cars.push_back(sam); };
			void UPDATE(CAR & tmp, const int n);
			virtual ~WORKSHOP() {}
			inline std::vector<CAR>& GET_CARS() { return cars; }
			exit();
			
					
			
};



#endif
