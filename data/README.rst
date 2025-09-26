nlohmann/json: Modern JSON for C++
==================================

Why I chose this module
-----------------------
I picked **nlohmann/json** because it's a widely adopted, header-only JSON library
that is not part of the C++ standard library. JSON shows up everywhere (APIs,
config files, logs), and this module makes reading/writing JSON in C++ feel as
simple as using STL containers.

What this repo shows
--------------------
- Parsing JSON from a file and querying fields (``src/main_parse.cpp``)
- Serializing/deserializing C++ structs with ``to_json``/``from_json`` (``src/main_serialize.cpp``)
- Pretty-printing, nested objects, and arrays
- A minimal CMake setup that automatically fetches the library

Installation options
--------------------

**Option A: Build this repo as-is (recommended, no manual install)**

This project uses CMake ``FetchContent`` to download ``nlohmann/json`` automatically.

1. Generate & build (out-of-source)::

      cmake -S . -B build
      cmake --build build

2. Run the demos from the repo root::

      ./build/main_parse
      ./build/main_serialize

**Option B: Install the module on your system/package manager**

- **vcpkg**::

      vcpkg install nlohmann-json

  Then link in CMake with ``find_package(nlohmann_json CONFIG REQUIRED)`` and
  ``target_link_libraries(your_target PRIVATE nlohmann_json::nlohmann_json)``.

- **Conan**::

      conan install . --requires nlohmann_json/3.11.3 --build=missing

- **Homebrew (macOS)**::

      brew install nlohmann-json

- **Single-header (manual)**

  Download ``include/nlohmann/json.hpp`` from the GitHub releases and add the
  folder to your compiler include path.

How to run
----------
- **Parse example**::

    ./build/main_parse

  Reads ``data/sample.json``, pretty-prints it, and shows how to access fields
  with defaults, nested objects, and arrays.

- **Serialize example**::

    ./build/main_serialize

  Converts a C++ ``User`` struct to JSON and back using ``to_json/from_json``.

Notes & tips
------------
- This library is header-only: no separate linking step is required.
- Use ``.value(key, default)`` when a field might be missing.
- For your own structs, define ``to_json`` and ``from_json`` to enable
  automatic (de)serialization.

Potential applications
----------------------
- Reading API responses (REST clients)
- Config files for C++ services or games
- Log enrichment/structured logging
- Data interchange between microservices

License/Attribution
-------------------
- Library: https://github.com/nlohmann/json
- Used under the MIT License; see the upstream repo for details.
