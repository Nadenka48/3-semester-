#include <iostream>
#include <vector>
#include <functional>
#include "Polyclinic.h"
#include "Person.h"
#include "Doctor.h"
#include "Patient.h"
#include "Appointment.h"

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main()
{
#ifdef _WIN32
    system("chcp 65001 > nul");
#endif

    Polyclinic polyclinic;

    Doctor doc1("Иванов Иван Иванович", "Терапевт", 101);
    doc1.addScheduleTime("ПН 08:00-14:00");
    doc1.addScheduleTime("СР 14:00-20:00");

    Doctor doc2("Петрова Анна Сергеевна", "Офтальмолог", 205);
    doc2.addScheduleTime("ВТ 09:00-13:00");
    doc2.addScheduleTime("ЧТ 09:00-13:00");

    polyclinic.addDoctor(doc1);
    polyclinic.addDoctor(doc2);

    Patient pat1("Сидоров Алексей Ильич", "15.05.1980", "1234567890123456");
    pat1.addChronicDisease("Гипертония");

    Patient pat2("Смирнова Ольга Владимировна", "22.11.1995", "9876543210987654");

    polyclinic.addPatient(pat1);
    polyclinic.addPatient(pat2);

    polyclinic.makeAppointment(Appointment(pat1.getId(), doc1.getId(), "10.11.2026 09:00", "Высокое давление"));
    polyclinic.makeAppointment(Appointment(pat2.getId(), doc2.getId(), "12.11.2026 10:30", "Резь в глазах"));

    std::cout << "Врачи поликлиники" << std::endl;
    for (const Doctor &doc : polyclinic.getDoctors())
    {
        std::cout << doc.getInfo() << "\n"
                  << std::endl;
    }

    std::cout << "Пациенты" << std::endl;
    for (const Patient &pat : polyclinic.getPatients())
    {
        std::cout << pat.getInfo() << "\n"
                  << std::endl;
    }

    std::cout << "Записи на прием" << std::endl;
    for (const Appointment &app : polyclinic.getAppointments())
    {
        std::cout << "Пациент: " << polyclinic.getPatientInfoById(app.getPatientId()) << std::endl;
        std::cout << "Врач: " << polyclinic.getDoctorInfoById(app.getDoctorId()) << std::endl;
        std::cout << "Дата и время: " << app.getDateTime() << std::endl;
        std::cout << "Жалобы: " << app.getReason() << "\n"
                  << std::endl;
    }

    std::vector<std::reference_wrapper<const Person>> people;

    Person basePerson("Главврач Михаил Потапович", 999);
    people.push_back(std::cref(basePerson));
    people.push_back(std::cref(doc1));
    people.push_back(std::cref(pat2));

    for (const Person &person : people)
    {
        std::cout << person.getInfo() << "\n"
                  << std::endl;
    }

    return 0;
}
