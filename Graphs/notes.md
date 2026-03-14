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

### Graph Traversal
Graph traversal is the process of visiting all the nodes in a graph. The two most common graph traversal algorithms are:
1. **Depth-First Search (DFS)**: A traversal method that explores as far as possible along each branch before backtracking.
2. **Breadth-First Search (BFS)**: A traversal method that explores all the neighbors of a node before moving on to the neighbors' neighbors.

### Applications of Graphs
- **Social Networks**: Representing relationships between people.
- **Computer Networks**: Representing connections between computers or devices.
- **Transportation Networks**: Representing roads, railways, or flight routes.
- **Dependency Graphs**: Representing dependencies between tasks or modules in software development.

### Minimum Spanning Tree
A minimum spanning tree (MST) is a subset of the edges of a connected, undirected graph that connects all the vertices together without any cycles and with the minimum possible total edge weight. Common algorithms to find an MST include Prim's algorithm and Kruskal's algorithm.

### Prim's Algorithm
Prim's algorithm is a greedy algorithm that builds the minimum spanning tree by starting from an arbitrary node and repeatedly adding the smallest edge that connects a node in the tree to a node outside the tree until all nodes are included.

### Kruskal's Algorithm
Kruskal's algorithm is a greedy algorithm that builds the minimum spanning tree by sorting all the edges in non-decreasing order of their weight and adding them one by one to the tree, as long as they do not form a cycle.

### Dijkstra's Algorithm
Dijkstra's algorithm is a popular algorithm for finding the shortest paths between nodes in a graph, which may represent, for example, road networks. It works by maintaining a priority queue of nodes to explore, starting from the source node and repeatedly visiting the node with the smallest known distance until the destination node is reached or all reachable nodes have been visited.

### Union-Find (Disjoint Set Union)
Union-Find is a data structure that keeps track of a set of elements partitioned into disjoint (non-overlapping) subsets. It provides efficient operations for union and find, which are used in algorithms like Kruskal's to manage and merge sets of nodes while building the minimum spanning tree.
## Path Compression
Path compression is an optimization technique used in the Union-Find data structure to speed up the find operation. When performing a find operation, path compression flattens the structure of the tree by making every node on the path from a given node to the root point directly to the root. This reduces the time complexity of subsequent find operations, making them nearly constant time.

### Topological Sort
Topological sort is a linear ordering of the vertices of a directed acyclic graph (DAG) such that for every directed edge (u, v), vertex u comes before vertex v in the ordering. It is commonly used in scheduling tasks, resolving dependencies, and organizing data with hierarchical relationships.

### Bridge
A bridge (or cut edge) in a graph is an edge that, if removed, would increase the number of connected components in the graph. In other words, it is an edge that, when removed, disconnects the graph. Bridges are important in network design and analysis, as they represent critical connections that can affect the overall connectivity of the graph.

### Articulation Point
An articulation point (or cut vertex) in a graph is a vertex that, if removed along with its associated edges, would increase the number of connected components in the graph. In other words, it is a vertex that, when removed, disconnects the graph. Articulation points are important in network design and analysis, as they represent critical nodes that can affect the overall connectivity of the graph.

### Strongly Connected Components
In a directed graph, a strongly connected component (SCC) is a subgraph where there is a path from every vertex to every other vertex. In other words, for any two vertices u and v in the SCC, there is a directed path from u to v and a directed path from v to u. Strongly connected components are important in understanding the structure of directed graphs and are often used in applications such as analyzing social networks, web page ranking, and optimizing compilers. Tarjan's algorithm is a common method for finding strongly connected components in a directed graph. Kosaraju's algorithm is another method that can be used to find strongly connected components, which involves performing two depth-first searches on the graph.