# Exercise 2.3.4

## Description

The inorder traversal (also see Section 4.7.2) of a standard (not necessarily balanced) BST is known to produce the BST’s element in sorted order and runs in $\mathbb{O}(n)$. Does the code below also produce the BST elements in sorted order? Can it be made to run in a total time of $\mathbb{O}(n)$ instead of $\mathbb{O}(\log n+(n−1)×\log n) = \mathbb{O}(n \log n)$? If possible, how?

```c++
x = findMin(); output x;
for(int i = 1; i < n; i++)      // is this loop O(n log n)?
    x = successor(x); output x
```

## My Answer

**Note**: `successor(x)` is to find the next value that is greater than `x`.

- The code does print out the numbers in ascending order.
- I think that there is no way. If we want to do that, the function `successor(x)` and `findMin()` must take $\mathbb{O}(1)$ time complexity. However, traversing tree always takes $\mathbb{O}(\log n)$.
