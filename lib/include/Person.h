#pragma once
#include <string>

/**
 * @brief Базовый класс Человек
 */
class Person
{
protected:
    /**
     * @brief Статический счетчик для генерации уникальных ID
     */
    static int nextId;

    /**
     * @brief id товара из списка
     */
    int id;

    /**
     * @brief ФИО человека
     */
    std::string fullName;

public:
    /**
     * @brief Конструктор по умолчанию
     */
    Person();

    /**
     * @brief Конструктор
     * @param fullName ФИО человека
     * @param id Идентификатор (0 для автогенерации)
     */
    explicit Person(const std::string &fullName, const int id = 0);

    /**
     * @brief Виртуальный деструктор
     */
    virtual ~Person() = default;

    /**
     * @brief Получить идентификатор
     * @return Уникальный ID
     */
    int getId() const noexcept;

    /**
     * @brief Получить ФИО
     * @return Константная ссылка на строку с ФИО
     */
    const std::string &getFullName() const noexcept;

    /**
     * @brief Получить базовую информацию
     * @return Строка с информацией о человеке
     */
    virtual std::string getInfo() const;
};
