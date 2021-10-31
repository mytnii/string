#include <iostream>
//#include <Windows.h>


/*
bool is_palindrome(char str[]);	DONE //Проверяет, является ли строка палиндромом (ого, или, 12321)
bool is_int_number(char str[]);	DONE //Проверяет, является ли строка целым десятичным числом
int  to_int_number(char str[]);	//Если строка - десятичное число, то функция возвращает его int-овое значение.
bool is_bin_number(char str[]);	//Проверяет, является ли строка двоичным числом
int  bin_to_dec(char str[]);	//Если строка - двоичное число, то функция возвращает его десятичное значение.
bool is_hex_number(char str[]);	//Проверяет, является ли строка шестнадцатеричным числом
int  hex_to_dec(char str[]);	//Если строка - шестнадцатеричное число, то функция возвращает его десятичное значение.
bool is_mac_address(char str[]);//Проверяет, является ли строка MAC-адресом
bool is_ip_address(char str[]);//Проверяет, является ли строка IP-адресом
*/


int strLength(char str[]);
void strToUpper(char str[]);
void strShrink(char str[]);
bool isPalindrome(char str[]);
void strShrink(char str[]);
//void rmSymbol(char str[], char symbol);
bool strIsDecInt(char str[]);
int  strToInt(char str[], size_t n);
bool strIsBin(char str[]);
int  strBinToDec(char str[], size_t n);
bool strIsHex(char str[]);
int  strHexToDec(char str[], size_t n);
bool isMacAddress(char str[], size_t n);
bool isIpAddress(char str[], size_t n);



int main() {
    using namespace std;
    //setlocale(LC_ALL, "Russian");
    //SetConsoleCP(1251);

    const size_t n = 200;
    char str[n];
    cout << "Enter the string: ";
    cin.getline(str, n);
    cout << endl;
    cout << "String is: " << str << endl;
    cout << endl;
    cout << "String length: " << strLength(str) << endl;
    size_t size = strLength(str);
    cout << endl;

    if (strIsDecInt(str)) {
        cout << "String is a Dec number: ";
        cout << strToInt(str, size) << endl;
    }
    else {
        cout << "String is not a Dec number" << endl;
    }

    cout << endl;

    if (strIsBin(str)) {
        cout << "String is a binary number, in Dec it equals: ";
        cout << strBinToDec(str, size) << endl;
    }
    else {
        cout << "String is not a binary number" << endl;
    }

    cout << endl;

    if (strIsHex(str)) {
        cout << "String is a hex number, in Dec it equals: ";
        cout << strHexToDec(str, size) << endl;
    }
    else {
        cout << "String is not a hex number" << endl;
    }

    cout << endl;

    if (isMacAddress(str, size)) {
        cout << "String is a MAC address in format aaaa.bbbb.cccc!" << endl;
    }
    else {
        cout << "String is not a MAC address in format aaaa.bbbb.cccc" << endl;
    }

    cout << endl;

    if (isIpAddress(str, size)) {
        cout << "String is an IPv4 address!" << endl;
    }
    else {
        cout << "String is not an IPv4 address" << endl;
    }

    cout << endl;

    if (isPalindrome(str)) {
        cout << "This is a palindrome!" << endl;
    }
    else {
        cout << "This is not a palindrome!" << endl;
    }


    return 0;
}

int strLength(char str[]) {
    size_t size = 0;

    while (str[size] != 0) {


        ++size;
    }

    return size;
}

void strToUpper(char str[]) {

    for (int i = 0; str[i]; ++i) {
        if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'а' && str[i] <= 'я') {
            str[i] -= 32;
        }
    }
}

void strShrink(char str[]) {
    //delete spaces more than one
    for (int i = 0; str[i]; ++i) {
        while (str[i] == ' ' && str[i + 1] == ' ') {
            for (int j = i + 1; str[j]; ++j) {

                str[j] = str[j + 1];

            }
        }
    }
}

bool isPalindrome(char str[]) //Реализация функции (Определение функции - Function definition)
{
    int n = strLength(str);
    strToUpper(str);
    strShrink(str);
    for (int i = 0; i < n / 2; ++i) {
        if (str[i] != str[n - 1 - i]) {
            return false;
        }
    }
    return true;
}

