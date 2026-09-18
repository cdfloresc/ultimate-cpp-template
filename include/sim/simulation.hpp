#pragma once
#include <vector>
#include <cstddef>

namespace sim {

struct alignas(32) Particle {
    float x, y, z;
    float vx, vy, vz;
    float mass;
    float pad; // Para alineación SIMD limpia a 32 bytes
};

class NBodySimulation {
public:
    explicit NBodySimulation(size_t particle_count, float softening_factor = 1e-3f);

    void initialize_random(unsigned int seed = 42);
    void step(float dt);

    [[nodiscard]] size_t get_particle_count() const { return particles_.size(); }
    [[nodiscard]] const std::vector<Particle>& get_particles() const { return particles_; }

    // Calcula energía total del sistema cinetica + potencial aproximada
    [[nodiscard]] double compute_kinetic_energy() const;

private:
    std::vector<Particle> particles_;
    float softening_sq_;
    float G_{1.0f}; // Constante gravitatoria normalizada
};

} // namespace sim
