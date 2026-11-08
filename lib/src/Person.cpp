#include "Person.h"

int Person::nextId = 1;

Person::Person() : id(nextId++), fullName("") {}

Person::Person(const std::string &fullName, const int id)
    : id(id > 0 ? id : nextId++), fullName(fullName)
{
    if (this->id >= nextId)
    {
        nextId = this->id + 1;
    }
}

int Person::getId() const noexcept
{
    return id;
}

const std::string &Person::getFullName() const noexcept
{
    return fullName;
}

std::string Person::getInfo() const
{
    return "ID: " + std::to_string(id) + " | ФИО: " + fullName;
}