/*
bool isPalindrome(char* str) {
    size_t n = 250;
    char* buffer = new char[n + 1]{}; // инициализируют выделенную память значениями по умолчанию
    //зануляет выделенную память
    n = strlen(buffer); // возвращает длинну строки в символах
    strcpy(buffer, str); //копирует одну строку в другую strcpy(dst, scr); // dst(destination) - строка получатель, scr(source) - строка источник
    strToUpper(buffer);
    strShrink(buffer);

    for (size_t i = 0; i < n / 2; ++i) {
        if (str[i] != str[n - 1 - i]) {
            delete[] buffer;
            return false;
        }
    }

    delete[] buffer;
    return true;
}


void rmSymbol(char* str, char symbol)
{
    for (int i = 0; str[i]; i++)
    {
        while (str[i] == symbol)
        {
            for (int j = i; str[j]; j++)
                str[j] = str[j + 1];
        }
    }
}

*/


bool strIsDecInt(char str[]) {

    for (int i = 0; str[i]; ++i) {

        if (!(str[i] >= '0' && str[i] <= '9')) // Если элемент не цифра
            return false;
    }
    return true;

}

int  strToInt(char str[], size_t n) {
    int number = 0;
    size_t counter = 0;

    for (int i = n - 1; i >= 0; --i) {

        number += (str[i] - 48) * pow(10, counter);
        ++counter;
    }

    return number;
}



bool strIsBin(char str[]) {

    if (!(str[0] == '0' && str[1] == 'b')) {
        return false;
    }
    for (int i = 2; str[i]; ++i) {
        if (!(str[i] >= '0' && str[i] <= '1')) {
            return false;
        }
    }


    return true;

}

int  strBinToDec(char str[], size_t n) {
    int number = 0;
    size_t counter = 0;

    for (int i = n - 1; i >= 0; --i) {
        if (str[i] == 49) {
            number += pow(2, counter);
            ++counter;
        }
    }

    return number;
}

bool strIsHex(char str[]) {
    if (!(str[0] == '0' && str[1] == 'x')) {
        return false;
    }

    for (int i = 2; str[i]; ++i) {
        if (!((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f'))) {
            return false;
        }
    }

    return true;

}

int  strHexToDec(char str[], size_t n) {
    int number = 0;
    size_t counter = 0;

    for (int i = n - 1; i >= 0; --i) {
        if (str[i] >= '0' && str[i] <= '9') {
            number += (str[i] - 48) * pow(16, counter);
            ++counter;
        }
        else if (str[i] >= 'a' && str[i] <= 'f') {
            number += (str[i] - 87) * pow(16, counter);
            ++counter;
        }
    }

    return number;
}


bool isMacAddress(char str[], size_t n) {

    if (!(str[n - 5] == '.' && str[n - 10] == '.' && n == 14)) {
        return false;
    }
    for (int i = n - 1; i >= 0; --i) {

        if (!((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f') || (str[i] >= '.'))) {
            return false;
        }

    }

    return true;
}

bool isIpAddress(char str[], size_t n) {
    const int size = 3;
    int newSize = 0;
    size_t counter = 0;
    size_t index = 0;
    size_t index2 = 0;
    bool check = true;
    char tmpStr1[size];
    char tmpStr2[size];
    char tmpStr3[size];
    char tmpStr4[size];


    if (n < 16 && n>6) {
        for (int i = 0; i < n; ++i) {
            if (!(str[i] >= '0' && str[i] <= '9' || str[i] == '.')) {
                check = false;
            }
        }

        if (check) {

            for (int i = 0; str[i] != '.'; ++i) {
                tmpStr1[i] = str[i];
                index = i;
                ++index2;
            }
            newSize = index2;
            if (strToInt(tmpStr1, newSize) >= 0 && strToInt(tmpStr1, newSize) < 256) {
                ++counter;
            };

            index2 = 0;

            for (int i = index + 2, j = 0; str[i] != '.'; ++i, ++j) {
                tmpStr2[j] = str[i];
                index = i;
                ++index2;
            }
            newSize = index2;
            if (strToInt(tmpStr2, newSize) >= 0 && strToInt(tmpStr2, newSize) < 256) {
                ++counter;
            };

            index2 = 0;

            for (int i = index + 2, j = 0; str[i] != '.'; ++i, ++j) {
                tmpStr3[j] = str[i];
                index = i;
                ++index2;
            }
            newSize = index2;
            if (strToInt(tmpStr3, newSize) >= 0 && strToInt(tmpStr3, newSize) < 256) {
                ++counter;
            };

            index2 = 0;

            for (int i = index + 2, j = 0; (str[i] >= '0' && str[i] <= '9'); ++i, ++j) {
                tmpStr4[j] = str[i];
                ++index2;
            }
            newSize = index2;
            if (strToInt(tmpStr4, newSize) >= 0 && strToInt(tmpStr4, newSize) < 256) {
                ++counter;
            };


            if (counter == 4) {
                return true;
            }
        }
    }
    return false;
}
