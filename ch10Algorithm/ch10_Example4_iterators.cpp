/*
 * ##################################################################
 * ## Reserve Iterator
 * ##################################################################
 * A reverse iterator is an iterator that traverses a container backward, from the last
 * element toward the first. A reverse iterator inverts the meaning of increment (and
 * decrement). Incrementing (++it) a reverse iterator moves the iterator to the previous
 * element; derementing (--it) moves the iterator to the next element
 *
 * The containers, aside from forward_list, all have reverse iterators. We obtain a
 * reverse iterator by calling the rbegin, rend, crbegin, and crend members. These
 * members return reverse iterators to the last element in the container and one “past”
 * (i.e., one before) the beginning of the container. As with ordinary iterators, there are
 * both const and nonconst reverse iterators
 *
 *               vec.begin()                                  vec.end()
 *             |             | | | | ..... | |              |
 *  vec.rend()                                 vec.rbegin()
 *
 *  Note:  we can define a reverse iterator only from an iterator that supports --
 *         as well as ++. After all, the purpose of a reverse iterator is to move
 *         the iterator backward through the sequence
 *
 */
