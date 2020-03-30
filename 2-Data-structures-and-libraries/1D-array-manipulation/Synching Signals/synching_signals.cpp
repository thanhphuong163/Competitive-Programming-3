// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://onlinejudge.org/external/4/467.pdf
// Submit: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=submit_problem&problemid=408&category=0

#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

const int maxSeconds = 60*60;

bool isAllGreen(int time, vector<int> timings) {
    for (int i=0; i<timings.size(); i++) {
        if (time % (timings[i] * 2) >= timings[i] - 5) return false;
    }
    return true;
}

int main(int argc, char const *argv[]) {
    string line;
    int T = 1;
    while (getline(cin, line)) {
        stringstream ss(line);
        vector<int> timings;
        int time;
        int lowestTimer = 90;
        while (ss >> time) {
            timings.push_back(time);
            if (time < lowestTimer) {
                lowestTimer = time;
            }
        }
        int currTime = lowestTimer * 2;
        while (!isAllGreen(currTime, timings) && currTime <= maxSeconds) {
            currTime++;
        }
        if (currTime > maxSeconds) {
            cout << "Set " << T << " is unable to synch after one hour.\n" ;
        }
        else {
            cout << "Set " << T << " synchs again at " << currTime/60 << " minute(s) and " << currTime%60 << " second(s) after all turning green.\n";
        }
        T++;
    }
    return 0;
}
