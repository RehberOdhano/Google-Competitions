#include <iostream>
#include <string>
#include <algorithm>
#define ll long long 
using namespace std;

bool is_palindrome(string s) {
	string temp = s;
	reverse(s.begin(), s.end());
	if(temp == s) return true;
	else return false;
}

ll solve(ll A) {
	ll count = 0;
	ll start = 1;
	while(start * start <= A) {
		if(A % start == 0) {
			if(is_palindrome(to_string(start))) count++;
			if(A/start != start) {
				if(is_palindrome(to_string(A/start))) count++;
			}
		}
		start++;
	}
	return count;
}

int main() {
	int T, test = 1;
	cin>>T;
	while(T--) {
		ll A;
		cin>>A;
		cout<<"Case #"<<test<<": "<<solve(A)<<endl;
		test++;
	}
	return 0;
}