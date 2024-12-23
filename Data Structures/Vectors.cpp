#include <bits/stdc++.h>
using namespace std;

void print_vector(vector<int> vec) {
	for(auto i: vec) {
		cout << i << " ";
	}
	cout << "\n";
}

int main() {
	vector<int> vec= {1,2,3,4,5,6};

	// .begin() points towards first element
	vector<int> ::iterator it = vec.begin();
	auto i = vec.begin();
	cout << *it << " " << *i << "\n";
	i++;
	cout << *it << " " << *i << "\n";

	//.end() points to the position after the last element
	// *(.end()-1) returns the last element
	auto i2 = vec.end();
	cout << *(i2) << " " << *(i2-1) << "\n";

	// i++ and i+1 has no diffrence for vectors but the sme is not the case for other ds
	vector<pair<int,int>> vp = {{1,2},{3,4},{5,6}};
	auto i3=vp.begin();
	i3++;
	cout << (i3)->first << " " << (*(i3)).second << "\n";
	// (i3)->first <=> (*(i3)).first


	// auto dynamically allocates types based on input to it, cant use it without input
	// to change actual values reference(&) is needed
	for(auto i : vec) {
		i++;
	}
	print_vector(vec);
	for(auto &i : vec) {
		i++;
	}
	print_vector(vec);
}