#ifndef POLYNOM_H
#define POLYNOM_H

// перегрузить оператор деления (/) чтобы он находил остаток от деления в виде полинома A на B

#include <iostream>

class Polynom
{
private:
    int degree;
    double* coefficents;

public:
    Polynom();
    Polynom(int size, int &error);
    Polynom(const Polynom&);
    ~Polynom();

    int get_degree() const;
    double get_coefficents(int i, int &error) const;
    void set_coefficents(double num, int i, int& error);
    Polynom operator+(const Polynom&) const;
    Polynom operator-(const Polynom&) const;
    Polynom operator*(double p) const;
    void operator=(const Polynom& f);

    friend std::ostream& operator<< (std::ostream& s, const Polynom& c);
    friend std::istream& operator>> (std::istream& s, Polynom& c);

    Polynom operator/(const Polynom& t) const;
    friend Polynom divide_poly(const Polynom a, const Polynom b);
    friend Polynom shrink_to_fit(Polynom& a);
};

#endif