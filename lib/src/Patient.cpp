#include "Patient.h"

Patient::Patient() : Person(), birthDate(""), insurancePolicy("") {}

Patient::Patient(const std::string &fullName, const std::string &birthDate, const std::string &insurancePolicy, const int id)
    : Person(fullName, id), birthDate(birthDate), insurancePolicy(insurancePolicy) {}

void Patient::addChronicDisease(const std::string &disease)
{
    chronicDiseases.push_back(disease);
}

const std::vector<std::string> &Patient::getChronicDiseases() const noexcept
{
    return chronicDiseases;
}

std::string Patient::getInfo() const
{
    std::string result = Person::getInfo();
    result += " | Д.Р.: " + birthDate;
    result += " | Полис: " + insurancePolicy;
    result += "\n   Хронические заболевания: ";
    if (chronicDiseases.empty())
    {
        result += "Нет";
    }
    else
    {
        for (std::size_t i = 0; i < chronicDiseases.size(); ++i)
        {
            result += chronicDiseases[i] + (i < chronicDiseases.size() - 1 ? ", " : "");
        }
    }
    return result;
}
