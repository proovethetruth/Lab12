
#include "Lab12.h"

int main() {
    setlocale(LC_ALL, "");
    int n;
    double p;

    cout << "\n Введите степень полинома: ";
    cin >> n;
    while (!cin.good() || n < 0)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (n < INT_MAX)
            cout << " Некорректный ввод. Степень полинома - целое, положительное число. Попробуйте ещё раз.\n\n Введите степень полинома: ";
        else
            cout << " Некорректный ввод. Число слишком большое. Попробуйте ещё раз.\n\n Введите степень полинома: ";
        cin >> n;
    }

    Polynom A(n);

    cout << " Введите коэфициенты полинома: ";
    cin >> A;
    while (!cin.good())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << " Некорректный ввод. Коэффиценты полинома представляют собой набор вещественных чисел. Попробуйте ещё раз.\n\n Введите коэффиценты полинома: ";
        cin >> A;
    }

    cout << "\n Многочлен А: " << A;

    cout << "\n Введите число: ";
    cin >> p;
    while (!cin.good())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (p < DBL_MAX)
            cout << " Некорректный ввод. Требуется ввести число. Попробуйте ещё раз.\n\n Введите число: ";
        else
            cout << " Некорректный ввод. Число(-а) слишком большое. Попробуйте ещё раз.\n\n Введите число: ";
        cin >> p;
    }

    Polynom res(A);

    res * p;
    cout << " Результат умножения: " << res << "\n";

    res = A;
    res + p;
    cout << " Результат сложения: " << res << "\n";

    res = A;
    res - p;
    cout << " Результат вычитания: " << res << "\n";
	return 0;
}