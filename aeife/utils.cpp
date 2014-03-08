#include "StdAfx.h"
#include "utils.h"

// require: math.abs

namespace ei
{
	namespace math
	{

		bool approximate(float a, float b)
		{
			return abs(a - b) < kEpsilon;
		}


	} // end ns:math
} // end ns:ei
