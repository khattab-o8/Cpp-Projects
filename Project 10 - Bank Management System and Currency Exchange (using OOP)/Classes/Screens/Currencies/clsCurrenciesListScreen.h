#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>

class clsCurrenciesListScreen : protected clsScreen
{
private:

	static void CurrenciesListScreenHeader()
	{
		cout << "\n" << setw(3) << left << "" << "__________________________________________________________"
			"________________________________________________________\n";
		cout << "\n" << setw(3) << left << "";
		cout << "| " << left << setw(35) << "Country";
		cout << "| " << left << setw(12) << "Code";
		cout << "| " << left << setw(45) << "Name";
		cout << "| " << left << setw(13) << "Rate/(1$)";
		cout << "\n" << setw(3) << left << "" << "__________________________________________________________"
			"________________________________________________________\n";

	}

	static void _PrintCurrencyRecordLine(clsCurrency Currency)
	{
		cout << "\n" << setw(3) << left << "";
		cout << "| " << left << setw(35) << Currency.Country();
		cout << "| " << left << setw(12) << Currency.CurrencyCode();
		cout << "| " << left << setw(45) << Currency.CurrencyName();
		cout << "| " << left << setw(13) << Currency.Rate();
	}

public:

	static void ShowCurrenciesListScreen()
	{
		vector <clsCurrency> vCurrencys;
		vCurrencys = clsCurrency::GetCurrenciesList();

		string Title = "\tCurrencies List Screen";
		string Subtitle = "\t   (" + to_string(vCurrencys.size()) + ") Currency.";

		_DrawScreenHeader(Title, Subtitle);

		CurrenciesListScreenHeader();

		if (vCurrencys.size() == 0)
			cout << "\n\n" << "\t\t\t\t\tNo Currencies Data Available In the System!\n";

		else {
			//ranged loop
			for (clsCurrency& C : vCurrencys)
			{
				_PrintCurrencyRecordLine(C);
			}
		}

		cout << "\n" << setw(3) << left << "" << "__________________________________________________________"
			"________________________________________________________\n";

	}

};

