#include <gtest/gtest.h>
#include "Polyclinic.h"
#include "Person.h"
#include "Doctor.h"
#include "Patient.h"
#include "Appointment.h"
#include <string>
#include <algorithm>
#include <typeinfo>
#include <functional>

TEST(PersonTest, DefaultConstructorHasValidId)
{
    Person p;
    EXPECT_GT(p.getId(), 0);
    EXPECT_EQ(p.getFullName(), "");
}

TEST(PersonTest, GettersAutoId)
{
    Person p("Иванов И.И.");
    EXPECT_GT(p.getId(), 0);
    EXPECT_EQ(p.getFullName(), "Иванов И.И.");
}

TEST(PersonTest, ConstructorWithExplicitId)
{
    Person p("Смирнов С.С.", 42);
    EXPECT_EQ(p.getId(), 42);
    EXPECT_EQ(p.getFullName(), "Смирнов С.С.");
}

TEST(PersonTest, GetInfo)
{
    Person p("Кузнецов К.К.", 10);
    std::string info = p.getInfo();
    EXPECT_NE(info.find("ID: 10"), std::string::npos);
    EXPECT_NE(info.find("Кузнецов К.К."), std::string::npos);
}

TEST(DoctorTest, DefaultConstructorHasValidId)
{
    Doctor d;
    EXPECT_GT(d.getId(), 0);
    EXPECT_EQ(d.getFullName(), "");
    EXPECT_EQ(d.getSpecialty(), "");
    EXPECT_EQ(d.getRoomNumber(), 0);
    EXPECT_TRUE(d.getSchedule().empty());
}

TEST(DoctorTest, ParameterizedConstructor)
{
    Doctor d("Петров П.П.", "Хирург", 305, 99);
    EXPECT_EQ(d.getId(), 99);
    EXPECT_EQ(d.getFullName(), "Петров П.П.");
    EXPECT_EQ(d.getSpecialty(), "Хирург");
    EXPECT_EQ(d.getRoomNumber(), 305);
}

TEST(DoctorTest, AddAndGetSchedule)
{
    Doctor d("Иванов И.И.", "Терапевт", 101);
    EXPECT_TRUE(d.getSchedule().empty());

    d.addScheduleTime("ПН 08:00-14:00");
    d.addScheduleTime("СР 14:00-20:00");

    ASSERT_EQ(d.getSchedule().size(), 2u);
    EXPECT_EQ(d.getSchedule()[0], "ПН 08:00-14:00");
    EXPECT_EQ(d.getSchedule()[1], "СР 14:00-20:00");
}

TEST(DoctorTest, GetInfoContainsAllFields)
{
    Doctor d("Петров П.П.", "Хирург", 305, 77);
    d.addScheduleTime("ПТ 10:00-12:00");
    std::string info = d.getInfo();

    EXPECT_NE(info.find("ID: 77"), std::string::npos);
    EXPECT_NE(info.find("Петров П.П."), std::string::npos);
    EXPECT_NE(info.find("Хирург"), std::string::npos);
    EXPECT_NE(info.find("305"), std::string::npos);
    EXPECT_NE(info.find("ПТ 10:00-12:00"), std::string::npos);
}

TEST(PatientTest, DefaultConstructorHasValidId)
{
    Patient p;
    EXPECT_GT(p.getId(), 0);
    EXPECT_EQ(p.getFullName(), "");
    EXPECT_TRUE(p.getChronicDiseases().empty());
}

TEST(PatientTest, ParameterizedConstructor)
{
    Patient p("Сидоров С.С.", "12.05.1990", "111222333", 88);
    EXPECT_EQ(p.getId(), 88);
    EXPECT_EQ(p.getFullName(), "Сидоров С.С.");
    EXPECT_NE(p.getInfo().find("12.05.1990"), std::string::npos);
    EXPECT_NE(p.getInfo().find("111222333"), std::string::npos);
}

TEST(PatientTest, AddAndGetChronicDiseases)
{
    Patient p("Сидоров С.С.", "12.05.1990", "111222333");
    EXPECT_TRUE(p.getChronicDiseases().empty());

    p.addChronicDisease("Астма");
    p.addChronicDisease("Диабет");

    ASSERT_EQ(p.getChronicDiseases().size(), 2u);
    EXPECT_EQ(p.getChronicDiseases()[0], "Астма");
    EXPECT_EQ(p.getChronicDiseases()[1], "Диабет");
}

