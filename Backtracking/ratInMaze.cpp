#include <bits/stdc++.h> 
using namespace std;

bool isSafe(int newX, int newY, vector<vector<bool>> &visited,
    vector<vector<int>> &arr, int n){
    if(newX>=0 && newX<n && newY>=0 && newY<n &&
    visited[newX][newY]!=1 && arr[newX][newY]==1){
        return true;
    }
    return false;
}

void solve(int x, int y, vector<vector<int>> &arr,
    int n, vector<vector<bool>> &visited, string &path, vector<string> &ans){
    if(x==n-1 && y==n-1){
        ans.push_back(path);
        return;
    }

    // D,L,R,U
    int xMov[4]={x+1,x,x,x-1};
    int yMov[4]={y,y-1,y+1,y};
    char mov[4]={'D','L','R','U'};

    for(int i=0;i<4;i++){
        visited[x][y]=1;
        if(isSafe(xMov[i],yMov[i],visited,arr,n)){
            path.push_back(mov[i]);
            solve(xMov[i],yMov[i],arr,n,visited,path,ans);
            path.pop_back();
        }
        visited[x][y]=0;
    }
}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool>(n,0));
    string path="";

    if(arr[0][0]==0) return ans;

    solve(0,0,arr,n,visited,path,ans);

    return ans;
}