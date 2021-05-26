
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
    size = (int)size;
    if (size > 40)
    {
        std::cout << " ¬ведЄнна€ степень слишком больша€, первоначальное значение уменьшено до 40" << std::endl;
        size = 40;
    }

    int i;
    degree = size;
    coefficents = (double*)calloc(degree + 1, sizeof(double) * (degree + 1));
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
        s >> c.coefficents[i];

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
    if ((i <= degree) && (i >= 0))
        return coefficents[i];
    else
        return 0.0;
}

Polynom Polynom::operator*(double p)
{
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