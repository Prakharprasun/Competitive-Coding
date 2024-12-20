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

const int n = 140;
map<pair<int, int>, bool> vis;
map<pair<int, int>, pair<int,int>> dp;
pair<int, int> helper(int i, int j, vector<vector<char>>& a) {
    if (vis[{i, j}]) return {0, 0}; // Already visited
    vis[{i, j}] = true;

    // Result values: perimeter and area
    pair<int, int> result = {0, 1};

    // Directions for checking neighbors
    pair<int, int> dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    pair<int, int> diag[4] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    int corner = 0;
    pair<int, int> ver[2] = {{-1, 0}, {1, 0}};
    pair<int, int> hoz[2] = {{0, 1}, {0, -1}};
    int v = 0;
    for (auto [ dx , dy] : ver) {
        int diagx = i + dx, diagy = j + dy;
        if (diagx < 0 || diagx >= n || diagy < 0 || diagy >= n || a[diagx][diagy] != a[i][j]) {
            v++;
        }
    }

    int h = 0;
    for (auto [ dx , dy] : hoz) {
        int diagx = i + dx, diagy = j + dy;
        if (diagx < 0 || diagx >= n || diagy < 0 || diagy >= n || a[diagx][diagy] != a[i][j]) {
            h++;
        }
    }

    if (h>=1 && v>=1) {
        if (h+v == 4) corner+=4;
        else if (h+v == 3) corner+=2;
        else if (h+v == 2) corner+=1;
    }
        {
        // Check each diagonal
        for (auto [dx, dy] : diag) {
            int diagx = i + dx, diagy = j + dy;
            if (diagx < 0 || diagx >= n || diagy < 0 || diagy >= n || a[diagx][diagy] != a[i][j])
            {
                // If diagonal is out of bounds or empty, check orthogonal neighbors
                int nx1 = i + dx, ny1 = j; // Vertical neighbor
                int nx2 = i, ny2 = j + dy; // Horizontal neighbor

                if ((nx1 >= 0 && nx1 < n && ny1 >= 0 && ny1 < n && a[nx1][ny1] == a[i][j]) &&
                    (nx2 >= 0 && nx2 < n && ny2 >= 0 && ny2 < n && a[nx2][ny2] == a[i][j])) {
                    corner++; // Valid corner found
                    }
            }
        }
    }

    // Add corners to perimeter count
    result.first += corner;

    // Process orthogonal neighbors
    for (auto [dx, dy] : dir) {
        int nx = i + dx, ny = j + dy;

        if (nx < 0 || ny < 0 || nx >= n || ny >= n || a[nx][ny] != a[i][j]) {
            // No perimeter update here, as it's handled by corners
        } else if (!vis[{nx, ny}]) {
            auto subresult = helper(nx, ny, a);
            result.first += subresult.first; // Aggregate the perimeter from sub-calls
            result.second += subresult.second; // Aggregate the area from sub-calls
        }
    }

    dp[{i, j}] = result;
    return result;
}


void Solve() {

    // Input
    vector<vector<char>> a(n,vector<char>(n));
    frange(i, n) {
        frange(j, n) {
            cin >> a[i][j];
        }
    }

    //Solution
    i128 ans = 0;

    frange(i, n) {
        frange(j, n) {
            if (!vis[{i, j}])
                {
                auto [perimeter, area] = helper(i, j, a);
                ans += perimeter * area;
                    println(a[i][j],i,j,perimeter,area);
            }
        }
    }

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