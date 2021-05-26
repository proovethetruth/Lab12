
#include "Polynom.h"
#include <iostream>


int main() {
    setlocale(LC_ALL, "");
    int n, i;
    double p;

    std::cout << "\n ДЕМОНСТРАЦИЯ МЕТОДОВ КЛАССА POLYNOM.";

    std::cout << "\n ----------------------------------------------------------------- \n\n";

    std::cout << " Введите степень полинома A: ";
    std::cin >> n;
    while (!std::cin.good() || n < 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (n < INT_MAX)
            std::cout << " Некорректный ввод. Степень полинома - целое, положительное число. Попробуйте ещё раз.\n\n Введите степень полинома А: ";
        else
            std::cout << " Некорректный ввод. Число слишком большое. Попробуйте ещё раз.\n\n Введите степень полинома А: ";
        std::cin >> n;
    }

    Polynom A(n);

    std::cout << " Введите коэфициенты полинома A: ";
    std::cin >> A;
    while (!std::cin.good())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << " Некорректный ввод. Коэффиценты полинома представляют собой набор вещественных чисел. Попробуйте ещё раз.\n\n Введите коэффиценты полинома А: ";
        std::cin >> A;
    }

    std::cout << "\n Многочлен А: " << A;
    std::cout << " Степень полинома А: " << A.get_degree();

    std::cout << "\n Введите индекс коэффицента полинома А (демонстрация метода get_coefficents): ";
    std::cin >> i;
    while (!std::cin.good() || (i < 0))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (i < INT_MAX)
            std::cout << " Некорректный ввод. Требуется ввести неотрицательное число. Попробуйте ещё раз.\n\n Введите индекс коэффицента полинома А (демонстрация метода get_coefficents): ";
        else
            std::cout << " Некорректный ввод. Число слишком большое. Попробуйте ещё раз.\n\n Введите индекс коэффицента полинома А (демонстрация метода get_coefficents): ";
        std::cin >> i;
    }
    std::cout << " Коэффицент по индексу " << i << ": " <<  A.get_coefficents(i-1);

    std::cout << "\n\n ----------------------------------------------------------------- \n\n";

    n = 0;
    std::cout << " Введите степень полинома B: ";
    std::cin >> n;
    while (!std::cin.good() || n < 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (n < INT_MAX)
            std::cout << " Некорректный ввод. Степень полинома - целое, положительное число. Попробуйте ещё раз.\n\n Введите степень полинома В: ";
        else
            std::cout << " Некорректный ввод. Число слишком большое. Попробуйте ещё раз.\n\n Введите степень полинома В: ";
        std::cin >> n;
    }

    Polynom B(n);

    std::cout << " Введите коэфициенты полинома B: ";
    std::cin >> B;
    while (!std::cin.good())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << " Некорректный ввод. Коэффиценты полинома представляют собой набор вещественных чисел. Попробуйте ещё раз.\n\n Введите коэффиценты полинома В: ";
        std::cin >> B;
    }

    std::cout << "\n Многочлен B: " << B;
    std::cout << " Степень полинома В: " << B.get_degree();

    i = 0;
    std::cout << "\n Введите индекс коэффицента полинома В (демонстрация метода get_coefficents): ";
    std::cin >> i;
    while (!std::cin.good())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (i < INT_MAX)
            std::cout << " Некорректный ввод. Требуется ввести число. Попробуйте ещё раз.\n\n Введите индекс коэффицента полинома В (демонстрация метода get_coefficents): ";
        else
            std::cout << " Некорректный ввод. Число слишком большое. Попробуйте ещё раз.\n\n Введите индекс коэффицента полинома В (демонстрация метода get_coefficents): ";
        std::cin >> i;
    }
    std::cout << " Коэффицент по индексу " << i << ": " << B.get_coefficents(i - 1);

    std::cout << "\n\n\n Результат сложения (A + B): " << (A + B);
    std::cout << " Результат вычитания (A - B): " << (A - B) << "\n";

    std::cout << "\n Введите число: ";
    std::cin >> p;
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

    std::cout << " Результат умножения A: " << A * p;
    std::cout << " Результат умножения B: " << B * p << "\n";

	return 0;
}