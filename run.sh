#!/usr/bin/env bash
set -e

CONFIG=${1:-Release}

echo "======================================================================"
echo "   Compilando y Ejecutando Proyecto C++ ($CONFIG)"
echo "======================================================================"

if ! command -v cmake &> /dev/null; then
    echo "[ERROR] CMake no esta instalado. Instala con: sudo apt install cmake"
    exit 1
fi

if [ ! -d "build" ]; then
    echo "[1/2] Primera ejecucion detectada. Configurando CMake..."
    cmake -B build -S . -DCMAKE_BUILD_TYPE=$CONFIG
fi

echo "[1/2] Compilando codigo C++ en modo $CONFIG..."
cmake --build build --config $CONFIG

echo "[2/2] Iniciando ejecucion..."
echo ""
if [ -f "./build/simulacion_benchmark" ]; then
    ./build/simulacion_benchmark
elif [ -f "./build/$CONFIG/simulacion_benchmark" ]; then
    ./build/$CONFIG/simulacion_benchmark
else
    echo "[ERROR] No se encontro el ejecutable generado en build."
    exit 1
fi
