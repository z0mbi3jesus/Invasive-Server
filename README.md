\# 🚀 SpaceSim Engine \& Server



\*\*SpaceSim Engine\*\* is a cross-platform, modular game engine designed for large-scale \*\*space sandbox simulations\*\*.  

It solves the floating-origin (0,0,0) precision issues common in other engines by using a \*\*double-precision world coordinate system\*\* combined with \*\*camera-relative rendering\*\*.



This repository contains:

\- \*\*Core Engine Modules\*\* – ECS, math utilities, transform systems, physics hooks.

\- \*\*Dedicated Server\*\* – Authoritative world simulation with ENet networking.

\- \*\*Networking Layer\*\* – Built on \[ENet](https://github.com/lsalzman/enet) for low-latency, reliable UDP communication.



---



\## ✨ Features (Current / Planned)



| Status | Feature |

|--------|---------|

| ✅ | Modular, double-precision math core |

| ✅ | Headless authoritative server |

| ✅ | ENet networking layer (UDP reliable/unreliable channels) |

| 🔄 | Sector/Chunk streaming for infinite world |

| 🔄 | Real-time physics integration |

| 🔄 | Dynamic entity spawning \& sandbox editing |

| 🔜 | Multi-client stress testing |

| 🔜 | Mobile (iOS/Android) client support |



---



\## 📂 Repository Structure



server/ # Dedicated server

src/ # Server entry point and main loop

core/ # Math, ECS, transforms (shared with engine)

world/ # Sector management and world state

physics/ # Physics engine wrapper

network/ # ENet-based networking

logging/ # Logging utilities

external/enet/ # ENet submodule (if used)

engine/ # Future client/engine modules (rendering, tools)

docs/ # Design documents, diagrams





---



\## 🛠️ Build Instructions



\### Prerequisites

\- \*\*C++17\*\* or later

\- \*\*CMake 3.15+\*\*

\- \[ENet](https://github.com/lsalzman/enet) (automatically included as a submodule or install via system package)



\### Clone \& Build

```bash

git clone --recursive https://github.com/z0mbi3jesus/spacesim-engine.git

cd spacesim-engine

mkdir build \&\& cd build

cmake ..

cmake --build .



---

bash



./server \[port]

If no port is specified, the server defaults to 4000.



---



Design Overview



The engine uses double precision for global coordinates and converts to camera-relative floats at render time.

The server maintains authoritative world state, including:



Sector loading/unloading



Physics simulation



Real-time state replication via ENet



Clients receive only the local float-space data they need, enabling near-infinite worlds without floating-point drift.



&nbsp;Development Roadmap

Phase 0 – Core Setup \[x]



&nbsp;Project scaffolding, CMake setup \[x]



&nbsp;Core math \& ECS modules \[x]



&nbsp;ENet networking bootstrap \[x]



Phase 1 – Basic Server Loop \[]



&nbsp;World tick loop (sectors, physics) \[]



&nbsp;Client connect/disconnect \[]



&nbsp;Broadcast test packets \[]



Phase 2 – Sandbox Features 



&nbsp;Sector streaming



&nbsp;Dynamic entity spawning



&nbsp;Multi-client synchronization



Phase 3 – Engine Client 



&nbsp;Rendering engine (PC)



&nbsp;Cross-platform clients (iOS/Android)



&nbsp;Editor tools



&nbsp;License



This project is released under the MIT License.

ENet is also MIT licensed and included here as a submodule.



&nbsp;Contributing



Fork the repository



Create a feature branch: git checkout -b feature/your-feature



Commit changes: git commit -m 'Add your feature'



Push to branch: git push origin feature/your-feature



Open a Pull Request



&nbsp;Contact



Project Lead: z0mbi3jesus / Invasive Game Studios

z0mb.g.sus@gmail.com

Questions, ideas, or collaborations are welcome!

















