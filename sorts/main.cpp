// main.cpp - test sorting methods
// Copyright 2026 Humberto Ortiz Zuazaga
// Based on Algorithms.h by Pat Morin
// in https://opendatastructures.org/
// Released under
// https://creativecommons.org/licenses/by/2.5/ca/

#include "Algorithms.h"
#include "array.h"

using namespace ods;

template<class T>
void print(array<T> &a) {
  for (int i = 0; i < (a.length - 1); i++) {
    std::cout << a[i] << ", " ;
  }
  std::cout << a[a.length - 1] << std::endl;
}

int main() {
  array<int> numbers(10);

  for (int i = 0; i < 10; i++) {
    // llenar el arrego con numeros aleatorios entre 0 u 99
    numbers[i] = rand()%100;
  }

  array<int> b(10);		// copia de los elementos desordenados
  array<int>::copyOfRange(b, numbers, 0, 10);
  
  std::cout << "Antes de mergeSort:" << std::endl;
  print(numbers);
    mergeSort(numbers);
  std::cout << "Luego de mergeSort:" << std::endl;
  print(numbers);

  std::cout << "Antes de quickSort:" << std::endl;
  print(b);
  quickSort(b);
  std::cout << "Luego de quickSort:" << std::endl;
  print(b);

  return 0;
}
