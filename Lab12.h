
#ifndef LAB12_H
#define LAB12_H

#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

class Polynom
{
private:
    int degree;                         // ������� �������� 
    double* coefficents;                // ��������� �� ������ ������������� �������� coefficents[i] - ����������� ��� i-� �������

public:
    Polynom();
    Polynom(int size);                  // ����������� � �����������
    Polynom(const Polynom&);            // ����������� �����������
    ~Polynom();                         // ����������

    int get_degree();                   // ������� ��������� ������� ��������
    double get_coefficents(int);        // ������� ��������� ������������ ��� i-� �������

    void operator+(int p);              // �������� ��������
    void operator-(int p);              // �������� ���������
    void operator*(int p);              // �������� ���������
    void operator=(const Polynom&);     // �������� �������������

    friend ostream& operator<< (ostream& s, const Polynom& c);  // ������������� �������� ������
    friend istream& operator>> (istream& s, Polynom& c);       // ������������� �������� �����

    double& operator()(int i)
    {
        return coefficents[i];
    }
};

#endif