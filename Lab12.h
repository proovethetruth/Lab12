
#ifndef LAB12_H
#define LAB12_H

#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

class Polynom
{
private:
    int degree;                         // степень полинома 
    double* coefficents;                // указатель на массив коэффициентов полинома coefficents[i] - коэффициент при i-й степени

public:
    Polynom();
    Polynom(int size);                  // конструктор с параметрами
    Polynom(const Polynom&);            // конструктор копирования
    ~Polynom();                         // деструктор

    int get_degree();                   // функция получения степени полинома
    double get_coefficents(int);        // функция получения коэффициента при i-й степени

    void operator+(int p);              // оператор сложения
    void operator-(int p);              // оператор вычитания
    void operator*(int p);              // оператор умножения
    void operator=(const Polynom&);     // оператор приравнивания

    friend ostream& operator<< (ostream& s, const Polynom& c);  // перегруженный оператор вывода
    friend istream& operator>> (istream& s, Polynom& c);       // перегруженный оператор ввода

    double& operator()(int i)
    {
        return coefficents[i];
    }
};

#endif