#ifndef POLYNOM_H
#define POLYNOM_H

#include <fstream>

class Polynom
{
private:
    int degree;
    double* coefficents;

public:
    Polynom();
    Polynom(int size);
    Polynom(const Polynom&);
    ~Polynom();

    int get_degree();
    double get_coefficents(int);

    Polynom operator+(const Polynom&);
    Polynom operator-(const Polynom&);
    Polynom operator*(double p);
    void operator=(const Polynom&);

    friend std::ostream& operator<< (std::ostream& s, const Polynom& c);
    friend std::istream& operator>> (std::istream& s, Polynom& c);
};

#endif