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
#include "fifo.h" // for FIFO structure/container
using namespace std;

/**
 * This class implements storage and search examples
 */
class mySearch {
public:
    myFIFO storage; //!< Variable that stores the array

    /**
     * Constructor
     */
    mySearch() {
        cout << "Added a seqSearch instance" << endl;
    }

    /**
     * Fills storage with sequential numbers starting with start
     * 
     * @param start - The number to start filling at
     */
    void fillStorage(int start) {
        for(int ii = 0; ii < storage.bufLen(); ii++){
            storage.add(start++);
        }
    }

    void printStorage() {
        storage.printStats();
    }

    /**
     * Sequential search for the value passed
     * 
     * @param searchTerm The term to search for
     * @param N Returns the number of iterations to find searchTerm (Pass by reference)
     * @return Returns the location of searchTerm or -1 if not found
     */
    int seqSearch(int searchTerm, int &N) {
        N = 0; // initialize N
        for(int ii = 0; ii < storage.lenFull(); ii++) {
            if(storage.getElement(ii) == searchTerm) {
                N = ii+1;
                return(ii);
            }
        }
        N = storage.lenFull();
        return(-1);
    }
  
    /**
     * Binary search for the value passed
     * 
     * This requires the data to be ordered in increasing value. This is 
     * based off the example in Malik's Data Structures in C++ 2nd Ed.
     * 
     * @param searchTerm The term to search for
     * @param N Returns the number of iterations to find searchTerm (Pass by reference)
     * @return Returns the location of searchTerm or -1 if not found
     */
    int binSearch(int searchTerm, int &N) {
        int first = 0; // index to first value to search
        int last = storage.lenFull() - 1; // index to last value to search
        int mid; // index to the middle element
        bool found = false; // true if searchTerm is found
        N = 0; // initialize N

        while((first <= last) && !found) {
            N++; // increment iteration counter
            mid = (first + last)/2;

            if(storage.getElement(mid) == searchTerm) {
                found = true;
            } else if(storage.getElement(mid) > searchTerm) {
                last = mid - 1;
            } else { // searchTerm is > mid->value
                first = mid + 1;
            }
        }
        if(found) {
            return(mid);
        } else {
            return(-1);
        }
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
    mySearch s1; 
    int nIterations;
    vector<int> allIters;
    s1.fillStorage(0);
    s1.printStorage();
/*
    cout << "Sequential searching" << endl;
    for(int ii = 0; ii < (s1.storage.lenFull()+1); ii++)
    {
        //cout << "Search for " << ii << " returns ";
        //cout << s1.search(ii, nIterations) << " in " << nIterations; 
        //cout << " iterations" << endl;
        s1.seqSearch(ii, nIterations);
        allIters.push_back(nIterations);
    }
    cout << "Calculating the average" << endl;
    cout << "The average number of iterations for sequential search is ";
    cout << avg1(allIters) << endl;
*/
    cout << "Binary searching" << endl;
    for(int ii = 0; ii < (s1.storage.lenFull()+1); ii++)
    {
        s1.binSearch(ii, nIterations);
        allIters.push_back(nIterations);
    }
    cout << "Calculating the average" << endl;
    cout << "The average number of iterations for binary search is ";
    cout << avg1(allIters) << endl;

}
