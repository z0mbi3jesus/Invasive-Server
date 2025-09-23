#pragma once
#include "MathTypes.h"
#include "ECS.h"
#include <vector>

struct Sector {
    SectorIndex index;
    std::vector<Entity> entities;

    void update(double dt) {
        for (auto& e : entities)
            e.update(dt);
    }
};
