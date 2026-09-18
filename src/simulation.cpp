#include "sim/simulation.hpp"
#include <cmath>
#include <random>

#ifdef USE_OPENMP
#include <omp.h>
#endif

namespace sim {

NBodySimulation::NBodySimulation(size_t particle_count, float softening_factor)
    : particles_(particle_count),
      softening_sq_(softening_factor * softening_factor) {}

void NBodySimulation::initialize_random(unsigned int seed) {
    std::mt19937 rng(seed);
    std::uniform_real_distribution<float> pos_dist(-10.0f, 10.0f);
    std::uniform_real_distribution<float> vel_dist(-0.5f, 0.5f);
    std::uniform_real_distribution<float> mass_dist(1.0f, 10.0f);

    for (auto& p : particles_) {
        p.x = pos_dist(rng);
        p.y = pos_dist(rng);
        p.z = pos_dist(rng);

        p.vx = vel_dist(rng);
        p.vy = vel_dist(rng);
        p.vz = vel_dist(rng);

        p.mass = mass_dist(rng);
        p.pad = 0.0f;
    }
}

void NBodySimulation::step(float dt) {
    const size_t n = particles_.size();
    Particle* const p_data = particles_.data();
    const float eps_sq = softening_sq_;
    const float g_const = G_;

    // Actualización de fuerzas y velocidades con paralelización multinúcleo
#if defined(USE_OPENMP)
    #pragma omp parallel for schedule(static)
#endif
    for (long long i = 0; i < static_cast<long long>(n); ++i) {
        float fx = 0.0f;
        float fy = 0.0f;
        float fz = 0.0f;

        const float pi_x = p_data[i].x;
        const float pi_y = p_data[i].y;
        const float pi_z = p_data[i].z;

        for (size_t j = 0; j < n; ++j) {
            const float dx = p_data[j].x - pi_x;
            const float dy = p_data[j].y - pi_y;
            const float dz = p_data[j].z - pi_z;

            const float dist_sq = dx * dx + dy * dy + dz * dz + eps_sq;
            const float inv_dist = 1.0f / std::sqrt(dist_sq);
            const float inv_dist3 = inv_dist * inv_dist * inv_dist;

            const float s = g_const * p_data[j].mass * inv_dist3;

            fx += dx * s;
            fy += dy * s;
            fz += dz * s;
        }

        p_data[i].vx += fx * dt;
        p_data[i].vy += fy * dt;
        p_data[i].vz += fz * dt;
    }

    // Actualización de posiciones
#if defined(USE_OPENMP)
    #pragma omp parallel for schedule(static)
#endif
    for (long long i = 0; i < static_cast<long long>(n); ++i) {
        p_data[i].x += p_data[i].vx * dt;
        p_data[i].y += p_data[i].vy * dt;
        p_data[i].z += p_data[i].vz * dt;
    }
}

double NBodySimulation::compute_kinetic_energy() const {
    double total_ke = 0.0;
    const size_t n = particles_.size();
    const Particle* const p_data = particles_.data();

#if defined(USE_OPENMP)
    #pragma omp parallel for reduction(+:total_ke) schedule(static)
#endif
    for (long long i = 0; i < static_cast<long long>(n); ++i) {
        const double vx = p_data[i].vx;
        const double vy = p_data[i].vy;
        const double vz = p_data[i].vz;
        const double v_sq = vx * vx + vy * vy + vz * vz;
        total_ke += 0.5 * static_cast<double>(p_data[i].mass) * v_sq;
    }

    return total_ke;
}

} // namespace sim
