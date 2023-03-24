#include <bits/stdc++.h>
using namespace std;

#define for_(i,s,e) for (ll i=s;i<(ll)e; i++)
#define for__(i,s,e) for (ll i=s;i>(ll)e; i--)

typedef long long ll;


const ll MIN_DIM = 500;
const ll MAX_DIM = 501;

const ll MIN_VAL = -INT_MAX;
const ll MAX_VAL = INT_MAX;

int main() {
  // Seed the random number generator
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dim(MIN_DIM, MAX_DIM);
  uniform_int_distribution<> val(MIN_VAL, MAX_VAL);

  // Generate random values for n, m, and k
  ll n = dim(gen);
  ll m = dim(gen);
  ll k = dim(gen);

  // Print the values of n, m and k
  cout << n << " " << m << " " << k << endl;

  // Generate and print the n by m matrix
  for_(i,0,n) {
    for_(j,0,m)
      cout << val(gen) << " ";
    cout << endl;
  }

  // Generate and print the m by k matrix
  for_(i,0,m){ 
    for_(j,0,k) 
      cout << val(gen) << " ";
    cout << endl;
  }

  return 0;
}