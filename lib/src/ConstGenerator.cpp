#include "ConstGenerator.h"

ConstGenerator::ConstGenerator(const int value) : value(value) {}

int ConstGenerator::generate() const
{
    return value;
}
