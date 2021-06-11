
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
		printf("\n Negative polynom degree error");
		return -1;
	}

	std::cout << " Введите коэфициенты полинома A: ";
	std::cin >> A;

	std::cout << "\n Многочлен А: " << A;

	std::cout << "\n\n ----------------------------------------------------------------- \n\n";

	size = 0;
	std::cout << " Введите степень полинома B: ";
	std::cin >> size;
	Polynom B(size, error);
	if (error == 1)
	{
		printf("\n Negative polynom degree error");
		return -1;
	}

	std::cout << " Введите коэфициенты полинома B: ";
	std::cin >> B;
	std::cout << "\n Многочлен B: " << B;

	std::cout << " Результат деления (A / B): " << (A / B) << "\n";
	return 0;
}