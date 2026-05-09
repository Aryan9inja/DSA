#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Upper bound for values in nums — SPF sieve is built up to this limit
    static const int MAXV = 1'000'000;

    // Returns a reference to a lazily-initialized Smallest Prime Factor (SPF) table.
    // spf[i] = smallest prime that divides i (spf[i] == i means i is prime).
    // Built once via an Eratosthenes-style sieve and reused across all test cases.
    static const vector<int>& getSPF() {
        static const vector<int> spf = []() {
            vector<int> s(MAXV + 1);

            // Initialize every number as its own smallest prime factor
            for (int i = 0; i <= MAXV; i++) {
                s[i] = i;
            }

            // Sieve: for each prime i, mark its composites with i as their SPF
            for (long long i = 2; i * i < MAXV; i++) {
                if (s[i] == i) {                          // i is prime
                    for (long long j = i * i; j < MAXV; j += i) {
                        if (s[j] == j) {                  // not yet assigned a smaller factor
                            s[j] = i;
                        }
                    }
                }
            }
            return s;
        }();
        return spf;
    }

    // Returns true iff x is prime, using the precomputed SPF table
    bool isPrime(int x, const vector<int>& spf) {
        return x >= 2 && spf[x] == x;
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;   // already at the destination

        const auto& spf = getSPF();
        int maxi = *max_element(nums.begin(), nums.end());

        // Mark which primes actually appear as values in nums.
        // Only these primes are useful as "teleport hubs" between indices.
        vector<char> primeSeen(maxi + 1, false);
        for (int x : nums) {
            if (isPrime(x, spf)) {
                primeSeen[x] = true;
            }
        }

        // For every prime p that appears in nums, build a list of all indices
        // whose value shares p as a prime factor.
        // mp[p] = { indices i : p | nums[i] }
        unordered_map<int, vector<int>> mp;
        mp.reserve(n * 2);
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            while (x > 1) {
                int p = spf[x];                           // smallest prime factor of x
                // Only track primes that exist as direct values (i.e., valid hubs)
                if (p <= maxi && primeSeen[p]) {
                    mp[p].push_back(i);
                }
                while (x % p == 0) x /= p;               // divide out all copies of p
            }
        }

        // BFS over indices; each "step" is one of:
        //   1. Move to idx-1 or idx+1 (adjacent)
        //   2. Teleport to any index j where nums[idx] | nums[j] via a shared prime
        vector<int> dist(n, -1);

        // Prevents revisiting the same prime hub twice across the whole BFS,
        // ensuring each prime's adjacency list is expanded at most once — O(n) total
        vector<char> usedPrime(maxi + 1, false);

        queue<int> q;
        q.push(0);
        dist[0] = 0;

        while (!q.empty()) {
            int idx = q.front();
            q.pop();

            if (idx == n - 1) return dist[idx];   // reached destination

            // --- Neighbor 1: step left ---
            if (idx - 1 >= 0 && dist[idx - 1] == -1) {
                dist[idx - 1] = dist[idx] + 1;
                q.push(idx - 1);
            }

            // --- Neighbor 2: step right ---
            if (idx + 1 < n && dist[idx + 1] == -1) {
                dist[idx + 1] = dist[idx] + 1;
                q.push(idx + 1);
            }

            // --- Neighbor 3: prime-factor teleport ---
            // If nums[idx] is itself a prime hub and hasn't been expanded yet,
            // enqueue all indices that share this prime factor in one BFS level
            int x = nums[idx];
            if (x <= maxi && isPrime(x, spf) && !usedPrime[x]) {
                usedPrime[x] = true;              // mark hub as exhausted
                auto it = mp.find(x);
                if (it != mp.end()) {
                    for (int nextIdx : it->second) {
                        if (dist[nextIdx] == -1) {
                            dist[nextIdx] = dist[idx] + 1;
                            q.push(nextIdx);
                        }
                    }
                }
            }
        }

        return -1;  // unreachable (problem guarantees a path exists)
    }
};