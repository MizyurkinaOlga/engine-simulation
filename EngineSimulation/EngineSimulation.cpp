#include <iostream>

#include "TestStand.h"
#include "InterfaceIO.h"

int main()
{
	double ambientTemp = interfaceio::GetAmbientTemperature();
	engines::InternalCombustionEngine engine = engines::InternalCombustionEngine();
	teststand::TestOverheatTime<engines::InternalCombustionEngine> currentTest(engine, ambientTemp);
	int seconds = currentTest.StartTestEngine();
	interfaceio::WriteOverheatTime(seconds);
}
