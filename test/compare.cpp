#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

#define for_(i, s, e) for (ll i = s; i < (ll)e; i++)
#define for__(i, s, e) for (ll i = s; i > (ll)e; i--)

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

int main(int argc, char *argv[]) {
  if (argc < 3) {
    cerr << "Usage: " << argv[0] << " file1 file2" << endl;
    return 1;
  }

  ifstream file1(argv[1]), file2(argv[2]);

  // Read the first matrix from file1
  ll n1, m1;
  file1 >> n1 >> m1;
  vvl a(n1, vl(m1));
  for_(i, 0, n1) {
    for_(j, 0, m1) {
      file1 >> a[i][j];
    }
  }

  // Read the second matrix from file2
  ll n2, m2;
  file2 >> n2 >> m2;
  vvl b(n2, vl(m2));
  for_(i, 0, n2) {
    for_(j, 0, m2) {
      file2 >> b[i][j];
    }
  }

  // Check if the two matrices match
  if (n1 != n2 || m1 != m2) {
    cout << "FAILED" << endl;
    return 0;
  }
  for_(i, 0, n1) {
    for_(j, 0, m1) {
      if (a[i][j] != b[i][j]) {
        cout << "FAILED" << endl;
        return 0;
      }
    }
  }

  cout << "PASSED" << endl;
  return 0;
}
