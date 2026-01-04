#pragma once

#include <iostream>
#include <string>
#include "clsDate.h"

using namespace std;

class clsUtil
{

public :

    enum enCharacterType { SmallLetter = 1, CapitalLetter, Digit, MixChars, SpecialChar };

	static void Srand() {

		srand((unsigned)time(NULL));

    }



	static int  RandomNumber(int From, int To) {

		int randNumber = rand() % (To - From + 1) + From;

		return randNumber;
	}

	
    static char  GetRandomCharacter(enCharacterType charType) {

        if (charType == MixChars) {
           charType = (enCharacterType) RandomNumber(1 , 3);
        }

        switch (charType) {
        case enCharacterType::SmallLetter:
            return char(RandomNumber(97, 122));
            break;
        case enCharacterType::CapitalLetter:
            return char(RandomNumber(65, 90));
            break;
        case enCharacterType::SpecialChar:
            return char(RandomNumber(33, 47));
            break;
        case enCharacterType::Digit:
            return char(RandomNumber(48, 57));
            break;

        default:
            return char(RandomNumber(65, 90));
            break;

        }

        return '\0';
    }




    
    static string GenerateWord(enCharacterType CharType, short Length) {

        string word = "";

        for (short i = 1; i <= Length; i++) {
            word += GetRandomCharacter(CharType);
        }

        return word;
    }

    static string GenerateKey(enCharacterType CharType) {

        string key = "";

        key = GenerateWord(CharType, 4) + "-";
        key += GenerateWord(CharType, 4) + "-";
        key += GenerateWord(CharType, 4) + "-";
        key += GenerateWord(CharType, 4);

        return key;
    }

    static void GenerateKeys(enCharacterType CharType , short NumberOfKeys) {

        for (int i = 0; i < NumberOfKeys; i++) {
            cout << "Key [" << i + 1 << "] : " << GenerateKey(CharType) << endl;
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

    static void Swap(char& A, char& B)
    {
        char Temp;
        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(bool& A, bool& B)
    {
        bool Temp;
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


    static void Swap(clsDate& A, clsDate& B)
    {
         clsDate::SwapDates(A,B);
    }


    static void ShuffleArray(int arr[100], int arrSize) {

        for (int i = 0; i < arrSize; i++) {

            Swap(arr[RandomNumber(1, arrSize) - 1], arr[RandomNumber(1, arrSize) - 1]);

        }

    }


    static void ShuffleArray(string arr[100], int arrSize) {

        for (int i = 0; i < arrSize; i++) {

            Swap(arr[RandomNumber(1, arrSize) - 1], arr[RandomNumber(1, arrSize) - 1]);

        }

    }


    static void FillArrayWithRandomNumbers(int arr[100], int arrLength) {

        for (int i = 0; i < arrLength; i++) {
            arr[i] = RandomNumber(1, 100);
        }

    }


    static void FillArrayWithRandomWords(string arr[100], int arrLength , enCharacterType CharType, short WordLength) {

        for (int i = 0; i < arrLength; i++) {
            arr[i] = GenerateWord(CharType , WordLength);
        }

    }


    static void FillArrayWithRandomKeys(string arr[100], int arrLength , enCharacterType CharType) {

        for (int i = 0; i < arrLength; i++) {
            arr[i] = GenerateKey(CharType);
        }

    }


    static string Tabs(short NumberOfTabs) {
        string t = "";

        for (int i = 1; i < NumberOfTabs; i++) {
            t += "\t";
        }

        return t;
    }

    static string EncryptText(string text, short encryptionKey) {

        for (int i = 0; i < text.length(); i++) {
            text[i] = char((int)text[i] + encryptionKey);
        }

        return text;

    }


    static string DecryptText(string text, short encryptionKey) {

        for (int i = 0; i < text.length(); i++) {
            text[i] = char((int)text[i] - encryptionKey);
        }

        return text;

    }

};




