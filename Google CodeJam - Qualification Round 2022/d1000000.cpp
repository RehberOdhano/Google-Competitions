#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solve(int size, vector<int>arr) {
	if(size == 1) return size;
	else {
		int val = 1, count = 0;
		int max_num = *max_element(arr.begin(), arr.end());
		sort(arr.begin(), arr.end());
		for(int i = 0; i < size; i++) {
			if(val > max_num) break;
			if(val > arr[i]) continue;
			if(val <= arr[i]) {
				count++;
				val++;
			}
		}
		return count;
	}
}

int main() {
	int T, test = 1;
	cin>>T;
	if(T >= 1 && T <= 100) {
		while(T--) {
			int N, num;
			cin>>N;
			if(N < 1 || N > 100000) continue;
			vector<int>sides;
			for(int i = 0; i < N; i++) {
				cin>>num;
				if(num >= 4 && num <= 1000000) sides.push_back(num);
			}
			cout<<"Case #"<<test<<": "<<solve(N, sides)<<endl;
			test++;
		}
	}
	return 0;
}