#include <chrono>
#include <thread>
#include "world/WorldState.h"
#include "physics/PhysicsEngine.h"
#include "network/NetworkServer.h"
#include "logging/Logger.h"

constexpr double FIXED_DT = 1.0 / 60.0; // 60 Hz server tick

int main(int argc, char** argv)
{
    Logger::info("=== SpaceSim Test Server Starting ===");

    // 1️ Initialize WorldState and load starting sector
    WorldState world;
    SectorIndex startingSector{0,0,0};
    world.sectorManager.loadSector(startingSector);
    Logger::info("World initialized with starting sector (0,0,0)");

    // 2️ Start Physics Engine
    PhysicsEngine physics;
    Logger::info("Physics Engine started.");

    // 3️ Start Network Server (configurable port)
    int port = 4000;
    if (argc > 1) port = std::stoi(argv[1]);
    NetworkServer net;
    if (!net.start(port)) return -1;

while (running) {
    net.acceptClients();
    world.update(FIXED_DT);
    physics.step(FIXED_DT);
    net.sendWorldUpdates();
    ...
}

net.shutdown();
    net.world = &world;
    net.start(port);
    Logger::info("Network Server listening on port " + std::to_string(port));

    // 4️ Main Tick Loop
    Logger::info("Entering main loop...");
    auto prev = std::chrono::high_resolution_clock::now();
    double accumulator = 0.0;

    bool running = true;
    while (running)
    {
        // measure frame time
        auto now = std::chrono::high_resolution_clock::now();
        double frameTime = std::chrono::duration<double>(now - prev).count();
        prev = now;
        accumulator += frameTime;

        // handle network events outside fixed step
        net.acceptClients();

        while (accumulator >= FIXED_DT)
        {
            // Update world
            world.update(FIXED_DT);

            // Step physics
            physics.step(FIXED_DT);

            // Send world updates to clients
            net.sendWorldUpdates();

            accumulator -= FIXED_DT;
        }

        // Sleep briefly to reduce CPU load
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    Logger::info("Server shutting down...");
    return 0;
}
