#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <memory>
#include <set>
#include <map>

namespace graph {

  auto derefLess = [](const auto& p1, const auto& p2) { return *p1 < *p2; };
template<typename T>
  using SHPT = std::shared_ptr<T>;
template<typename T>
  using SET = std::set<SHPT<T>, decltype(derefLess)>;
template<typename T>
  using MAP = std::map<int, SET<T>>;
template<typename T>
  using ARRT = std::unique_ptr<SHPT<T>[]>;

/**
  Checks all neighbours of the node u. If a neighbour is in
  the visited set - the sortest path to it has been found
  and we are done with all its neigbours - then skip it.
  Calculate the distance through the node u to each unvisited
  neighbour, and update the neighbour's distance if smaller.
  Inserts an unvisited neighbour in the queue unless it is there.
*/
template<typename T, typename D>
void Adj (const SHPT<T>& u, SET<T>& prtyqu, ARRT<T>& arr, const MAP<D>& mp) {
  auto prev = u->getId();
  auto it = mp.find(prev);
  if (it != mp.end()) {
    for (auto its = it->second.begin(); its != it->second.end(); ++its) {
      auto i = (*its)->getId();
      // dist[u] + length(u, v)
      auto dist = u->distance + (*its)->getWeight();
      if (arr[i] == nullptr) {
        auto spn = std::make_shared<T>(i, prev, dist);
        prtyqu.insert (spn);
        arr[i] = spn;
      } else if (!arr[i]->visited) {
        if (arr[i]->distance > dist) {
          auto itn = prtyqu.find (arr[i]);
          prtyqu.erase (itn);
          arr[i]->distance = dist;
          arr[i]->prev = prev;
          // decrease priority
          prtyqu.insert (arr[i]);
        }
      }
    }
  }
}

  /**
    Finds shortest paths from the source to all other nodes
    in the graph, producing a shortest-path tree.
  */
template<typename T, typename D>
void getShortestPathTree (int s, ARRT<T>& arr, const MAP<D>& mp) {
  SET<T> prtyqu (derefLess);
  auto spn = std::make_shared<T>(s, -1, 0);
  prtyqu.insert (spn);
  arr[spn->getId()] = spn;

  while (!prtyqu.empty()) {
    spn = *prtyqu.begin();
    prtyqu.erase (*prtyqu.begin());
    spn->visited = true;
    Adj (spn, prtyqu, arr, mp);
  }
}

} // namespace graph

#endif /* GRAPH_H */
