#include <bits/stdc++.h>
using namespace std;

double helper(int l, int r, vector<int> &a,map<pair<pair<int,int>, bool>, double> &dp, bool flag){
    if(l>r) return 0;
    if(dp.find({{l,r},flag})!=dp.end()){
        return dp[{{l,r},flag}];
    }
    double prob;
    if(flag){
        prob = 0.5*(a[l] + helper(l+1,r,a,dp,!flag)) + 0.5*(a[r] + helper(l,r-1,a,dp,!flag));

    } else {
        prob = 0.5*(helper(l+1,r,a,dp,!flag)) + 0.5*(helper(l,r-1,a,dp,!flag));
    }
    dp[{{l,r},flag}] = prob;
    return dp[{{l,r},flag}];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // your code goes here
    std::cout << std::fixed << std::showpoint;
    cout << setprecision(15);
    int t;
    cin >> t;
    while(t--){

        // 1 2 3 4
        // 1 -> 0.5 ; 4 -> 0.5
        // 1 : 2 3 4 or 1 2 3 one is eaten by B

        int n;
        cin >> n;
        vector<int> a(n);
        for(auto &i : a){
            cin >> i;
        }

        map<pair<pair<int,int>, bool>, double> dp;
        bool flag = true;
        cout << helper(0,a.size()-1,a,dp,flag) << '\n';


    }


}
