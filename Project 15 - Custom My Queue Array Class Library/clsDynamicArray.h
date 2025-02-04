#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDynamicArray {
private:

	short _ArraySize = 0;
	T* Ptr = NULL;

public:

	clsDynamicArray(short ArraySize) {
		_ArraySize = ArraySize;
		Ptr = new T[ArraySize];
	}

	bool IsEmpty() {
		return (_ArraySize == 0);
	}

	short Size() {
		return _ArraySize;
	}

	void SetItem(int Index, T Value) {
		*(Ptr + Index) = Value;
	}

	void PrintList() {
		for (short i = 0; i < _ArraySize; i++)
		{
			cout << *(Ptr + i) << "  ";
		}
		cout << endl;
	}

	bool Resize(short NewSize) {
		//Validation for New Size.
		if (NewSize < 0 || NewSize == _Size)
			return false;

		if (NewSize < _Size || NewSize > _Size) {
			_Size = NewSize;
			return true;
		}
	}

	T GetItem(int Index) {
		//Validation for Index.
		if (Index < 0 || Index >= _Size)
			return NULL;

		return OriginalArray[Index];
	}

	void Reverse() {
		_TempArray = new T[_Size];

		for (short i = 0; i < _Size; i++) {

			_TempArray[i] = OriginalArray[_Size - 1 - i];
		}

		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}

	void Clear() {
		delete[] OriginalArray;
		_Size = 0;
	}

	bool DeleteItemAt(int Index) {
		//Validation for Index.
		if (Index < 0 || Index >= _Size)
			return false;

		T Item = GetItem(Index);

		short NewSize = _Size - 1;
		_TempArray = new T[NewSize];

		short counter = 0;
		for (short i = 0; i < _Size; i++)
		{
			if (OriginalArray[i] != Item)
			{
				_TempArray[counter] = OriginalArray[i];
				counter++;
			}
		}

		_Size = NewSize;
		delete[] OriginalArray;
		OriginalArray = _TempArray;
		return true;
	}
	
	bool DeleteFirstItem() {
		return DeleteItemAt(0);
	}

	bool DeleteLastItem() {
		return DeleteItemAt(_Size - 1);
	}	

	short Find(T Value) {
		if (IsEmpty())
			return -1;

		for (short i = 0; i < _Size; i++) {
			if (OriginalArray[i] == Value)
				return i;
		}
		return -1;
	}

	bool DeleteItem(T Value) {
		short Index = Find(Value);

		if (Index == -1)
			return false;

		return DeleteItemAt(Index);
	}

	bool InsertAt(int Index, T Value) {

		if (Index < 0 || Index >= _Size)
			return false;

		short NewSize = _Size + 1;
		_TempArray = new T[NewSize];
		short counter = 0;

		if (Index == 0) {
			_TempArray[counter] = Value;

			for (short i = 0; i < _Size; i++) {
				counter++;
				_TempArray[counter] = OriginalArray[i];
			}
		}
		else {

			// 1 - Copy All Data Before Index And Put New Index With it's New Value To Temp Array.
			for (short i = 0; i < Index + counter; i++) {
				if (i == Index) {
					_TempArray[counter] = Value;
					counter++;
					break;

				}
				_TempArray[counter] = OriginalArray[i];
				counter++;
			}

			// 2 - Copy The rest of Data To Temp Array.
			for (short i = Index; i < NewSize; i++) {
				_TempArray[counter] = OriginalArray[i];
				counter++;
			}
		}

		_Size = NewSize;
		delete[] OriginalArray;
		OriginalArray = _TempArray;
		return true;
	}

	bool InsertAtBegining(T Value) {
		return InsertAt(0, Value);
	}

	bool InsertBefore(int Index, T Value) {
		return InsertAt(Index - 1, Value);
	}

	bool InsertAfter(int Index, T Value) {
		return InsertAt(Index + 1, Value);
	}

	bool InsertAtEnd(T Value) {
		return InsertAt(_Size, Value);
	}

	//Destructor.
	~clsDynamicArray() {
		if (!IsEmpty())
			delete[] OriginalArray;
	}
};

