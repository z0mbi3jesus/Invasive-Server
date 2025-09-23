#pragma once
#include <vector>
#include "WorldState.h"

class ClientConnection {
public:
    int id;
    // connection info
};

class NetworkServer {
public:
    WorldState* world;

    std::vector<ClientConnection> clients;

    void start(int port);
    void acceptClients();
    void sendWorldUpdates();
};
