#pragma once
#include <vector>
#include <memory>
#include "Transform.h"

using EntityID = uint64_t;

struct Component {
    virtual ~Component() = default;
};

struct Entity {
    EntityID id;
    Transform transform;
    std::vector<std::unique_ptr<Component>> components;

    void update(double dt) {
        // Update all components
    }
};
