#include <iostream>
#include <vector>
using namespace std;

#define for_(i, s, e) for (ll i = s; i < (ll)e; i++)
#define for__(i, s, e) for (ll i = s; i > (ll)e; i--)
#define mod(x) ((x) % MOD)

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
const ll MOD = 1e9 + 7;  // 998244353;

int main() {
  ll n, m, k;
  cin >> n >> m >> k;

  // Initialize the matrices using vectors
  vvl a(n, vl(m)), b(m, vl(k)), c(n, vl(k));
  for_(i,0,n) {
    for_(j,0,m) {
      cin >> a[i][j];
    }
  }
  for_(i,0,m) {
    for_(j,0,k) {
      cin >> b[i][j];
    }
  }

  // Multiply the matrices
  for_(i,0,n) {
    for_(j,0,k) {
      c[i][j] = 0;
      for_(p,0,m) {
        c[i][j] += mod(a[i][p] * b[p][j]);
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
