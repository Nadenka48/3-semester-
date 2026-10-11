#pragma once
#include <iostream>
#include "Generator.h"
/**
 * @brief Класс генератора значений из потока ввода
 */
class InputGenerator : public Generator
{
private:
    /**
     * @brief Ссылка на поток ввода
     */
    std::istream &in;

public:
    /**
     * @brief Конструктор
     * @param input_stream Ссылка на поток ввода
     */
    explicit InputGenerator(std::istream &input_stream);

    /**
     * @brief Перегруженный деструктор
     */
    ~InputGenerator() override = default;

    /**
     * @brief Метод чтения числа из потока
     * @return Считанное число
     */
    int generate() const override;
};
