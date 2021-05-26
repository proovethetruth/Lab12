
#include "Polynom.h"

int main() {
    setlocale(LC_ALL, "");
    int size = 0, i, error = 0;
    double p;

    std::cout << "\n ДЕМОНСТРАЦИЯ МЕТОДОВ КЛАССА POLYNOM.";

    std::cout << "\n ----------------------------------------------------------------- \n\n";

    std::cout << " Введите степень полинома A: ";
    std::cin >> size;

    Polynom A(size, error);
    if (error == 1)
    {
        printf("\n Error");
        return -1;
    }

    std::cout << " Введите коэфициенты полинома A: ";
    std::cin >> A;

    std::cout << "\n Многочлен А: " << A;
    std::cout << " Степень полинома А: " << A.get_degree();

    std::cout << "\n Введите индекс коэффицента полинома А (демонстрация метода get_coefficents): ";
    std::cin >> i;

    std::cout << " Коэффицент по заданному индексу: " << A.get_coefficents(i, error);
    if (error == 1)
    {
        printf("\n Error");
        return -1;
    }

    std::cout << "\n\n ----------------------------------------------------------------- \n\n";

    size = 0;
    std::cout << " Введите степень полинома B: ";
    std::cin >> size;
    Polynom B(size, error);
    if (error == 1)
    {
        printf("\n Error");
        return -1;
    }

    std::cout << " Введите коэфициенты полинома B: ";
    std::cin >> B;

    std::cout << "\n Многочлен B: " << B;
    std::cout << " Степень полинома В: " << B.get_degree();

    i = 0;
    std::cout << "\n Введите индекс коэффицента полинома В (демонстрация метода get_coefficents): ";
    std::cin >> i;
    std::cout << " Коэффицент по индексу: " << B.get_coefficents(i - 1, error);
    if (error == 1)
    {
        printf("\n Error");
        return -1;
    }

    std::cout << "\n\n\n Результат сложения (A + B): " << (A + B);
    std::cout << " Результат вычитания (A - B): " << (A - B) << "\n";

    std::cout << "\n Введите число: ";
    std::cin >> p;
    std::cout << " Результат умножения A: " << A * p;
    std::cout << " Результат умножения B: " << B * p << "\n";

	return 0;
}