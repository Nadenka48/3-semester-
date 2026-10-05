#pragma once
#include <iostream>
#include <string>
#include "Generator.h"
/**
 * @brief Класс для работы с двумерной матрицей
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
     * @brief Указатель на двумерный массив данных
     */
    int **data;

    /**
     * @brief Выделение памяти под матрицу
     */
    void allocateMemory();

    /**
     * @brief Освобождение памяти, выделенной под матрицу
     */
    void freeMemory();

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
    Matrix(const size_t r,const size_t c);
    /**
     * @brief Конструктор копирования
     * @param other Матрица для копирования
     */
    Matrix(const Matrix &other);
    /**
     * @brief Конструктор перемещения
     * @param other Матрица для перемещения
     */
    Matrix(Matrix &&other) noexcept;
    /**
     * @brief Деструктор
     */
    ~Matrix();
    /**
     * @brief Оператор присваивания копированием
     * @param other Матрица для копирования
     * @return Ссылка на текущую матрицу
     */
    Matrix &operator=(const Matrix &other);
    /**
     * @brief Оператор присваивания перемещением
     * @param other Матрица для перемещения
     * @return Ссылка на текущую матрицу
     */
    Matrix &operator=(Matrix &&other) noexcept;
    /**
     * @brief Оператор сравнения на равенство
     * @param other Матрица для сравнения
     * @return true, если матрицы равны, иначе false
     */
    bool operator==(const Matrix &other) const;
    /**
     * @brief Оператор сравнения на неравенство
     * @param other Матрица для сравнения
     * @return true, если матрицы не равны, иначе false
     */
    bool operator!=(const Matrix &other) const;
    /**
     * @brief Доступ к строке матрицы
     * @param index Индекс строки
     * @return Указатель на начало строки
     */
    int *operator[](const size_t index);
    /**
     * @brief Доступ к строке матрицы
     * @param index Индекс строки
     * @return Константный указатель на начало строки
     */
    const int *operator[](const size_t index) const;
    /**
     * @brief Получить количество строк
     * @return Количество строк
     */
    size_t getRows() const;
    /**
     * @brief Получить количество столбцов
     * @return Количество столбцов
     */
    size_t getColumns() const;
    /**
     * @brief Заполнение матрицы с помощью абстрактного класса Generator
     * @param generator - результат выполнения функции Generator
     */
    void fillArray(const Generator &generator);
    /**
     * @brief Преобразование матрицы в строку
     * @return Строковое представление матрицы
     */
    std::string toString() const;
    /**
     * @brief Вставка строки после указанного индекса
     * @param rowIndex Индекс строки, после которой нужно вставить новую
     * @param newRow Указатель на массив новой строки
     */
    void insertRowAfter(const size_t rowIndex, const int *newRow);
    /**
     * @brief Удаление столбца по индексу
     * @param colIndex Индекс удаляемого столбца
     */
    void removeColumn(const size_t colIndex);
    /**
     * @brief Оператор вывода в поток
     * @param os Поток вывода
     * @param matrix Матрица для вывода
     * @return Поток вывода
     */
    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);
    /**
     * @brief Оператор ввода из потока
     * @param is Поток ввода
     * @param matrix Матрица для записи
     * @return Поток ввода
     */
    friend std::istream &operator>>(std::istream &is, Matrix &matrix);
};
