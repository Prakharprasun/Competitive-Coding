#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;
        int k;
        cin >> k;

        int n = s.size();

        queue<char> used;
        queue<char> notused;

        for(char i='a';i<='z';i++){
            bool flag = false;
            for(int j=0;j<n;j++){
                if(s[j]==i){
                    flag = true;
                    break;
                }
            }
            if(flag){
                used.push(i);
            } else {
                notused.push(i);
            }
        }
        // given -> n not used -> 26-n to make with 26-n+k;
        if(!(n<=26-n+k)){
            cout << "NOPE" <<'\n';
        } else {
            string ans;

            while(!(notused.empty())){
                ans+=notused.front();
                notused.pop();
            }
            for(int i=0;i<k;i++){
                ans+=used.front();
                used.pop();
            }

            sort(ans.begin(),ans.end());

            for(int i=0;i<n;i++){
                cout << ans[i];
            }
            cout << '\n';
        }
    }

}
