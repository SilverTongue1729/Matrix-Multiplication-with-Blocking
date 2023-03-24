#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

// #define for_(i,s,te) for (ll i=s,e=te; ((i<e)&&(s<e)) || ((i>e)&&(s>=e)); (s<e)?i++:i--)
#define for_(i,s,e) for (ll i=s;i<(ll)e; i++)
#define for__(i,s,e) for (ll i=s;i>(ll)e; i--)
#define mod(x) ((x) % MOD)
#define mid(x,y) midpoint(x,y)
#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define bg begin()
#define ed end()
#define sz(a) int(a.size())
#define all(x) (x).bg,(x).ed
#define allr(x) x.rbegin(),x.rend()
#define uniq(v) (v).erase(unique(all(v)),(v).end())
#define nl "\n"
#define _ << ' ' <<
#define pb emplace_back
#define MP make_pair
#define UB upper_bound
#define LB lower_bound
#define ff first
#define ss second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vpii> vvpii;
typedef vector<vpll> vvpll;
// typedef array<int, 2> ii;
const ll MOD = 1e9+7; // 998244353;

template<typename T1,typename T2> inline istream& operator >>(istream& in, pair<T1,T2>& a) { in>>a.ff>>a.ss; return in; }
template<typename T1,typename T2> inline ostream& operator <<(ostream& out, pair<T1,T2>& a) { out<<a.ff<<" "<<a.ss; return out; }
template<typename T> inline istream& operator >>(istream& in, vector<T>& v) { for_(i,0,sz(v)) in>>v[i]; return in; }
template<typename T> inline ostream& operator <<(ostream& out, vector<T>& v) { for_(i,0,sz(v)) out<<v[i]<<" "; return out; }
template<typename T> inline istream& operator >>(istream& in, set<T>& s) { string str; while (!sz(str)) getline(in,str); istringstream iss(str); T vs; while (iss>>vs) s.insert(vs); return in; }
template<typename T> inline ostream& operator <<(ostream& out, set<T>& s) { for (auto& vs : s) out<<vs<<" "; return out; }
template<typename T> inline istream& operator >>(istream& in, multiset<T>& s) { string str; while (!sz(str)) getline(in,str); istringstream iss(str); T vs; while (iss>>vs) s.insert(vs); return in; }
template<typename T> inline ostream& operator <<(ostream& out, multiset<T>& s) { for (auto& vs : s) out<<vs<<" "; return out; }
template<typename T1,typename T2> inline pair<T1,T2> operator +(pair<T1,T2>& l,pair<T1,T2>& r) { return {l.ff+r.ff,l.ss+r.ss}; }

template<typename T> inline void g_in(vector<vector<T>>& g, int m, int rev) { T x,y; for_(i,0,m){ cin>>x>>y; g[--x].pb(--y); if(rev) g[y].pb(x); } }
template<typename T1, typename T2> inline void g_in(vector<vector<pair<T1,T2>>>& g, int m, int rev) { T1 x,y; T2 c; for_(i,0,m){ cin>>x>>y>>c; g[--x].pb(--y,c); if(rev) g[y].pb(x,c); } } 

void read(auto&... args) { ((cin >> args), ...); }
void put(auto&&... args) { ((cout << args << " "), ...); }

#ifdef LOCAL
#include "/home/sriteja/Competitive Programming/Debugging/print.cpp"
#else
#define print(...) ((void)0)
#define printl(...) ((void)0)
#define cerr if(0) cerr
#endif

void solve(){
  

}

int main(){
#ifdef LOCAL
  freopen("/home/sriteja/Competitive Programming/Debugging/IO/output_01.txt","w",stderr);
#endif
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tt=1,ttt;
  // cin>>tt;
  printl(tt);
  ttt = tt;
  // auto start = chrono::steady_clock::now();
  while (tt--) {
    cerr<<"-------------- TC "<<ttt-tt<<" -----------------"<<nl;
    solve();
  };
  cerr<<"-------------- DONE -----------------"<<nl;
  
  string warning_string;
  while (getline(cin,warning_string).eof() == false || warning_string != ""){
    if (warning_string == "") continue;
    cerr<<"\n!!!!!! WARNING : UNREAD INPUT !!!!!!!\n"<<warning_string<<nl;
    while (getline(cin,warning_string)) cerr<<warning_string<<nl;
    break;
  }
  // auto end = chrono::steady_clock::now();
  // cerr << "Elapsed (s): " << chrono::duration_cast<chrono::milliseconds>(end - start).count()/1000.0 << endl;

  return 0;
}
