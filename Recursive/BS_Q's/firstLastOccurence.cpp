#include <iostream>
#include <vector>
using namespace std;

int firstOccurence(vector<int>& arr, int s, int e, int k) {
    if (s > e) return -1;

    int mid = s + (e - s) / 2;
    if (arr[mid] == k) {
        int left = firstOccurence(arr, s, mid - 1, k);
        return (left != -1) ? left : mid;
    }
    else if (arr[mid] > k) {
        return firstOccurence(arr, s, mid - 1, k);
    }
    else {
        return firstOccurence(arr, mid + 1, e, k);
    }
}

int lastOccurence(vector<int>& arr, int s, int e, int k) {
    if (s > e) return -1;

    int mid = s + (e - s) / 2;
    if (arr[mid] == k) {
        int right = lastOccurence(arr, mid + 1, e, k);
        return (right != -1) ? right : mid;
    }
    else if (arr[mid] > k) {
        return lastOccurence(arr, s, mid - 1, k);
    }
    else {
        return lastOccurence(arr, mid + 1, e, k);
    }
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k) {
    pair<int, int> ans;
    ans.first = firstOccurence(arr, 0, n - 1, k);
    ans.second = lastOccurence(arr, 0, n - 1, k);
    return ans;
}

int main() {
    vector<int> arr;
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(5);
    cout << firstAndLastPosition(arr, 4, 8).first << " ";
    cout << firstAndLastPosition(arr, 4, 8).second;

    return 0;
}