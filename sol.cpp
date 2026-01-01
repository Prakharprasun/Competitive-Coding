#ifndef ONPC
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#endif

#include <algorithm>
#include <array>
#include <stack>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
#include <fstream>
using namespace std;

// Debugging macro
#ifdef ONPC
#include "DEBUG.h"
#else
#define debug(...)  // No-op for production
#endif

void solve() {
   cout << "clang works 3!" << '\n'; 
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef ONPC
    freopen("inputf.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int t = 1;
    cin >> t;
    while(t--) solve();
}
