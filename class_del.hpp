#ifndef CLASS_DEL_HPP
#define CLASS_DEL_HPP
#include <iostream>
#include <vector>

class DEL 
{
	public:
		void ALL(std::vector<CAR> &cars, std::vector<CAR> &kosz);
		void YEAR(std::vector<CAR> &cars, std::vector<CAR> &kosz, const int y);
		void MILEAGE(std::vector<CAR> &cars, std::vector<CAR> &kosz, const int l);
		void SERVICE(std::vector<CAR> &cars,std::vector<CAR> &kosz, const char p);
		virtual ~DEL() {};
};



#endif
