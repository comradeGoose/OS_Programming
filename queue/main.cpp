#include <iostream>
using namespace std;

class Queue
{
public:
    Queue();                   // конструктор по умолчанию
    Queue(int s);              // конструктор для очереди заданного размера
    Queue(const Queue &other); // конструктор копирования
    ~Queue();                  // деструктор

    void add(int elem); // добавить элемент в очередь
    int remove();       // удалить первый элемент из очереди
    void print();       // вывести содержимое очереди

private:
    int *data;    // массив для хранения данных очереди
    int size;     // текущий размер очереди
    int capacity; // ёмкость очереди
};

Queue::Queue()
{
    capacity = 10;
    size = 0;
    data = new int[capacity];
}

Queue::Queue(int s)
{
    capacity = s;
    size = 0;
    data = new int[capacity];
}

Queue::Queue(const Queue &other)
{
    capacity = other.capacity;
    size = other.size;
    data = new int[capacity];
    for (int i = 0; i < size; i++)
    {
        data[i] = other.data[i];
    }
}

Queue::~Queue()
{
    delete[] data;
}

void Queue::add(int elem)
{
    if (size == capacity)
    {
        // увеличиваем ёмкость очереди вдвое
        capacity *= 2;
        int *new_data = new int[capacity];
        for (int i = 0; i < size; i++)
        {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
    }
    data[size] = elem;
    size++;
}

int Queue::remove()
{
    if (size == 0)
    {
        cerr << "Ошибка: очередь пуста." << endl;
        exit(1);
    }
    int first = data[0];
    for (int i = 1; i < size; i++)
    {
        data[i - 1] = data[i];
    }
    size--;
    return first;
}

void Queue::print()
{
    cout << "Очередь содержит элементы: ";
    for (int i = 0; i < size; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

int main()
{
    Queue q;

    // добавляем элементы в очередь
    q.add(10);
    q.add(20);
    q.add(30);

    // выводим содержимое очереди
    q.print();

    // удаляем первый элемент и выводим его значение
    int first = q.remove();
    cout << "Удален первый элемент очереди: " << first << endl;

    // добавляем еще элементы в очередь
    q.add(40);
    q.add(50);
    cout << "Добавлены элементы в очередь: 40, 50 " << endl;

    // выводим содержимое очереди
    q.print();

    return 0;
}