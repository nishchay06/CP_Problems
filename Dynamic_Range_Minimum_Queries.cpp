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
class SegmentTree{
public:
    ll n;
    vl tree;
    SegmentTree(vl& a){
        n = sz(a);
        tree.assign(4*n,0);
        buildTree(1,0,n-1,a);
    }
 
    void buildTree(ll ind, ll l, ll r, vl& a){
        if(r < l) return;
        if(r == l){
            tree[ind] = a[l];
            return;
        }
        ll mid = (r+l)/2;
        buildTree(2*ind,l,mid,a);
        buildTree(2*ind+1,mid+1,r,a);
        tree[ind] = min(tree[2*ind],tree[2*ind+1]);
    }
 
    void upd(ll idx, ll val){
        updTree(1,0,n-1,idx,val);
    }
 
    void updTree(ll ind, ll l, ll r, ll idx, ll val){
        if(l > r) return;
        if(l == r){
            if(l == idx){
                tree[ind] = val;
            }
            return;
        }
        ll mid = (r+l)/2;
        updTree(2*ind,l,mid,idx,val);
        updTree(2*ind+1,mid+1,r,idx,val);
        tree[ind] = min(tree[2*ind],tree[2*ind+1]);
    }
    int calc(ll l, ll r){
        return getAns(1,l,r,0,n-1);
    }
 
    ll getAns(ll ind, ll l, ll r, ll l_lim, ll r_lim){
        if(l_lim > r_lim) return INT_MAX;
        if(l > r_lim or r < l_lim) return INT_MAX;
        if(l <= l_lim and r >= r_lim) return tree[ind];
        if(l_lim == r_lim){
            return tree[ind];
        }
        ll mid = (r_lim+l_lim)/2;
        return min(getAns(2*ind,l,r,l_lim,mid),(getAns(2*ind+1,l,r,mid+1,r_lim)));
    }
};
void solve(){
    ll n,q;
    cin >> n >> q;
    vl a(n);
    inpt(a);
    SegmentTree s1 = SegmentTree(a);
    For(q){
        ll t;
        cin >> t;
        if(t == 1){
            ll k,u;
            cin >> k >> u;
            k--;
            s1.upd(k,u);
        }
        else{
            ll l,r;
            cin >> l >> r;
            l--, r--;
            cout<<s1.calc(l,r);nl
        }
    }
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