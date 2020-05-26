#include <iostream>
#include "InterfaceIO.h"
#include "TestStand.h"

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
		if (seconds == teststand::MAX_TIME)
		{
			std::cout << "At a given ambient temperature and error, the engine does not overheat." << std::endl;
		}
		else
		{
			std::cout << "Time until engine overheats: " << seconds << " seconds." << std::endl;
		}
	}
}