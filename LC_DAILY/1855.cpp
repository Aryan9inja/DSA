#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        // Binary Search (O(n*log(m)))
        /*
        int ans = 0;
    
        int n = min(nums1.size(), nums2.size());
        for(int i=0; i<n; i++){
            if(nums2[i] >= nums1[i]){
                int start = i;
                int end = nums2.size()-1;

                while(start <= end){
                    int mid = start + (end-start)/2;

                    if(nums2[mid] >= nums1[i]){
                        ans = max(ans, mid-i);
                        start = mid+1;
                    }
                    else{
                        end = mid - 1;
                    }
                }
            }
        }
        return ans;
        */

        // Two Pointer (O(n+m))
        int ans = 0;
        int i = 0, j = 0;
        int n1 = nums1.size(), n2 = nums2.size();

        while (i < n1 && j < n2) {
            if (nums2[j] >= nums1[i]) {
                // Valid pair — record distance and try to extend j
                ans = max(ans, j - i);
                j++;
            } else {
                // nums2[j] too small — move i forward
                // but ensure j never falls behind i
                if (j == i) j++;
                i++;
            }
        }

        return ans;
    }
};