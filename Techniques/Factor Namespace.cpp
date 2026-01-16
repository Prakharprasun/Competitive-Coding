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

// POLLARD–RHO FACTORIZATION NAMESPACED
// Works for unsigned 64-bit integers (≤ 1e18), CP-safe

namespace factor {
/**
 * @brief Multiply a and b modulo mod without overflow.
 *
 * Uses 128-bit intermediate arithmetic.
 *
 * @example
 * mod_mul(1e18, 1e18, 1e18+3)
 */
inline u64 mod_mul(u64 a, u64 b, u64 mod) { return (u128)a * b % mod; }

/**
 * @brief Compute a^d mod mod.
 *
 * @example
 * mod_pow(2, 10, 1000) == 24
 */
inline u64 mod_pow(u64 a, u64 d, u64 mod) {
  u64 r = 1;
  while (d) {
    if (d & 1)
      r = mod_mul(r, a, mod);
    a = mod_mul(a, a, mod);
    d >>= 1;
  }
  return r;
}

/**
 * @brief Deterministic Miller–Rabin primality test for 64-bit integers.
 *
 * Guaranteed correct for all n < 2^64.
 *
 * @example
 * is_prime(2)        -> true
 * is_prime(17)       -> true
 * is_prime(221)      -> false
 * is_prime(1e18+3)   -> true/false correctly
 */
inline bool is_prime(u64 n) {
  if (n < 2)
    return false;
  for (u64 p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
    if (n % p == 0)
      return n == p;
  }

  u64 d = n - 1, s = 0;
  while ((d & 1) == 0)
    d >>= 1, ++s;

  for (u64 a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
    if (a % n == 0)
      continue;
    u64 x = mod_pow(a, d, n);
    if (x == 1 || x == n - 1)
      continue;
    bool composite = true;
    for (u64 r = 1; r < s; ++r) {
      x = mod_mul(x, x, n);
      if (x == n - 1) {
        composite = false;
        break;
      }
    }
    if (composite)
      return false;
  }
  return true;
}

// RNG for Pollard–Rho
static std::mt19937_64
    rng(std::chrono::steady_clock::now().time_since_epoch().count());

/**
 * @brief Pollard–Rho algorithm to find a non-trivial factor of n.
 *
 * @note n must be composite.
 *
 * @example
 * pollards_rho(91) -> 7 or 13
 */
inline u64 pollards_rho(u64 n) {
  if (n % 2 == 0)
    return 2;
  if (n % 3 == 0)
    return 3;

  u64 c = std::uniform_int_distribution<u64>(1, n - 1)(rng);
  u64 x = std::uniform_int_distribution<u64>(0, n - 1)(rng);
  u64 y = x, d = 1;

  auto f = [&](u64 x) { return (mod_mul(x, x, n) + c) % n; };

  while (d == 1) {
    x = f(x);
    y = f(f(y));
    d = std::gcd(x > y ? x - y : y - x, n);
    if (d == n)
      return pollards_rho(n);
  }
  return d;
}

/**
 * @brief Recursive helper for full factorization.
 */
inline void factor_rec(u64 n, std::vector<u64> &res) {
  if (n == 1)
    return;
  if (is_prime(n)) {
    res.push_back(n);
  } else {
    u64 d = pollards_rho(n);
    factor_rec(d, res);
    factor_rec(n / d, res);
  }
}

/**
 * @brief Prime factorization with multiplicity.
 *
 * @returns vector of prime factors in sorted order.
 *
 * @example
 * factor(18)      -> {2, 3, 3}
 * factor(360)     -> {2,2,2,3,3,5}
 * factor(1e18+3)  -> {1e18+3} if prime
 */
inline std::vector<u64> factor(u64 n) {
  std::vector<u64> res;
  factor_rec(n, res);
  std::sort(res.begin(), res.end());
  return res;
}

/**
 * @brief Compress prime factor list into (prime, exponent).
 *
 * @example
 * compress({2,2,3,3,3}) -> {{2,2}, {3,3}}
 */
inline std::vector<std::pair<u64, int>> compress(const std::vector<u64> &pf) {
  std::vector<std::pair<u64, int>> res;
  for (u64 p : pf) {
    if (res.empty() || res.back().first != p)
      res.emplace_back(p, 1);
    else
      ++res.back().second;
  }
  return res;
}

/**
 * @brief Compute the number of divisors τ(n).
 *
 * Uses prime factorization: if n = ∏ p_i^{e_i},
 * then τ(n) = ∏ (e_i + 1).
 *
 * @example
 * divisor_count(1)    -> 1
 * divisor_count(18)   -> 6   (1,2,3,6,9,18)
 * divisor_count(360)  -> 24
 */
inline u64 divisor_count(u64 n) {
  auto f = compress(factor(n));
  u64 ans = 1;
  for (auto [p, e] : f)
    ans *= (e + 1);
  return ans;
}

/**
 * @brief Enumerate all positive divisors of n.
 *
 * Uses prime factorization + recursive construction.
 * Complexity: O(τ(n)) after factorization.
 *
 * @example
 * divisors(1)     -> {1}
 * divisors(18)    -> {1,2,3,6,9,18}
 * divisors(360)   -> 24 divisors
 */
inline std::vector<u64> divisors(u64 n) {
  if (n == 0)
    return {}; // undefined, but safe guard
  if (n == 1)
    return {1};

  auto pf = compress(factor(n));
  std::vector<u64> res = {1};

  for (auto [p, e] : pf) {
    std::vector<u64> cur;
    u64 pe = 1;
    for (int i = 1; i <= e; ++i) {
      pe *= p;
      for (u64 x : res)
        cur.push_back(x * pe);
    }
    res.insert(res.end(), cur.begin(), cur.end());
  }

  std::sort(res.begin(), res.end());
  return res;
}

} // namespace factor

static vector<int> divisors(1'000'001, -1);
void compute(u32 n) { divisors[n] = factor::divisor_count(n); }

void solve() {
  u32 x;
  cin >> x;
  if (divisors[x] == -1)
    compute(x);
  cout << divisors[x] << '\n';
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
  cin >> t;
  while (t--)
    solve();
}