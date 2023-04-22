#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

void balance(char *in, char *out)
{
  ifstream input(in);   // открываем файл для чтения
  ofstream output(out); // открываем файл для записи
  stack<char> stack;    // создаем стек для хранения скобок

  char c;
  int line_number = 1;  // номер текущей строки
  bool balanced = true; // флаг для проверки баланса скобок

  while (input.get(c))
  {
    if (c == '{')
    {
      stack.push(c);
    }
    else if (c == '}')
    {
      if (stack.empty() || stack.top() != '{')
      {
        cout << "Ошибка: закрывающая скобка } на строке " << line_number << " не имеет открывающей скобки\n";
        output << "Ошибка: закрывающая скобка } на строке " << line_number << " не имеет открывающей скобки\n";
        balanced = false;
      }
      else
      {
        stack.pop();
      }
    }
    else if (c == '\n')
    {
      line_number++;
    }
  }

  if (!stack.empty())
  {
    cout << "Ошибка: открывающая скобка { не имеет закрывающей скобки\n";
    output << "Ошибка: открывающая скобка { не имеет закрывающей скобки\n";
    balanced = false;
  }

  if (balanced)
  {
    cout << "Скобки сбалансированы\n";
    output << "Скобки сбалансированы\n";
  }

  input.close();  // закрываем файл для чтения
  output.close(); // закрываем файл для записи
}

int main()
{
  balance("program.txt","out.txt");
  balance("program_error.txt","out_error.txt");
  return 0;
}
