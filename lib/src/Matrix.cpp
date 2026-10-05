#include "Matrix.h"
#include <sstream>

void Matrix::allocateMemory()
{
    if (rows == 0 || columns == 0)
    {
        data = nullptr;
        return;
    }
    data = new int *[rows];
    for (size_t i = 0; i < rows; i++)
    {
        data[i] = new int[columns]{0};
    }
}

void Matrix::freeMemory()
{
    if (data)
    {
        for (size_t i = 0; i < rows; i++)
        {
            delete[] data[i];
        }
        delete[] data;
        data = nullptr;
    }
}

Matrix::Matrix() : rows(0), columns(0), data(nullptr) {}

Matrix::Matrix(size_t r, size_t c) : rows(r), columns(c), data(nullptr)
{
    allocateMemory();
}

Matrix::Matrix(const Matrix &other) : rows(other.rows), columns(other.columns), data(nullptr)
{
    allocateMemory();
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            data[i][j] = other.data[i][j];
        }
    }
}

Matrix::Matrix(Matrix &&other) noexcept : rows(other.rows), columns(other.columns), data(other.data)
{
    other.rows = 0;
    other.columns = 0;
    other.data = nullptr;
}

Matrix::~Matrix()
{
    freeMemory();
}

Matrix &Matrix::operator=(const Matrix &other)
{
    if (this != &other)
    {
        freeMemory();
        rows = other.rows;
        columns = other.columns;
        allocateMemory();
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < columns; j++)
            {
                data[i][j] = other.data[i][j];
            }
        }
    }
    return *this;
}

Matrix &Matrix::operator=(Matrix &&other) noexcept
{
    if (this != &other)
    {
        freeMemory();
        rows = other.rows;
        columns = other.columns;
        data = other.data;
        other.rows = 0;
        other.columns = 0;
        other.data = nullptr;
    }
    return *this;
}

bool Matrix::operator==(const Matrix &other) const
{
    if (rows != other.rows || columns != other.columns)
        return false;
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            if (data[i][j] != other.data[i][j])
                return false;
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix &other) const
{
    return !(*this == other);
}

int *Matrix::operator[](size_t index)
{
    return data[index];
}

const int *Matrix::operator[](size_t index) const
{
    return data[index];
}

size_t Matrix::getRows() const { return rows; }
size_t Matrix::getColumns() const { return columns; }

void Matrix::fillArray(const Generator &generator)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            data[i][j] = generator.generate();
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
            os << data[i][j] << (j == columns - 1 ? "" : " ");
        }
        if (i != rows - 1)
            os << "\n";
    }
    return os.str();
}

void Matrix::insertRowAfter(size_t rowIndex, const int *newRow)
{
    if (rowIndex >= rows)
        return;
    int **newData = new int *[rows + 1];
    for (size_t i = 0, newI = 0; i < rows; i++, newI++)
    {
        newData[newI] = data[i];
        if (i == rowIndex)
        {
            newI++;
            newData[newI] = new int[columns];
            for (size_t j = 0; j < columns; j++)
            {
                newData[newI][j] = newRow[j];
            }
        }
    }
    delete[] data;
    data = newData;
    rows++;
}

void Matrix::removeColumn(size_t colIndex)
{
    if (colIndex >= columns || columns == 0)
        return;

    if (columns == 1)
    {
        freeMemory();
        rows = 0;
        columns = 0;
        return;
    }

    int **newData = new int *[rows];
    for (size_t i = 0; i < rows; ++i)
    {
        newData[i] = new int[columns - 1];
        for (size_t j = 0, newJ = 0; j < columns; ++j)
        {
            if (j != colIndex)
            {
                newData[i][newJ] = data[i][j];
                newJ++;
            }
        }
    }

    for (size_t i = 0; i < rows; i++)
    {
        delete[] data[i];
    }
    delete[] data;

    data = newData;
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
