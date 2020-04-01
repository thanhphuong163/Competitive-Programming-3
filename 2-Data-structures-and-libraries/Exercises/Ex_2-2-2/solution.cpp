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

int main(int argc, char const *argv[]) {
    // int n_testcase;
    // scanf("%d", &n_testcase);
    // while (n_testcase > 0) {
    //     /* your code */
    //     n_testcase--;
    // }
    cout << solve_1(19, 8) << endl;
    return 0;
}
