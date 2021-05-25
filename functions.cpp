
#include "Lab12.h"

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
    if (size > 40)
    {
        cout << " Entered degree was too big, initial value shrinked to 40" << endl;
        size = 40;
    }

    int i;
    degree = size;
    coefficents = (double*) calloc(degree + 1, sizeof(double) * (degree + 1));
}

Polynom::Polynom(const Polynom& f)
{
    degree = f.degree;
    coefficents = (double*) malloc(sizeof(double) * (degree + 1));

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

istream& operator>>(istream& s, Polynom& c)
{
    for (int i = 0; i <= c.degree; i++)
        s >> c.coefficents[i];

    return s;
}

ostream& operator<<(ostream& s, const Polynom& c)
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
    if (i <= degree)
        return coefficents[i];
    else
        return 0.0;
}

void Polynom::operator*(int p)
{
    for (int i = 0; i <= degree; i++)
        coefficents[i] *= p;
}

void Polynom::operator+(int p)
{
    for (int i = 0; i <= degree; i++)
        coefficents[i] += p;
}

void Polynom::operator-(int p)
{
    for (int i = 0; i <= degree; i++)
        coefficents[i] -= p;
}