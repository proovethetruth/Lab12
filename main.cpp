
#include "Lab12.h"

int main() {

    setlocale(LC_ALL, "");
    int n, p;

    cout << "\n ������� ������� ��������: ";
    cin >> n;
    Polynom A(n);

    cout << " ������� ����������� ��������: ";
    cin >> A;

    cout << "\n ��������� �: " << A;

    cout << "\n ������� �����: ";
    cin >> p;

    Polynom res(A);

    res * p;
    cout << " ��������� ���������: " << res;

    res = A;
    res + p;
    cout << " ��������� ��������: " << res;

    res = A;
    res - p;
    cout << " ��������� ���������: " << res;
	return 0;
}