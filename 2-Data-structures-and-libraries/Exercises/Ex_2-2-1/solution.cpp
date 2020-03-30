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
    for (int i=1; i < vi.size(); i++) {
        if (curr != vi[i]) {curr = vi[i];}
        else {return true;}
    }
    return false;
}

map<int, int> solve_2(vector<int>vi, int v) {
    map<int, int> result;
    
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

        for (int i=0; i < vi.size(); i++) {
            cout << vi[i] << " ";
        }
        cout << endl;
        n_testcase--;
    }
    return 0;
}
