// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: 
// Submit: 

#include <stdio.h>
#include <iostream>

using namespace std;

int solve_1(int number, int divider) {
    // Find # shift steps
    int n = 0;
    while (divider != 1) {
        n++;
        divider = divider >> 1;
    }
    // Find the remainder
    int temp = (number >> n) << n;
    return number - temp;
}

bool solve_2(int num) {
    int temp = num;
    int n = 0;
    while (temp != 1)
    {
        n++;
        temp = temp >> 1;
    }

    return num == (num >> n) << n;
}

int solve_3(int S) {
    int a = 1 << 31;
    int tmp = S;
    int n = 31;
    while(tmp != a) {
        tmp = tmp << 1;
        n--;
    }
    S ^= (1 << n);
    return S;
}

int main(int argc, char const *argv[]) {
    // int n_testcase;
    // scanf("%d", &n_testcase);
    // while (n_testcase > 0) {
    //     /* your code */
    //     n_testcase--;
    // }
    cout << solve_1(19, 8) << endl;
    int n = 1024;
    cout << "Is " << n << " a power of 2? " << solve_2(n) << endl;
    cout << solve_3(18) << endl;
    return 0;
}
