#pragma once

// reference: <limits>

#define NS_BEGIN(ns) namespace ns {
#define NS_END(ns) }

NS_BEGIN (ei)
NS_BEGIN(math)

const float kEpsilon = 0.000001f;
const float kPi = 3.1415927f;
const float kHalfPi = 1.570796f;
const float k2Pi = 6.283185f;
const float kE = 2.718282f;

enum eAngle
{
    eAngle_Acute,
    eAngle_Right,
    eAngle_Obtuse
};

enum eTurn
{
    eTurn_UNCERTAIN,
    eTurn_CW,
    eTurn_CCW
};

bool approximate(float a, float b);

NS_END(math)
NS_END(ei)
