#pragma once
#include "clsDate.h"

class clsInputValidate
{
public:

	static bool IsNumberBetween(int Number, int From, int To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(float Number, float From, float To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsDateBetween(clsDate DateToCheck, clsDate DateFrom, clsDate DateTo)
	{
		if (!(clsDate::IsDate1BeforeDate2(DateFrom, DateTo)))
		{
			clsDate::SwapDates(DateFrom, DateTo);

			return ((clsDate::IsDate1AfterDate2(DateToCheck, DateFrom) || clsDate::IsDate1EqualDate2(DateToCheck, DateFrom))
				&& (clsDate::IsDate1BeforeDate2(DateToCheck, DateTo) || clsDate::IsDate1EqualDate2(DateToCheck, DateTo)));
		}
		return ((clsDate::IsDate1AfterDate2(DateToCheck, DateFrom) || clsDate::IsDate1EqualDate2(DateToCheck, DateFrom))
			&& (clsDate::IsDate1BeforeDate2(DateToCheck, DateTo) || clsDate::IsDate1EqualDate2(DateToCheck, DateTo)));
	}

	static int ReadIntNumber(string Massage)
	{
		int Number = 0;
		cin >> Number;

		while (cin.fail())
		{
			// user didn't input a number
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << Massage;
			cin >> Number;
		}
		return Number;
	}

	static double ReadDblNumber(string Massage)
	{
		double Number = 0;
		cin >> Number;

		while (cin.fail())
		{
			// user didn't input a number
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << Massage;
			cin >> Number;
		}
		return Number;
	}

	static int ReadIntNumberBetween(int From, int To, string Massage)
	{
		int Number = 0;
		cin >> Number;
		while (cin.fail())
		{
			// user didn't input a number
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid Number, Enter again:\n";
			cin >> Number;
		}

		while (Number < From || Number > To)
		{
			cout << Massage << endl;
			cin >> Number;
		}

		return Number;
	}

	static double ReadDblNumberBetween(double From, double To, string Massage)
	{
		double Number = 0;
		cin >> Number;

		while (cin.fail())
		{
			// user didn't input a number
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid Number, Enter again:\n";
			cin >> Number;
		}

		while (Number < From || Number > To)
		{
			cout << Massage << endl;
			cin >> Number;
		}
		return Number;
	}

	static bool IsValideDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}

};

