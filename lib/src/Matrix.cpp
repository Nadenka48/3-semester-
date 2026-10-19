#include "Matrix.h"
#include <sstream>
#include <stdexcept>

Matrix::Matrix() : rows(0), columns(0), data() {}

Matrix::Matrix(const size_t r, const size_t c) 
    : rows(r), columns(c), data(r, std::vector<int>(c, 0)) {}

bool Matrix::operator==(const Matrix &other) const
{
    return rows == other.rows && columns == other.columns && data == other.data;
}

bool Matrix::operator!=(const Matrix &other) const
{
    return !(*this == other);
}

std::vector<int> &Matrix::operator[](size_t index)
{
    return data.at(index);
}

const std::vector<int> &Matrix::operator[](size_t index) const
{
    return data.at(index);
}

size_t Matrix::getRows() const { return rows; }
size_t Matrix::getColumns() const { return columns; }

void Matrix::fillArray(const Generator &generator)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            data.at(i).at(j) = generator.generate();
        }
    }
}

std::string Matrix::toString() const
{
    if (rows == 0 || columns == 0)
        return "";
    std::ostringstream os;
    os << rows << " " << columns << "\n";
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            os << data.at(i).at(j) << (j == columns - 1 ? "" : " ");
        }
        if (i != rows - 1)
            os << "\n";
    }
    return os.str();
}

void Matrix::insertRowAfter(size_t rowIndex, const std::vector<int> &newRow)
{
    if (rowIndex >= rows)
        return;
    data.insert(data.begin() + rowIndex + 1, newRow);
    rows++;
}

void Matrix::removeColumn(size_t colIndex)
{
    if (colIndex >= columns || columns == 0)
        return;

    if (columns == 1)
    {
        data.clear();
        rows = 0;
        columns = 0;
        return;
    }

    for (size_t i = 0; i < rows; ++i)
    {
        data.at(i).erase(data.at(i).begin() + colIndex);
    }
    columns--;
}

std::ostream &operator<<(std::ostream &os, const Matrix &matrix)
{
    os << matrix.toString();
    return os;
}

std::istream &operator>>(std::istream &is, Matrix &matrix)
{
    size_t r, c;
    if (is >> r >> c)
    {
        Matrix temp(r, c);
        for (size_t i = 0; i < r; i++)
        {
            for (size_t j = 0; j < c; j++)
            {
                is >> temp[i][j];
            }
        }
        matrix = std::move(temp);
    }
    return is;
}
