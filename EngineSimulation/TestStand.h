#pragma once
#include "Engine.h"

namespace teststand
{
	const double DELTA_TEMP = 1e-6;
	const int MAX_TIME = 6e2;

	template <class T>
	class TestOverheatTime
	{
		double engineTemperature;
		double ambientTemperature;
		T* thisEngine;

	public:
		TestOverheatTime(T &engine, double ambientTemp)
		{
			thisEngine = &engine;
			engineTemperature = ambientTemp;
			ambientTemperature = ambientTemp;
		}

		bool OverheatingOccured()
		{
			if (abs(thisEngine->overheatTemperature - engineTemperature) < DELTA_TEMP ||
							engineTemperature>thisEngine->overheatTemperature)
				return true;
			return false;
		}

		int StartTestEngine()
		{
			int seconds = 0;
			double a = thisEngine->M / thisEngine->I;
			while (!OverheatingOccured() && seconds < MAX_TIME)
			{
				seconds++;
				thisEngine->V += a;
				thisEngine->UpdateM();
				engineTemperature += thisEngine->Vh() + thisEngine->Vc(ambientTemperature, engineTemperature);
				a = thisEngine->M / thisEngine->I;
			}
			return seconds;
		}
	};
}
