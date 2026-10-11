#include "InputGenerator.h"

InputGenerator::InputGenerator(std::istream &input_stream) : in(input_stream) {}

int InputGenerator::generate() const
{
    int val;
    in >> val;
    return val;
}
