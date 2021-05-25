
#include "Lab12.h"

int main() {
    setlocale(LC_ALL, "");
    int n;
    double p;

    cout << "\n ������� ������� ��������: ";
    cin >> n;
    while (!cin.good() || n < 0)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (n < INT_MAX)
            cout << " ������������ ����. ������� �������� - �����, ������������� �����. ���������� ��� ���.\n\n ������� ������� ��������: ";
        else
            cout << " ������������ ����. ����� ������� �������. ���������� ��� ���.\n\n ������� ������� ��������: ";
        cin >> n;
    }

    Polynom A(n);

    cout << " ������� ����������� ��������: ";
    cin >> A;
    while (!cin.good())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << " ������������ ����. ����������� �������� ������������ ����� ����� ������������ �����. ���������� ��� ���.\n\n ������� ����������� ��������: ";
        cin >> A;
    }

    cout << "\n ��������� �: " << A;

    cout << "\n ������� �����: ";
    cin >> p;
    while (!cin.good())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (p < DBL_MAX)
            cout << " ������������ ����. ��������� ������ �����. ���������� ��� ���.\n\n ������� �����: ";
        else
            cout << " ������������ ����. �����(-�) ������� �������. ���������� ��� ���.\n\n ������� �����: ";
        cin >> p;
    }

    Polynom res(A);

    res * p;
    cout << " ��������� ���������: " << res << "\n";

    res = A;
    res + p;
    cout << " ��������� ��������: " << res << "\n";

    res = A;
    res - p;
    cout << " ��������� ���������: " << res << "\n";
	return 0;
}