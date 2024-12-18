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

string decimalToTernary(int n) {
    string ternary = "";
    if (n == 0) return "0"; // Edge case for 0
    while (n > 0) {
        ternary += char((n % 3) + '0'); // Append the remainder
        n /= 3;
    }
    reverse(ternary.begin(), ternary.end()); // Reverse to get correct order
    return ternary;
}

int getTernaryDigit(const string& ternary, int k) {
    // Ensure the index is within bounds
    if (k < 0 || k >= ternary.size()) {
        return 0;
    }
    // Since the string is in correct order, just access the k-th character
    return ternary[k] - '0'; // Convert character to integer
}


void Solve() {

    // Input
    int n = 850;
    vector<int> a;
    vector<vector<int>> b(n);
    frange(i,n) {
        string s;
        getline(cin, s);
        string x;
        frange(j,s.size()) {
            if (s[j] == ':') {
                a.pb(stoll(x));
                x = "";
                j++;
                continue;
            }
            if (s[j] == ' ') {
                b[i].pb(stoll(x));
                x = "";
                continue;
            }
            x.pb(s[j]);
        }
        b[i].pb(stoll(x));
    }


    //Solution

    __int128 ans = 0;

    frange(i,n) {
        set<i128> possum;
        i128 total = binpow(3,b[i].size());
        for (i128 j = 0; j < total; j++) {
            i128 sum = 0;
            i128 num = j; // Ternary representation
            for (int k = 0; k < b[i].size(); k++) {
                int digit = num % 3;  // Extract ternary digit
                num /= 3;

                if (digit == 0) {
                    sum += b[i][k];
                } else if (digit == 1) {
                    sum *= b[i][k];
                } else { // digit == 2
                    sum = sum * pow(10, to_string(b[i][k]).length()) + b[i][k];
                }
            }
            possum.insert(sum);
        }

        for (auto j : possum) {
            if (j == a[i]) {
                ans += j;
            }
        }
    }

    // Print __int128 (custom printing is needed)
    printi128(ans);
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
