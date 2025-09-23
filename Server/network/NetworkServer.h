#pragma once
#include <enet/enet.h>
#include <vector>
#include "WorldState.h"
#include <string>
#include "logging/Logger.h"

class ClientConnection {
public:
    int id;
    // connection info
};

class NetworkServer {
public:
    WorldState* world;
    bool start(int port);
    void acceptClients();
    void sendWorldUpdates();
    void shutdown();

private:
    ENetAddress address;
    ENetHost* server = nullptr;
    std::vector<ClientConnection> clients;

    void start(int port);
    void acceptClients();
    void sendWorldUpdates();
};
