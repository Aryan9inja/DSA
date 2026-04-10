#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        // O(n^3)
        /*
        int n = nums.size();
        int ans = INT_MAX;
        for(int i = 0; i <= n-3; i++){
            for(int j = i+1; j <= n-2; j++){
                for(int k = j+1; k <= n-1; k++){
                    if(nums[i] == nums[j] && nums[j] == nums[k]){
                        int temp = abs(i-j) + abs(j-k) + abs(k-i);
                        ans = min(ans, temp);
                    }
                }
            }
        }
        if(ans == INT_MAX) return -1;
        return ans;
        */

        // O(n)
        /*
        i < j < k
        then -> abs(i-j) + abs(j-k) + abs(k-i)
        becomes -> j-i + k-j + k-i
        becomes -> 2k - 2i
        that is -> 2*(last_index - first_index)
        */
        int n = nums.size();
        unordered_map<int, pair<int, int>> mp;
        int mini = INT_MAX;

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            if (mp.find(num) == mp.end()) {
                mp[num] = {-1, i};
            } else {
                auto& [prev, last] = mp[num];

                if (prev != -1) {
                    int a = prev, b = last, c = i;
                    int dist = 2 * (max({a, b, c}) - min({a, b, c}));
                    mini = min(mini, dist);
                }

                prev = last;
                last = i;
            }
        }

        return mini == INT_MAX ? -1 : mini;
    }
};