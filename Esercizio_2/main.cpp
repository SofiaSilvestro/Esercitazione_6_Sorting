#include <iostream>
#include <sstream>
#include <chrono> // useful to count time
#include <vector>
#include <algorithm> // useful for generate

#include "SortingAlgorithm.hpp"

using namespace std;
using namespace std::chrono;
using namespace SortLibrary;

void printvec(const vector<int> &vec)
{
    for(auto &v : vec)
        cout << v << " ";
    cout << endl;
}

vector<int> GenOrdVec(unsigned int& sizevec)
{
    int n = 0;
    vector<int> ordvec(sizevec);
    generate(ordvec.begin(), ordvec.end(),
             [&n] () {return n++;});
    /* If you want to print all the vector:
     * cout << "ordvec:\n";
     * for (unsigned int i = 0; i < sizevec; i++)
     *     cout << ordvec[i] << " ";
     * cout << endl; */
    return ordvec;
}

vector<int> GenRandVec(unsigned int &sizevec)
{
    /* commented lines are used if you want
     * to print all the vector */
    vector<int> randvec(sizevec);
    // cout << "randvec:\n";
    for (unsigned int i = 0; i < sizevec; i++)
    {
        randvec[i] = rand() % 100;
        // cout << randvec[i] << " ";
    }
    // cout << endl;
    return randvec;
}


/* Two possibilities to take arguments
 * from the command line:
 * 1) int main(int argcount, char *argvec[])
 * 2) int main(int argcount, char **argvec)
 * You can write on the command line from Qt Creator
 * or from the terminal git bash */

int main(int argcount, char **argvec)
{
    if(argcount != 2)
        cout << "More arguments than requested"
                " by the exercise" << endl;

    /* Declare variable to memorize the
     * dimension of vector */
    unsigned int sizevec;
    /* create stringstream object to read data
     * from the command line and convert int from
     * string to int type */
    stringstream ss(argvec[1]);
    ss >> sizevec;
    cout << "\nThe dimension of vectors is: "
         << sizevec << "\n" << endl;

    /** WITH MERGESORT **/

    // vec1 ordered
    vector<int> vecm1 = GenOrdVec(sizevec);

    steady_clock::time_point startm1
        = steady_clock::now();
    MergeSort2(vecm1);
    steady_clock::time_point endm1
        = steady_clock::now();

    double durationm1 = duration_cast<milliseconds>
                        (endm1 - startm1).count();
    /* If you want to print all the vector:
     * cout << "Ordered vecm1 with mergesort:\n";
     * print(vecm1); */
    cout << "Time operation with mergesort "
            "on an ordered vector: durationm1 = "
         << durationm1 << " ms\n" << endl;

    // vec2 randomic
    vector<int> vecm2 = GenRandVec(sizevec);
    steady_clock::time_point startm2 =
        steady_clock::now();
    MergeSort2(vecm2);
    steady_clock::time_point endm2 =
        steady_clock::now();

    double durationm2 = duration_cast<milliseconds>
                        (endm2 - startm2).count();
    /* If you want to print all the vector:
     * cout << "ordered vecm2 with mergesort:\n";
     * print(vecm2); */
    cout << "Time operation with mergesort "
            "on a randomic vector: durationm2 = "
         << durationm2 << " ms\n" << endl;



    /** WITH BUBBLESORT **/

    // vec1 ordered
    vector<int> vecb1= GenOrdVec(sizevec);
    steady_clock::time_point startb1 =
        steady_clock::now();
    BubbleSort(vecb1);
    steady_clock::time_point endb1 =
        steady_clock::now();

    double durationb1 = duration_cast<milliseconds>
                        (endb1 - startb1).count();
    /* If you want to print all the vector:
     * cout << "ordered vecb1 with bubblesort:\n";
     * print(vecb1); */
    cout << "Time operation with bubblesort "
            "on an ordered vector: durationb1 = "
         << durationb1 << " ms\n" << endl;

    // vec2 randomic
    vector<int> vecb2= GenRandVec(sizevec);
    steady_clock::time_point startb2 =
        steady_clock::now();
    BubbleSort(vecb2);
    steady_clock::time_point endb2 =
        steady_clock::now();

    double durationb2 = duration_cast<milliseconds>
                        (endb2 - startb2).count();
    /* If you want to print all the vector:
     * cout << "ordered vecb2 with bubblesort:\n";
     * print(vecb2); */
    cout << "Time operation with bubblesort "
            "on a randomic vector: durationb2 = "
         << durationb2 << " ms\n" << endl;

    return 0;
}
