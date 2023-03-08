#include <iostream>
using namespace std;

const int TICKET_PRICE = 10; // стоимость билета

int main()
{
    int age[5];
    float total_cost;

    cout << "Введите возраст каждого члена группы:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> age[i];
    }

    // находим самого младшего члена группы
    int min_age = age[0];
    for (int i = 1; i < 5; i++)
    {
        if (age[i] < min_age)
        {
            min_age = age[i];
        }
    }

    // определяем скидку в зависимости от возраста самого младшего члена группы
    float discount = 1 - (min_age / 100);

    // вычисляем общую стоимость билетов
    total_cost = TICKET_PRICE * 5 * discount;

    cout << "Общая стоимость билетов: " << total_cost << " долларов." << endl;

    return 0;
}