#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int> &arr, int M, int mid)
{

    int dish = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        int time = 0;
        int m = 1;
        while (time + (m * arr[i]) <= mid)
        {
            time += m * arr[i];
            dish++;
            if (dish == M)
                return true;
            m++;
        }
    }
    return false;
}

int main()
{
    int testCases;
    cin >> testCases;

    int Pratas;
    int Cooks;
    int temp;
    vector<int> CookRanks;

    for (int i = 0; i < testCases; i++)
    {
        CookRanks.clear();
        int MaxRank = -1;
        cin >> Pratas;
        cin >> Cooks;
        for (int j = 0; j < Cooks; j++)
        {
            cin >> temp;
            CookRanks.push_back(temp);
            MaxRank = max(MaxRank, temp);
        }

        int s = 1;
        int e = MaxRank * Pratas * (Pratas + 1) / 2;
        int ans = 0;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (isPossible(CookRanks, Pratas, mid))
            {
                ans = mid;
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
