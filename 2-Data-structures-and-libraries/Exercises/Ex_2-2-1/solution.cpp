// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: 
// Submit: 

#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

bool solve_1(vector<int> vi) {
    sort(vi.begin(), vi.end()); // sort with complexity O(nlogn)
    int curr = vi[0];
    for (int i = 1; i < vi.size(); i++) {
        if (curr != vi[i]) {curr = vi[i];}
        else {return true;}
    }
    return false;
}

void solve_2(vector<int>vi, int v) {
    vector< pair<int, int> > result;
    // This solution has complexity O(n^2).
    for (int i = 0; i < vi.size(); i++) {
        // vi[i] is now considered as a
        int b = v - vi[i];
        for (int j=i+1; j<vi.size(); j++) {
            if (b == vi[j]) {
                result.push_back(make_pair(vi[i],vi[j]));
            }
        }
    }
    if (!result.empty()) {
        for (vector< pair<int, int> >::iterator it=result.begin(); it != result.end(); it++) {
            cout << "(" << it->first << ", " << it->second << ") ";
        }
    }
    else {
        cout << "There is no pair (a, b) such that a+b=" << v << ".";
    }
    cout << endl;
}

void solve_3(vector<int> vi, int v) {
    // In case of the sorted array, I have a O(n) solution.
    int start=0;
    int end
}

int main(int argc, char const *argv[]) {
    int n_testcase;
    scanf("%d\n", &n_testcase);
    while (n_testcase > 0) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> vi;
        int ele;
        while (ss >> ele) {
            vi.push_back(ele);
        }
        if (solve_1(vi)) {
            cout << "There exists at least one pair of duplicate." << endl;
        }
        else {
            cout << "There is no pair of duplicate." << endl;
        }
        solve_2(vi, 5);
        // for (int i=0; i < vi.size(); i++) {
        //     cout << vi[i] << " ";
        // }
        // cout << endl;
        n_testcase--;
    }
    return 0;
}
