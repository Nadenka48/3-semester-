#include <iostream>
#include <cstdlib>

#include "Matrix.h"
#include "RandomGenerator.h"
#include "ConstGenerator.h"
#include "InputGenerator.h"
#include "Task1Exercise.h"
#include "Task2Exercise.h"

enum gen
{
    random_fill = 1,
    const_fill,
    input_fill
};

enum task
{
    task1_choice = 1,
    task2_choice
};

size_t getPos(const char *message);
int getInt(const char *message);
void runTask(Matrix &matrix, const Generator &generator);

int main(void)
{
    system("chcp 65001 > nul");

    const size_t rows = getPos("Введите количество строк:");
    const size_t columns = getPos("Введите количество столбцов:");

    Matrix matrix(rows, columns);

    std::cout << "Выберите тип заполнения массива:\n"
              << random_fill << " - случайными числами\n"
              << const_fill << " - одинаковым числом (константой)\n"
              << input_fill << " - ввод с клавиатуры\n"
              << std::endl;
    int var = getInt("");

    switch (var)
    {
    case random_fill:
    {
        int minVal = getInt("Введите минимум диапазона:");
        int maxVal = getInt("Введите максимум диапазона:");
        RandomGenerator genObj(minVal, maxVal);
        matrix.fillArray(genObj);
        break;
    }
    case const_fill:
    {
        int value = getInt("Введите значение константы:");
        ConstGenerator genObj(value);
        matrix.fillArray(genObj);
        break;
    }
    case input_fill:
    {
        std::cout << "Введите значения массива:\n";
        InputGenerator genObj(std::cin);
        matrix.fillArray(genObj);
        break;
    }
    default:
        std::cerr << "Некорректный выбор" << std::endl;
        std::exit(1);
    }

    std::cout << "Полученная матрица:\n"
              << matrix.toString() << std::endl;

    switch (var)
    {
    case random_fill:
    {
        int minVal = 0;
        int maxVal = 0;
        RandomGenerator genObj(minVal, maxVal);
        runTask(matrix, genObj);
        break;
    }
    case const_fill:
    {
        int value = 0;
        ConstGenerator genObj(value);
        runTask(matrix, genObj);
        break;
    }
    case input_fill:
    {
        InputGenerator genObj(std::cin);
        runTask(matrix, genObj);
        break;
    }
    }

    return 0;
}

size_t getPos(const char *message)
{
    size_t value = 0;
    std::cout << message << std::endl;
    if (std::cin >> value && value > 0)
    {
        return value;
    }
    std::cerr << "Некорректный ввод" << std::endl;
    std::exit(1);
}

int getInt(const char *message)
{
    int value = 0;
    std::cout << message << std::endl;
    if (std::cin >> value)
        return value;
    std::cerr << "Некорректный ввод" << std::endl;
    std::exit(1);
}

void runTask(Matrix &matrix, const Generator &generator)
{
    std::cout << "Выберите задание:\n"
              << task1_choice << " - Задание 1. Заменить четный элемент каждого столбца максимальным по модулю\n"
              << task2_choice << " - Задание 2. Удалить все столбцы, в которых первый элемент четный" << std::endl;
    const int var = getInt("");

    switch (var)
    {
    case task1_choice:
    {
        Task1Exercise task(matrix, generator);
        Matrix result = task.solve();
        std::cout << "Результат:\n"
                  << result.toString() << std::endl;
        break;
    }
    case task2_choice:
    {
        Task2Exercise task(matrix, generator);
        Matrix result = task.solve();
        std::cout << "Результат:\n"
                  << result.toString() << std::endl;
        break;
    }
    default:
        std::cerr << "Некорректный выбор" << std::endl;
        std::exit(1);
    }
}
