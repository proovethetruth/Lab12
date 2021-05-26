
#include "Polynom.h"
#include <iostream>

Polynom::Polynom()
{
    degree = 0;
    coefficents = NULL;
}

Polynom::~Polynom()
{
    delete[] coefficents;
}

Polynom::Polynom(int size)
{
    while (!std::cin.good() || size < 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (size < INT_MAX)
            std::cout << " Некорректный ввод. Степень полинома - целое, положительное число. Попробуйте ещё раз.\n\n Введите степень полинома А: ";
        else
            std::cout << " Некорректный ввод. Число слишком большое. Попробуйте ещё раз.\n\n Введите степень полинома А: ";
        std::cin >> size;
    }
    if (size > 40)
    {
        std::cout << " Введённая степень слишком большая, первоначальное значение уменьшено до 40" << std::endl;
        size = 40;
    }
    degree = size;
    coefficents = (double*)calloc(degree + 1, sizeof(double) * (degree + 1));

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

Polynom::Polynom(const Polynom& f)
{
    degree = f.degree;
    coefficents = (double*)malloc(sizeof(double) * (degree + 1));

    if (coefficents != NULL) {
        for (int i = 0; i <= degree; i++)
            coefficents[i] = f.coefficents[i];
    }
}

void Polynom::operator=(const Polynom& f) {
    degree = f.degree;
    coefficents = (double*)malloc(sizeof(double) * (degree + 1));

    if (coefficents != NULL) {
        for (int i = 0; i <= degree; i++)
            coefficents[i] = f.coefficents[i];
    }
}

std::istream& operator>>(std::istream& s, Polynom& c)
{
    for (int i = 0; i <= c.degree; i++)
    {
        s >> c.coefficents[i];
        while (!(s.good()))
        {
            s.clear();
            s.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << " Некорректный ввод. Коэффиценты полинома - вещественные числа. Попробуйте ещё раз.\n\n Введите коэффиценты полинома А: ";
            s >> c.coefficents[i];
        }
    }

    s.clear();
    s.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return s;
}

std::ostream& operator<<(std::ostream& s, const Polynom& c)
{
    int i, n = 0;

    for (i = 0; i <= c.degree; i++)
    {
        if (c.coefficents[i] != 0)
            n++;
    }

    if (n != 0)
    {
        if (c.coefficents[0] != 0)
        {
            s << c.coefficents[0];
        }
        for (i = 1; i <= c.degree; i++)
        {
            if (c.coefficents[i] < 0)
            {
                if (c.coefficents[i] != -1)
                    s << " " << c.coefficents[i] << "x^" << i;
                else
                    s << " - " << "x^" << i;
            }
            else
            {
                if (c.coefficents[i] != 0)
                {
                    if (c.coefficents[i] != 1)
                        s << " + " << c.coefficents[i] << "x^" << i;
                    else
                        s << " + " << "x^" << i;
                }
            }
        }
        s << '\n';
    }
    else
        s << 0;
    return s;
}

int Polynom::get_degree()
{
    return degree;
}

double Polynom::get_coefficents(int i)
{
    while (!std::cin.good() || (i < 0))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (i < INT_MAX)
            std::cout << " Некорректный ввод. Требуется ввести неотрицательное число. Попробуйте ещё раз.\n\n Введите индекс коэффицента полинома (демонстрация метода get_coefficents): ";
        else
            std::cout << " Некорректный ввод. Число слишком большое. Попробуйте ещё раз.\n\n Введите индекс коэффицента полинома (демонстрация метода get_coefficents): ";
        std::cin >> i;
    }

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (i <= degree)
        return coefficents[i];
    else
        return 0.0;
}

Polynom Polynom::operator*(double p)
{
    while (!std::cin.good())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (p < INT_MAX)
            std::cout << " Некорректный ввод. Требуется ввести число. Попробуйте ещё раз.\n\n Введите число: ";
        else
            std::cout << " Некорректный ввод. Число слишком большое. Попробуйте ещё раз.\n\n Введите число: ";
        std::cin >> p;
    }

    Polynom Z = *this;
    for (int i = 0; i <= degree; i++)
        Z.coefficents[i] *= p;

    return Z;
}

Polynom Polynom::operator+(const Polynom& t)
{
    int i;
    if (degree >= t.degree)
    {
        Polynom Z = *this;
        for (i = 0; i <= degree; i++)
            Z.coefficents[i] = coefficents[i] + t.coefficents[i];
        return Z;
    }
    else
    {
        Polynom Z = t;
        for (i = 0; i <= degree; i++)
            Z.coefficents[i] = t.coefficents[i] + coefficents[i];
        return Z;
    }
}

Polynom Polynom::operator-(const Polynom& t)
{
    int i;
    if (degree >= t.degree)
    {
        Polynom Z = *this;
        for (i = 0; i <= t.degree; i++)
            Z.coefficents[i] = coefficents[i] - t.coefficents[i];
        return Z;
    }
    else
    {
        Polynom Z(t.degree);
        for (i = 0; i <= degree; i++)
            Z.coefficents[i] = -t.coefficents[i] + coefficents[i];
        for (i = degree + 1; i <= t.degree; i++)
            Z.coefficents[i] = -t.coefficents[i];
        return Z;
    }
}