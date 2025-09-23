#pragma once
#include "Sector.h"
#include <unordered_map>

class SectorManager {
public:
    std::unordered_map<int64_t, Sector> loadedSectors; // key = flattened SectorIndex

    void loadSector(const SectorIndex& idx);
    void unloadSector(const SectorIndex& idx);
};
