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
 * This class implements storage and hash search examples
 */
class myHashSearch {
public:
    vector<int> storage; //!< Variable that stores the array
    int lenStorage;

    /**
     * Constructor: Only stores values >=0
     */
    myHashSearch(int size) {
        cout << "Added a seqSearch instance" << endl;
        lenStorage = size;
        // create and initialize the storage
        for(int ii = 0; ii < size; ii++) {
            storage.push_back(-1);
        }
    }

    /**
     * Computes the hash of an integer using the modulus function
     * 
     * @param num is integer to hash
     * @param modNumber is the integer to modulus by
     * @returns hash of num (num % modNumber)
     */
    int modHash(int num) {
        return(num % lenStorage);
    }

    /**
     * Computes the hash of an integer using a Knuth multiplicative method
     * 
     * Copied from a good stackovervlow page:
     * https://stackoverflow.com/a/665545
     * 
     * @param num is integer to hash
     * @returns hash of num 
     */
    int knuthHash(int num) {
        return(num*2654435761 % lenStorage);
    }

    /**
     * Adds a number to storage using hashing
     * 
     * @param num the number to add to storage
     * @returns true if successful, false otherwise
     */
    bool add(int num) {
        int hashedNum = knuthHash(num);
        if(storage.at(hashedNum) == -1) { // location is empty
            storage.at(hashedNum) = num;
            cout << "success adding " << num << endl;
            return(true);
        } else { // location was full
            // sequential search for empty spot
            for(int ii = hashedNum+1; ii < lenStorage; ii++) {
                if(storage.at(ii) == -1) { //found an empty location
                    storage.at(ii) = num;
                    cout << "sequential search added " << num << endl;
                    return(true);
                }
            }
            cout << "Collision: failed to add " << num << endl;
            return(false);
        }
    }

    /**
     * Fills storage with sequential numbers starting with start
     * 
     * @param start - The number to start filling at
     */
    void fillStorage(int start) {
        int ind; // index into the hash table
        for(int ii = 0; ii < lenStorage; ii++) {
            cout << "Adding " << start << " at location " << start % lenStorage << endl;
            storage.at(modHash(start)) = start;
            start++;
        }
    }

    /**
     * prints the contents of storage (beware of calling on large values)
     */
    void printStorage(){
        if(lenStorage < 10) {
            for(int ii = 0; ii < lenStorage; ii++) {
                cout << storage.at(ii) << '\t';
            }
            cout << endl;
        } else {
            cout << "Too long to display" << endl;
        }
    }

    /**
     * Hash search for the value passed
     * 
     * @param searchTerm The term to search for
     * @param N Returns the number of iterations to find searchTerm (Pass by reference)
     * @return Returns the location of searchTerm or -1 if not found
     */
    int search(int searchTerm, int &N) {
        N = 1; // initialize N
        int hashedNum = knuthHash(searchTerm);
        //int hashedNum = modHash(searchTerm);

        if(storage.at(hashedNum) == searchTerm) {
            return(hashedNum);
        } else {
            // sequential search for empty spot
            for(int ii = hashedNum+1; ii < lenStorage; ii++) {
                N++;
                if(storage.at(ii) == searchTerm) { //found the search term
                    cout << "sequential search found " << searchTerm << " at " << ii << endl;
                    return(ii);
                }
            }
            cout << "failed to find " << searchTerm << endl;
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
    int lenHashTable = 9;
    myHashSearch s1(lenHashTable); 
    int nIterations;
    int nTries = 5; // number of items in tryNums
    int tryNums[] = {11,6,16,21,26};
    vector<int> allIters;

    s1.printStorage();
    for(int ii = 0; ii < nTries; ii++) {
        s1.add(tryNums[ii]);
        s1.printStorage();
    }

    cout << "Hash based searching" << endl;
    for(int ii = 0; ii < nTries; ii++)
    {
        s1.search(tryNums[ii], nIterations);
        allIters.push_back(nIterations);
    }
    cout << "Calculating the average" << endl;
    cout << "The average number of iterations for hash search is ";
    cout << avg1(allIters) << endl;
}
