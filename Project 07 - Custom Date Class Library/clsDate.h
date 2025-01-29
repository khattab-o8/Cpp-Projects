#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <string>
#include <iomanip>
#include "clsString.h"
using namespace std;

class clsDate
{
private:

	short _Day = 1;
	short _Month = 1;
	short _Year = 1900;

public:

	clsDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		_Day = now->tm_mday;
		_Month = now->tm_mon + 1;
		_Year = now->tm_year + 1900;
	}

	clsDate(string Date)
	{
		vector <string> _Vstring = clsString::Split(Date,"/");

		_Day = stoi (_Vstring[0]);
		_Month = stoi (_Vstring[1]);
		_Year = stoi(_Vstring[2]);
	}

	clsDate(short Day, short Month, short Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}

	clsDate(short DateOrderInYear, short Year)
	{
		clsDate Date;
		Date = GetDateFromDayOrderInYear(DateOrderInYear, Year);

		_Day = Date._Day;
		_Month = Date._Month;
		_Year = Date._Year;
	}

	void SetDay(short Day)
	{
		_Day = Day;
	}

	short GetDay()
	{
		return _Day;
	}

	__declspec(property(get = GetDay, put = SetDay)) short Day;

	void SetMonth(short Month)
	{
		_Month = Month;
	}

	short GetMonth()
	{
		return _Month;
	}

	__declspec(property(get = GetMonth, put = SetMonth)) short Month;

	void SetYear(short Year)
	{
		_Year = Year;
	}

	short GetYear()
	{
		return _Year;
	}

	__declspec(property(get = GetYear, put = SetYear)) short Year;

	//______________________________________________________//

	void Print()
	{
		cout << DateToString(*this) << endl;
	}

	static clsDate GetSystemDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		short Day = 0, Month = 0, Year = 0;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;

		return clsDate(Day, Month, Year);
	}

	static bool isLeapYear(short Year)
	{
		return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
	}

	bool isLeapYear()
	{
		return isLeapYear(_Year);
	}

	static short NumberOfDaysInAMonth(short Month, short Year)
	{
		if (Month < 1 || Month>12)
			return 0;
		int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
	}

	short NumberOfDaysInAMonth()
	{
		return NumberOfDaysInAMonth(_Month, _Year);
	}

	static clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
	{
		clsDate Date;

		short RemainingDays = DateOrderInYear;
		short MonthDays = 0;
		Date._Year = Year;
		Date._Month = 1;
		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(Date._Month, Year);
			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date._Month++;
			}
			else
			{
				Date._Day = RemainingDays;
				break;
			}
		}
		return Date;
	}

	static short DayOfWeekOrder(short Day, short Month, short Year)
	{
		short a = 0, y = 0, m = 0;

		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + (12 * a) - 2;

		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	short DayOfWeekOrder()
	{
		return DayOfWeekOrder(_Day, _Month, _Year);
	}

	static string MonthName(short Month)
	{
		string MonthOfYear[] =
		{ "", "Jan", "Feb", "Mar", "Apr", "May", "Jun",
		"Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

		return MonthOfYear[Month];
	}

	string MonthName()
	{
		return MonthName(_Month);
	}

	static void PrintWeekDays()
	{
		string DaysOfWeek[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

		for (short i = 0; i < 7; i++)
		{
			cout << "\t" << setw(5) << left << DaysOfWeek[i];
		}
		cout << endl;
	}

	static void PrintMonthCalendar(short Month, short Year)
	{
		cout << "\n\n";

		short Current = DayOfWeekOrder(1, Month, Year);
		short NumberOfDays = NumberOfDaysInAMonth(Month, Year);

		cout << "\t" << "________________________" << MonthName(Month) << "________________________" << "\n\n";
		PrintWeekDays();

		short i;
		for (i = 0; i < Current; i++)
		{
			cout << "\t" << setw(3) << right << " ";
		}

		for (short j = 1; j <= NumberOfDays; j++)
		{
			if (i == 7)
			{
				cout << endl;
				i = 0;
			}
			cout << "\t" << setw(3) << right << j;
			i++;
		}
		cout << endl;
		cout << "\t" << "___________________________________________________" << "\n\n";
	}

	void PrintMonthCalendar()
	{
		PrintMonthCalendar(_Month, _Year);
	}

	static void PrintYearCalendar(short Year)
	{
		cout << "\n\n" << "\t" << "___________________________________________________" << "\n\n";
		cout << "\t\t" << "          CaLendar - " << Year << endl;
		cout << "\t" << "___________________________________________________" << "\n";

		for (short i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(i, Year);
		}
	}

	void PrintYearCalendar()
	{
		PrintYearCalendar(_Year);
	}

	static bool IsValidDate(clsDate Date)
	{
		if (Date.Day < 1 || Date.Day>31)
			return false;

		if (Date.Month < 1 || Date.Month>12)
			return false;

		if (Date.Month == 2)
		{
			if (isLeapYear(Date.Year))
			{
				if (Date.Day > 29)
					return false;
			}
			else
			{
				if (Date.Day > 28)
					return false;
			}
		}
	}

	bool IsValid()
	{
		return IsValidDate(*this);
	}

	static string DateToString(clsDate Date)
	{
		return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
	}

	string DateToString()
	{
		return DateToString(*this);
	}

	//Global Version
	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
		Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
		Date2.Month ? Date1.Day < Date2.Day : false)) : false);
	}

	//Object Version
	bool IsDateBeforeDate2(clsDate Date2)
	{
		return IsDate1BeforeDate2(*this, Date2);
	}

	static bool IsLastDayInMonth(clsDate Date)
	{
		return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
	}

	bool IsLastDayInMonth()
	{
		return IsLastDayInMonth(*this);
	}

	static bool IsLastMonthInYear(short Month)
	{
		return (Month == 12);
	}

	bool IsLastMonthInYear()
	{
		return IsLastMonthInYear(_Month);
	}

	static void IncreaseDateByOneDay(clsDate &Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date.Month))
			{
				Date.Month = 1;
				Date.Day = 1;
				Date.Year++;
			}
			else
			{
				Date.Day = 1;
				Date.Month++;
			}
		}
		else
		{
			Date.Day++;
		}
	}

	void IncreaseDateByOneDay()
	{
		 IncreaseDateByOneDay(*this);
	}

	static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
	{
		int Days = 0;
		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Days++;
			IncreaseDateByOneDay(Date1);
		}
		return IncludeEndDay ? ++Days : Days;
	}

	int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay = false)
	{
		return GetDifferenceInDays(*this, Date2, IncludeEndDay);
	}

	static int CalculateMyAgeInDays(clsDate Date1, clsDate Date2 = GetSystemDate(), bool IncludeEndDay = false)
	{
		return GetDifferenceInDays(Date1, Date2, IncludeEndDay);
	}

	static short DaysFromTheBeginingOfYear(short Day, short Month, short Year)
	{
		short TotalDays = 0;
		for (int i = 1; i <= Month - 1; i++)
		{
			TotalDays += NumberOfDaysInAMonth(i, Year);
		}
		TotalDays += Day;
		return TotalDays;
	}

	short DaysFromTheBeginingOfYear()
	{
		return DaysFromTheBeginingOfYear(_Day, _Month, _Year);
	}

	static clsDate DateAddDays(short Days, clsDate Date)
	{
		short RemainingDays = Days + DaysFromTheBeginingOfYear(Date.Day, Date.Month, Date.Year);
		short MonthDays = 0;
		Date.Month = 1;
		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);
			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date.Month++;
				if (Date.Month > 12)
				{
					Date.Month = 1;
					Date.Year++;
				}
			}
			else
			{
				Date.Day = RemainingDays;
				break;
			}
		}
		return Date;
	}

	clsDate DateAddDays(short Days)
	{
		return DateAddDays(Days, *this);
	}

	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1.Year == Date2.Year) ? ((Date1.Month ==
		Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
	}

	bool IsDateEqualDate2(clsDate Date2)
	{
		return IsDate1EqualDate2(*this, Date2);
	}
};

