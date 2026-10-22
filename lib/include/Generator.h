#pragma once

/**
 * @brief Базовый абстрактный класс для генераторов
 */
class Generator
{
public:
    /**
     * @brief Виртуальный деструктор
     */
    virtual ~Generator() = default;

    /**
     * @brief Чисто виртуальный метод генерации числа
     * @return Сгенерированное число
     */
    virtual int generate() const = 0;
};
