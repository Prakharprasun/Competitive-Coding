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

// Debugging
#ifdef ONPC
#include "DEBUG.h"
#else
#define debug(...) // No-op for contest
#endif

void precompute() {}

void solve() {}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef ONPC
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif

  cout << fixed << setprecision(15);
  precompute();
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}