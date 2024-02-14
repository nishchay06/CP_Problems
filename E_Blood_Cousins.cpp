#include<bits/stdc++.h>
using namespace std;
 
using str =  string;
using ll  =  long long;
using ld  =  long double;
using vl  =  vector<ll>;
using vb  =  vector<bool>;
using vvl  =  vector<vl>;
using vs  =  vector<str>;
using vpl =  vector<pair<ll,ll> >;
using sll =  set<ll>;
using pll =  pair<ll,ll>;
#define mset multiset
 
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
#define Vmax(x)   *max_element(all(x))
#define Vmin(x)   *min_element(all(x))
#define Vsum(x)   accumulate(all(x),0ll)
#define lowB(v,x) lower_bound(all(v),x)-v.begin()
#define upB(v,x)  upper_bound(all(v),x)-v.begin() 
#define cntB(x)   __builtin_popcountll(x)  
#define cntC(s,x) ll(count(all(s),x))
 
#define For(n)      for (ll i = 0; i < n; i++)
#define ForR(n)     for (ll i = n-1; i >= 0; i--)
#define Forj(n)     for (ll j = 0; j < n; j++)
#define For1(n)     for (ll i = 1; i < n; i++)
#define Forl(x,y,z) for (ll x = y; x < z; x++)
 
#define done     return;
#define nl       cout << "\n";
#define endl     "\n";
#define ya       cout << "YES\n";
#define na       cout << "NO\n";
#define prs(n)   fixed << setprecision(n)
#define dbg(x)   cout << #x << " = " << x << endl;
#define inpt(v)  For(sz(v)) cin >> v[i];
#define prt(v)  {for(auto &x:v) cout << x << ' '; nl}
 
const int M = 1e9+7;
// const int M = 998244353;
const int N = 2e5+5;
const ld pi = 3.141592653589793238;
const ll INF = 2e18;
 
ll power(ll a,ll b){ll r=1; while(b) {if(b&1) r=(r*a)%M; a=(a*a)%M; b/=2;} return r;}
vl sieve(ll n) {vl a(n+1,1),v; a[0]=a[1]=0; Forl(i,2,n+1) if(a[i]) {v.pus(i); for(ll j=i*i; j <=n; j+=i) a[j]=0;} return a;}
vl divsr(ll n) {vl a(n+1,1); For(n+1) a[i]=i; Forl(i,2,n+1) if(a[i]==i) {for(ll j=2*i; j<=n; j+=i) a[j]=i;} return a;}
vl fac(ll n) {vl v(n+1,1); Forl(i,2,n+1) v[i] = (v[i-1]*i)%M; return v;}
ll gcd(ll a, ll b){if(b == 0){return a;}return gcd(b,a%b);}
 
// ll n, x, y, z, a, b, c, d, k, q, m; str s; 
 
/* stuff you should look for 
    * check for int overflow
    * check for time complexity (make sure not to TLE)
    * special case (n = 1)
    * make sure to initialize everything (array)
    * don't be lazy, write out your thought and code it out
*/
 
//-------------------------------------------------------------------------------------------------------------------------------------

vvl al;
vl inTime, outTime;
int Time;
vvl parent;
vl depth;
vvl lst;

void dfs(ll i, ll p = -1){
    inTime[i] = Time++;
    (p != -1) ? depth[i] = 1+depth[p] : depth[i] = 0;
    lst[depth[i]].pus(inTime[i]);
    parent[0][i] = p;
    for(auto& ch : al[i]){
        if(ch != p) dfs(ch,i);
    }
    outTime[i] = Time++;
}

void binLift(){
    ll n = parent[0].size();
    for(int k = 1; k <= log2(n); k++){
        for(int i = 0; i < n; i++){
            if(parent[k-1][i] != -1){
                parent[k][i] = parent[k-1][parent[k-1][i]];
            }
        }
    }
}

ll getKthParent(ll x, ll k){
    ll n = parent[0].size();
    for(int i = 0; i <= log2(n); i++){
        if(k & (1 << i)){
            x = parent[i][x];
            if(x == -1){
                break;
            }
        }
    }
    return x;
}

void solve(){
    ll n;
    cin >> n;
    vl root;
    al.resize(n);
    For(n){
        ll p;
        cin >> p;
        if(p == 0) root.pus(i);
        else {
            al[i].pus(p-1);
            al[p-1].pus(i);
        }
    }
    parent.resize(log2(n)+1,vl(n,-1));
    inTime.resize(n);
    outTime.resize(n);
    depth.resize(n);
    lst.resize(n,vl());
    Time = 0;
    for(auto& i : root) dfs(i);
    binLift();
    ll m;
    cin >> m;
    For(m){
        ll v,p;
        cin >> v >> p;
        ll ancs = getKthParent(v-1,p);
        if(ancs == -1){
            cout<<0<<" ";
        }
        else{
            ll up = upB(lst[depth[v-1]],outTime[ancs]);
            ll lo = lowB(lst[depth[v-1]],inTime[ancs]);
            ll num = ((up-1)-lo+1)-1;
            cout<<num<<" ";
        }
    }
    nl
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}