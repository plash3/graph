# The shortest path algorithm

The project implements an algorithm for finding the shortest paths between
nodes in an undirected weighted graph. Known as Dijkstra's algorithm.

Main logic of the underlying algorithm is implemented in graph.h template.

The implementation is based on a min-priority queue
provided by a set class template.

The algorithm takes a single node as a "source" node and
finds shortest paths from the source to all other nodes
in the graph, producing a shortest-path tree.

The algorithm picks a vertex from the priority queue with
the lowest distance, calculates the distance through it
to each unvisited neighbour, and updates the neighbour's
distance if smaller. Marks it visited when it is moved
out of the priority queue and done with neighbours.

The description of the algorithm can be found at -

en.wikipedia.org/wiki/Dijkstra's_algorithm

To run the project -

1. Build it using make utility.
2. Run it as ./main
