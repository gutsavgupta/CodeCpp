/*
 * Maximum XOR with prefix and suffix
 * The algorithm uses binary trie to find maxium xor for each (prefix array)
 * Algorithm first construct a vector of suffix, each suffix[i] = xor(a[n-1],a[n-2]
 * ....,a[i]), then it adds all the suffix[i] i=0 to n-1 to binary trie + plus 0 for
 * including empty suffix case. Then it takes maximum of max_xor{prefix[i]}, current_max
 * time complexity = O(nlog(n))
 */

#include <iostream>
#include <vector>
#define NBITS 42

using namespace std;
typedef long long int LL;

vector < LL > array; 	// Input array
vector < LL > suffix;	// Suffix array
#define NBITS 42		// 42 bits for 1xe12

typedef struct node
{
	struct node* left; 	// left for 0
	struct node* right; // right for 1
	struct node* parent;// Parent node
}NODE;

/* Add a node in binary trie, for
 * binary representation of x
 */
void add_node(NODE *head, LL x);

/* Remove a node from binary trie, for
 * binary representation of x, if x doesn't
 * exit in trie than it simply returns
 * it purges a branch of trie if, both the
 * leaves are deleted
 */
void rem_node(NODE *head, LL x);

/* purges a branch in a trie, if branch has
 * no leaves representing binary representation
 * for any suffix
 */
void prg_node(NODE *node_parent);

/* Returns suffix in trie, such that xor of 
 * (x ^ max_xor(x)) is maximum, it simply search 
 * for opposite bit for each ith bit of x.
 */
long long int max_xor(NODE *head, LL x);


long long int max(LL a, LL b)
{
	return (a>b)?a:b;
}

int main()
{
	/* N- no of inputs, a- values of individual inputs
	 * xor_a- for taking xor of series of no., i- counter
	 */
	LL N, a;		
	LL xor_a, i;	
	
	// Taking Inputs
	cin >> N;

	for(i=0;i<N;i++)
	{
		cin >> a;
		array.push_back(a);
	}

	// Constructing root of binary trie
	NODE *head;
	head = new NODE;
	head->right = NULL;head->left = NULL;head->parent = NULL;

	// Constructing suffix array, 
	// suffix[i] = xor(a[n-1],...,a[i])
	xor_a = 0;
	for(i=N-1;i>=0;i--)
	{
		xor_a = array[i]^xor_a;
		add_node(head, xor_a);
		suffix.insert(suffix.begin(), xor_a);
	}
	add_node(head, 0); // for empty suffix

	// debugging	
	// for(i=0;i<suffix.size();i++)
	//	cout << suffix[i] << " ";

	LL max_pfx = 0;
	LL cur_max = 0;
	xor_a 	= 0;
	cur_max = max_xor(head,0); // for empty prefix
	
	// Now iterating for each prefix
	for(i=0;i<N;i++)
	{
		/* Removes suffix[i] for avoiding overlap
		 * Find max_suff for prefix[i]
		 * stores maximum as cur_max
		 */
		rem_node(head,suffix[i]);
		xor_a = xor_a^array[i];
		
		max_pfx =  	max_xor(head, xor_a)^xor_a;
		cur_max = 	max(cur_max, max_pfx);
	}
	
	cout << cur_max <<endl;
	return 0;
}

void rem_node(NODE* head, LL x)
{
	NODE *temp_node = head;

	for(int i=NBITS; i>=0; i--)
	{
		LL ref = 1;

		if(temp_node == NULL)
			return;

		else if( (ref<<i)&x )
		{
			if(i==0)
			{
				// if i=0, leaf node then remove it
				// check parent branch for purging
				temp_node->right = NULL;
				prg_node(temp_node);
			}
			else
				temp_node = temp_node->right;
		}
		else
		{
			if(i==0)
			{
				temp_node->left = NULL;
				prg_node(temp_node);
			}
			else
				temp_node = temp_node->left;
		}
	}
}

void prg_node(NODE *node_parent)
{
	NODE *temp= node_parent;
	if(temp != NULL)
	{
		if(temp->left == NULL && temp->right == NULL)
		{
			NODE *new_temp = temp->parent;
			if(new_temp != NULL)
			{
				if( temp == new_temp->right)
					new_temp->right = NULL;
				else
					new_temp->left = NULL;

				prg_node(new_temp);
			}
		}
	}
}

long long int max_xor(NODE *root, LL x)
{
	NODE *head = root;
	LL result = 0;

	for(int i=NBITS;i>=0;i--)
	{
		LL ref = 1;
		int bin = 0;

		if( (ref<<i)&x )
		{
			if(head->left != NULL)
			{
				bin = 0;
				head = head->left;
			}
			else if(head->right != NULL)
			{
				bin = 1;
				head = head->right;
			}
		}
		else
		{
			if(head->right != NULL)
			{
				bin = 1;
				head = head->right;
			}
			else if (head->left != NULL)
			{
				bin = 0;
				head = head->left;
			}	
		}
		result = result*2 + bin;
	}
	return result;
}


void add_node(NODE *head, LL x)
{
	NODE *temp_node = head;
	
	for(int i=NBITS;i>=0;i--)
	{
		LL ref = 1;
		if( (ref<<i)&x ) // ith bit is 1
		{
			
			if(temp_node->right == NULL)
			{
				temp_node->right = new NODE;
				temp_node->right->right = NULL;
				temp_node->right->left = NULL;
				temp_node->right->parent = temp_node;
				temp_node = temp_node->right;
			}
			else
				temp_node = temp_node->right;
			
		}
		else
		{
			
			if(temp_node->left == NULL)
			{
				temp_node->left = new NODE;
				temp_node->left->right = NULL;
				temp_node->left->left = NULL;
				temp_node->left->parent = temp_node;
				temp_node = temp_node->left;
			}
			else
				temp_node = temp_node->left;
		}
	}

	return;
}