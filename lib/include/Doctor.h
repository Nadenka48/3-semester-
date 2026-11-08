#pragma once
#include "Person.h"
#include <vector>
#include <string>

/**
 * @brief Класс Врач, наследуемый от Person
 */
class Doctor : public Person
{
private:
    /**
     * @brief Специальность врача
     */
    std::string specialty;

    /**
     * @brief Номер кабинета
     */
    int roomNumber;

    /**
     * @brief Расписание приема
     */
    std::vector<std::string> schedule;

public:
    /**
     * @brief Конструктор по умолчанию
     */
    Doctor();

    /**
     * @brief Конструктор с параметрами
     * @param fullName ФИО врача
     * @param specialty Специальность
     * @param roomNumber Номер кабинета
     * @param id Идентификатор
     */
    Doctor(const std::string &fullName, const std::string &specialty, const int roomNumber, const int id = 0);

    /**
     * @brief Получить специальность
     * @return Константная ссылка на специальность
     */
    const std::string &getSpecialty() const noexcept;

    /**
     * @brief Получить номер кабинета
     * @return Номер кабинета
     */
    int getRoomNumber() const noexcept;

    /**
     * @brief Добавить время приема в расписание
     * @param timeSlot Строка со временем
     */
    void addScheduleTime(const std::string &timeSlot);

    /**
     * @brief Получить расписание
     * @return Cсылка на вектор с расписанием
     */
    const std::vector<std::string> &getSchedule() const noexcept;

    /**
     * @brief Получить подробную информацию о враче
     * @return Строка с информацией
     */
    std::string getInfo() const override;
};
