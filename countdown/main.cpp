#include <iostream>
using namespace std;

int main() {
   cout << "Введите число: ";
   int N;
   cin >> N;
   
   for (int i = N; i >= 1; i--) {
      cout << i;
      if (i % 5 == 0) { // проверка на кратность 5
         cout << " Beep";
      }
      cout << endl;
   }
   
   return 0;
}