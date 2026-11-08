#include "Polyclinic.h"
#include <algorithm>

bool Polyclinic::containsDoctorId(const int id) const
{
    return std::any_of(doctors.begin(), doctors.end(), [id](const Doctor &d)
                       { return d.getId() == id; });
}

bool Polyclinic::containsPatientId(const int id) const
{
    return std::any_of(patients.begin(), patients.end(), [id](const Patient &p)
                       { return p.getId() == id; });
}

void Polyclinic::addDoctor(const Doctor &doctor)
{
    if (!containsDoctorId(doctor.getId()))
    {
        doctors.push_back(doctor);
    }
}

void Polyclinic::addPatient(const Patient &patient)
{
    if (!containsPatientId(patient.getId()))
    {
        patients.push_back(patient);
    }
}

void Polyclinic::makeAppointment(const Appointment &appointment)
{
    appointments.push_back(appointment);
}

const std::vector<Doctor> &Polyclinic::getDoctors() const noexcept
{
    return doctors;
}

const std::vector<Patient> &Polyclinic::getPatients() const noexcept
{
    return patients;
}

const std::vector<Appointment> &Polyclinic::getAppointments() const noexcept
{
    return appointments;
}

std::string Polyclinic::getDoctorInfoById(const int doctorId) const
{
    auto it = std::find_if(doctors.begin(), doctors.end(), [doctorId](const Doctor &d)
                           { return d.getId() == doctorId; });
    if (it != doctors.end())
    {
        return it->getFullName() + " (" + it->getSpecialty() + ")";
    }
    return "Неизвестный врач";
}

std::string Polyclinic::getPatientInfoById(const int patientId) const
{
    auto it = std::find_if(patients.begin(), patients.end(), [patientId](const Patient &p)
                           { return p.getId() == patientId; });
    if (it != patients.end())
    {
        return it->getFullName();
    }
    return "Неизвестный пациент";
}
