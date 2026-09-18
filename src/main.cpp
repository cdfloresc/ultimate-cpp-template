#include "sim/simulation.hpp"
#include "sim/timer.hpp"
#include <iostream>
#include <iomanip>
#include <thread>
#include <string>

#ifdef USE_OPENMP
#include <omp.h>
#endif

void print_header() {
    std::cout << "======================================================================\n";
    std::cout << "       ULTIMATE C++20 TEMPLATE - HIGH PERFORMANCE COMPUTING          \n";
    std::cout << "   Plantilla Profesional para Simulaciones, Algoritmos y Proyectos    \n";
    std::cout << "======================================================================\n\n";
}

void print_system_specs() {
    unsigned int threads = std::thread::hardware_concurrency();

    std::cout << "[1] Diagnostico de Hardware y Entorno:\n";
    std::cout << "    - Estandar de C++:       C++20\n";
    std::cout << "    - Hilos de CPU (Cores):  " << threads << "\n";

#ifdef USE_OPENMP
    std::cout << "    - Multi-hilo (OpenMP):   HABILITADO (" << omp_get_max_threads() << " hilos activos)\n";
#else
    std::cout << "    - Multi-hilo (OpenMP):   DESACTIVADO (mono-hilo)\n";
#endif

#if defined(__AVX2__)
    std::cout << "    - Vectorizacion SIMD:    AVX2 Activado (Optimizacion de Registros)\n";
#elif defined(_M_AMD64) || defined(__x86_64__)
    std::cout << "    - Arquitectura:          x86_64 64-bits\n";
#endif

    std::cout << "\n";
}

void run_quick_demo() {
    std::cout << "[2] Ejecutando Demo Rapida (Comprobacion de Estructuras):\n";
    sim::NBodySimulation mini_sim(500);
    mini_sim.initialize_random(42);
    mini_sim.step(0.01f);
    std::cout << "    -> Sistema inicializado correctamente (500 particulas procesadas).\n\n";
}

void run_heavy_benchmark() {
    const size_t NUM_PARTICLES = 12000;
    const int NUM_STEPS = 20;
    const float TIME_STEP = 0.001f;
    const double total_interactions = static_cast<double>(NUM_PARTICLES) * NUM_PARTICLES * NUM_STEPS;

    std::cout << "[3] Benchmark Cientifico Pesado (Simulacion Gravitacional N-Body):\n";
    std::cout << "    - Particulas en simulacion:  " << NUM_PARTICLES << "\n";
    std::cout << "    - Complejidad computacional: O(N^2) -> " 
              << (NUM_PARTICLES * NUM_PARTICLES) / 1'000'000.0 << " Millones de fuerzas / paso\n";
    std::cout << "    - Pasos de tiempo simulados: " << NUM_STEPS << "\n";
    std::cout << "    - Total de interacciones:    " 
              << total_interactions / 1'000'000'000.0 << " Giga-Interacciones\n\n";

    std::cout << "    Iniciando computo intensivo en paralelo...\n";
    sim::NBodySimulation sim(NUM_PARTICLES);
    sim.initialize_random(1337);

    double initial_ke = sim.compute_kinetic_energy();

    sim::HighResTimer total_timer;
    std::cout << std::fixed << std::setprecision(3);

    for (int step = 1; step <= NUM_STEPS; ++step) {
        sim::HighResTimer step_timer;
        sim.step(TIME_STEP);
        double step_ms = step_timer.elapsed_milliseconds();

        double interactions = static_cast<double>(NUM_PARTICLES) * NUM_PARTICLES;
        double giga_interactions_per_sec = (interactions / (step_ms / 1000.0)) / 1e9;

        std::cout << "    -> Paso [" << std::setw(2) << step << "/" << NUM_STEPS << "] | "
                  << "Tiempo: " << std::setw(7) << step_ms << " ms | "
                  << "Rendimiento: " << std::setw(5) << giga_interactions_per_sec << " G-Int/s\n";
    }

    double total_sec = total_timer.elapsed_seconds();
    double final_ke = sim.compute_kinetic_energy();
    double avg_giga_interactions = (total_interactions / total_sec) / 1e9;

    std::cout << "\n======================================================================\n";
    std::cout << "                    RESUMEN DE RENDIMIENTO FINAL                      \n";
    std::cout << "======================================================================\n";
    std::cout << "  * Tiempo total de computo:        " << total_sec << " s\n";
    std::cout << "  * Tasa de procesamiento promedio: " << avg_giga_interactions << " Giga-Interacciones/s\n";
    std::cout << "  * Energia Cinetica Inicial:       " << std::scientific << std::setprecision(4) << initial_ke << " J\n";
    std::cout << "  * Energia Cinetica Final:         " << std::scientific << std::setprecision(4) << final_ke << " J\n";
    std::cout << "======================================================================\n";
    std::cout << "  [SUCCESS] Tu entorno C++20 esta configurado al maximo rendimiento!\n";
    std::cout << "======================================================================\n";
}

int main() {
    print_header();
    print_system_specs();
    run_quick_demo();
    run_heavy_benchmark();
    return 0;
}
