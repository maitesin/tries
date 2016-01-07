Radix Tree
=====
#Definition
Radix Tree (also radix trie or compact prefix tree) is a data structure that represents a space-optimized trie in which each node that is the only child is merged with its parent. The result is that the number of children of every internal node is at least the radix *r* of the radix trie, where *r* is a positive integer and a power *x* of 2, having *x* >= 1. Unlike in regular tries, edges can be labeled with sequences of elements as well as single elements. This makes radix trees much more efficient for small sets (especially if the strings are long) and for sets of strings that share long prefixes.

#Example of a radix tree

