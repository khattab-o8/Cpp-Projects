#include <iostream>
using namespace std;

class clsCalculator
{
private:

	float _LastNumber = 0;
	float _PreviosResult = 0;
	float _Result = 0;
	string _IdentifyOperation = " ";

	bool _IsZeroNumber(float Number)
	{
		return (Number == 0);
	}

public:

	//Property Set

	void Add(float Number)
	{
		_LastNumber = Number;
		_PreviosResult = _Result;
		_Result += Number;

		_IdentifyOperation = " Adding ";
	}

	void Subtract(float Number)
	{
		_LastNumber = Number;
		_PreviosResult = _Result;
		_Result -= Number;

		_IdentifyOperation = " Subtracting ";
	}

	void Multiply(float Number)
	{
		_LastNumber = Number;
		_PreviosResult = _Result;
		_Result *= Number;

		_IdentifyOperation = " Multiplying ";
	}

	void Divide(float Number)
	{
		_LastNumber = Number;

		if (_IsZeroNumber(Number))
		{
			Number = 1;
		}
		//if (Number == 0)
		//{
		//	Number = 1;
		//}

		_PreviosResult = _Result;
		_Result /= Number;

		_IdentifyOperation = " Dividing ";
	}

	void CancelLastOperation()
	{
		_LastNumber = 0;
		_Result = _PreviosResult;

		_IdentifyOperation = " Cancelling Last Operation ";
	}

	void Clear()
	{
		_LastNumber = 0;
		_PreviosResult = 0;
		_Result = 0;

		_IdentifyOperation = " Clear ";
	}

	float GetFinalResult()
	{
		return _Result;
	}

	//Property Get
	void PrintResult()
	{
		cout << "Result After" << _IdentifyOperation << _LastNumber << " is: " << _Result << "\n";
	}
};


int main()
{
	clsCalculator Calculator1;

	Calculator1.Clear();
	Calculator1.PrintResult();

	Calculator1.Add(20);
	Calculator1.PrintResult();

	Calculator1.Subtract(5);
	Calculator1.PrintResult();

	Calculator1.Multiply(2);
	Calculator1.PrintResult();

	Calculator1.Divide(0);
	Calculator1.PrintResult();

	Calculator1.Divide(3);
	Calculator1.PrintResult();

	Calculator1.CancelLastOperation();
	Calculator1.PrintResult();


	cout << "Getting Final Result = " << Calculator1.GetFinalResult();


	system("pause>0");
	return 0;
}