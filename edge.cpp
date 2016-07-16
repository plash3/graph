#include "edge.h"

namespace graph {

bool CEdge::operator< (const CEdge& rhs) const {
  return id < rhs.id;
}

std::ostream& operator<< (std::ostream& out, const CEdge& t) {
  return out << "(" << t.id << ',' << t.weight << ")";
}

} // namespace graph
