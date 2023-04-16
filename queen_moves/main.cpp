#include <iostream>
#include <cmath>

using namespace std;

int letterToNumber(char letter) {
    switch(letter) {
        case 'A':
        case 'a':
            return 1;
        case 'B':
        case 'b':
            return 2;
        case 'C':
        case 'c':
            return 3;
        case 'D':
        case 'd':
            return 4;
        case 'E':
        case 'e':
            return 5;
        case 'F':
        case 'f':
            return 6;
        case 'G':
        case 'g':
            return 7;
        case 'H':
        case 'h':
            return 8;
        default:
            return 0;
    }
}

int main() {
    char c1, c2;
    int x1, y1, x2, y2;
    cout << "Enter the coordinates of the first cell: ";
    cin >> c1 >> y1;
    cout << "Enter the coordinates of the second cell: ";
    cin >> c2 >> y2;

    // Преобразование буквенных координат в числовые
    x1 = letterToNumber(c1);
    x2 = letterToNumber(c2);

    // Проверка, что координаты находятся на доске
    if (x1 < 1 || x1 > 8 || y1 < 1 || y1 > 8 ||
        x2 < 1 || x2 > 8 || y2 < 1 || y2 > 8) {
        cout << "Error: Invalid coordinates" << endl;
        return 1;
    }

    // Проверка, может ли ферзь сделать ход из одной клетки в другую
    if (x1 == x2 || y1 == y2 || abs(x1 - x2) == abs(y1 - y2)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
