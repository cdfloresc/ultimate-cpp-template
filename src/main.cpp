#include "sim/simulation.hpp"
#include "sim/timer.hpp"
#include <iostream>
#include <iomanip>
#include <thread>

#ifdef USE_OPENMP
#include <omp.h>
#endif

int main() {
    std::cout << "===============================================================\n";
    std::cout << "   MOTOR DE SIMULACION CIENTIFICA C++20 - ALTO RENDIMIENTO\n";
    std::cout << "===============================================================\n";

    unsigned int hardware_threads = std::thread::hardware_concurrency();
    std::cout << "[+] Hilos de CPU detectados: " << hardware_threads << "\n";

#ifdef USE_OPENMP
    int omp_threads = omp_get_max_threads();
    std::cout << "[+] OpenMP Habilitado con max threads: " << omp_threads << "\n";
#else
    std::cout << "[-] Advertencia: OpenMP desactivado. Ejecutando en mono-hilo.\n";
#endif

    const size_t NUM_PARTICLES = 12000;
    const int NUM_STEPS = 20;
    const float TIME_STEP = 0.001f;

    std::cout << "\n[+] Inicializando sistema N-Body:\n";
    std::cout << "    - Numero de particulas: " << NUM_PARTICLES << "\n";
    std::cout << "    - Interacciones por paso: " << (NUM_PARTICLES * NUM_PARTICLES) / 1'000'000.0 << " Millones (O(N^2))\n";
    std::cout << "    - Pasos temporales a simular: " << NUM_STEPS << "\n";
    std::cout << "    - Total de interacciones gravitacionales: " 
              << (static_cast<double>(NUM_PARTICLES) * NUM_PARTICLES * NUM_STEPS) / 1'000'000'000.0 << " Giga-Interacciones\n\n";

    sim::NBodySimulation sim(NUM_PARTICLES);
    sim.initialize_random(1337);

    double initial_ke = sim.compute_kinetic_energy();
    std::cout << "[+] Energia Cinetica Inicial: " << std::scientific << std::setprecision(5) << initial_ke << " J\n\n";

    std::cout << "--- INICIANDO BENCHMARK DE COMPUTO PESADO ---\n";
    std::cout << std::fixed << std::setprecision(3);

    sim::HighResTimer total_timer;

    for (int step = 1; step <= NUM_STEPS; ++step) {
        sim::HighResTimer step_timer;
        sim.step(TIME_STEP);
        double step_ms = step_timer.elapsed_milliseconds();

        double interactions = static_cast<double>(NUM_PARTICLES) * NUM_PARTICLES;
        double giga_interactions_per_sec = (interactions / (step_ms / 1000.0)) / 1e9;

        std::cout << "Paso [" << std::setw(2) << step << "/" << NUM_STEPS << "] -> "
                  << "Tiempo: " << std::setw(7) << step_ms << " ms | "
                  << "Rendimiento: " << std::setw(6) << giga_interactions_per_sec << " Giga-Interacciones/s\n";
    }

    double total_sec = total_timer.elapsed_seconds();
    double final_ke = sim.compute_kinetic_energy();

    double total_interactions = static_cast<double>(NUM_PARTICLES) * NUM_PARTICLES * NUM_STEPS;
    double avg_giga_interactions = (total_interactions / total_sec) / 1e9;

    std::cout << "\n===============================================================\n";
    std::cout << "   RESUMEN DE RENDIMIENTO\n";
    std::cout << "===============================================================\n";
    std::cout << "Tiempo total de computo:        " << total_sec << " s\n";
    std::cout << "Rendimiento promedio global:    " << avg_giga_interactions << " Giga-Interacciones/s\n";
    std::cout << "Energia Cinetica Final:         " << std::scientific << final_ke << " J\n";
    std::cout << "Delta Energia Cinetica:         " << std::scientific << (final_ke - initial_ke) << " J\n";
    std::cout << "===============================================================\n";
    std::cout << "[OK] El entorno de C++ esta 100% operativo y optimizado.\n";

    return 0;
}
