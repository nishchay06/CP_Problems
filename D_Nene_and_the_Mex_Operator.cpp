#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <vector>
#include <cstring>
#include <numeric>
#include <cassert>
#include <iomanip>
using namespace std;

using str =  string;
using ll  =  long long;
using ld  =  long double;
using vl  =  vector<ll>;
using vs  =  vector<str>;
using vpl =  vector<pair<ll,ll>>;
using sll =  set<ll>;
using pll =  pair<ll,ll>;
#define mset multiset
#define umap unordered_map

/*#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using iset = tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>;
#define sAt(s,x) s.find_by_order(x) //Returns xth Iterator
#define sPos(s,x) s.order_of_key(x) //Return lower bound index*/

#define pus push_back
#define pub pop_back
#define in  insert
#define ff  first
#define ss  second

#define sz(x)     ((ll)(x).size())
#define all(x)    x.begin(),x.end()
#define srt(x)    sort(all(x))
#define srtd(x)   sort(x.rbegin(),x.rend())
#define rev(x)    reverse(all(x));
#define nextP(v)  next_permutation(all(v))
#define Vmax(x)   (*max_element(all(x)))
#define Vmin(x)   (*min_element(all(x)))
#define Vsum(x)   accumulate(all(x),0ll)
#define lowB(v,x) (lower_bound(all(v),x)-v.begin())
#define upB(v,x)  (upper_bound(all(v),x)-v.begin())
#define cntB(x)   (__builtin_popcountll(x))  
#define cntC(s,x) ll(count(all(s),x))

#define For(n)      for (ll i = 0; i < n; i++)
#define ForR(n)     for (ll i = n-1; i >= 0; i--)
#define Forj(n)     for (ll j = 0; j < n; j++)
#define For1(n)     for (ll i = 1; i < n; i++)
#define Forl(x,y,z) for (ll x = y; x < z; x++)

#define nl       cout << "\n";
#define endl     "\n";
#define ya       cout << "Yes\n"
#define na       cout << "No\n"
#define prs(n)   fixed << setprecision(n)
#define dbg(x)   cout << #x << " = " << x << endl;
#define inpt(v)  For(sz(v)) cin >> v[i];
#define prt(v)  {for(auto &x:v) cout << x << ' '; nl}

const int M = 1e9+7; /*998244353;*/
const int N = 262144;
const ld pi = 3.141592653589793238;
const ll INF = 2e18;

ll power(ll a,ll b) {ll r=1; while(b) {if(b&1) r=(r*a)%M; a=(a*a)%M; b/=2;} return r;}
vl sieve(ll n) {vl a(n+1,1),v; a[0]=a[1]=0; Forl(i,2,n+1) if(a[i]) {v.pus(i); for(ll j=2*i; j <=n; j+=i) a[j]=0;} return a;}
vl divsr(ll n) {vl a(n+1,1); For(n+1) a[i]=i; Forl(i,2,n+1) if(a[i]==i) {for(ll j=2*i; j<=n; j+=i) a[j]=i;} return a;}
vl fac(ll n) {vl v(n+1,1); Forl(i,2,n+1) v[i] = (v[i-1]*i)%M; return v;}

ll n, x, y, z, a, b, c, d, k, q, m; str s; 
 
//---------------------------------------------------------------------------------------------------------------------------------
//Let's Go :)

vpl cal(ll l, ll r){
    vpl ans;
    vl seted(n + 1);
    ans.pus({l, l});
    seted[l] = sz(ans);
    for (ll i = l + 1; i <= r; i++){
        ans.pus({l, i});
        for (ll j = 0; j < seted[i - 1]; j++)
            ans.pus(ans[j]);
        seted[i] = sz(ans);
    }
    ans.pus({l, r});
    return ans;
}

void solve(){
    cin >> n;
    vl v(n), t;
    vpl ans;
    ll val = 0;
    inpt(v);
    For((1 << n)){
        vl curr(n);
        Forj(n) if ((1 << j) & i) curr[j] = 1;
        ll currval = 0, cnt = 0;
        Forj(n){
            if (curr[j]){
                currval += v[j] + cnt * cnt;
                cnt = 0;
            }
            else cnt++;
        }
        currval += cnt * cnt;
        if (currval >= val){
            val = currval;
            t = curr;
        }
    }
    t.pus(1);
    For(n + 1){
        if (t[i])
            continue;
        for (ll j = i + 1; j <= n; j++){
            if (t[j]){
                for (ll k = i + 1; k < j; k++)
                    if (v[k])
                        ans.pus({k, k});
                if (v[i] == 0)
                    ans.pus({i, i});
                vpl temp = cal(i, j - 1);
                for (auto &pr : temp)
                    ans.pus(pr);
                i = j;
                break;
            }
        }
    }
    cout << val << ' ' << sz(ans);
    nl for (auto &pr : ans) cout << pr.ff + 1 << ' ' << pr.ss + 1 << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}