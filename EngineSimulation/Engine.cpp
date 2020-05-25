#include "Engine.h"

namespace engines
{
	double InternalCombustionEngine::Vh() 
	{
		return M * Hm + V * V * Hv;
	}

	double InternalCombustionEngine::Vc(double ambientTemp, double engineTemp)
	{
		return C * (ambientTemp - engineTemp);
	}
}