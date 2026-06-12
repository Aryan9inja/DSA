#include<bits/stdc++.h>
using namespace std;

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    // Constants for modulo operations and binary lifting limit (2^17 >= 131,072 nodes)
    static constexpr int mod = 1000000007;
    static constexpr int LOG = 18;

    int n;                              // Total number of vertices in the tree
    vector<vector<int>> adj;            // Adjacency list representation of the tree
    vector<int> depth;                  // depth[i] stores the distance of node i from the root (node 1)
    vector<vector<int>> up;             // up[node][j] stores the (2^j)-th ancestor of 'node'
    vector<int> pow2;                   // Memoization table for powers of 2 modulo 1000000007

    /*
     * Legacy DFS function (retained but currently swapped out for an iterative approach
     * in the main function to avoid recursion overhead / stack overflow limits).
     */
    void dfs(int node, int parent) {
        up[node][0] = parent;

        for (int child : adj[node]) {
            if (child == parent) {
                continue;
            }

            depth[child] = depth[node] + 1;
            dfs(child, node);
        }
    }

    /*
     * Finds the Lowest Common Ancestor (LCA) of nodes u and v in O(LOG) time.
     */
    int lca(int u, int v) {
        // Step 1: Ensure node 'u' is always the deeper node
        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        // Step 2: Lift node 'u' up to the same depth level as node 'v' using binary jumps
        for (int j = LOG - 1; j >= 0; j--) {
            if (diff & (1 << j))
                u = up[u][j];
        }

        // If they landed on the same node, that node is the LCA
        if (u == v)
            return u;

        // Step 3: Lift both nodes simultaneously until they are right below their common ancestor
        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }

        // The direct parent (2^0 ancestor) is now the LCA
        return up[u][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
        vector<vector<int>>& queries) {
        // In a valid tree, Number of Nodes = Number of Edges + 1
        n = edges.size() + 1;

        // Precompute powers of 2 under modulo to answer individual path length math in O(1)
        pow2.resize(n + 1);
        pow2[0] = 1;
        for (int i = 1; i <= n; i++)
            pow2[i] = (pow2[i - 1] * 2) % mod;

        // Build the undirected graph
        adj.resize(n + 1);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // Initialize structures; index 0 serves as a safe dummy node pointing to itself (0)
        depth.resize(n + 1);
        up.assign(n + 1, vector<int>(LOG, 0));

        // Start DFS from root node '1' whose depth is 0
        depth[1] = 0;
        vector<pair<int, int>> st; // Stack stores: {current_node, parent_node}
        st.push_back({ 1, 0 });

        // Iterative DFS traversal to capture direct ancestors and depths without recursion limits
        while (!st.empty()) {
            auto [node, parent] = st.back();
            st.pop_back();

            // Store immediate parent (2^0 ancestor)
            up[node][0] = parent;

            for (int child : adj[node]) {
                if (child == parent)
                    continue;

                // Calculate depth before pushing child onto processing stack
                depth[child] = depth[node] + 1;
                st.push_back({ child, node });
            }
        }

        // Dynamic Programming: Compute binary lifting ancestor table
        // Relation: The (2^j)-th ancestor of 'node' is the (2^(j-1))-th ancestor of its (2^(j-1))-th ancestor.
        for (int j = 1; j < LOG; j++) {
            for (int node = 1; node <= n; node++) {
                up[node][j] = up[up[node][j - 1]][j - 1];
            }
        }

        vector<int> res;
        res.reserve(queries.size());

        // Process queries in O(LOG) time each
        for (const auto& q : queries) {
            int u = q[0];
            int v = q[1];

            int l = lca(u, v);

            // k = Total number of edges along the unique path between u and v
            int k = depth[u] + depth[v] - 2 * depth[l];

            // If path length is 0, weight is 0. Otherwise compute base metric 2^(k-1) % mod
            int ans = (k == 0) ? 0 : pow2[k - 1];
            res.push_back(ans);
        }

        return res;
    }
};