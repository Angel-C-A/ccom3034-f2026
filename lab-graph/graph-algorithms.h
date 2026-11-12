// graph-algorithms.h - graph algorithms:
// depth first and breadth first searches
// to test conectivity in graphs,
// read graphs as .csv files from disk
// Copyright (2026) - Humberto Ortiz Zuazaga
// Released under
// https://creativecommons.org/licenses/by/4.0/deed.en
// based on 
/*
 * Algorithms.h
 *
 *  Created on: 2011-11-30
 *      Author: morin
 */

#ifndef ALGORITHMS_H_
#define ALGORITHMS_H_

#include <fstream>
#include <sstream>
#include <string>

#include "SLList.h"

#include "utils.h"
#include "array.h"

namespace ods {


template<class Graph>
bool bfs_reachable(Graph &g, int r, int t) {
  // search g starting from r, find t
  bool *seen = new bool[g.nVertices()];
  for (int i = 0; i < g.nVertices(); i++) {
    seen[i] = false;
  }
  SLList<int> q;
  q.add(r);
  seen[r] = true;
  while (q.size() > 0) {
    int i = q.remove();
    ArrayStack<int> edges;
    g.outEdges(i, edges);

    for (int k = 0; k < edges.size(); k++) {
      int j = edges.get(k);
      if (!seen[j]) {
	q.add(j);
	seen[j] = true;
      }
    }
  }

  bool found = seen[t];
  delete[] seen;
  return found;
}

enum { white='w', grey='g', black='b' };

template<class Graph>
void dfs(Graph &g, int i, char *c) {
  c[i] = grey;  // currently visiting i
  ArrayStack<int> edges;
  g.outEdges(i, edges);
  for (int k = 0; k < edges.size(); k++) {
    int j = edges.get(k);
    if (c[j] == white) {
      c[j] = grey;
      dfs(g, j, c);
    }
  }
  c[i] = black; // done visiting i
}

template<class Graph>
bool dfs_reachable(Graph &g, int r, int t) {
  // is there a path in g from r to t?
  char *c = new char[g.nVertices()];
  for (int i = 0; i < g.nVertices(); i++)
    c[i] = white;
  dfs(g, r, c);
  for (int i = 0; i < g.nVertices(); i++)
    std::cout << i << ":" << c[i] << std::endl;
  bool reachable = c[t] == black;
  delete[] c;
  return reachable;
}

AdjacencyLists readGraph(char *filename) {
  ods::ArrayStack<int> sources;
  ods::ArrayStack<int> sinks;

  std::fstream file(filename);

  std::string line;

  int from, to, bigger, max = 0;
  std::string token;

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
  return g;
}


} /* namespace ods */

#endif /* ALGORITHMS_H_ */