TEST(AppointmentTest, DefaultConstructor)
{
    Appointment a;
    EXPECT_EQ(a.getDateTime(), "");
    EXPECT_EQ(a.getReason(), "");
}

TEST(AppointmentTest, Getters)
{
    Appointment a(1, 2, "20.11.2026 15:00", "Болит спина");
    EXPECT_EQ(a.getPatientId(), 1);
    EXPECT_EQ(a.getDoctorId(), 2);
    EXPECT_EQ(a.getDateTime(), "20.11.2026 15:00");
    EXPECT_EQ(a.getReason(), "Болит спина");
}

TEST(PolyclinicTest, DefaultConstructorEmptyCollections)
{
    Polyclinic poly;
    EXPECT_TRUE(poly.getDoctors().empty());
    EXPECT_TRUE(poly.getPatients().empty());
    EXPECT_TRUE(poly.getAppointments().empty());
}

TEST(PolyclinicTest, AddAndGetDoctorsAndPatients)
{
    Polyclinic poly;

    Doctor d1("Иванов И.И.", "Терапевт", 101, 1001);
    Doctor d2("Петров П.П.", "Окулист", 202, 1002);
    poly.addDoctor(d1);
    poly.addDoctor(d2);

    ASSERT_EQ(poly.getDoctors().size(), 2u);
    EXPECT_EQ(poly.getDoctors()[0].getFullName(), "Иванов И.И.");

    Patient p1("Сидоров С.С.", "12.05.1990", "111", 2001);
    poly.addPatient(p1);

    ASSERT_EQ(poly.getPatients().size(), 1u);
    EXPECT_EQ(poly.getPatients()[0].getFullName(), "Сидоров С.С.");
}

TEST(PolyclinicTest, DuplicateIdRejected)
{
    Polyclinic poly;

    Doctor d("Иванов И.И.", "Терапевт", 101, 1001);
    poly.addDoctor(d);
    poly.addDoctor(Doctor("Клон Иванова", "Хирург", 999, 1001));

    EXPECT_EQ(poly.getDoctors().size(), 1u);
    EXPECT_EQ(poly.getDoctors()[0].getFullName(), "Иванов И.И.");

    Patient p("Сидоров С.С.", "12.05.1990", "111", 2001);
    poly.addPatient(p);
    poly.addPatient(Patient("Клон Сидорова", "01.01.2000", "222", 2001));

    EXPECT_EQ(poly.getPatients().size(), 1u);
    EXPECT_EQ(poly.getPatients()[0].getFullName(), "Сидоров С.С.");
}

TEST(PolyclinicTest, MakeAppointment)
{
    Polyclinic poly;
    Appointment a(1, 2, "20.11.2026", "Жалоба");
    poly.makeAppointment(a);

    ASSERT_EQ(poly.getAppointments().size(), 1u);
    EXPECT_EQ(poly.getAppointments()[0].getPatientId(), 1);
    EXPECT_EQ(poly.getAppointments()[0].getDoctorId(), 2);
}

TEST(PolyclinicTest, GetInfoByIdMethods)
{
    Polyclinic poly;
    poly.addDoctor(Doctor("Иванов И.И.", "Терапевт", 101, 10));
    poly.addPatient(Patient("Сидоров С.С.", "12.05.1990", "111", 20));

    EXPECT_EQ(poly.getDoctorInfoById(10), "Иванов И.И. (Терапевт)");
    EXPECT_EQ(poly.getDoctorInfoById(999), "Неизвестный врач");

    EXPECT_EQ(poly.getPatientInfoById(20), "Сидоров С.С.");
    EXPECT_EQ(poly.getPatientInfoById(999), "Неизвестный пациент");
}

TEST(PolyclinicTest, PolymorphismByReference)
{
    Person base("Обычный Человек", 1);
    Doctor doc("Врач Врачов", "Хирург", 100, 2);
    Patient pat("Пациент Пациентов", "01.01.2000", "OMS", 3);

    const Person &pRef = base;
    const Person &dRef = doc;
    const Person &patRef = pat;

    EXPECT_THROW((void)dynamic_cast<const Doctor &>(pRef), std::bad_cast);
    EXPECT_NO_THROW((void)dynamic_cast<const Doctor &>(dRef));
    EXPECT_THROW((void)dynamic_cast<const Doctor &>(patRef), std::bad_cast);

    EXPECT_EQ(pRef.getInfo().find("Хирург"), std::string::npos);
    EXPECT_NE(dRef.getInfo().find("Хирург"), std::string::npos);
    EXPECT_NE(patRef.getInfo().find("OMS"), std::string::npos);
}
