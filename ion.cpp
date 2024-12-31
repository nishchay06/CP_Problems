#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> getCacheSize(vector<vector<int>> data, vector<int> queries)
{
    int n = size(data);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int a = data[i][0];
        int b = data[i][0] + data[i][1];
        mp[a]++;
        mp[b + 1]--;
    }
    int pre = 0;
    for (auto &[time, freq] : mp)
    {
        freq += pre;
        pre = freq;
    }

    for (auto &[time, freq] : mp)
    {
        cout << time << " " << freq << endl;
    }

    int q = size(queries);
    vector<int> ans;
    for (int i = 0; i < q; i++)
    {
        auto it = mp.upper_bound(queries[i]);
        it = prev(it);
        cout<<(*it).first<<endl;
        ans
    }
    return ans;
}

void solve()
{
    vector<vector<int>> data{
        {105231, 183}, {105334, 34}, {105198, 543}};
    vector<int> queries{
        105338, 105410};
    getCacheSize(data, queries);
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
