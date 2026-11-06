// main.cpp - use graph algorithms to test conectivity in graphs
// Copyright (2026) - Humberto Ortiz Zuazaga
// Released under
// https://creativecommons.org/licenses/by/4.0/deed.en

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

#include <bits/stdc++.h>

#include "ArrayStack.h"
#include "AdjacencyLists.h"
#include "graph-algorithms.h"

int main (int argc, char *argv[]) {
  ods::ArrayStack<int> sources;
  ods::ArrayStack<int> sinks;

  if (argc < 4) { 
    std::cout << "Usage: " << argv[0] << "<graph> <source> <target> \n"; 
    exit(1);
  }

  std::fstream file(argv[1]);

  std::string line;

  int from, to, bigger, max = 0;
  std::string token;

  int start = std::atoi(argv[2]); 
  int target = std::atoi(argv[3]);

  // read the graph csv file, put source, target pairs into parallel arrays
  // also find the maximal element to size the graph
  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::getline(ss, token, ',');
    std::stringstream sstf(token);
    sstf >> from;
    std::getline(ss, token, ',');
    std::stringstream sstt(token);
    sstt >> to;
    sources.add(from);
    sinks.add(to);
    bigger = std::max(from, to);
    max = std::max(max, bigger);
  }

  ods::AdjacencyLists g(max+1);
  
  while (sources.size() > 0) {
    // pop source and sink from lists, add edges to g
    int src = sources.remove(sources.size()-1);
    int snk = sinks.remove(sinks.size()-1);

    g.addEdge(src, snk);
  }

  // check if we can reach the target, starting from start
  if (ods::bfs_reachable<ods::AdjacencyLists>(g, start, target)) {
    std::cout << "Found a path from " << start << " to " << target << std::endl;
  } else {
    std::cout << "No path found from " << start << " to " << target << "!\n";
  }
  return 0;
}
