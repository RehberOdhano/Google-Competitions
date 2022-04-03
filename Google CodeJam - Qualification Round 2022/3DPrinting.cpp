#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> solve(int min_y, int min_m, int min_c, int min_k) {
	vector<int>res;

	if((min_y + min_m + min_c + min_k) < 1000000) res = {};
	else if((min_y + min_m + min_c + min_k) == 1000000) {
		res.insert(res.end(), {min_y, min_m, min_c, min_k});
	} else {
		vector<int>arr(4,0);
		arr[0] = min_y;
		arr[1] = min_m;
		arr[2] = min_c;
		arr[3] = min_k;

		int a = -1, b = -1, c = -1, d = -1;
		sort(arr.begin(), arr.end());
		for(int i = 0; i < 4; i++) {
			if(arr[i] == min_y && a == -1) a = i;
			else if(arr[i] == min_m && b == -1) b = i;
			else if(arr[i] == min_c && c == -1) c = i;
			else if(arr[i] == min_k && d == -1) d = i;
		}

		vector<int>total(4,0);
		total[0] = arr[0];
		total[1] = total[0] + arr[1];
		total[2] = total[1] + arr[2];
		total[3] = total[2] + arr[3];

		int index = 3;
		while(total[index] > 1000000) {
			if((total[index]-1000000) > arr[index]) {
				arr[index] = 0;
				index--;
			} else {
				arr[index] = arr[index] - (total[index] - 1000000);
				index--;
			}
		}
		res.insert(res.end(), {arr[a], arr[b], arr[c], arr[d]});
	}
	return res;
}


int main() {
	int T, test = 1;
	cin>>T;
	while(T--) {
		vector<int>y(3,0);
		vector<int>m(3,0);
		vector<int>c(3,0);
		vector<int>k(3,0);
		int min_y = 1000001, min_m = 1000001, min_c = 1000001, min_k = 1000001; 
		for(int i = 0; i < 3; i++) {
			cin>>y[i]>>m[i]>>c[i]>>k[i];
			min_y = min(min_y, y[i]);
			min_m = min(min_m, m[i]);
			min_c = min(min_c, c[i]);
			min_k = min(min_k, k[i]);
		}
		auto res = solve(min_y, min_m, min_c, min_k);
		if(res.size() == 0) cout<<"Case #"<<test<<": IMPOSSIBLE"<<endl;
		else {
			cout<<"Case #"<<test<<": ";
			for(int x : res) cout<<x<<" ";
			cout<<endl;
		}
		test++;
	}
	return 0;
}