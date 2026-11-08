#pragma once
#include <string>

/**
 * @brief Класс Запись на прием
 */
class Appointment
{
private:
    /**
     * @brief Идентификатор пациента
     */
    int patientId;

    /**
     * @brief Идентификатор врача
     */
    int doctorId;

    /**
     * @brief Дата и время приема
     */
    std::string dateTime;

    /**
     * @brief Цель визита или жалобы
     */
    std::string reason;

public:
    /**
     * @brief Конструктор по умолчанию
     */
    Appointment() = default;

    /**
     * @brief Конструктор с параметрами
     * @param patientId Идентификатор пациента
     * @param doctorId Идентификатор врача
     * @param dateTime Дата и время приема
     * @param reason Причина обращения
     */
    Appointment(const int patientId, const int doctorId, const std::string &dateTime, const std::string &reason);

    /**
     * @brief Получить идентификатор пациента
     * @return ID пациента
     */
    int getPatientId() const noexcept;

    /**
     * @brief Получить идентификатор врача
     * @return ID врача
     */
    int getDoctorId() const noexcept;

    /**
     * @brief Получить дату и время
     * @return Ссылка на строку с датой и временем
     */
    const std::string &getDateTime() const noexcept;

    /**
     * @brief Получить причину визита
     * @return Ссылка на строку с причиной
     */
    const std::string &getReason() const noexcept;
};
