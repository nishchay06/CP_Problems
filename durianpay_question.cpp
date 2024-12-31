/*

Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.
Example 1:
Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true
Explanation: 
All possible ways to reach at index 3 with value 0 are: 
index 5 -> index 4 -> index 1 -> index 3 
index 5 -> index 6 -> index 4 -> index 1 -> index 3 
Example 2:
Input: arr = [4,2,3,0,3,1,2], start = 0
Output: true 
Explanation: One possible way to reach at index 3 with value 0 is: 
index 0 -> index 4 -> index 1 -> index 3


 [4,2,3,0,3,1,2], start = 5
  0 1 2 3 4 5 6
            ^

[4,2,3,0,3,1,2], start = 0
 0 1 2 3 4 5 6
 ^ ^   ^   ^
3, 0, 0, 3, 0, 0, 3
0  1  2  3  4  5  6
^        ^        ^

*/ 
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void getPaths(int i, vector<set<int>> &parent, vector<int> cr, int &startingInd) {
    
    cr.push_back(i);

    if(parent[i].size() == 0 && i == startingInd){
        for(int i = size(cr)-1; i >= 0; i--) {
            cout<<cr[i]<<" ";
        }
        cout<<endl;
        return;
    }


    for(auto &par : parent[i]) {
        getPaths(par,parent,cr, startingInd);
    }

    cr.pop_back();
}

void solve() {

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int startingIndex;
    cin >> startingIndex;

    vector<int> vis(n);
    vector<set<int>> parent(n,set<int>());

    queue<int> q;
    q.push(startingIndex);

    while(size(q)) {
        int crInd = q.front(); 
        q.pop();

        vis[crInd] = 1;

        int val = arr[crInd];
        int nextInd = crInd + val;
        int prevInd = crInd - val;

        if(nextInd >= 0 && nextInd < n) {
            if(parent[nextInd].find(crInd) != parent[nextInd].end()) continue;
            if(crInd != nextInd) {
                parent[nextInd].insert(crInd);
                q.push(nextInd);
            }
        }

        if(prevInd >= 0 && prevInd < n) {
            if(parent[prevInd].find(crInd) != parent[prevInd].end()) continue;
            if(crInd != prevInd) {
                parent[prevInd].insert(crInd);
                q.push(prevInd);
            }
        }
    }

    vector<int> endingInd;
    for(int i = 0; i < n; i++) {
        if(arr[i] == 0) {
            endingInd.push_back(i);
        }
    }

    for(auto i : endingInd) {
        vector<int> cr;
        getPaths(i,parent,cr,startingIndex);
    }
    
}

int main(){
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}