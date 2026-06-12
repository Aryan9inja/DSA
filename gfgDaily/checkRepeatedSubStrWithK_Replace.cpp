#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool kSubstr(string& s, int k) {
        int n = s.length();

        // If the string length isn't a multiple of k, 
        // it can't be perfectly divided into k-length repetitions.
        if (n % k != 0) return false;

        unordered_map<string, int> chunk_counts;

        // Extract non-overlapping chunks of size k
        for (int i = 0; i < n; i += k) {
            string chunk = s.substr(i, k);
            chunk_counts[chunk]++;
        }

        // Analyze the unique chunks
        // If all chunks are already identical, 0 operations needed.
        if (chunk_counts.size() == 1) return true;

        // If there are more than 2 different types of chunks, 
        // 1 replacement won't be enough.
        if (chunk_counts.size() > 2) return false;

        // If there are exactly 2 unique chunks, one of them MUST 
        // appear exactly once so we can replace it.
        for (const auto& [chunk, count] : chunk_counts) {
            if (count == 1) {
                return true;
            }
        }

        return false;
    }
};