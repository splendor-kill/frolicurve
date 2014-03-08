#include "StdAfx.h"
#include "td_vec3.h"

#include "eiMath.h"
using namespace ei::math;

td_vec3::td_vec3(void)
{
	cVec3 v1;
	cVec3 v2(1, 2, 0);
	cVec3 v3(8,7,6);
	cVec3 v4(v2);
	cVec3 vx(1,0,0);
	cVec3 vy(0,1,0);
	cVec3 vz(0,0,1);
	assert(v1.is_zero());
	assert(v2 == v4);
	assert(-v2 == cVec3(-1, -2, 0));
	assert(v1 + v2 == v2);
	assert(3.0f*v3 == v3*3.0f);
	assert(v3.dot(vx) == 8 && v3.dot(vy) == 7 && v3.dot(vz) == 6);
	assert(v2.is_orthogonal(cVec3(-2, 1, 0)));
	assert(v2.is_parallel(cVec3(2, 4, 0)));

	assert(approximate(v2.length(), sqrtf(5)));
	v2.normalize();
	assert(v2.is_normal());
	assert(vx.project(cVec3(2,1,1)) == cVec3(2,0,0));
	assert(vx.perpendicular(cVec3(1,1,0)) == vy);
	assert(vx.cross(vy) == vz);
	assert(approximate(vx.angle(vy), kHalfPi));




}

td_vec3::~td_vec3(void)
{
}
