#include <bits/stdc++.h>
using namespace std;

void input_output(){
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.txt", "w", stdout);
    freopen("error.in", "w", stderr);
#endif
}

typedef long long ll;
typedef vector<long long> vll;

#define each(a,x) for (auto& a: x)

template <typename T1> void print(T1 t1){ 
	cout << t1 << "\n"; 
}

void inputvec(vll &v){
	each(i,v){
		cin >> i;
	}
}
void printvec(vll v){
	each(i,v){
		cout << i;
	}
}

void string_append(string &s, char a){
	s.push_back(a);
}

int main(){
	input_output();
	ios::sync_with_stdio(false);cin.tie(nullptr);
	string s;
	char a;
	cin >> s >> a;
	string_append(s,a);
	print(s);
}