#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
    int n = size(nums), q = size(queries);
    vector<int> ans;
    vector<vector<int>> dp(n,vector<int>(n,-1));
    for(int i = 0; i < n; i++) {
        dp[0][i] = nums[i];
    }
    for(int i = 1; i < n; i++) {
        for(int j = 0 ; j+1 < n; j++) {
            if(dp[i-1][j] != -1 && dp[i-1][j+1] != -1) {
                dp[i][j] = dp[i-1][j]^dp[i-1][j+1];
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout<<dp[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 1; i < n; i++) {
        for(int j = 0 ; j+1 < n; j++) {
            if(dp[i-1][j] != -1 && dp[i-1][j+1] != -1) {
                dp[i][j] = max({dp[i][j],dp[i-1][j],dp[i-1][j+1]});
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout<<dp[i][j] << " ";
        }
        cout << endl;
    }
    for(auto& q : queries) {
        ans.push_back(dp[q[1]-q[0]][q[0]]);
    }
    return ans;
}

void solve() {
    vector<int> nums;
    vector<vector<int>> queries;
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        nums.push_back(val);
    }
    for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        queries.push_back({a,b});
    }
    vector<int> ans = maximumSubarrayXor(nums,queries);
    for(auto& it : ans) cout<<it<<" ";
    cout<<endl;
}

int main(){
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}

/*

00 11 22 33 
01 12 23
02 13
03

0,0 -> 00
0,1 -> 11
0,2 -> 22
0,3 -> 33
1,0 -> 01
1,1 -> 12
1,2 -> 23
2,0 -> 02
2,1 -> 13
3,0 -> 03

1 2 3 4 5 6
1,2 2,3 3,4 4,5 5,6
1,3 2,4 3,5 4,6
1,2,3,4 2,3,4,5 3,4,5,6
1,5 2,6
1,2,5,6

*/ 