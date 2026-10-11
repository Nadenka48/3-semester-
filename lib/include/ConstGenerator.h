#pragma once
#include "Generator.h"
/**
 * @brief Класс генератора константных значений
 */
class ConstGenerator : public Generator
{
private:
    /**
     * @brief Константное значение для генерации
     */
    int value;

public:
    /**
     * @brief Конструктор
     * @param value Значение, которое будет всегда возвращаться
     */
    explicit ConstGenerator(const int value);
    /**
     * @brief Перегруженный деструктор
     */
    ~ConstGenerator() override = default;
    /**
     * @brief Метод генерации
     * @return Константное значение
     */
    int generate() const override;
};
