/* Recognization of character
 * Algorithm recognize minimum number of
 * pixel required to recognize image
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


/* Defining 1D, 2D and 3D vector
 * for storing images pixel in cube
 * of kxmxn
 */
typedef vector <int> v1d;
typedef vector <v1d> v2d;
typedef vector <v2d> v3d;

/* bit_set array contains, unique set of bit_vectors
 * of any (m,n) pixel across all k_image. bit_set do not
 * contain repeated bit_vector, all one or all zero bit_vec
 * , neither any two bit_vector are inversion of each other,
 */
void update(v2d &bit_set, v1d &bit);

/* check function checks weather, bit_vector a != b
 */
bool check(v1d &a, v1d &b);

/* checks if bit_vector contains all ones or zero
 */
bool allsamecheck(v1d &a);

/* compare function help to sort bit vector based on
 * information it contain
 */
bool compare(v1d &a, v1d &b);

/* returns information stored in bit_vector (bit)
 */
int info(v1d bit);

/* Found function returns true, if i bit_vector from
 * bit set can represent k-> different combination
 */
bool found( v2d &bit_set, int i, int k);

/* Return min_pixel required to recognize char
 */
int min_pix(v2d &bit_set, int log_k, int k);

/* return inverted bit vector of a
 */
v1d inversion(v1d &a);


int main()
{
	int n,m,k;

	cin >> n;
	cin >> m;
	cin >> k;

	v3d cube (k, v2d(n, v1d(m,0)));

	for(int i=0;i<k;i++)
	{
		for(int j=0; j<n; j++)
		{
			string temp;
			cin >> temp;
			for(int x=0; x<m; x++)
			{
				int temp_int;
				temp_int = temp[x] - '0';
				cube[i][j][x] = temp_int;
			}
		}
	}

	v2d bit_set;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			v1d bit;
			for(int x=0;x<k;x++)
			{
				bit.push_back(cube[x][i][j]);
			}
			update(bit_set, bit);
		}
	}

	sort(bit_set.begin(), bit_set.end(), compare);
	int log_k = (log2(k) > int(log2(k)))?(log2(k)+1):log2(k);
	
	cout << min_pix(bit_set, log_k, k) <<endl;

	return 0;
}

int min_pix(v2d &bit_set, int log_k, int k)
{
	int i;
	if( bit_set.size() <= log_k)
		return bit_set.size();

	for(i=log_k; i<k-1;i++)
	{
		if( found(bit_set, i, k) )
			return i;
	}
	return i;
}

bool found( v2d &bit_set, int i, int k)
{
	int result = 0;

	for(int j=0;j<i;j++)
	{
		result += info(bit_set[j]);
	}

	if(result < k) return false;
	else return true;

}

int info(v1d bit)
{
	int one = 0;
	for(int i=0;i<bit.size();i++)
	{
		if(bit[i] == 1)
			one ++;
	}

	return (one < bit.size()-one)? one: (bit.size()-one);
}

bool compare(v1d &a, v1d &b)
{
	return info(a) > info(b);
}

void update(v2d &bit_set, v1d &bit)
{
	if( allsamecheck(bit) ) return;

	v1d inv_bit;
	inv_bit = inversion(bit);
	
	for(int i=0; i<bit_set.size(); i++)
	{		

		if( check(bit_set[i], bit) || check(bit_set[i], inv_bit) )
			return;
	}
	bit_set.push_back(bit);
	return;
}

bool check(v1d &a, v1d &b)
{
	bool flag = true;
	
	for(int i=0; i<a.size(); i++)
	{
		if( a[i] != b[i])
		{
			flag = false;
			break;
		}
	}

	return flag;
}

bool allsamecheck(v1d &a)
{
	for(int i=0;i < a.size() -1;i++)
	{
		if(a[i] != a[i+1])
		{
			return false;
		}
	}
	return true;
}

v1d inversion(v1d &a)
{
	v1d inv_bit;

	for(int i=0;i<a.size();i++)
	{
		inv_bit.push_back( !(a[i]) );
	}

	return inv_bit;
}