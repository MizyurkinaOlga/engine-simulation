#include "Engine.h"

namespace engine
{
	double InternalCombustionEngine::Vh() 
	{
		return M * Hm + V * V * Hv;
	}

	double InternalCombustionEngine::Vc(int ambientTemperature, int engineTemperature)
	{
		return C * (ambientTemperature - engineTemperature);
	}
}