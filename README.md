# MegaKit C++ — Modern C++ Algorithms & Utilities

A curated **multi-module C++ project** showcasing production-style structure: a reusable static library (`megakit`),
a CLI toolkit (`megakit_cli`), examples, and tests — all built with **CMake** and **C++17**. Designed to look professional in a GitHub portfolio while remaining dependency‑free and easy to build anywhere (Windows, Linux, macOS).

## ✨ Features
- Clean `include/` + `src/` split with namespaced headers
- Algorithms: graph (BFS, Dijkstra, topological sort), strings (KMP), math (gcd, sieve), DSU, segment tree
- Tiny test framework (no external deps) wired to `ctest`
- Examples and a CLI with subcommands
- Editor configs: `.clang-format`, `.editorconfig`, VS Code tasks
- Scripts for one‑command builds

## 📦 Structure
```
megakit-cpp/
├─ CMakeLists.txt
├─ include/megakit/
│  ├─ algo/
│  │  ├─ bfs.hpp
│  │  ├─ dijkstra.hpp
│  │  ├─ topo_sort.hpp
│  │  └─ kmp.hpp
│  ├─ ds/
│  │  ├─ disjoint_set.hpp
│  │  └─ segment_tree.hpp
│  ├─ math/
│  │  ├─ gcd.hpp
│  │  └─ sieve.hpp
│  ├─ io/argparse.hpp
│  └─ utils/timer.hpp
├─ src/megakit/...
├─ apps/toolkit/main.cpp
├─ examples/example_graph.cpp
├─ tests/
│  ├─ test_main.cpp
│  ├─ test_graph.cpp
│  ├─ test_strings.cpp
│  └─ test_math.cpp
├─ scripts/build.sh
├─ scripts/run_tests.sh
└─ .vscode/...
```

## 🚀 Build & Run

### Prerequisites
- CMake ≥ 3.16
- A C++17 compiler (MSVC, Clang, or GCC)

### Configure & Build
```bash
# From project root
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j
```

### Run CLI
```bash
./build/megakit_cli --help
./build/megakit_cli graph dijkstra --n 5 --m 6 --src 0
```

### Run Tests
```bash
ctest --test-dir build --output-on-failure
```

### Build Examples
```bash
cmake -S . -B build -DBUILD_EXAMPLES=ON
cmake --build build -j
./build/example_graph
```

## 🧪 Tiny Test Framework
We ship a minimal header (`tests/test_util.hpp`) with `TEST_CASE` and `REQUIRE` macros. No external dependencies required.

## 🛠 VS Code
Open the folder and run tasks:
- **Build (CMake)** — builds `Release`
- **Run tests** — executes `ctest`

## 📄 License
MIT — do whatever you want, but attribution is appreciated.
