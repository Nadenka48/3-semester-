#pragma once
#include "Matrix.h"

/**
 * @brief Базовый абстрактный класс для выполнения заданий
 */
class Exercise
{
protected:
    /**
     * @brief Ссылка на исходную матрицу
     */
    Matrix &source;

public:
    /**
     * @brief Конструктор
     * @param src Ссылка на исходную матрицу
     */
    explicit Exercise(Matrix &src);

    /**
     * @brief Виртуальный деструктор
     */
    virtual ~Exercise() = default;

    /**
     * @brief Чисто виртуальный метод решения задания
     * @return Результирующая матрица после выполнения алгоритма
     */
    virtual Matrix solve() = 0;
};
