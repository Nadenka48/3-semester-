#include "Task1Exercise.h"
#include <cmath>
#include <algorithm>

Task1Exercise::Task1Exercise(Matrix &src, const Generator &gen) : Exercise(src, gen) {}

Matrix Task1Exercise::solve()
{
    Matrix result(source);
    const size_t rows = result.getRows();
    const size_t columns = result.getColumns();

    if (rows == 0 || columns == 0)
    {
        return result;
    }

    for (size_t j = 0; j < columns; j++)
    {
        int maxAbsValue = std::abs(result[0][j]);
        for (size_t i = 1; i < rows; i++)
        {
            if (std::abs(result[i][j]) > maxAbsValue)
            {
                maxAbsValue = std::abs(result[i][j]);
            }
        }

        for (size_t i = 0; i < rows; i++)
        {
            if (result[i][j] % 2 == 0)
            {
                result[i][j] = maxAbsValue;
            }
        }
    }

    return result;
}
