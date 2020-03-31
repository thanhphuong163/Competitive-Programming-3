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
    // We need to sort the array as the description
    sort(vi.begin(), vi.end());
    // In case of the sorted array, I have a O(n) solution.
    vector< pair<int, int> > result;
    int head = 0;
    int tail = vi.size() - 1;
    while (head < tail) {
        if (vi[head] + vi[tail] > v) {
            tail--;
        }
        else if (vi[head] + vi[tail] < v) {
            head++;
        }
        else {
            result.push_back(make_pair(vi[head], vi[tail]));
            head++;
            tail--;
        }
    }
    if (!result.empty()) {
        for (vector< pair<int, int> >::iterator it = result.begin(); it != result.end(); it++) {
            cout << "(" << it->first << ", " << it->second << ") ";
        }
    }
    else {
        cout << "There is no pair (a, b) such that a+b=" << v << ".";
    }
    cout << endl;
}

void solve_4(vector<int> vi, int a, int b) {
    vector<int> result;
    for (const auto &i: vi) {
        if (i >= a && i <= b) {
            result.push_back(i);
        }
    }
    sort(result.begin(), result.end());
    for (const int &i: result) {
        cout << i << " ";
    }
    cout << endl;
}

int solve_5(vector<int> vi) {
    int head = 0;
    int tail = 1;
    int longest_length = 0;
    while (tail < vi.size()) {
        if (vi[tail] < vi[tail + 1]) {
            tail++;
            if (tail - head + 1 > longest_length) {
                longest_length = tail - head + 1;
            }
        }
        else {
            tail++;
            head = tail;
        }
    }
    return longest_length;
}

int solve_6(vector<int> vi) {
    int med_pos = vi.size() / 2;
    sort(vi.begin(), vi.end());
    return vi[med_pos];
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
        solve_3(vi, 5);
        solve_4(vi, 2, 7);
        cout << "The length of the longest increasing contiguous sub-array is " << solve_5(vi) << endl;
        cout << "Median of the array S is " << solve_6(vi) << endl;
        // for (int i=0; i < vi.size(); i++) {
        //     cout << vi[i] << " ";
        // }
        // cout << endl;
        n_testcase--;
    }
    return 0;
}
