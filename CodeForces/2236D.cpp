#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    
    vector<long long> a(n);
    map<long long, int> freq;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }
    
    // Extract unique elements in sorted order
    vector<long long> unique_a;
    for (auto const& [val, count] : freq) {
        unique_a.push_back(val);
    }
    
    int m = unique_a.size();
    // dp[i] will store true if moving FROM unique_a[i] is a Winning position
    vector<bool> dp(m, false);
    
    // Track the value of the closest losing position found so far to the right
    // Initialize with a value out of bounds
    long long closest_losing_val = -1; 
    
    // Process from right to left
    for (int i = m - 1; i >= 0; i--) {
        long long current_val = unique_a[i];
        
        // Check if we can reach an independent losing state to the right
        if (closest_losing_val != -1 && closest_losing_val - current_val <= k) {
            dp[i] = true;
        } else {
            // If there's no losing state reachable to the right, 
            // check if we can use the duplicates of the current element.
            // If freq[current_val] is even, the game theoretic value changes.
            if (freq[current_val] % 2 == 0) {
                dp[i] = true;
            } else {
                dp[i] = false;
            }
        }
        
        // Update the closest losing position
        if (!dp[i]) {
            closest_losing_val = current_val;
        }
        
        // If the next element to the left is too far away, 
        // the current losing tracking cannot cross the gap.
        if (i > 0 && unique_a[i] - unique_a[i-1] > k) {
            closest_losing_val = -1; 
        }
    }
    
    // Arseniy wins if there is at least one element he can pick 
    // that leaves Egor in a winning position (dp[i] == true)
    bool egorWins = false;
    for (int i = 0; i < m; i++) {
        if (dp[i]) {
            egorWins = true;
            break;
        }
    }
    
    if (egorWins) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}