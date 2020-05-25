#pragma once

#include <vector>
namespace engines 
{
	class InternalCombustionEngine 
	{

		double I = 10;
		double overheatTemperature = 100.0;
		double Hm = 0.01;
		double Hv = 0.0001;
		double C = 0.1;
		std::vector<int> vectorM = { 20,75,100,105,75,0 };
		std::vector<int> vectorV = { 0,75,150,200,250,300 };

		double M;
		double V;

	public:

		double Vh();
		double Vc(double ambientTemp, double engineTemp);
		InternalCombustionEngine ()
		{
			M = vectorM[0];
			V = vectorV[0];
		}
	};
}