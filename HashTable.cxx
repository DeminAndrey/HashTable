#include "HashTable.h"

#include <iostream>

using namespace std;

HashTable::HashTable(size_t size)
    : table(size), size_(size) {}

size_t HashTable::hashFunction(int key) const {
  return key % size_;
}

void HashTable::insert(int key, const string& value) {
  size_t index = hashFunction(key);
  for (auto it = table[index].begin(); it != table[index].end(); ++it) {
    if ((*it).key == key) { // Обновление значения, если ключ уже существует
      (*it).value = value;
      return;
    }
  }
  // Добавляем новый элемент в начало списка
  table[index].push_front(Node(key, value));
}

bool HashTable::find(int key, string& result) const {
  size_t index = hashFunction(key);
  for (const auto& node : table[index]) {
    if (node.key == key) {
      result = node.value;
      return true;
    }
  }
  return false;
}

void HashTable::remove(int key) {
  size_t index = hashFunction(key);
  for (auto it = table[index].begin(); it != table[index].end(); ) {
    if ((*it).key == key) {
      it = table[index].erase(it); // Удаляем узел
    } else {
      ++it;
    }
  }
}

void HashTable::print() const {
  for (size_t i = 0; i < size_; ++i) {
    cout << "Bucket " << i << ": ";
    for (const auto& node : table[i]) {
      cout << "(" << node.key << ", " << node.value << ") -> ";
    }
    cout << "NULL\n";
  }
}
