#include <bits/stdc++.h>
using namespace std;

// #define for_(i,s,te) for (ll i=s,e=te; ((i<e)&&(s<e)) || ((i>e)&&(s>=e)); (s<e)?i++:i--)
#define for_(i,s,e) for (ll i=s;i<(ll)e; i++)
#define for__(i,s,e) for (ll i=s;i>(ll)e; i--)
#define mod(x) ((x) % MOD)

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
const ll MOD = 1e9+7; // 998244353;

const ll BLOCK_SIZE = 16;  // block size

int main() {
  ll n, m, k;
  cin >> n >> m >> k;

  // Initialize the matrices
  vvl a(n, vl(m));
  vvl b(m, vl(k));
  for_(i,0,n) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for_(i,0,m) {
    for_(j,0,k) {
      cin >> b[i][j];
    }
  }

  // Multiply the matrices using blocking
  vvl c(n, vl(k));
  for (ll ii = 0; ii < n; ii += BLOCK_SIZE) {
    for (ll jj = 0; jj < k; jj += BLOCK_SIZE) {
      for (ll kk = 0; kk < m; kk += BLOCK_SIZE) {
        // multiply the blocks
        for (ll i = ii; i < min(ii + BLOCK_SIZE, n); i++) {
          for (ll j = jj; j < min(jj + BLOCK_SIZE, k); j++) {
            for (ll p = kk; p < min(kk + BLOCK_SIZE, m); p++) {
              c[i][j] += mod(a[i][p] * b[p][j]);
            }
          }
        }
        
      }
    }
  }

  // Print the result
  cout << n << " " << k << endl;
  for_(i,0,n) {
    for_(j,0,k) {
      cout << mod(c[i][j]+MOD) << " ";
    }
    cout << endl;
  }

  return 0;
}