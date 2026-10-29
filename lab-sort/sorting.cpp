// Measure execution times of bubble sort vs. the STL implementation
// of sort.
//
// Usage:
//    ./<exec name> <size of list>

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <chrono>

#include "Algorithms.h"

using namespace std;


//
// Given a vector if ints, bubble sort it.
//
void bubbleSort(vector<int> & arr) {
  int i, j;
  int n = arr.size();
  for (i = 0; i < n-1; i++)  {    
    // Last i elements are already in place   
    for (j = 0; j < n-i-1; j++) {
      if (arr[j] > arr[j+1])
        swap(arr[j], arr[j+1]);
    }
  }
}


int main(int argc, char *argv[]) {
  
  if (argc < 2) { 
  	cout << "Usage: " << argv[0] << " <size> \n"; 
    exit(1);
  }
  int size = atoi(argv[1]);
  
  vector<int> v(size), w(size);	// vectors to sort
  ods::array<int> x(size);	// an array to sort
  
  // This is the C++20 way of generating random numbers, first a random device
  std::random_device rd;

  // .. then a generator ...
  std::mt19937 gen(rd());

  // .. the a distribution for the whole range of intengers
  std::uniform_int_distribution<int> dist(std::numeric_limits<int>::lowest(), std::numeric_limits<int>::max());

  // fill the v, w vectors and x array with the same random integers   
  for (int i = 0; i < size; i++) {
    v[i] = w[i] = x[i] = dist(gen);
  }

  auto start = std::chrono::steady_clock::now();
  bubbleSort(v);
  auto end = std::chrono::steady_clock::now();

  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  cout << "\nTime elapsed for Bubblesort: " << duration << "\n";
  
  // measure time to sort using the STL sort algorithm
  start = std::chrono::steady_clock::now();
  sort(w.begin(),w.end());
  end = std::chrono::steady_clock::now();

  duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  cout << "Time elapsed for STL sort: " << duration << "\n";

  // measure time to sort using the book's mergeSort
  start = std::chrono::steady_clock::now();
  ods::mergeSort(x);
  end = std::chrono::steady_clock::now();

  duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  cout << "Time elapsed for ods::mergeSort: " << duration << "\n";

  if ( is_sorted(v.begin(),v.end()) &&
       is_sorted(w.begin(),w.end()) &&
       is_sorted(x.a+0, x.a+x.length)) 
    cout << "Congrats! All vectors and arrays were properly sorted!\n\n";
  else 
    cout << "At least one of the algorithms returned an unsorted collection.\n\n"; 
  
  return 0;
}



