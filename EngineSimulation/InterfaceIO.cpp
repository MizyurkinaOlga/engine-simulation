#include <iostream>
#include "InterfaceIO.h"

namespace interfaceio
{
	double GetAmbientTemperature()
	{
		double temp;
		std::cout << "Enter the ambient temperature: ";
		std::cin >> temp;
		return temp;
	}

	void WriteOverheatTime(int seconds)
	{
		std::cout << "Time until engine overheats: " << seconds << " seconds." << std::endl;
	}
}