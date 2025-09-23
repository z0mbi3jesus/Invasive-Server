#pragma once
#include "SectorManager.h"

class WorldState {
public:
    SectorManager sectorManager;

    void update(double dt) {
        for (auto& [key, sector] : sectorManager.loadedSectors)
            sector.update(dt);
    }
};
