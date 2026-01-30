#include "RandomGenerator.h"

bool RandomGenerator::randomBool(float probability) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::bernoulli_distribution dist(probability);
    return dist(gen);
}
