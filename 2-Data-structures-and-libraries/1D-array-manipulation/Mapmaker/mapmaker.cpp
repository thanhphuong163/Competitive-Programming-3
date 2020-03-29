// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://onlinejudge.org/external/3/394.pdf
// Submit: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=submit_problem&problemid=330&category=0

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

typedef vector<int> params;
typedef unordered_map<string, params> list_array;

int main(int argc, char const *argv[]) {
	int n_array;
	int n_ref;
	cin >> n_array >> n_ref;
	list_array lst_arr;
	while (n_array > 0) {
		/* your code */
		string name;
		int base, ele_size, dimension;
		cin >> name >> base >> ele_size >> dimension;
		params lb(dimension);	// lower bound
		params ub(dimension);	// upper bound
		for (int i=0; i<dimension; i++) {
			cin >> lb[i] >> ub[i];
		}
		vector<int> c(dimension+1);
		c[dimension] = ele_size;
		for (int i=dimension-1; i>=1; i--) {
			c[i] = c[i+1] * (ub[i] - lb[i] + 1);
		}
		c[0] = base;
		for (int i=1; i<=dimension; i++) {
			c[0] -= c[i]*lb[i-1];
		}
		lst_arr[name] = c;
		n_array--;
	}
	while (n_ref > 0) {
		string name;
		cin >> name;
		vector<int> c = lst_arr[name];
		int address = c[0];
		cout << name << "[";
		for (int i=1; i<c.size();i++) {
			int x;
			cin >> x;
			cout << x;
			address += x * c[i];
			if (i < c.size()-1) {
				cout << ", ";
			}
			else {
				cout << "] = ";
			}
		}
		cout << address << endl;
		n_ref--;
	}
	return 0;
}
