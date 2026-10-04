#include "RandomGenerator.h"
#include <cstdlib>
#include <algorithm>

RandomGenerator::RandomGenerator(int min, int max)
{
    min_val = std::min(min, max);
    max_val = std::max(min, max);
}

int RandomGenerator::generate() const
{
    if (min_val == max_val)
        return min_val;
    return min_val + std::rand() % (max_val - min_val + 1);
}
