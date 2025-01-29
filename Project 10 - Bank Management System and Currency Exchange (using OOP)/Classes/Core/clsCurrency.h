#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsString.h"
using namespace std;

class clsCurrency
{

private:

    enum enMode { EmptyMode = 0, UpdateMode = 1 };

    enMode _Mode;
    string _Country;
    string _CurrencyCode;
    string _CurrencyName;
    float _Rate;

    static clsCurrency _ConvertLinetoCurrencyObject(string Line, string Seperator = "#//#")
    {
        vector<string> vCurrencyData;
        vCurrencyData = clsString::Split(Line, Seperator);

        return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2],
            stof(vCurrencyData[3]));
    }

    static string _ConverCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
    {
        string stCurrencyRecord = "";

        stCurrencyRecord += Currency.Country() + Seperator;
        stCurrencyRecord += Currency.CurrencyCode() + Seperator;
        stCurrencyRecord += Currency.CurrencyName() + Seperator;
        stCurrencyRecord += to_string(Currency.Rate());

        return stCurrencyRecord;
    }

    static  vector <clsCurrency> _LoadCurrencysDataFromFile()
    {
        vector <clsCurrency> vCurrencys;
        string Line = "";
        fstream MyFile;

        MyFile.open("Currencies.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            while (getline(MyFile, Line))
            {
                if (Line != "")
                {
                    clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
                    vCurrencys.push_back(Currency);
                }
            }
            MyFile.close();
        }
        return vCurrencys;
    }

    static void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrencys)
    {
        fstream MyFile;
        string DataLine = "";

        MyFile.open("Currencies.txt", ios::out); //overwrite

        if (MyFile.is_open())
        {
            for (clsCurrency& C : vCurrencys)
            {
                DataLine = _ConverCurrencyObjectToLine(C);
                MyFile << DataLine << endl;
            }
            MyFile.close();
        }
    }

    static clsCurrency _GetEmptyCurrencyObject()
    {
        return clsCurrency(enMode::EmptyMode, "", "", "", 0);
    }

    void _Update()
    {
        vector <clsCurrency> _vCurrencys;
        _vCurrencys = _LoadCurrencysDataFromFile();

        for (clsCurrency& C : _vCurrencys)
        {
            if (C.CurrencyCode() == CurrencyCode())
            {
                C = *this;
                break;
            }
        }
        _SaveCurrencyDataToFile(_vCurrencys);
    }

public:


    clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
    {
        _Mode = Mode;
        _Country = Country;
        _CurrencyCode = CurrencyCode;
        _CurrencyName = CurrencyName;
        _Rate = Rate;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    //Read Only Property.
    string Country()
    {
        return _Country;
    }

    string CurrencyCode()
    {
        return _CurrencyCode;
    }

    string CurrencyName()
    {
        return _CurrencyName;
    }

    float Rate()
    {
        return _Rate;
    }

    void UpdateRate(float NewRate)
    {
        _Rate = NewRate;
        _Update();
    }

    static clsCurrency FindByCode(string CurrencyCode)
    {
        CurrencyCode = clsString::UpperAllString(CurrencyCode);

        string Line = "";
        fstream MyFile;

        MyFile.open("Currencies.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            while (getline(MyFile, Line))
            {
                if (Line != "")
                {
                    clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
                    if (Currency.CurrencyCode() == CurrencyCode)
                    {
                        MyFile.close();
                        return Currency;
                    }
                }
            }

            MyFile.close();
        }
        return _GetEmptyCurrencyObject();
    }

    static clsCurrency FindByCountry(string Country)
    {
        Country = clsString::UpperAllString(Country);
        string Line = "";
        fstream MyFile;

        MyFile.open("Currencies.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            while (getline(MyFile, Line))
            {
                if (Line != "")
                {
                    clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
                    if (clsString::UpperAllString(Currency.Country()) == Country)
                    {
                        MyFile.close();
                        return Currency;
                    }
                }
            }
            MyFile.close();
        }
        return _GetEmptyCurrencyObject();
    }

    static vector <clsCurrency> GetCurrenciesList()
    {
        return _LoadCurrencysDataFromFile();
    }

    static bool IsCurrencyExist(string CurrencyCode)
    {
        clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode);
        return (!C1.IsEmpty());
    }

    static bool IsCountryExist(string Country)
    {
        clsCurrency C1 = clsCurrency::FindByCountry(Country);
        return (!C1.IsEmpty());
    }

    float ConvertToUSD(float Amount)
    {
        return (Amount / _Rate);
    }

    float ConvertToOtherCurrency(clsCurrency CurrencyTo, float Amount)
    {
        float AmountInUSD = ConvertToUSD(Amount);

        if (CurrencyTo.CurrencyCode() == "USD") {

            return AmountInUSD;
        }

        return (AmountInUSD * CurrencyTo._Rate);
    }

};



