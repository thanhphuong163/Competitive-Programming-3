# Exercise 2.3.8

## Description

Prove or disprove this statement: “The second largest element in a Max Heap with $n ≥ 3$ distinct elements is always one of the direct children of the root”. Follow up question: What about the third largest element? Where is/are the potential location(s) of the third largest element in a Max Heap?

## My Answer

- Suppose the root's left child and right child don't contain the second largest element in Max Heap, then the second largest element must be in subtrees of both. This violates the properties of Max Heap the all elements in subtree must smaller than the root of the subtree. Therefore, the statement must be true.
- The third largest element must be in either directive child of the root or subtree of the second largest element.
