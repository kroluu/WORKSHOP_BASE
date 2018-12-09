#ifndef CLASS_BIN_HPP_
#define CLASS_BIN_HPP_
#include <iostream>
#include <vector>

class BIN
{
	private:
			std::vector<CAR> bin;
	public:
			const void LIST() const;
			void RESTORE(std::vector<CAR>& cars);
			inline void REMOVE() { bin.erase(bin.begin(),bin.end());}
			inline std::vector<CAR>& GET_BIN() { return bin; }
			virtual ~BIN() {}
};




#endif
