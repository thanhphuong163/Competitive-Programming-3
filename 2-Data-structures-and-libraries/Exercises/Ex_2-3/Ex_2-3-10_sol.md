# Exercise 2.3.10

## Description

Given an unsorted array $S$ of $n$ distinct integers $(2k ≤ n ≤ 10^5)$, find the largest and smallest $k$ $(1 ≤ k ≤ 32)$ integers in $S$ in $\mathcal{O}(n \log k)$. **Note**: For this written exercise, assume that an $\mathcal{O}(n \log n)$ algorithm is *not* acceptable.

## My Answer

$S$: [4 5 3 7 6 1 2 9]

Insert elements of $S$ one by one into a max heap. If the size of the max heap exceeds $k$, then remove the root of the max heap. After inserting all elements of $S$, what remain in max heap is the k smallest elements of $S$.

```c++
vector<int> get_k_largest(vector<int> &nums, int k) {
    priority_queue<int> max_heap;
    for (int i = 0; i < nums.size(); i++) {
        max_heap.push(nums[i]);
        if (max_heap.size() > k)
            max_heap.pop();
    }
    vector<int> v;
    for (int i = 0; i < max_heap.size(); i++) {
        v.push_back(max_heap.front());
        max_heap.pop();
    }
    return v;
}
```
