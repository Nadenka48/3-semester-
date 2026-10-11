#include "Task2Exercise.h"

Task2Exercise::Task2Exercise(Matrix &src, const Generator &gen) : Exercise(src, gen) {}

Matrix Task2Exercise::solve()
{
    Matrix result(source);

    if (result.getRows() == 0 || result.getColumns() == 0)
    {
        return result;
    }

    for (size_t j = result.getColumns(); j > 0; --j)
    {
        size_t actual_index = j - 1;

        if (result[0][actual_index] % 2 == 0)
        {
            result.removeColumn(actual_index);
        }
    }

    return result;
}
