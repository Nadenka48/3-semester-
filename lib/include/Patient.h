#pragma once
#include "Person.h"
#include <vector>
#include <string>

/**
 * @brief Класс Пациент, наследуемый от Person
 */
class Patient : public Person
{
private:
    /**
     * @brief Дата рождения
     */
    std::string birthDate;

    /**
     * @brief Номер страхового полиса
     */
    std::string insurancePolicy;

    /**
     * @brief Список хронических заболеваний
     */
    std::vector<std::string> chronicDiseases;

public:
    /**
     * @brief Конструктор по умолчанию
     */
    Patient();

    /**
     * @brief Конструктор с параметрами
     * @param fullName ФИО пациента
     * @param birthDate Дата рождения
     * @param insurancePolicy Номер полиса
     * @param id Идентификатор
     */
    Patient(const std::string &fullName, const std::string &birthDate, const std::string &insurancePolicy, const int id = 0);

    /**
     * @brief Добавить хроническое заболевание
     * @param disease Название заболевания
     */
    void addChronicDisease(const std::string &disease);

    /**
     * @brief Получить список заболеваний
     * @return Cсылка на вектор заболеваний
     */
    const std::vector<std::string> &getChronicDiseases() const noexcept;

    /**
     * @brief Получить подробную информацию о пациенте
     * @return Строка с информацией
     */
    std::string getInfo() const override;
};
