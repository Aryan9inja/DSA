## Graph
Graphs are a data structure that consists of a set of nodes (also called vertices) and a set of edges that connect pairs of nodes. Graphs can be directed or undirected, depending on whether the edges have a direction or not.

### Nodes and Edges
- **Node (Vertex)**: A fundamental unit of a graph that can represent an entity or a point in the graph.
- **Edge**: A connection between two nodes. In a directed graph, edges have a direction, while in an undirected graph, they do not.

### Types of Graphs
1. **Undirected Graph**: In an undirected graph, the edges do not have a direction. The edge (A, B) is the same as (B, A).
2. **Directed Graph (Digraph)**: In a directed graph, the edges have a direction. The edge (A, B) is different from (B, A).
3. **Weighted Graph**: In a weighted graph, each edge has a weight or cost associated with it. This is often used to represent distances, costs, or capacities.
4. **Unweighted Graph**: In an unweighted graph, all edges are considered to have the same weight or no weight at all.

### Graph Representations
1. **Adjacency Matrix**: A 2D array where the entry at row i and column j indicates the presence (and possibly the weight) of an edge between nodes i and j.
2. **Adjacency List**: A list where each node has a list of its adjacent nodes. This is more space-efficient for sparse graphs.
3. **Edge List**: A list of all edges in the graph, where each edge is represented as a pair (or triplet for weighted graphs) of nodes.

### Degree of a Node
The degree of a node in an undirected graph is the number of edges connected to it. In a directed graph, we have:
- **In-degree**: The number of edges coming into the node.
- **Out-degree**: The number of edges going out from the node.