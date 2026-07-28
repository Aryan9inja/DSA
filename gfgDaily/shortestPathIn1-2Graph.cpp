#include <bits/stdc++.h>
using namespace std;

/**
 * Approach 1: Standard Dijkstra Algorithm
 *
 * Strategy: Uses a Min-Priority Queue to always expand the node with the smallest distance.
 *
 * Time Complexity:  O((V + E) log V) - Priority Queue push/pop operations take O(log V) time.
 * Space Complexity: O(V + E)        - Adjacency list, distance array, and Priority Queue.
 */
class Dijkstra {
public:
    int shortestPath(int V, int src, int dest, vector<vector<int>>& edges) {
        // Build undirected graph adjacency list: u -> {v, weight}
        vector<vector<pair<int, int>>> adj(V);
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({ v, w });
            adj[v].push_back({ u, w });
        }

        // Stores shortest known distance to each node from src
        vector<int> dist(V, INT_MAX);

        // Min-heap storing pair<distance, node> sorted by distance
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        // Initialize source
        dist[src] = 0;
        pq.push({ 0, src });

        while (!pq.empty()) {
            auto [distance, node] = pq.top();
            pq.pop();

            // Skip stale/outdated queue entries if a shorter path was already processed
            if (distance > dist[node])
                continue;

            // Relax adjacent edges
            for (auto& [adjNode, adjDist] : adj[node]) {
                if (distance + adjDist < dist[adjNode]) {
                    dist[adjNode] = distance + adjDist;
                    pq.push({ dist[adjNode], adjNode });
                }
            }
        }

        return dist[dest] == INT_MAX ? -1 : dist[dest];
    }
};

/**
 * Approach 2: Edge Splitting + Standard BFS
 *
 * Strategy: Converts a weighted graph (weights 1 or 2) into an unweighted graph by inserting
 *           a dummy node for every edge of weight 2 (u -> dummy -> v). Runs standard BFS.
 *
 * Time Complexity:  O(V + E) - Unweighted BFS runs in linear time.
 * Space Complexity: O(V + E) - Allocates memory for up to E dummy nodes and extra edges.
 */
class EdgeSplit {
public:
    int shortestPath(int V, int src, int dest, vector<vector<int>>& edges) {
        // ID counter for newly created dummy nodes (starts right after original V nodes)
        int idx = V;

        // Reserve space for worst-case capacity: V original nodes + up to E dummy nodes
        vector<vector<int>> adj(V + edges.size());
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            if (w == 1) {
                // Weight 1 edge: direct connection
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            else {
                // Weight 2 edge: split into two weight 1 edges using dummy node `idx`
                adj[u].push_back(idx);
                adj[idx].push_back(v);

                adj[v].push_back(idx);
                adj[idx].push_back(u);

                idx++; // Next available dummy node ID
            }
        }

        // Distance array initialized to -1 (unvisited)
        vector<int> dist(idx, -1);

        queue<int> q;
        q.push(src);
        dist[src] = 0;

        // Standard Unweighted BFS
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            // Early exit if target destination reached
            if (node == dest) {
                return dist[node];
            }

            for (int neighbour : adj[node]) {
                if (dist[neighbour] == -1) {
                    dist[neighbour] = dist[node] + 1;
                    q.push(neighbour);
                }
            }
        }

        return -1;
    }
};

/**
 * Approach 3: Dial's Algorithm (Optimized Bucket-Based Dijkstra)
 *
 * Strategy: Replaces the priority queue with cyclic buckets (using modulo 3 for max weight 2).
 *           Bucket i stores nodes at distance `i`. Reduces Dijkstra to linear time.
 *
 * Time Complexity:  O(V + E) - Constant time bucket insertions and extractions.
 * Space Complexity: O(V + E) - Uses original graph structure with zero dummy node overhead.
 */
class DialAlgo {
public:
    int shortestPath(int V, int src, int dest, vector<vector<int>>& edges) {
        // Build undirected graph adjacency list
        vector<vector<pair<int, int>>> adj(V);
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({ v, w });
            adj[v].push_back({ u, w });
        }

        vector<int> dist(V, INT_MAX);

        // 3 cyclic buckets: buckets[d % 3] stores all nodes at current distance d
        // Required size is Max_Weight + 1 = 2 + 1 = 3
        vector<vector<int>> buckets(3);

        buckets[0].push_back(src);
        dist[src] = 0;

        int curr_dist = 0;
        int processed = 0; // Tracks unique nodes fully processed

        while (processed < V) {
            // Increment curr_dist until we hit a non-empty bucket
            while (buckets[curr_dist % 3].empty()) {
                curr_dist++;

                // Upper limit check: max possible shortest path distance is 2 * V
                if (curr_dist > 2 * V)
                    break;
            }

            // Graph is disconnected or remaining unreachable nodes exist
            if (curr_dist > 2 * V)
                break;

            int bucketIdx = curr_dist % 3;
            int node = buckets[bucketIdx].back();
            buckets[bucketIdx].pop_back();

            // Skip duplicate/stale entries if node was reached via a shorter path previously
            if (dist[node] < curr_dist)
                continue;

            processed++;

            // Early termination when target is reached
            if (node == dest)
                return dist[node];

            // Relax neighbors
            for (auto& [adjNode, adjDist] : adj[node]) {
                if (curr_dist + adjDist < dist[adjNode]) {
                    dist[adjNode] = curr_dist + adjDist;

                    // Insert neighbor into its corresponding cyclic bucket
                    buckets[dist[adjNode] % 3].push_back(adjNode);
                }
            }
        }

        return dist[dest] == INT_MAX ? -1 : dist[dest];
    }
};