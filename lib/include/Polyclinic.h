#pragma once
#include "Doctor.h"
#include "Patient.h"
#include "Appointment.h"
#include <vector>

/**
 * @brief Класс Поликлиника
 */
class Polyclinic
{
private:
    /**
     * @brief Список врачей
     */
    std::vector<Doctor> doctors;

    /**
     * @brief Список пациентов
     */
    std::vector<Patient> patients;

    /**
     * @brief Список записей на прием
     */
    std::vector<Appointment> appointments;

    /**
     * @brief Проверка наличия врача по ID
     * @param id Идентификатор врача
     * @return true, если врач существует
     */
    bool containsDoctorId(const int id) const;

    /**
     * @brief Проверка наличия пациента по ID
     * @param id Идентификатор пациента
     * @return true, если пациент существует
     */
    bool containsPatientId(const int id) const;

public:
    /**
     * @brief Конструктор по умолчанию
     */
    Polyclinic() = default;

    /**
     * @brief Деструктор
     */
    ~Polyclinic() = default;

    /**
     * @brief Добавить врача
     * @param doctor Объект врача
     */
    void addDoctor(const Doctor &doctor);

    /**
     * @brief Добавить пациента
     * @param patient Объект пациента
     */
    void addPatient(const Patient &patient);

    /**
     * @brief Записать пациента на прием
     * @param appointment Объект записи на прием
     */
    void makeAppointment(const Appointment &appointment);

    /**
     * @brief Получить список врачей
     * @return Ссылка на вектор врачей
     */
    const std::vector<Doctor> &getDoctors() const noexcept;

    /**
     * @brief Получить список пациентов
     * @return Ссылка на вектор пациентов
     */
    const std::vector<Patient> &getPatients() const noexcept;

    /**
     * @brief Получить список записей
     * @return Ссылка на вектор записей
     */
    const std::vector<Appointment> &getAppointments() const noexcept;

    /**
     * @brief Получить информацию о враче по его ID
     * @param doctorId Идентификатор врача
     * @return Строка с ФИО и специальностью врача
     */
    std::string getDoctorInfoById(const int doctorId) const;

    /**
     * @brief Получить информацию о пациенте по его ID
     * @param patientId Идентификатор пациента
     * @return Строка с ФИО пациента
     */
    std::string getPatientInfoById(const int patientId) const;
};
