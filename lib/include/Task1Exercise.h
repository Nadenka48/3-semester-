#pragma once
#include "Exercise.h"

/**
 * @brief Класс для выполнения первого задания
 */
class Task1Exercise : public Exercise
{
public:
    /**
     * @brief Конструктор
     * @param src Ссылка на матрицу
     */
    explicit Task1Exercise(Matrix &src);

    /**
     * @brief Перегруженный деструктор
     */
    ~Task1Exercise() override = default;

    /**
     * @brief Выполнить задание 1
     * @return Выполненное задание
     */
    Matrix solve() override;
};
