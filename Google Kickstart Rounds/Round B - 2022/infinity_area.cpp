#include <iostream>
#include <iomanip>
#include <math.h>
#define ll long long
#define PI 3.14159265358979323846 
using namespace std;

double solve(int r, int a, int b) {
	double ans = PI * pow(r, 2);

	while(r != 0) {
		r = r * a;
		ans += PI * pow(r, 2);
		r = r/b;
		ans += PI * pow(r, 2);
	}

	return ans;
}

int main() {
	int T, test = 1;
	cin>>T;
	while(T--) {
		int R, A, B;
		cin>>R>>A>>B;
		cout<<fixed<<setprecision(6);
		cout<<"Case #"<<test<<": "<<solve(R, A, B)<<endl;
		test++;
	}
	return 0;
}