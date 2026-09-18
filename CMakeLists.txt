cmake_minimum_required(VERSION 3.25)
project(SimulacionPesada LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Soporte OpenMP para cálculo paralelo masivo
find_package(OpenMP)

add_executable(simulacion_benchmark
    src/main.cpp
    src/simulation.cpp
)

target_include_directories(simulacion_benchmark PRIVATE include)

if(OpenMP_CXX_FOUND)
    target_link_libraries(simulacion_benchmark PRIVATE OpenMP::OpenMP_CXX)
    target_compile_definitions(simulacion_benchmark PRIVATE USE_OPENMP)
    message(STATUS "OpenMP encontrado y activado para paralelismo multi-núcleo.")
else()
    message(WARNING "OpenMP no encontrado, se ejecutará en mono-hilo.")
endif()

# Optimizaciones para MSVC
if(MSVC)
    target_compile_options(simulacion_benchmark PRIVATE
        $<$<CONFIG:Release>:/O2 /Oi /Ot /fp:fast /arch:AVX2 /MP>
        $<$<CONFIG:Debug>:/Od /Zi /RTC1>
        /W4
    )
endif()
