#ifndef NODE_H
#define NODE_H

#include <iostream>

namespace graph {

class CNode {
    // identity of the node
    int id;
  public:
    // previous node in optimal path from source
    int prev;
    // distance from the initial node - the source;
    // tentative distance values: set it to zero for
    // the source and to infinity for all other nodes.
    int distance;
    // mark visited when done with neighbours
    bool visited;
    CNode (int i, int p) : id(i), prev(p), distance(-1), visited(false) {}
    CNode (int i, int p, int d) : id(i), prev(p), distance(d), visited(false) {}
    ~CNode() {}
    auto getId() { return id; }
    bool operator< (const CNode&) const;
    friend std::ostream& operator<< (std::ostream&, const CNode&);
};

} // namespace graph

#endif /* NODE_H */
