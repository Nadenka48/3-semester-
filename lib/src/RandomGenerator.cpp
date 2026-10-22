#include "RandomGenerator.h"
#include <cstdlib>
#include <algorithm>
#include <ctime>

RandomGenerator::RandomGenerator(const int min, const int max)
{
    static bool seeded = false;
    if (!seeded)
    {
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        seeded = true;
    }

    min_val = std::min(min, max);
    max_val = std::max(min, max);
}

int RandomGenerator::generate() const
{
    if (min_val == max_val)
        return min_val;
    return min_val + std::rand() % (max_val - min_val + 1);
}
