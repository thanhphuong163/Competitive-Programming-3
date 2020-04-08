# Exercise 2.3.3

## Description

Suppose you are given a reference to the root $R$ of a binary tree $T$ containing $n$ vertices. You can access a node’s left, right and parent vertices as well as its key through its reference. Solve each of the following tasks below with the best possible algorithms that you can think of and analyze their time complexities. Let’s assume the following constraints: $1 ≤ n ≤ 100K$ so that $\mathbb{O}(n^2)$ solutions are theoretically infeasible in a contest environment.

1. Check if $T$ is a BST.
2. Output the elements in $T$ that are within a given range $[a..b]$ in ascending order.
3. Output the contents of the *leaves* of $T$ in *descending* order.

## My Answer

1. Using recursive algorithm. For each node, check the left node smaller than parent node and parent node smaller than right node (asceding order). Then return answer in form (result_parent and result_left and result_right), where result_left and result_right are recursive.
2. If tree $T$ is a BST, then create an inorder traversal function with condition node's value within $[a..b]$.
3. Similar to (2), but reverse the order of returned values (right, root, left).
