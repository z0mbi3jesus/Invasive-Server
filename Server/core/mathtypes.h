#pragma once
#include <cstdint>

struct double3 {
    double x, y, z;
    double3 operator+(const double3& rhs) const { return {x+rhs.x, y+rhs.y, z+rhs.z}; }
    double3 operator-(const double3& rhs) const { return {x-rhs.x, y-rhs.y, z-rhs.z}; }
};

struct SectorIndex {
    int64_t x, y, z;
};
