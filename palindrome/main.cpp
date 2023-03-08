#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(int n)
{
    // конвертируем число в строку
    string num_str = to_string(n);
    // создаем копию строки
    string rev_str = num_str;
    // переворачиваем копию строки
    reverse(rev_str.begin(), rev_str.end());
    // сравниваем строки
    return num_str == rev_str;
}

int main()
{
    int n;
    cout << "Введите число: ";
    cin >> n;
    
    if (isPalindrome(n))
    {
        cout << "Число " << n << " является палиндромом." << endl;
    }
    else
    {
        cout << "Число " << n << " не является палиндромом." << endl;
    }

    return 0;
}