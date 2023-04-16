#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Структура для хранения информации о записях в файле
struct Record {
    string phone_number;
    string name;
    string address;
};

// Функция сравнения для сортировки записей по номеру телефона
bool compare_records(const Record& a, const Record& b) {
    return a.phone_number < b.phone_number;
}

int main() {
    string input_filename = "input.txt";
    string output_filename = "output.txt";

    ifstream input_file(input_filename);
    if (!input_file.is_open()) {
        cerr << "Error: Cannot open input file " << input_filename << endl;
        return 1;
    }

    // Считывание записей из файла в вектор
    vector<Record> records;
    Record record;
    while (getline(input_file, record.phone_number, ',') &&
           getline(input_file, record.name, ',') &&
           getline(input_file, record.address)) {
        // Удаление лишних пробелов в начале и конце полей
        record.phone_number = record.phone_number.substr(record.phone_number.find_first_not_of(" "));
        record.phone_number = record.phone_number.substr(0, record.phone_number.find_last_not_of(" ") + 1);
        record.name = record.name.substr(record.name.find_first_not_of(" "));
        record.name = record.name.substr(0, record.name.find_last_not_of(" ") + 1);
        record.address = record.address.substr(record.address.find_first_not_of(" "));
        record.address = record.address.substr(0, record.address.find_last_not_of(" ") + 1);
        records.push_back(record);
    }

    input_file.close();

    // Сортировка записей по номеру телефона
    sort(records.begin(), records.end(), compare_records);

    ofstream output_file(output_filename);
    if (!output_file.is_open()) {
        cerr << "Error: Cannot open output file " << output_filename << endl;
        return 1;
    }

    // Запись отсортированных записей в файл
    for (const auto& r : records) {
        output_file << r.phone_number << ", " << r.name << ", " << r.address << endl;
    }

    output_file.close();

    return 0;
}
