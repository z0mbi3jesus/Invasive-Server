#include "NetworkServer.h"

bool NetworkServer::start(int port) {
    if (enet_initialize() != 0) {
        Logger::error("ENet initialization failed.");
        return false;
    }

    address.host = ENET_HOST_ANY;
    address.port = port;

    server = enet_host_create(&address, /*maxClients*/ 32, /*channels*/ 2,
                              /*incomingBandwidth*/ 0, /*outgoingBandwidth*/ 0);
    if (!server) {
        Logger::error("Failed to create ENet server host.");
        return false;
    }

    Logger::info("ENet server started on port " + std::to_string(port));
    return true;
}

void NetworkServer::acceptClients() {
    ENetEvent event;
    while (enet_host_service(server, &event, 0) > 0) {
        switch (event.type) {
            case ENET_EVENT_TYPE_CONNECT:
                Logger::info("Client connected from " +
                    std::to_string(event.peer->address.host) + ":" +
                    std::to_string(event.peer->address.port));
                break;
            case ENET_EVENT_TYPE_RECEIVE:
                Logger::info("Packet received, length: " +
                    std::to_string(event.packet->dataLength));
                // Process packet...
                enet_packet_destroy(event.packet);
                break;
            case ENET_EVENT_TYPE_DISCONNECT:
                Logger::info("Client disconnected.");
                break;
            default: break;
        }
    }
}

void NetworkServer::sendWorldUpdates() {
    // Example broadcast to all clients
    if (!server) return;
    const char* msg = "World Update";
    ENetPacket* packet = enet_packet_create(msg, strlen(msg) + 1, ENET_PACKET_FLAG_RELIABLE);
    enet_host_broadcast(server, 0, packet);
    enet_host_flush(server);
}

void NetworkServer::shutdown() {
    if (server) {
        enet_host_destroy(server);
        server = nullptr;
    }
    enet_deinitialize();
}
