#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int findPeakIndex(vector<int>& arr){
        int left = 0, right = arr.size()-1;

        while(left < right){
            int mid = left + (right - left)/2;

            if(arr[mid] < arr[mid+1]){
                left = mid+1;
            }
            else{
                right = mid;
            }
        }
        return left;
    }
    
public:
    int compareBitonicSums(vector<int>& nums) {
        int peakIndex = findPeakIndex(nums);

        long long ascending = 0;
        for(int i = 0; i <= peakIndex; i++){
            ascending += nums[i];
        }

        long long descending = 0;
        for(int i = peakIndex; i<nums.size(); i++){
            descending += nums[i];
        }

        if(ascending - descending > 0) return 0;
        else if(ascending - descending < 0) return 1;
        else return -1;
    }
};