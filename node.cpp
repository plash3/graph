#include "node.h"

namespace graph {

bool CNode::operator< (const CNode& rhs) const {
  return (distance < rhs.distance) || (distance == rhs.distance && id < rhs.id);
}

std::ostream& operator<< (std::ostream& out, const CNode& t) {
  return out << t.distance;
}

} // namespace graph
