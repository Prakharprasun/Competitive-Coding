#include <utility>
#ifndef ONPC
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

// Debugging macro
#ifdef ONPC
#include "DEBUG.h"
#else
#define debug(...) // No-op for production
#endif

string s;
map<char, i64> freq;
i64 permutations;

i64 factorials[9];
i64 fact(int n) {
  if (factorials[n] != 0)
    return factorials[n];
  if (n == 0)
    return 1;
  factorials[n] = n * fact(n - 1);
  return factorials[n];
}

void solve() {
  cin >> s;
  for (auto it : s) {
    freq[it]++;
  }

  i64 denominator = 1;
  for (auto it : freq) {
    denominator *= fact(it.second);
  }

  permutations = fact(s.size()) / denominator;

  cout << permutations << '\n';

  set<string> arrangements;

  for (int i = 0; i < permutations; i++) {
    next_permutation(s.begin(), s.end());
    arrangements.insert(s);
  }

  for (auto &it : arrangements) {
    cout << it << '\n';
  }
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef ONPC
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif

  cout << fixed << setprecision(15);
  int t = 1;
  // cin >> t;
  while (t--)
    solve();
}