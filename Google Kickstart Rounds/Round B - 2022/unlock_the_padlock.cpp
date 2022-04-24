#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

ll solve(vector<ll>dials, ll n, ll d) {
	ll min_op = 0;	

	for(int i = 0; i < n; i++) {
		ll min = *min_element(dials.begin(), dials.end());
		ll max = *max_element(dials.begin(), dials.end());
		// cout<<"min: "<<min<<" and max: "<<max<<endl;
		if(min == max) {
			min_op++;
			break;
		}
		else if(dials[i] == 0 && max != 0) {
			int start = i, end = i;
			for(int j = i+1; j < n; j++) {
				if(dials[j] == 0) end = j;
				else break;
			}
			if(start == end && start == 0) dials[i] = 1;
			else {
				fill_n(dials.begin()+start, end, 1); 
				min_op++;
			}
		}
		else if(max == 1 && max == (d-1) && dials[i] == 1) continue;
		else if(max == (d - 1)) {
			int max_index = find(dials.begin(), dials.end(), max) - dials.begin();
			int end = max_index;
			for(int j = max_index; j < n; j++) {
				if(dials[j] == max) end = j;
			}
			fill_n(dials.begin()+max_index, end, 1);
			min_op++;
		}
		else if(max != (d - 1)) {
			while(max != min) {
				int max_index = find(dials.begin(), dials.end(), max) - dials.begin();
				int end = max_index;
				for(int j = max_index; j < n; j++) {
					if(dials[j] == max) end = j;
				}
				fill_n(dials.begin()+max_index, end, dials[max_index]-1);
				min_op++;
				max = *max_element(dials.begin(), dials.end());
			}
		}
	}
	
	return min_op;
}

int main() {
	int T, test = 1;
	cin>>T;
	while(T--) {
		ll N, D;
		cin>>N>>D;
		vector<ll>dials(N, 0);
		for(int i = 0; i < N; i++) cin>>dials[i];
		cout<<"Case #"<<test<<": "<<solve(dials, N, D)<<endl;
		test++;
	}
	return 0;
}