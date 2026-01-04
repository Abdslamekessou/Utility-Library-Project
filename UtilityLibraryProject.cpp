
#include <iostream>
#include "clsUtil.h"


using namespace std;

int main()
{
    clsUtil::Srand();

    cout << clsUtil::RandomNumber(1 ,10) <<endl;
    cout << clsUtil::GetRandomCharacter(clsUtil::MixChars) << endl;
    cout << clsUtil::GenerateWord(clsUtil::MixChars,10) << endl;
    clsUtil::GenerateKeys(clsUtil::MixChars , 10 );


    // Swap Int

    int x = 10 ;  int y = 20;

    cout << x << " " << y << endl;

    clsUtil::Swap(x , y);

    cout << x << " " << y << endl;


    // Swap double

    double z = 1000;  double k = 2000;

    cout <<"\n\n" << z << " " << k << endl;

    clsUtil::Swap(z, k);

    cout << z << " " << k << endl;



    // Swap string

    string S1 = "Kessouri";  string S2 = "Abdessalem";

    cout << "\n\n" << S1 << " " << S2 << endl;

    clsUtil::Swap(S1, S2);

    cout << S1 << " " << S2 << endl;


    // Swap Dates

    clsDate D1(3 , 1 , 2026) ;  clsDate D2(4 , 1 , 2026);

    cout << "\nDates Before Swapping : \n";
    D1.Print();
    
    cout << " ";
    D2.Print();


    clsUtil::Swap(D1, D2);

    cout << "\nDates After Swapping : \n ";
    D1.Print();

    cout << " ";
    D2.Print();

    // Shuffle Array

    // int Array

    int Arr1[5] = {1 , 2 , 3 , 4 , 5};

    clsUtil::ShuffleArray(Arr1 , 5);

    cout << "\n\nArray after shuffle : " <<endl;
    for (int i = 0; i < 5; i++) {
        cout << Arr1[i] << "  ";
    }


    // int Array

    string Arr2[5] = { "Ali" , "Mohammed" , "Abdessalem" , "Abderahmen" , "Saber"};

    clsUtil::ShuffleArray(Arr2, 5);

    cout << "\n\nArray after shuffle : " << endl;
    for (int i = 0; i < 5; i++) {
        cout << Arr2[i] << "  ";
    }


    int Arr3[5];

    clsUtil::FillArrayWithRandomNumbers(Arr3, 5);

    cout << "\n\nArray after fill : " << endl;
    for (int i = 0; i < 5; i++) {
        cout << Arr3[i] << "  ";
    }


    string Arr4[5];

    clsUtil::FillArrayWithRandomWords(Arr4, 5 , clsUtil::MixChars , 8);

    cout << "\n\nArray after fill : " << endl;
    for (int i = 0; i < 5; i++) {
        cout << Arr4[i] << "  ";
    
    }


    string Arr5[5];

    clsUtil::FillArrayWithRandomKeys(Arr5, 5 , clsUtil::MixChars);

    cout << "\n\nArray after filling keys : " << endl;
    for (int i = 0; i < 5; i++) {
        cout << Arr5[i]<< endl;
    }


    cout << "\nText 1" << clsUtil::Tabs(7) << "Text2" ;

    string TextAfterEncryption , TextAfterDecryption ;

    string Text = "Kessouri Abdessalem";

    TextAfterEncryption = clsUtil::EncryptText(Text , 2);
    TextAfterDecryption = clsUtil::DecryptText(TextAfterEncryption , 2);

    cout << "\nText Before Encryption : " << Text ;

    cout << "\nText After Encryption : " << TextAfterEncryption ;

    cout << "\nText After Decryption : " << TextAfterDecryption;

}



