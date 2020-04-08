# Exercise 2.3.9

## Description

Given a 1-based compact array $A$ containing n integers $(1 ≤ n ≤ 10^5)$ that are guaranteed to satisfy the Max Heap property, output the elements in $A$ that are greater than an integer $v$. What is the best algorithm?

## My Answer

This is a $\mathbb{O}(n)$ solution. The idea is that heap is an array, so we just go through the array and get integers that are greater than $v$.

```c++
void get_ele_gt(vector<int> &heap, int v) {
    for (int i = 0; i < heap.size(); i++) {
        if (heap[i] > v)
            cout << heap[i];
    }
    cout << endl;
}
```
