#include <iostream>
#include "clsDate.h"
#include "clsUtil.h"
using namespace std;


int main()
{
    clsUtil::Srand();

    cout << clsUtil::RandomNumber(1, 10) << endl;
    cout << clsUtil::GetRandomCharacter(clsUtil::enCharType::SamallLetter) << endl;
    cout << clsUtil::GenerateWord(clsUtil::MixChars, 8) << endl;
    cout << clsUtil::GenerateKey(clsUtil::CapitalLetter) << endl << endl;
    clsUtil::GenerateKeys(10, clsUtil::SamallLetter);

    cout << "\n\n";

    //Swap Int
    int x = 10, y = 30;
    cout << x << "   " << y << endl;
    clsUtil::Swap(x, y);
    cout << x << "   " << y << endl;

    cout << "\n\n";

    //Swap double
    double a = 10.5, b = 30.5;
    cout << a << "   " << b << endl;
    clsUtil::Swap(a, b);
    cout << a << "   " << b << endl;

    cout << "\n\n";

    //Swap String
    string S1 = "Ali", S2 = "Ahmed";
    cout << S1 << "   " << S2 << endl;
    clsUtil::Swap(S1, S2);
    cout << S1 << "   " << S2 << endl;

    cout << "\n\n";

    //Swap Dates
    clsDate D1(11, 5, 2023), D2(8, 11, 2020);
    cout << D1.DateToString() << "   " << D2.DateToString() << endl;
    clsUtil::Swap(D1, D2);
    cout << D1.DateToString() << "   " << D2.DateToString() << endl;


    cout << "\n\n";

    //Shuffle Array

    //int array
    int arr1[5] = { 1, 2, 3, 4, 5, };
    clsUtil::ShuffleArray(arr1, 5);
    cout << "\nArray After Shuffle : \n";
    for (short i = 0; i < 5; i++)
    {
        cout << arr1[i] << "  ";
    }

    cout << "\n\n";
    //String array
    string arr2[5] = { "Ahmed", "Taha", "Moustafa", "Mohammed", "Mahmoud" };
    clsUtil::ShuffleArray(arr2,5);
    cout << "\nArray After Shuffle : \n";
    for (short i = 0; i < 5; i++)
    {
        cout << arr2[i] << "  ";
    }

    cout << "\n\n";
    ///Fill Array With Random Numbers.
    int arr3[5];
    clsUtil::FillArrayWithRandomNumbers(arr3, 5, 10, 60);
    cout << "\nArray After Fill : \n";
    for (short i = 0; i < 5; i++)
    {
        cout << arr3[i] << "  ";
    }

    cout << "\n\n";
    //Fill Array With Random Words.
    string arr4[5];
    clsUtil::FillArrayWithRandomWords(arr4, 5, clsUtil::CapitalLetter,8);
    cout << "\nArray After Fill with Random Words : \n";
    for (short i = 0; i < 5; i++)
    {
        cout << arr4[i] << "  ";
    }

    cout << "\n\n";
    //Fill Array With Random Words.
    string arr5[5];
    clsUtil::FillArrayWithRandomKeys(arr5, 5, clsUtil::CapitalLetter);
    cout << "\nArray After Fill with Random Keys : \n";
    for (short i = 0; i < 5; i++)
    {
        cout << arr5[i] << endl;
    }

    cout << "\n\n";

    cout << "Text1" << clsUtil::Tabs(3) << "Text2" << endl;

    cout << "\n\n";

    const short EncryptionKey = 3;
    string TextAfterEncryption = " ", TextAfterDecryption = " ";
    string Text = "Ahmed Mohemmed Khattab";

    TextAfterEncryption = clsUtil::EncryptText(Text, EncryptionKey);
    TextAfterDecryption = clsUtil::DecryptText(TextAfterEncryption, EncryptionKey);

    cout << Text << "\n\n";
    cout << TextAfterEncryption << "\n\n";
    cout << TextAfterDecryption << "\n\n";


    system("pause > 0");
    return 0;

}