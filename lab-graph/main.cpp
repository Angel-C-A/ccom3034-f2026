// main.cpp - use graph algorithms to test conectivity in graphs
// Copyright (2026) - Humberto Ortiz Zuazaga
// Released under
// https://creativecommons.org/licenses/by/4.0/deed.en

#include <iostream>

#include "AdjacencyLists.h"
#include "graph-algorithms.h"

int main (int argc, char *argv[]) {

  if (argc < 4) { 
    std::cout << "Usage: " << argv[0] << "<graph> <source> <target> \n"; 
    exit(1);
  }

  ods::AdjacencyLists g = ods::readGraph(argv[1]);
  int start = std::atoi(argv[2]); 
  int target = std::atoi(argv[3]);
  
  // check if we can reach the target, starting from start
  if (ods::dfs_reachable<ods::AdjacencyLists>(g, start, target)) {
    std::cout << "Found a path from " << start << " to " << target << std::endl;
  } else {
    std::cout << "No path found from " << start << " to " << target << "!\n";
  }
  return 0;
}
