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
vl tin, tout, depth;
vvl parent;
vvl al;
ll gtime = 0;
ll lim;
void dfs(ll i, ll p = 0){
    tin[i] = gtime++;
    if(p) depth[i] = depth[p]+1;
    parent[i][0] = p;
    for(int k = 1; k <= lim; k++){
        parent[i][k] = parent[parent[i][k-1]][k-1];
    }
    for(auto& ch : al[i]){
        if(ch != p){
            dfs(ch,i);
        }
    }
    tout[i] = gtime++;
}

bool isAn(ll x, ll y){
    return tin[x] <= tin[y] and tout[x] >= tout[y];
}

ll getkpar(ll x, ll k){
    for(ll i = 0; i <= lim; i++){
        if(k & (1 << i)){
            x = parent[x][i];
            if(x == 0) break;
        }
    }
    return x;
}

ll lca(int a, int b){
    if(isAn(a,b)) return a;
    if(isAn(b,a)) return b;
    if(depth[a] < depth[b]){
        return lca(b,a);
    }
    int diff = depth[a]-depth[b];
    a = getkpar(a,diff);
    for(int i = lim; i >= 0; i--){
        if(parent[a][i] != parent[b][i]){
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return parent[a][0];
}

void dfs2(ll i, vl& val, ll p = 0){
    for(auto& ch : al[i]){
        if(ch != p){
            dfs2(ch,val,i);
            val[i] += val[ch];
        }
    }
}

void solve(){
    ll n,m;
    cin>>n>>m;
    al.resize(n+1);
    For(n-1){
        ll u,v;
        cin>>u>>v;
        al[u].pus(v);
        al[v].pus(u);
    }
    tin.resize(n+1);
    tout.resize(n+1);
    depth.resize(n+1);
    lim = ceil(log2(n));
    parent.resize(n+1,vl(lim+1));
    dfs(1);
    vl val(n+1);
    For(m){
        ll s,e;
        cin>>s>>e;
        if(depth[s] < depth[e]) swap(s,e);
        ll par = lca(s,e);
        if(par == e){
            val[s] += 1;
            if(parent[par][0]) val[parent[par][0]] -= 1;
        }
        else{
            val[s] += 1;
            if(parent[par][0]) val[parent[par][0]] -= 1;
            val[e] += 1;
            val[par] -= 1;
        }
    }
    dfs2(1,val);
    For1(n+1) cout<<val[i]<<" ";
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