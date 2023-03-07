#include <iostream>
#include <cmath>
using namespace std;

struct point {
    double x;
    double y;
};

int main() {
	setlocale(0,"");
    int n; // Количество вершин многоугольника
    cout << "Введите количество вершин многоугольника: ";
    cin >> n;
    // Задаем координаты вершин многоугольника
    point vertices[n];
    for (int i = 0; i < n; i++) {
        cout << "Введите координаты вершины " << i+1 << ": ";
        cin >> vertices[i].x >> vertices[i].y;
    }

    // Вычисляем площадь многоугольника
    double area = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += (vertices[j].x + vertices[i].x) * (vertices[j].y - vertices[i].y);
    }
    area /= 2;
    area = abs(area);

    // Выводим результат
    cout << "Площадь многоугольника равна " << area << endl;

    return 0;
}
