#pragma once
#include "Generator.h"
/**
 * @brief Класс генератора случайных чисел
 */
class RandomGenerator : public Generator
{
private:
    /**
     * @brief Минимальное значение диапазона
     */
    int min_val;

    /**
     * @brief Максимальное значение диапазона
     */
    int max_val;

public:
    /**
     * @brief Конструктор
     * @param min Минимальное значение
     * @param max Максимальное значение
     */
    RandomGenerator(int min, int max);
    /**
     * @brief Перегруженный деструктор
     */
    ~RandomGenerator() override = default;
    /**
     * @brief Метод генерации
     * @return Случайное число в заданном диапазоне
     */
    int generate() const override;
};
