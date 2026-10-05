#pragma once

#include "Exercise.h"
/**
 * @brief Класс для выполнения второго задания
 */
class Task2Exercise : public Exercise
{
public:
    /**
     * @brief Конструктор
     * @param src Ссылка на матрицу
     * @param gen Ссылка на генератор
     */
    Task2Exercise(Matrix &src, const Generator &gen);
    /**
     * @brief Перегруженный деструктор
     */
    ~Task2Exercise() override = default;
    /**
     * @brief Выполнить задание 2
     * @return Выполненное задание
     */
    Matrix solve() override;
};
