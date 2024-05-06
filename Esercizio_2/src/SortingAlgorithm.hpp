#ifndef __SORTING_ALGORITHM_H
#define __SORTING_ALGORITHM_H

#include <iostream>
#include <vector>

using namespace std;

/** This function permits to print the vectors
 *  contained in the program **/
void printvec(const vector<int> &vec);

/** This function creates a vector with elements
 *  in ascending order by using the
 *  function generate **/
vector<int> GenOrdVec(unsigned int& sizevec);

/** This function creates a vector with random
 *  elements between 0 and RAND_MAX = 100 **/
vector<int> GenRandVec(unsigned int &sizevec);

namespace SortLibrary {
/** This library contains the implementation
 *  of the two algorithms:
 *  mergesort, in three functions,
 *  and bubblesort, in only one function **/

template<typename T>
void Merge(vector<T> &v,
           const unsigned int &sx,
           const unsigned int &cx,
           const unsigned int &dx)
{
    unsigned int i = sx;
    unsigned int j = cx + 1;

    vector<T> b;
    b.reserve(dx - sx + 1);

    while( i <= cx && j <= dx)
    {
        if (v[i] <= v[j])
            b.push_back(v[i++]);
        else
            b.push_back(v[j++]);
    }

    if (i <= cx)
        b.insert(b.end(),
                 v.begin() + i,
                 v.begin() + cx + 1);
    if ( j <= dx)
        b.insert(b.end(),
                 v.begin() + j,
                 v.begin() + dx + 1);

    copy(b.begin(), b.end(), v.begin() + sx);

}

template<typename T>
void MergeSort1(vector<T> &v,
               const unsigned int &sx,
               const unsigned int &dx)
{
    if (sx < dx)
    {
        unsigned int cx = (sx + dx) / 2;
        MergeSort1(v, sx, cx);
        MergeSort1(v, cx + 1, dx);

        Merge(v, sx, cx, dx);
    }

}

template<typename T>
void MergeSort2(vector<T> &v)
{
    MergeSort1(v, 0, v.size()-1);
}

template<typename T>
void BubbleSort(vector<T> &data)
{
    size_t rem_size = data.size();
    // size_t last_seen = rem_size;
    bool swapped = true;

    while (swapped)
    {
        swapped = false;
        for (size_t i = 1; i < rem_size; i++)
        {
            if (data[i-1] > data[i])
            {
                swap(data[i-1], data[i]);
                swapped = true;
                // last_seen = i;
            }
        }
/* Below two different possibilities to optimize
 * the program:
 * with a new variable "last_seen" or by using
 * only one variable "rem_size" to represents the
 * dimension of the vector and to optimize the program.
 * I tried the two version and the time difference
 * is not very impressive, in average. */
        rem_size = rem_size - 1;
        // rem_size = last_seen;
    }
}
} // closing namespace

#endif // __SORTING_ALGORITHM_H
