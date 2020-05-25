#pragma once
#include "Engine.h"

namespace teststand
{
	template <class T>
	class TestOverheatTime
	{
		double engineTemperature;
		double ambientTemperature;
		T thisEngine;

	public:
		TestOverheatTime(T engine, double ambientTemp);
		void StartEngine();
		int GetTimeOverheat();


	};
}
