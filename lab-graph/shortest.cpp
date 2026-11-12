// shortest.cpp - print the shortest path between given nodes in a graph
// Copyright (2026) - Humberto Ortiz Zuazaga
// Released under
// https://creativecommons.org/licenses/by/4.0/deed.en

#include <iostream>

#include "AdjacencyLists.h"
#include "graph-algorithms.h"

template<class Graph>
bool shortestPath(Graph &g, int r, int t) {
  // search g starting from r, find and print a shortest path to t
  throw std::runtime_error("No se encontrar caminos");
  return false;
}

int main (int argc, char *argv[]) {
  // make sure we were called with 3 arguments
  if (argc < 4) { 
    std::cout << "Usage: " << argv[0] << "<graph> <source> <target> \n"; 
    exit(1);
  }

  ods::AdjacencyLists g = ods::readGraph(argv[1]);
  int start = std::atoi(argv[2]); 
  int target = std::atoi(argv[3]);
  
  // check if we can reach the target, starting from start
  if (shortestPath<ods::AdjacencyLists>(g, start, target)) {
    std::cout << "Found a path from " << start << " to " << target << std::endl;
  } else {
    std::cout << "No path found from " << start << " to " << target << "!\n";
  }
  return 0;
}
