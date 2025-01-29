#include <iostream>
#include "clsInputValidate.h"
using namespace std;


int main()
{
    cout << clsInputValidate::IsNumberBetween(6, 1, 10) << endl;
    cout << clsInputValidate::IsNumberBetween(10.9f, 1.3f, 10.8f) << endl;

    cout << clsInputValidate::IsDateBetween(clsDate(31, 12, 2023),clsDate(1, 1, 2024), clsDate(5, 1, 2024)) << endl;

    cout << clsInputValidate::IsDateBetween(clsDate(3, 1, 2024), clsDate(5, 1, 2024), clsDate(1, 1, 2024)) << endl;

    cout << "\n\n";

    cout << "\nPlease Enter a Number:\n";
    int x = clsInputValidate::ReadIntNumber("Invalid Number, Enter again:\n");
    cout << "x = " << x;

    cout << "\n\n";

    cout << "\nPlease Enter a Number between 1 and 5:\n";
    int y = clsInputValidate::ReadIntNumberBetween(1, 5, "Number is not within range,Enter again: ");
    cout << "y = " << y;

    cout << "\n\n";

    cout << "\nPlease Enter a Double Number:\n";
    double a = clsInputValidate::ReadDblNumber("Invalid Number, Enter again:\n");
    cout << "a = " << a;

    cout << "\nPlease Enter a Double Number between 1.4 and 5.8:\n";
    double F = clsInputValidate::ReadDblNumberBetween(1.4, 5.8, "Number is not within range,Enter again: ");
    cout << "F = " << F;

    cout << clsInputValidate::IsValideDate(clsDate(44, 12, 2023)) << endl;



    system("pause > 0");
    return 0;
}