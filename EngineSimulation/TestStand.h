#pragma once
#include "Engine.h"

namespace teststand
{
	const double DELTA_TEMP = 1e-3;

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
			//задать начальные значения
			int seconds = 0;
			double a = thisEngine->M / thisEngine->I;
			while (!OverheatingOccured())
			{
				seconds++;
				thisEngine->V += a;
				thisEngine->UpdateM();
				engineTemperature = engineTemperature + thisEngine->Vh() +
										thisEngine->Vc(ambientTemperature, engineTemperature);
				a = thisEngine->M / thisEngine->I;
			}
			return seconds;
		}
	};
}
