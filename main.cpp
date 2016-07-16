#include "graph.h"
#include "edge.h"
#include "node.h"

/**
  A key in the map is regarded as a node identifier. A vertex pair (x,y)
  is an edge. Every edge is stored twice - as an outgoing edge
  for one node, and an incoming edge for another. Thus the map
  constitutes adjacency lists for every node in the graph.
 
*/
template<typename T>
inline void addedge (int x, int y, int w, graph::MAP<T>& mp) {
  auto spt = std::make_shared<T>(y, w);
  auto it = mp.find(x);
  if (it != mp.end()) {
    it->second.emplace (spt);
  } else {
    graph::SET<T> st (graph::derefLess);
    st.emplace (spt);
    mp.emplace (x, st);
  }

  spt = std::make_shared<T>(x, w);
  it = mp.find(y);
  if (it != mp.end()) {
    it->second.emplace (spt);
  } else {
    graph::SET<T> st (graph::derefLess);
    st.emplace (spt);
    mp.emplace (y, st);
  }

  return;
}

/**
  Given an undirected weighted graph consisting of N nodes (labelled 1 to N).
  Find shortest paths from the source to all other nodes in the graph.
*/
int main() {
  int n, d;
  std::cin >> n;
  std::cin >> d;

  graph::MAP<graph::CEdge> mp;
  for (int i = 0; i < d; i++) {
    int x, y, w;
    std::cin >> x;
    std::cin >> y;
    std::cin >> w;
    addedge (x-1, y-1, w, mp);
  }

  auto arr = std::make_unique<graph::SHPT<graph::CNode>[]>(n);
  graph::getShortestPathTree (0, arr, mp);

  for (int i = 0; i < n; i++) {
    if (arr[i] != nullptr) {
      std::cout << *arr[i] << " ";
    } else {
      std::cout << "NO PATH EXISTS ";
    }
  }
  std::cout << std::endl;

  return 0;
}
