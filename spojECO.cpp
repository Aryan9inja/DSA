#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isAnswer(const vector<int> &arr, int M, int mid)
{
    long long currentCut = 0;
    for (int height : arr)
    {
        if (height > mid)
        {
            currentCut += (height - mid);
        }
    }
    return currentCut >= M;
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> arr(N);
    int maxHeight = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        maxHeight = max(maxHeight, arr[i]);
    }

    int s = 0, e = maxHeight, ans = 0;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (isAnswer(arr, M, mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }

    cout << ans << endl;
    return 0;
}
