## Problem Statement
We have N numbers as an array, you need to find a prefix array and a suffix array, which we can get the maximum xor value with all elements in them. Notice that for prefix(0, l) and suffix(r, n - 1) do not intersect l <. r and they can be empty. For example

array  : 1 2 3

answer : 3 prefix can be empty,and suffix can be {3} or prefix can be {1,2}, and suffix can be empty.

## Algorithm
Maximum XOR with prefix and suffix
The algorithm uses binary trie to find maxium xor for each (prefix array) Algorithm first construct a vector of suffix, each suffix[i] = xor(a[n-1],a[n-2]....,a[i]), then it adds all the suffix[i] i=0 to n-1 to binary trie + plus 0 for including empty suffix case. Then it takes maximum of max_xor{prefix[i]}, current_max
# time complexity = O(nlog(n))

## Functions

typedef long long int LL;

vector < LL > array; 	// Input array
vector < LL > suffix;	// Suffix array
define NBITS 42		// 42 bits for 1xe12

* typedef struct node
{
	struct node* left; 	// left for 0
	struct node* right; // right for 1
	struct node* parent;// Parent node
}NODE;

Add a node in binary trie, for
binary representation of x

* void add_node(NODE *head, LL x);

Remove a node from binary trie, for
binary representation of x, if x doesn't
exit in trie than it simply returns
it purges a branch of trie if, both the
leaves are deleted

* void rem_node(NODE *head, LL x);

purges a branch in a trie, if branch has
no leaves representing binary representation
for any suffix

* void prg_node(NODE *node_parent);

Returns suffix in trie, such that xor of 
(x ^ max_xor(x)) is maximum, it simply search 
for opposite bit for each ith bit of x.

* long long int max_xor(NODE *head, LL x);


* long long int max(LL a, LL b)
{
	return (a>b)?a:b;
}
