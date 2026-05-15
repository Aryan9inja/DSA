### Kahn's ALGORITHM

Kahn's algorithm is a method for performing a topological sort on a directed acyclic graph (DAG). It works by repeatedly removing nodes with no incoming edges and adding them to the sorted list. The algorithm can be implemented using a queue to keep track of nodes with no incoming edges.

Indegree is the number of incoming edges to a node. In Kahn's algorithm, we start by calculating the indegree of each node in the graph. We then enqueue all nodes with an indegree of zero (i.e., nodes with no dependencies).

If cycles exist in the graph, Kahn's algorithm will not be able to process all nodes, and the resulting sorted list will contain fewer nodes than the total number of nodes in the graph. This is because nodes involved in a cycle will never have an indegree of zero.

Topological sorting is a linear ordering of vertices in a directed graph such that for every directed edge from vertex A to vertex B, vertex A comes before vertex B in the ordering. Kahn's algorithm is one of the methods used to achieve this sorting.

It uses a breadth-first search (BFS) approach, where we process nodes level by level, starting with those that have no dependencies. As we remove nodes from the graph, we update the indegree of their neighboring nodes and enqueue any that become zero.