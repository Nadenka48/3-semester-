#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Generator.h"

/**
 * @brief Класс для работы с двумерной матрицей с использованием std::vector
 */
class Matrix
{
private:
    /**
     * @brief Количество строк матрицы
     */
    size_t rows;

    /**
     * @brief Количество столбцов матрицы
     */
    size_t columns;

    /**
     * @brief Двумерный вектор для хранения данных матрицы
     */
    std::vector<std::vector<int>> data;

public:
    /**
     * @brief Конструктор по умолчанию
     */
    Matrix();

    /**
     * @brief Конструктор с параметрами
     * @param r Количество строк
     * @param c Количество столбцов
     */
    Matrix(const size_t r, const size_t c);

    /**
     * @brief Конструктор копирования (автоматический)
     */
    Matrix(const Matrix &other) = default;

    /**
     * @brief Конструктор перемещения (автоматический)
     */
    Matrix(Matrix &&other) noexcept = default;

    /**
     * @brief Деструктор (автоматический)
     */
    ~Matrix() = default;

    /**
     * @brief Оператор присваивания копированием (автоматический)
     */
    Matrix &operator=(const Matrix &other) = default;

    /**
     * @brief Оператор присваивания перемещением (автоматический)
     */
    Matrix &operator=(Matrix &&other) noexcept = default;

    /**
     * @brief Оператор сравнения на равенство
     */
    bool operator==(const Matrix &other) const;

    /**
     * @brief Оператор сравнения на неравенство
     */
    bool operator!=(const Matrix &other) const;

    /**
     * @brief Доступ к строке матрицы
     * @param index Индекс строки
     * @return Ссылка на вектор строки
     */
    std::vector<int> &operator[](const size_t index);

    /**
     * @brief Доступ к строке матрицы (константный)
     * @param index Индекс строки
     * @return Константная ссылка на вектор строки
     */
    const std::vector<int> &operator[](const size_t index) const;

    /**
     * @brief Получить количество строк
     */
    size_t getRows() const;

    /**
     * @brief Получить количество столбцов
     */
    size_t getColumns() const;

    /**
     * @brief Заполнение матрицы с помощью генератора
     */
    void fillArray(const Generator &generator);

    /**
     * @brief Преобразование матрицы в строку
     */
    std::string toString() const;

    /**
     * @brief Вставка строки после указанного индекса
     * @param rowIndex Индекс строки
     * @param newRow Вектор новой строки
     */
    void insertRowAfter(const size_t rowIndex, const std::vector<int> &newRow);

    /**
     * @brief Удаление столбца по индексу
     * @param colIndex Индекс удаляемого столбца
     */
    void removeColumn(const size_t colIndex);

    /**
     * @brief Оператор вывода в поток
     */
    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);

    /**
     * @brief Оператор ввода из потока
     */
    friend std::istream &operator>>(std::istream &is, Matrix &matrix);
};
