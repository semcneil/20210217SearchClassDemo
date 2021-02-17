/**
 * @file main.cpp
 * @brief This demonstrates header files, separate cpp files, and some searching.
 * @details Implements and times sequential searching using FIFO class
 * @author Seth McNeill
 * @date 2021 February 17
 * 
 */

#include <iostream>
#include "fifo.h"
using namespace std;

class seqSearch {
public:
    myFIFO storage; //!< Variable that stores the array

    /**
     * Constructor
     */
    seqSearch() {
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
     * Searches for the value passed
     * 
     * @param searchTerm
     * @return Returns the location of searchTerm or -1 if not found
     */
    int search(int searchTerm) {
        for(int ii = 0; ii < storage.lenFull(); ii++) {

        }
        return(-1);
    }
  
};

int main(int, char**) {
    seqSearch s1; 
    s1.fillStorage(0);
    s1.printStorage();
    cout << "Search for 1 returns " << s1.search(1) << endl;
}
