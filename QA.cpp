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

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;

    multiset<int> tickets;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        tickets.insert(x);
    }

    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        auto it = tickets.upper_bound(x);
        if (it == tickets.begin()) {
            cout << -1 << '\n';
        } else {
            --it;
            cout << *it << '\n';
            tickets.erase(it);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef ONPC
    freopen("inputf.txt","r",stdin);
    freopen("outputf.txt","w",stdout);
#endif

    int t = 1;
    //cin >> t;
    while(t--) solve();
}