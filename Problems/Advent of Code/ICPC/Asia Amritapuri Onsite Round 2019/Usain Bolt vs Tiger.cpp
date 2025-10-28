#include <bits/stdc++.h>
using namespace std;

int main() {
    // your code goes here
    int t;
    cin >> t;
    while(t--){
        double fi,di,ta,bs;
        cin >> fi >> di >> ta >> bs;

        double tt = sqrt((fi+di)/(0.5*ta));
        double bt = fi/(bs*1.0);

        if(tt>bt){
            cout << "Bolt" << '\n';
        }
        else {
            cout << "Tiger" << '\n';
        }
    }
}
