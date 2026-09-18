#!/usr/bin/env bash
set -e

CONFIG=${1:-Release}

echo "[1/2] Compilando ($CONFIG)..."
if [ ! -d "build" ]; then
    cmake -B build -S . -DCMAKE_BUILD_TYPE=$CONFIG
fi
cmake --build build --config $CONFIG

echo "[2/2] Ejecutando..."
if [ -f "./build/simulacion_benchmark" ]; then
    ./build/simulacion_benchmark
else
    ./build/$CONFIG/simulacion_benchmark
fi
