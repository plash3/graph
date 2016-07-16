#ifndef EDGE_H
#define EDGE_H

#include <iostream>

namespace graph {

class CEdge {
    int id, weight;
  public:
    CEdge (int i, int w) : id(i), weight(w) {}
    ~CEdge () {}
    auto getId() { return id; }
    auto getWeight() { return weight; }
    bool operator< (const CEdge&) const;
    friend std::ostream& operator<< (std::ostream&, const CEdge&);
};

} // namespace graph

#endif /* EDGE_H */
