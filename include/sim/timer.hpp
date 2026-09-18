#pragma once
#include <chrono>
#include <string>
#include <iostream>

namespace sim {

class HighResTimer {
public:
    HighResTimer() : start_time_(std::chrono::high_resolution_clock::now()) {}

    void reset() {
        start_time_ = std::chrono::high_resolution_clock::now();
    }

    [[nodiscard]] double elapsed_seconds() const {
        auto end_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end_time - start_time_;
        return elapsed.count();
    }

    [[nodiscard]] double elapsed_milliseconds() const {
        return elapsed_seconds() * 1000.0;
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time_;
};

} // namespace sim
