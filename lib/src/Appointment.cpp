#include "Appointment.h"

Appointment::Appointment(const int patientId, const int doctorId, const std::string &dateTime, const std::string &reason)
    : patientId(patientId), doctorId(doctorId), dateTime(dateTime), reason(reason) {}

int Appointment::getPatientId() const noexcept
{
    return patientId;
}

int Appointment::getDoctorId() const noexcept
{
    return doctorId;
}

const std::string &Appointment::getDateTime() const noexcept
{
    return dateTime;
}

const std::string &Appointment::getReason() const noexcept
{
    return reason;
}
