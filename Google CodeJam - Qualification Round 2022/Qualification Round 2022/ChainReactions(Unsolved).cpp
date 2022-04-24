#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

struct node {
	int val;
	int id;
	node* next = NULL;
	node* prev = NULL;
};

node* head = NULL;

int solve(int n, vector<int>f, vector<int>p) {
	int max_num = 0;
	vector<node*>ptrs;
	vector<int>start_points;
	
	for(int i = 0; i < n; i++) {
		node* module = new node();
		if(p[i] == -1) {
			module->next = head;
			module->id = -1;
			start_points.push_back(f[i]);
		}
		module->id = i;
		module->val = f[i];
		ptrs.push_back(module);
	}

	vector<node*>initiators;
	node* temp = NULL;
	node* ptr = NULL;
	for(int i = 0; i < n; i++) {
		if(p[i] != -1) {
			node* m = new node();
			m->id = i;
			m->val = f[i];
			m->next = ptrs[p[i]];
			ptr = m;
			
			// here, trying to keep track of initiator modules

			vector<int>::iterator it;
			// it = find(start_points.begin(), start_points.end(), ptr->next->val);
			// if(it != start_points.end() && p[it - start_points.begin()] == -1) {
			// 	initiators.pop_back();
			// 	initiators.insert(initiators.begin(), ptr);
			// }

			if(initiators.size() == 0) {
				temp = ptr;
				initiators.push_back(ptr);
			}
			else {
				it = find(start_points.begin(), start_points.end(), ptr->next->val);
				if(it != start_points.end()) {
					initiators.insert(initiators.begin(), ptr);
				} else {
					if(ptr->next->val == temp->val) {
						initiators.pop_back();
						initiators.insert(initiators.begin(), ptr);
						temp = ptr;
					}
				}
			}
		}
	}


	// cout<<"initiators: ";
	// for(auto x : initiators) cout<<x->val<<" ";
	// cout<<endl;

	vector<int>max_nums;
	
	int value = 0;
	// sort(initiators.begin(), initiators.end());
	for(int i = 0; i < initiators.size(); i++) {
		node* start = initiators[i];
		if(start->next->next == head) {
			// cout<<"start: ";
			while(start != head) {
				// cout<<start->val<<" ";
				value = max(value, start->val);
				start = start->next;
			}
			// cout<<endl;
			max_nums.push_back(value);	
		}
		// if(start->prev == NULL && start->next == head) {
		// 	max_nums.push_back(max(start->val, head->val));
		// } else {
		// 	while(start->next != head) {
		// 		value = max(value, start->val);
		// 		start = start->next;
		// 	}
		// 	max_nums.push_back(value);
		// }
	}

	for(int x : max_nums) {
		max_num += x;
		cout<<x<<" ";
	}
	cout<<endl;

	return max_num;
}

int main() {
	int T, test = 1;
	cin>>T;
	while(T--) {
		int N, F, P;
		cin>>N;
		vector<int>fun_factors;
		vector<int>pointers;
		for(int i = 0; i < N; i++) {
			cin>>F;
			fun_factors.push_back(F);
		}

		for(int i = 0; i < N; i++) {
			cin>>P;
			pointers.push_back(P-1);
		}

		cout<<"Case #"<<test<<": "<<solve(N, fun_factors, pointers)<<endl;
		test++;
	}
	return 0;
}