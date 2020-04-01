// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=623&page=show_problem&problem=423
// Submit: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=submit_problem&problemid=423&category=0

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<string> sort_arr(vector<int>& vi, vector<string>& vs) {
    vector<string> orginal_arr(vi.size());
    for (int i = 0; i < vi.size(); ++i) {
        orginal_arr[vi[i]-1] = vs[i];
    }
    return orginal_arr;
}

void print_vector_str(vector<string> &vs)
{
    for (int i = 0; i < vs.size(); ++i)
    {
        cout << vs[i] << endl;
    }
}

int main(int argc, char const *argv[]) {
    int n_testcase;
    cin >> n_testcase;
    cin.ignore();
    bool isFirst = true;
    string blankLine;
    while (n_testcase--) {
        getline(cin, blankLine);
        if (!isFirst)
            cout << "\n";
        isFirst = false;

        string line1, line2;
        getline(cin, line1);
        getline(cin, line2);
        stringstream ss1(line1);
        stringstream ss2(line2);
        int i;
        string v;
        vector<int> v_index;
        vector<string> v_value;
        while (ss1 >> i) {
            v_index.push_back(i);
        }
        while (ss2 >> v) {
            v_value.push_back(v);
        }
        vector<string> org_arr = sort_arr(v_index, v_value);
        print_vector_str(org_arr);

    }
    return 0;
}
