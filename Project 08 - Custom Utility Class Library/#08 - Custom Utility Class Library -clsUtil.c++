#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"
using namespace std;


class clsUtil
{
public:

	static void Srand()
	{
		srand((unsigned)time(NULL));
	}

	static int RandomNumber(int From, int To)
	{
		//Function to generate a random number
		int randNum = rand() % (To - From + 1) + From;
		return randNum;
	}

	static enum enCharType { SamallLetter = 1, CapitalLetter = 2, Digit = 3 , MixChars = 4 };

	static char GetRandomCharacter(enCharType CharType)
	{
		switch (CharType)
		{
		case enCharType::SamallLetter:
		{
			return char(RandomNumber(97, 122));
			break;
		}
		case enCharType::CapitalLetter:
		{
			return char(RandomNumber(65, 90));
			break;
		}
		case enCharType::Digit:
		{
			return char(RandomNumber(48, 57));
			break;
		}
		case enCharType::MixChars:
		{
			return char(RandomNumber(48 , 122));
			break;
		}
		}
	}

	static string GenerateWord(enCharType CharType, short Length)
	{
		string Word;
		for (int i = 1; i <= Length; i++)
		{
			Word = Word + GetRandomCharacter(CharType);
		}
		return Word;
	}

	static string GenerateKey(enCharType CharType)
	{
		string Key = "";
		Key = GenerateWord(CharType , 4) + "-";
		Key = Key + GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4);
		return Key;
	}

	static void GenerateKeys(short NumberOfKeys, enCharType CharType)
	{
		for (int i = 1; i <= NumberOfKeys; i++)
		{
			cout << "Key [" << i << "] : ";
			cout << GenerateKey(CharType) << endl;
		}
	}

	static void Swap(int& A, int& B)
	{
		int Temp;
		Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(double& A, double& B)
	{
		double Temp;
		Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(string& A, string& B)
	{
		string Temp;
		Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(clsDate& D1, clsDate& D2)
	{
		clsDate::SwapDates(D1, D2);
	}

	static void ShuffleArray(int arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}

	static void ShuffleArray(string arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}

	static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = RandomNumber(From, To);
	}

	static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short Length)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = GenerateWord(CharType, Length);
	}

	static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = GenerateKey(CharType);
	}

	static string Tabs(short Number)
	{
		string tab = " ";
		for (short i = 0; i < Number; i++)
		{
			tab += "\t";
		}

		return tab;
	}

	static string EncryptText(string Text, short EncryptionKey)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] + EncryptionKey);
		}
		return Text;
	}

	static string DecryptText(string Text, short EncryptionKey)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] - EncryptionKey);
		}
		return Text;
	}

};

