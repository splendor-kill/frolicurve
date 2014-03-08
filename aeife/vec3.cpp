#include "StdAfx.h"
#include "eiMath.h"

// require: math.sqrtf
// require: math.acos

namespace ei
{
	namespace math
	{

		cVec3::cVec3(void)
		{
			x = y = z = 0.0f;
		}

		cVec3::~cVec3(void)
		{
		}

		cVec3::cVec3(float x, float y, float z)
			: x(x), y(y), z(z)
		{
		}
		cVec3::cVec3(const cVec3& v)
			: x(v.x), y(v.y), z(v.z)
		{			
		}
		cVec3&  cVec3::operator =(const cVec3& v)
		{
			if (this != &v)
			{
				x = v.x;
				y = v.y;
				z = v.z;
			}
			return *this;
		}
		cVec3  cVec3::operator +(const cVec3& v) const
		{
			return add(v);
		}
		cVec3	cVec3::operator -() const
		{
			return cVec3(-x, -y, -z);
		}
		cVec3  cVec3::operator -(const cVec3& v) const
		{
			return add(-v);
		}
		bool	cVec3::operator ==(const cVec3& v) const
		{
			return is_equal(v);
		}

		cVec3	cVec3::add(const cVec3& v) const
		{
			return cVec3(x + v.x, y + v.y, z + v.z);
		}
		// note: normalize the zero vector will be zero
		cVec3&	cVec3::normalize()
		{
			float len = length();
			if (approximate(len, 0))
				return *this;
			x/=len, y/=len, z/=len;
			return *this;
		}
		bool	cVec3::is_zero() const
		{
			return is_equal(zero);
		}
		bool	cVec3::is_equal(const cVec3& v) const
		{
			if (approximate(x, v.x) 
				&& approximate(y, v.y)
				&& approximate(z, v.z))
			{
				return true;
			}
			return false;
		}
		bool	cVec3::is_orthogonal(const cVec3& v) const
		{
			return approximate(dot(v), 0);
		}
		bool	cVec3::is_parallel(const cVec3& v) const
		{
			if (is_zero() || v.is_zero())
				return true;
			return cross(v) == zero;
		}

		bool	cVec3::is_normal() const
		{
			return approximate(length(), 1.0f);
		}
		float	cVec3::lengthsq() const
		{
			return x * x + y * y + z * z;
		}
		float	cVec3::length() const
		{
			return sqrtf(x * x + y * y + z * z);
		}
		float	cVec3::dot(const cVec3& v) const
		{
			return x * v.x + y * v.y + z * v.z;
		}
		eAngle	cVec3::which_angle(const cVec3& v) const
		{
			float d = dot(v);
			if (approximate(d, 0))
				return eAngle_Right;
			else if (d < 0)
				return eAngle_Acute;
			else
				return eAngle_Obtuse;
		}

		cVec3	cVec3::project(const cVec3& v) const
		{
			if (is_zero())
				return *this;
			return dot(v) / lengthsq() * *this;
		}
		cVec3	cVec3::perpendicular(const cVec3& v) const
		{
			return v - project(v);
		}
		cVec3	cVec3::cross(const cVec3& v) const
		{
			return cVec3(y*v.z, z*v.x, x*v.y) - cVec3(v.y*z, v.z*x, v.x*y);
		}
		cVec3	cVec3::lerp(const cVec3& v, float f) const
		{
			return cVec3();
		}
		float	cVec3::angle(const cVec3& v) const
		{
			if (is_zero() || v.is_zero())
				return 0.0f;
			float len = length();
			float lenv = v.length();
			return acosf(dot(v) / (len * lenv));
		}
		eTurn	cVec3::which_turn(const cVec3& v, const cVec3& reference) const
		{
			float s = reference.dot(cross(v));	// scalar triple product
			if (approximate(s, 0))
				return eTurn_UNCERTAIN;
			else if (s > 0)
				return eTurn_CCW;
			else
				return eTurn_CW;
		}

		cVec3 cVec3::zero = cVec3();

		cVec3 operator *(const cVec3& v, float scale)
		{
			return cVec3(v.x * scale, v.y * scale, v.z * scale);
		}
		cVec3 operator *(float scale, const cVec3& v)
		{
			return cVec3(v.x * scale, v.y * scale, v.z * scale);
		}







	} // end ns:math
} // end ns:ei