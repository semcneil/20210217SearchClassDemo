/**
 * @file main.cpp
 * @brief This demonstrates header files, separate cpp files, and some searching.
 * @details Implements and times sequential searching using FIFO class
 * @author Seth McNeill
 * @date 2021 February 17
 * 
 */


#include <iostream> // for cout, cin
#include <vector> // for the vector container
#include <numeric> // for accumulate
using namespace std;

class hashSearch {
 public:
    vector<int> storage;
    hashSearch(int size) {
        for(int ii = 0; ii < size; ii++)
            storage.push_back(0); // initialize with zeros
    }

};

/**
 * Calculate the average value of a integer vector
 * 
 * This is taken from:
 * https://stackoverflow.com/a/35833470
 * It uses std::accumulate.
 * 
 * @param v is a integer std::vector
 * @returns The average value of the contents of v
 */
double avg1(vector<int> const& v) {
    return 1.0 * accumulate(v.begin(), v.end(), 0LL) / v.size();
}

int main(int, char**) {
    hasSearch s1; 
    int nIterations;
    vector<int> allIters;
    s1.fillStorage(0);
    s1.printStorage();
    // need to put internal timing here
    cout << "Hash Based Searching" << endl;
    for(int ii = 0; ii < (s1.storage.lenFull()+1); ii++)
    {
        //cout << "Search for " << ii << " returns ";
        //cout << s1.search(ii, nIterations) << " in " << nIterations; 
        //cout << " iterations" << endl;
        s1.search(ii, nIterations);
        allIters.push_back(nIterations);
    }
    cout << "Calculating the average" << endl;
    cout << "Hash search average number of iterations is " << avg1(allIters) << endl;
}