# Execution time of some sorting algorithms

## Introduction

The execution time of different programs or functions can vary due to
many factors, including the CPU, memory, load, input data. The main
component, however is the algorithm. In this lab we will measure the
time taken to sort collections of the same elements with different
algorithms.

The file `sorting.cpp` contains code to generate collections (vectors
and arrays) of random elements and time the execution of 3 algorithms:
bubble sort, the std::sort, and the textbook's mergeSort.

## Compiling and running

You can build and run the example code with `cmake`:

Create the build files with:

```
$ cmake -B build .
-- The CXX compiler identification is GNU 13.3.0
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (0.2s)
-- Generating done (0.0s)
-- Build files have been written to: /home/humberto/Sync/Documents/class/2026/ccom3034/ccom3034-f2026/lab-sort/build
```
Build the project with:

```
$ cmake --build build
[ 50%] Building CXX object CMakeFiles/sorting.dir/sorting.cpp.o
[100%] Linking CXX executable sorting
[100%] Built target sorting
```

And run the program on 100 random elements:

```
$ ./build/sorting 100

Time elapsed for Bubblesort: 141us
Time elapsed for STL sort: 50us
Time elapsed for ods::mergeSort: 93us
Congrats! All vectors and arrays were properly sorted!
```

### Compiling by hand

If you want to compile by hand (e.g. you don't have cmake), make sure to use c++20. In gcc, that means compiling with `--std=c++20`:

```
$ g++ --std=c++20 -o sorting sorting.cpp
$ ./sorting 100

Time elapsed for Bubblesort: 277us
Time elapsed for STL sort: 79us
Time elapsed for ods::mergeSort: 172us
Congrats! All vectors and arrays were properly sorted!

```

## Exercise 1

Add code in `sorting.cpp` to time sorting arrays with quickSort and
heapSort from the book. You can copy and modify the section that does
the sort with mergeSort:
```
  // measure time to sort using the book's mergeSort
  start = std::chrono::steady_clock::now();
  ods::mergeSort(x);
  end = std::chrono::steady_clock::now();

  duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  cout << "Time elapsed for ods::mergeSort: " << duration << "\n";
```

You should also make sure the resulting arrays are sorted.

## Exercise 2

Run the `sorting` program with varying input sizes, and record the
times in the following table:

| # elements | bubble sort | sort | mergeSort | quickSort | heapSort |
|------------|-------------|------|-----------|-----------|----------|
| 4,000      |             |      |           |           |          |
| 8,000      |             |      |           |           |          |
| 16,000     |             |      |           |           |          |
| 32,000     |             |      |           |           |          |

Which sort is fastest? slowest?

# Exercise 3

Run the `sorting` program again, and record the new times in the table
below:

| # elements | bubble sort | sort | mergeSort | quickSort | heapSort |
|------------|-------------|------|-----------|-----------|----------|
| 4,000      |             |      |           |           |          |
| 8,000      |             |      |           |           |          |
| 16,000     |             |      |           |           |          |
| 32,000     |             |      |           |           |          |

Plot each of the sorts in a separate series. Are there clear winners
or losers?
