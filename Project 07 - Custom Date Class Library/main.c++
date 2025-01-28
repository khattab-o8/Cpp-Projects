#include <iostream>
#include <string>
#include "clsDate.h"
using namespace std;


int main()
{

	clsDate Date1;
	Date1.Print();

	clsDate Date2("25/11/2022");
	Date2.Print();

	clsDate Date3(20, 12, 2022);
	Date3.Print();
	 
	clsDate Date4(250, 2022);
	Date4.Print();

	cout << Date3.GetDifferenceInDays(Date1) << endl;

	cout << clsDate::CalculateMyAgeInDays(clsDate(8, 11, 1995)) << endl;

	cout << "Days from the begining of year : " << Date3.DaysFromTheBeginingOfYear();

	cout << Date1.IsDateBeforeDate2(Date2) << endl;

	Date3.PrintMonthCalendar();

	Date2.PrintYearCalendar();

	cout << Date2.IsValid() << endl;

	cout << Date2.IsLastDayInMonth() << endl;

	cout << Date2.IsLastMonthInYear() << endl;

	Date2.Print();


	system("pause>0");
	return 0;
}