#include <gtest/gtest.h>

#include <sstream>
#include <string>

#include "Matrix.h"
#include "ConstGenerator.h"
#include "RandomGenerator.h"
#include "InputGenerator.h"
#include "Task1Exercise.h"
#include "Task2Exercise.h"

TEST(MatrixConstructors, DefaultIsEmpty)
{
    Matrix m;
    EXPECT_EQ(m.getRows(), 0u);
    EXPECT_EQ(m.getColumns(), 0u);
    EXPECT_EQ(m.toString(), "");
}

TEST(MatrixConstructors, SizedMatrixIsZeroFilled)
{
    Matrix m(3, 4);
    EXPECT_EQ(m.getRows(), 3u);
    EXPECT_EQ(m.getColumns(), 4u);
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            EXPECT_EQ(m[i][j], 0);
        }
    }
}

TEST(MatrixCopy, CopyIsDeep)
{
    Matrix a(2, 2);
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 3;
    a[1][1] = 4;

    Matrix b = a;
    b[0][0] = 999;

    EXPECT_EQ(a[0][0], 1);
    EXPECT_EQ(b[0][0], 999);
}

TEST(MatrixMove, MoveLeavesSourceEmpty)
{
    Matrix a(2, 2);
    a[0][0] = 42;

    Matrix b = std::move(a);
    EXPECT_EQ(b[0][0], 42);
    EXPECT_EQ(a.getRows(), 0u);
    EXPECT_EQ(a.getColumns(), 0u);
}

TEST(MatrixRemoveColumn, RemoveMiddleColumn)
{
    Matrix m(2, 3);
    m[0][0] = 1;
    m[0][1] = 2;
    m[0][2] = 3;
    m[1][0] = 4;
    m[1][1] = 5;
    m[1][2] = 6;

    m.removeColumn(1);

    EXPECT_EQ(m.getRows(), 2u);
    EXPECT_EQ(m.getColumns(), 2u);
    EXPECT_EQ(m[0][0], 1);
    EXPECT_EQ(m[0][1], 3);
    EXPECT_EQ(m[1][0], 4);
    EXPECT_EQ(m[1][1], 6);
}

TEST(MatrixRemoveColumn, RemoveOnlyColumn)
{
    Matrix m(3, 1);
    m[0][0] = 1;
    m[1][0] = 2;
    m[2][0] = 3;

    m.removeColumn(0);

    EXPECT_EQ(m.getRows(), 0u);
    EXPECT_EQ(m.getColumns(), 0u);
}

TEST(ConstGeneratorTest, ReturnsConstant)
{
    ConstGenerator gen(42);
    EXPECT_EQ(gen.generate(), 42);
    EXPECT_EQ(gen.generate(), 42);
}

TEST(RandomGeneratorTest, ValuesInRange)
{
    RandomGenerator gen(-10, 10);
    for (int i = 0; i < 1000; i++)
    {
        int v = gen.generate();
        EXPECT_GE(v, -10);
        EXPECT_LE(v, 10);
    }
}

TEST(Task1Test, ReplaceEvenElementsWithMaxAbsInColumn)
{
    Matrix m(3, 3);

    m[0][0] = -2;
    m[0][1] = 3;
    m[0][2] = 4;
    m[1][0] = 1;
    m[1][1] = -4;
    m[1][2] = 6;
    m[2][0] = 5;
    m[2][1] = 2;
    m[2][2] = -8;

    ConstGenerator dummyGen(0);
    Task1Exercise task(m, dummyGen);
    Matrix result = task.solve();

    EXPECT_EQ(result.getRows(), 3u);
    EXPECT_EQ(result.getColumns(), 3u);

    EXPECT_EQ(result[0][0], 5);
    EXPECT_EQ(result[1][0], 1);
    EXPECT_EQ(result[2][0], 5);

    EXPECT_EQ(result[0][1], 3);
    EXPECT_EQ(result[1][1], 4);
    EXPECT_EQ(result[2][1], 4);

    EXPECT_EQ(result[0][2], 8);
    EXPECT_EQ(result[1][2], 8);
    EXPECT_EQ(result[2][2], 8);
}

TEST(Task1Test, OriginalIsNotModified)
{
    Matrix m(2, 2);
    m[0][0] = 2;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;

    ConstGenerator dummyGen(0);
    Task1Exercise task(m, dummyGen);
    task.solve();

    EXPECT_EQ(m[0][0], 2);
    EXPECT_EQ(m[1][1], 4);
}

TEST(Task2Test, RemoveColumnsWithEvenFirstElement)
{
    Matrix m(2, 4);
    m[0][0] = 2;
    m[0][1] = 3;
    m[0][2] = -4;
    m[0][3] = 5;
    m[1][0] = 1;
    m[1][1] = 2;
    m[1][2] = 3;
    m[1][3] = 4;

    ConstGenerator dummyGen(0);
    Task2Exercise task(m, dummyGen);
    Matrix result = task.solve();

    EXPECT_EQ(result.getRows(), 2u);
    EXPECT_EQ(result.getColumns(), 2u);

    EXPECT_EQ(result[0][0], 3);
    EXPECT_EQ(result[1][0], 2);

    EXPECT_EQ(result[0][1], 5);
    EXPECT_EQ(result[1][1], 4);
}

TEST(Task2Test, RemoveAllColumns)
{
    Matrix m(2, 2);
    m[0][0] = 2;
    m[0][1] = 8;
    m[1][0] = 7;
    m[1][1] = 7;

    ConstGenerator dummyGen(0);
    Task2Exercise task(m, dummyGen);
    Matrix result = task.solve();

    EXPECT_EQ(result.getRows(), 0u);
    EXPECT_EQ(result.getColumns(), 0u);
}
