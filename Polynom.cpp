
#include "Polynom.h"

Polynom::Polynom()
{
    degree = 0;
    coefficents = NULL;
}

Polynom::~Polynom()
{
    if(coefficents)
        delete[] coefficents;
}

Polynom::Polynom(int size, int &error)
{
    degree = 0;
    coefficents = NULL;
    if (size < 0)
    {
        error = 1;
        return;
    }

    if (size > 40 || size > INT_MAX)
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
}                               // +

void Polynom::operator=(const Polynom& f) {
    degree = f.degree;
    coefficents = (double*)malloc(sizeof(double) * (degree + 1));

    if (coefficents != NULL) {
        for (int i = 0; i <= degree; i++)
            coefficents[i] = f.coefficents[i];
    }
}                        // +

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
}      //

int Polynom::get_degree() const
{
    return degree;
}

double Polynom::get_coefficents(int i, int &error) const
{
    if ((i <= degree) && (i >= 0) && coefficents)
        return coefficents[i];
    else
    {
        error = 1;
        return -1;
    }
}

void Polynom::set_coefficents(double num, int i, int& error)
{
    if (!coefficents || i < 0 || i > INT_MAX || !num)
    {
        error = 1;
        return;
    }
    coefficents[i] = num;
}

Polynom Polynom::operator*(double p) const
{
    Polynom Z = *this;
    for (int i = 0; i <= degree; i++)
        Z.coefficents[i] *= p;

    return Z;
}

Polynom Polynom::operator+(const Polynom& t) const
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

Polynom Polynom::operator-(const Polynom& t) const
{
    return *this + t * (-1);
}