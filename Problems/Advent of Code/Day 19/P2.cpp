/*
 * Author : Prakhar Prasun
 */

#include "bits/stdc++.h"
using namespace std;

// Debugging macro
#ifdef ONPC
#include "DEBUG.h"
#else
#define debug(...)  // No-op for production
#endif

// Type aliases
#define int long long
#define double long double
#define vi vector<int>

// __int128
#define i128 __int128
// Function to read __int128 from input
__int128 readi128() {
    string s;
    cin >> s; // Read as string
    bool negative = (s[0] == '-');
    if (negative) s = s.substr(1); // Remove negative sign for parsing

    __int128 result = 0;
    for (char c : s) {
        assert(isdigit(c)); // Ensure the input is numeric
        result = result * 10 + (c - '0'); // Build the number
    }
    return negative ? -result : result;
}

// Function to print __int128 to output
void printi128(__int128 num) {
    if (num == 0) {
        cout << 0;
        return;
    }

    if (num < 0) {
        cout << '-';
        num = -num;
    }

    string result;
    while (num > 0) {
        result += char('0' + (num % 10)); // Get the last digit
        num /= 10;
    }
    reverse(result.begin(), result.end()); // Reverse to correct order
    cout << result;
}

// Pair utilities
#define mp make_pair
#define f first
#define s second

// Macros for common operations
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define pb push_back
#define eb emplace_back
#define vma(a) *max_element(a.begin(),a.end());
#define vmi(a) *min_element(a.begin(),a.end());

// Scan/Input
template <typename T>
void scan(T& arg) {
    cin >> arg;
}
template <typename T, typename... Args>
void scan(T& arg, Args&... args) {
    cin >> arg;
    scan(args...); // Recursive call
}

// Print
void println() {
    cout << '\n'; // Simply prints a newline
}
template <typename T>
void println(T arg) {
    cout << arg << '\n'; // Print the last argument with a newline
}
template <typename T, typename... Args>
void println(T arg, Args... args) {
    cout << arg << " ";  // Print the first argument followed by a space
    println(args...);    // Recursive call for the rest
}
template <typename T>
void print(T arg) {
    cout << arg; // Print the last argument without a trailing space or newline
}
template <typename T, typename... Args>
void print(T arg, Args... args) {
    cout << arg << " ";  // Print the first argument followed by a space
    print(args...);      // Recursive call for the rest
}

// Loops
#define range(i, a, b) for (int i = (a); i < (b); ++i)
#define frange(i, n) range(i, 0, n)
#define rrange(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define rfrange(i, n) rrange(i, 0, n)
#define each(a, x) for (auto &a : x)

// Constants
constexpr int MOD = 998244353;  // Modular arithmetic
constexpr int MX = 2e5 + 5;     // Max array size
constexpr int INF = 1e18;       // Infinity
const double PI = acos(-1.0);
constexpr int dx[4] = {1, 0, -1, 0};  // Grid movement
constexpr int dy[4] = {0, 1, 0, -1};

// Random number generator
mt19937 rng(static_cast<uint32_t>(chrono::steady_clock::now().time_since_epoch().count()));

// Utilities for bitwise operations
constexpr int pct(int x) { return __builtin_popcountll(x); }  // Count bits set
constexpr int bits(int x) { return x == 0 ? 0 : 63 - __builtin_clzll(x); } // Log2
constexpr int p2(int x) { return 1LL << x; }  // 2^x
constexpr int msk2(int x) { return p2(x) - 1; }  // Mask with x bits set

// Math utilities
int cdiv(int a, int b) { return a / b + ((a ^ b) > 0 && a % b); }  // Ceil division
int fdiv(int a, int b) { return a / b - ((a ^ b) < 0 && a % b); }  // Floor division

// Helper functions
template <class T>
bool ckmin(T& a, const T& b) { return b < a ? a = b, true : false; }  // Minimize
template <class T>
bool ckmax(T& a, const T& b) { return a < b ? a = b, true : false; }  // Maximize

template <class T, class U>
T fstTrue(T lo, T hi, U f) {  // First true in range
    ++hi;
    assert(lo <= hi);
    while (lo < hi) {
        T mid = lo + (hi - lo) / 2;
        f(mid) ? hi = mid : lo = mid + 1;
    }
    return lo;
}

template <class T, class U>
T lstTrue(T lo, T hi, U f) {  // Last true in range
    --lo;
    assert(lo <= hi);
    while (lo < hi) {
        T mid = lo + (hi - lo + 1) / 2;
        f(mid) ? lo = mid : hi = mid - 1;
    }
    return lo;
}

template <class T>
void remDup(vector<T>& v) {  // Sort and remove duplicates
    sor(v);
    v.erase(unique(all(v)), end(v));
}

template <class T, class U>
void safeErase(T& container, const U& value) {  // Safe erase for containers
    auto it = container.find(value);
    assert(it != end(container));
    container.erase(it);
}

int binpow(int a , int b){
    int M = LLONG_MAX;
    int ans = 1;
    while(b){
        if(b&1)ans = ((ans * a) % M);
        a = ((a*a)%M);
        b >>= 1;
    }
    return ans;
}

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

vector<string> clr;
map<string, int> dp;
int helper(string &s) {
    if (dp.find(s) != dp.end()) {
        return dp[s];
    }
    if (s.empty()) {
        return 1;
    }
    string x;
    int ans = 0;
    frange(i,s.length()) {
        x.pb(s[i]);
        for (const auto& j : clr) {
            if (x == j) {
                string k = s.substr(i+1, s.size());
                ans += helper(k);
            }
        }
    }
    dp[s] = ans;
    return dp[s];
}

void Solve() {
    // Input
    string s;
    getline(cin, s);
    string x = "";
    frange(i, s.length()) {
        if (s[i] == ',') {
            clr.pb(x);
            i++;
            x = "";
            continue;
        }
        x.pb(s[i]);
    }
    clr.pb(x);
    getline(cin, s);
    vector<string> target;
    while (getline(cin, s)) {
        target.pb(s);
    }
    int ans = 0;
    for (auto i : target) {
        ans += helper(i);
    }
    println(ans);
}

// Main function
int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed << setprecision(10);

    int t = 1;
    //cin >> t;

    while (t--) Solve();
}

/*
 * - Check for integer overflow and array bounds
 * - Handle special cases (e.g., n = 1, empty input)
 * - Stay organized and write intermediate results down
 * - Avoid sticking to one approach for too long
 * - Use debugging effectively to locate errors
 */