
#include "Lab12.h"

int main() {

    setlocale(LC_ALL, "");
    int n, p;

    cout << "\n Введите степень полинома: ";
    cin >> n;
    Polynom A(n);

    cout << " Введите коэфициенты полинома: ";
    cin >> A;

    cout << "\n Многочлен А: " << A;

    cout << "\n Введите число: ";
    cin >> p;

    Polynom res(A);

    res * p;
    cout << " Результат умножения: " << res;

    res = A;
    res + p;
    cout << " Результат сложения: " << res;

    res = A;
    res - p;
    cout << " Результат вычитания: " << res;
	return 0;
}