#include <bits/stdc++.h>
using namespace std;

using str = string;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vb = vector<bool>;
using vvl = vector<vl>;
using vs = vector<str>;
using vpl = vector<pair<ll, ll>>;
using sll = set<ll>;
using pll = pair<ll, ll>;
#define mset multiset

/*#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using iset = tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>;
#define sAt(s,x) s.find_by_order(x) //Returns xth Iterator
#define sPos(s,x) s.order_of_key(x) //Return lower bound index*/

#define pus push_back
#define pub pop_back
#define in insert
#define ff first
#define ss second

#define sz(x) ((ll)(x).size())
#define all(x) x.begin(), x.end()
#define srt(x) sort(all(x))
#define srtd(x) sort(x.rbegin(), x.rend())
#define rev(x) reverse(all(x));
#define Vmax(x) *max_element(all(x))
#define Vmin(x) *min_element(all(x))
#define Vsum(x) accumulate(all(x), 0ll)
#define lowB(v, x) lower_bound(all(v), x) - v.begin()
#define upB(v, x) upper_bound(all(v), x) - v.begin()
#define cntB(x) __builtin_popcountll(x)
#define cntC(s, x) ll(count(all(s), x))

#define For(n) for (ll i = 0; i < n; i++)
#define ForR(n) for (ll i = n - 1; i >= 0; i--)
#define Forj(n) for (ll j = 0; j < n; j++)
#define For1(n) for (ll i = 1; i < n; i++)
#define Forl(x, y, z) for (ll x = y; x < z; x++)

#define done return;
#define nl cout << "\n";
#define endl "\n";
#define ya cout << "YES\n";
#define na cout << "NO\n";
#define prs(n) fixed << setprecision(n)
#define dbg(x) cout << #x << " = " << x << endl;
#define inpt(v) For(sz(v)) cin >> v[i];
#define prt(v)                \
    {                         \
        for (auto &x : v)     \
            cout << x << ' '; \
        nl                    \
    }

const int M = 1e9 + 7;
// const int M = 998244353;
const int N = 2e5 + 5;
const ld pi = 3.141592653589793238;
const ll INF = 2e18;

ll power(ll a, ll b)
{
    ll r = 1;
    while (b)
    {
        if (b & 1)
            r = (r * a) % M;
        a = (a * a) % M;
        b /= 2;
    }
    return r;
}
vl sieve(ll n)
{
    vl a(n + 1, 1), v;
    a[0] = a[1] = 0;
    Forl(i, 2, n + 1) if (a[i])
    {
        v.pus(i);
        for (ll j = i * i; j <= n; j += i)
            a[j] = 0;
    }
    return a;
}
vl divsr(ll n)
{
    vl a(n + 1, 1);
    For(n + 1) a[i] = i;
    Forl(i, 2, n + 1) if (a[i] == i)
    {
        for (ll j = 2 * i; j <= n; j += i)
            a[j] = i;
    }
    return a;
}
vl fac(ll n)
{
    vl v(n + 1, 1);
    Forl(i, 2, n + 1) v[i] = (v[i - 1] * i) % M;
    return v;
}
ll gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

/* stuff you should look for
 * check for int overflow
 * check for time complexity (make sure not to TLE)
 * special case (n = 1)
 * make sure to initialize everything (array)
 * don't be lazy, write out your thought and code it out
 */

//-------------------------------------------------------------------------------------------------------------------------------------
/*
You are given a 2D matrix grid of size m x n. In one operation, you can change the value of any cell to any non-negative number. You need to perform some operations such that each cell grid[i][j] is:

Equal to the cell below it, i.e. grid[i][j] == grid[i + 1][j] (if it exists).
Different from the cell to its right, i.e. grid[i][j] != grid[i][j + 1] (if it exists).
Return the minimum number of operations needed.

Input: grid = [[1,0,2],[1,0,2]]
Output: 0
Explanation:
All the cells in the matrix already satisfy the properties.

Input: grid = [[1,1,1],[0,0,0]]
Output: 3
Explanation:
The matrix becomes [[1,0,1],[1,0,1]] which satisfies the properties, by doing these 3 operations:
Change grid[1][0] to 1.
Change grid[0][1] to 0.
Change grid[1][2] to 1.

Constraints:
1 <= n, m <= 1000
0 <= grid[i][j] <= 9
*/

int minimumOperations(vector<vector<int>> &grid){
    int n = grid.size(), m = grid[0].size();
    // dp[i][j] = minimum number of operations needed to satisfy the properties for the first i columns and the last column has value j
    vector<vector<int>> dp(m, vector<int>(10, 1e9));
    // dp[i][j] = min(dp[i-1][k]) + cnt(grid[i][j] != k) for k = 0 to 9
    for (int i = 0; i < m; i++){
        // Base case
        for (int k = 0; k < 10; k++){
            // Count of cells that are not equal to k
            int cnt = 0;
            for (int j = 0; j < n; j++){
                if (grid[j][i] != k)
                    cnt += 1;
            }
            // If i = 0, then dp[i][k] = cnt
            dp[i][k] = cnt;
            if (i > 0){
                // If i > 0, then dp[i][k] = min(dp[i-1][j]) + cnt
                int mn = 1e9;
                // Find the minimum number of operations needed to satisfy the properties for the first i-1 columns
                for (int j = 0; j < 10; j++){
                    // If the last column has value k, then the last column of the previous column should not have value j
                    if (k != j){
                        mn = min(dp[i - 1][j], mn);
                    }
                }
                // Add the count of cells that are not equal to k
                dp[i][k] += mn;
            }
        }
    }
    // Find the minimum number of operations needed to satisfy the properties for the first m columns
    int ans = 1e9;
    for (int i = 0; i < 10; i++){
        // The last column has value i 
        ans = min(ans, dp[m - 1][i]);
    }
    return ans;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    cout << minimumOperations(grid) << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--){
        solve();
    }
    return 0;
}