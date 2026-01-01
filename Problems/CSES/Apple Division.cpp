#include <utility>
#ifndef ONPC
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>
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

int a[20];
i64 ans;
void solve() {
  i64 n;
  cin >> n;
  for (i64 i = 0; i < n; i++) {
    cin >> a[i];
  }
  i64 total = accumulate(a, a + n, 0LL);

  set<i64> achievable;

  for (i64 mask = 0; mask < (1LL << n); mask++) {
    i64 sum = 0;
    for (i64 i = 0; i < n; i++) {
      if (mask & (1 << i))
        sum += a[i];
    }
    achievable.insert(sum);
  }

  ans = 4e18;
  for (auto i : achievable) {
    if (i > total / 2)
      continue;
    ans = min(ans, total - 2 * i);
  }
  cout << ans << '\n';
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