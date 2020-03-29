// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://onlinejudge.org/external/4/414.pdf
// Submit: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=submit_problem&problemid=355&category=0

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    while (cin >> n, n) {
        cin.ignore();
        vector<int> count_space(n);
        int min_space = -1;
        for (int i=0; i<n; i++) {
            string line;
            getline(cin, line);
            int count = 0;
            for (int j=0; j<line.size(); j++) {
                if (line[j] == ' ') count++;
            }
            count_space[i] = count;
            if (min_space > count || min_space == -1) {
                min_space = count;
            }
        }
        int total = 0;
        for (int i=0; i<n; i++) {
            total += count_space[i] - min_space;
        }
        cout << total << endl;
    }
    return 0;
}
