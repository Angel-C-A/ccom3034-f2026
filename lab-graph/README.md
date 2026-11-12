# Graph algorithms

In class we discussed the breadth-first and depth-first tecniques to
search graphs. This repository implements both (in the file
`graph-algorithms.h`), and uses one to test if a path can be found in
a graph from a source vertex to a target vertex.

## Compiling

### Using cmake

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
-- Build files have been written to: /home/humberto/Sync/Documents/class/2026/ccom3034/ccom3034-f2026/lab-graph/build
$ cmake --build build
[ 16%] Building CXX object CMakeFiles/main.dir/main.cpp.o
[ 33%] Building CXX object CMakeFiles/main.dir/AdjacencyLists.cpp.o
[ 50%] Linking CXX executable main
[ 50%] Built target main
[ 66%] Building CXX object CMakeFiles/shortest.dir/shortest.cpp.o
[ 83%] Building CXX object CMakeFiles/shortest.dir/AdjacencyLists.cpp.o
[100%] Linking CXX executable shortest
[100%] Built target shortest
```

### By hand

```
$ g++ -o main --std=c++20 main.cpp AdjacencyLists.cpp 
$ ./main small.csv 1 8
Found a path from 1 to 8
```

## Example graphs

 - small.csv - An 8 vertex sample
 - tree.csv - The 7 vertex binary tree from class
 - unique-graph.csv - a large (50,000) vertex graph from ssb social network
 - unique-graph-10k.csv - a random sample of 10,000 edges from the ssb social network

## Social networks

![social networks](unique-graph-10k.csv.png)

Social networks can grow very large. The above graph is a portion of
the social network graph of an obscure social network, secure
scuttlebutt. The full graph has 54,153 vertices and 364,801 edges (see
`unique-graph.csv`).

## Exercise

The textbook discusses finding shortest paths in a graph by running a
modified breadth-first search using an auxiliary array `p` (see
section 12.3.1). Write a function to print the shortest path in a
given graph `g` from a source vertex `r` to a target vertex `t`.

> A particularly useful application of the breadth-first-search algorithm
> is, therefore, in computing shortest paths. To compute the shortest path
> from r to every other vertex, we use a variant of bfs(g, r) that uses an
> auxilliary array, p, of length n. When a new vertex j is added to q, we set
> p[j] = i. In this way, p[j] becomes the second last node on a shortest path
> from r to j. Repeating this, by taking p[p[j], p[p[p[j]]], and so on we can
> reconstruct the (reversal of) a shortest path from r to j.

```
template<class Graph>
bool shortestPath(Graph &g, int r, int t);
```

The file `shortest.cpp` has a skeleton implementation of
`shortestPath`. Fix it so that it works.

```
$ g++ -g -o shortest shortest.cpp AdjacencyLists.cpp 
$ ./shortest small.csv 1 8
terminate called after throwing an instance of 'std::runtime_error'
  what():  No se encontrar caminos
Aborted (core dumped)
```
