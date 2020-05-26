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

	void InternalCombustionEngine::UpdateM()
	{
		int sizeV = vectorV.size();
		for (int i = 0; i < sizeV - 1; i++)
		{
			if (V == vectorV[i])
			{
				M = vectorM[i];
				return;
			}
			if (V > vectorV[i] && V < vectorV[i + 1])
			{
				double deltaV = vectorV[i + 1] - vectorV[i];
				double deltaM = vectorM[i + 1] - vectorM[i];
				double deltaX = V - vectorV[i];
				double deltaY = (deltaM * deltaX) / deltaV;
				M = vectorM[i] + deltaY;
				return;
			}
		}
		M = vectorM[vectorM.size() - 1];
	}
}