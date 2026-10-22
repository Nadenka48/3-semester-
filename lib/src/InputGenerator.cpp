#include "InputGenerator.h"

InputGenerator::InputGenerator(std::istream &input_stream) : in(input_stream) {}

int InputGenerator::generate() const
{
    int val = 0;
    if (!(in >> val))
    {
        in.clear();
        in.ignore(32767, '\n');
    }
    return val;
}
