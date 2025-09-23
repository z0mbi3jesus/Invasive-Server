#pragma once
#include "MathTypes.h"

struct Transform {
    double3 worldPos;
    double3 localPos;
    double3 rotation; // placeholder, can use quaternion later
};
