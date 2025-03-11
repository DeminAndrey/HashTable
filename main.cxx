#include "HashTable.h"

#include <iostream>

using namespace std;

int main() {
  HashTable ht(5); // Создаем таблицу размером 5

  // Вставляем элементы
  ht.insert(1, "Earth");
  ht.insert(6, "Pluton");
  ht.insert(11, "Jupiter");
  ht.insert(16, "Date");
  ht.insert(21, "Mars");

  // Печать содержимого таблицы
  ht.print();

  // Поиск элемента
  string result;
  if (ht.find(11, result)) {
    cout << "Found: " << result << "\n";
  }
  else {
    cout << "Not found.\n";
  }

  // Удаление элемента
  ht.remove(11);

  // Печать после удаления
  ht.print();

  return 0;
}
