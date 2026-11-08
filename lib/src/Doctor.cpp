#include "Doctor.h"

Doctor::Doctor() : Person(), specialty(""), roomNumber(0) {}

Doctor::Doctor(const std::string &fullName, const std::string &specialty, const int roomNumber, const int id)
    : Person(fullName, id), specialty(specialty), roomNumber(roomNumber) {}

const std::string &Doctor::getSpecialty() const noexcept
{
    return specialty;
}

int Doctor::getRoomNumber() const noexcept
{
    return roomNumber;
}

void Doctor::addScheduleTime(const std::string &timeSlot)
{
    schedule.push_back(timeSlot);
}

const std::vector<std::string> &Doctor::getSchedule() const noexcept
{
    return schedule;
}

std::string Doctor::getInfo() const
{
    std::string result = Person::getInfo();
    result += " | Специальность: " + specialty;
    result += " | Кабинет: " + std::to_string(roomNumber);
    result += "\n   Расписание: ";
    if (schedule.empty())
    {
        result += "Нет приема";
    }
    else
    {
        for (std::size_t i = 0; i < schedule.size(); ++i)
        {
            result += schedule[i] + (i < schedule.size() - 1 ? ", " : "");
        }
    }
    return result;
}
