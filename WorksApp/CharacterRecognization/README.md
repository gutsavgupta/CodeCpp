## Problem Statement
Character recognition is the conversion of images into text. For now we consider each character in the picture is a N*M matrix with only zeros and ones, and we need to recognize K characters. You are to write a program to find minimal number of pixels so that we can recognize each character.

For example, we have only two characters 'T' and 'L', and the matrix is 3*3, we can think 'T' and 'L' are:

1 1 1	1 0 0

0 1 0	1 0 0

0 1 0	1 1 1

so we can recognize the character with only one pixel, such as bottom-left pixel. The answer is 1.

## Algorithm: 
Recognization of character using minimum number of pixel in an Image. Algorithm works on the principle of Information contained in bits of layered vector i.e v1[i], v2[i] .. and so on.

## Functions Used
Defining 1D, 2D and 3D vector for storing images pixel in cube of kxmxn

* typedef vector <int> v1d;
* typedef vector <v1d> v2d;
* typedef vector <v2d> v3d;

bit_set array contains, unique set of bit_vectors of any (m,n) pixel across all k_image. bit_set do not contain repeated bit_vector, all one or all zero bit_vec, neither any two bit_vector are inversion of each other

* void update(v2d &bit_set, v1d &bit);

check function checks weather, bit_vector a != b

* bool check(v1d &a, v1d &b);

checks if bit_vector contains all ones or zero

* bool allsamecheck(v1d &a);

compare function help to sort bit vector based on
information it contain

* bool compare(v1d &a, v1d &b);

Found function returns true, if i bit_vector from
bit set can represent k-> different combination

* bool found( v2d &bit_set, int i, int k);

returns information stored in bit_vector (bit)

* int info(v1d bit);

Return min_pixel required to recognize char

* int min_pix(v2d &bit_set, int log_k, int k);

return inverted bit vector of a

* v1d inversion(v1d &a);
