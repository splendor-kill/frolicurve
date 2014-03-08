#pragma once

namespace ei
{
	namespace math
	{

		class cVec3
		{
		public:
			cVec3(void);
			~cVec3(void);

			cVec3(float x, float y, float);
			cVec3(const cVec3& v);
			cVec3&  operator =(const cVec3& v);
			cVec3	operator +(const cVec3& v) const;
			cVec3	operator -() const; // unary minus
			cVec3	operator -(const cVec3& v) const;  // binary subtraction
			friend	cVec3 operator *(const cVec3& v, float scale);
			friend	cVec3 operator *(float scale, const cVec3& v);
			bool	operator ==(const cVec3& v) const;


			cVec3	add(const cVec3& v) const;
			cVec3&	normalize();
			bool	is_zero() const;
			bool	is_equal(const cVec3& v) const;
			bool	is_orthogonal(const cVec3& v) const;
			bool	is_parallel(const cVec3& v) const;
			bool	is_normal() const;
			float	lengthsq() const;
			float	length() const;
			float	dot(const cVec3& v) const;
			eAngle	which_angle(const cVec3& v) const;
			// project v onto this vector
			cVec3	project(const cVec3& v) const;
			// part of v that is perpendicular to this vector
			cVec3	perpendicular(const cVec3& v) const;
			cVec3	cross(const cVec3& v) const;
			cVec3	lerp(const cVec3& v, float f) const;
			float	angle(const cVec3& v) const;
			// depend on reference direction
			eTurn	which_turn(const cVec3& v, const cVec3& reference) const;

			static	cVec3 zero;
		private:
			float x, y, z;
		};


	} // end ns:math
} // end ns:ei
