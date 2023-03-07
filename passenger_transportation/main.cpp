#include <iostream>
using namespace std;

const int BUS_CAPACITY = 50;

int main() {
    int passengers; // Количество пассажиров на автовокзале
    cout << "Введите количество пассажиров: ";
    cin >> passengers;

    // Рассчитываем количество свободных мест в последнем автобусе
    int last_bus = passengers % BUS_CAPACITY;
    int empty_seats = (last_bus == 0) ? 0 : BUS_CAPACITY - last_bus;

    // Выводим результат
    cout << "В последнем автобусе будет " << empty_seats << " свободных мест." << endl;

    return 0;
}