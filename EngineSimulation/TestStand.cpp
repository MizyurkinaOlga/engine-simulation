#include "TestStand.h"

namespace teststand
{
	template <class T>
	TestOverheatTime<class T>::TestOverheatTime(T engine, double ambientTemp)
	{
		ambientTemperature = ambientTemp;
		engineTemperature = ambientTemp;
		thisEngine = engine;
		
	}


}