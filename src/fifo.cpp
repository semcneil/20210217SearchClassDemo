/**
 * @file fifo.cpp
 * @brief This is a simple implementation of a FIFO queue
 * @details This only uses arrays, no STL
 * @author Seth McNeill
 * @date 2021 February 02
 * 
 */

#include <iostream>
#include "fifo.h"
using namespace std;

/** 
 * Constructor
 */
myFIFO::myFIFO() { 
    for(int ii = 0; ii < bufLength; ii++) {
        buffer[ii] = 0;
    }
}

/**
 * Adds a integer to the back of the FIFO
 * 
 * @param x Integer to add to the FIFO
 * @returns true if successful, false otherwise
 */
bool myFIFO::add(int x) {
    //if(bufBack < bufLength) {
    if(length < bufLength) {
        buffer[bufBack] = x; // Add value to buffer
        bufBack++; // equivalent to bufBack = bufBack + 1
        bufBack = bufBack % bufLength; // wraps around to the beginning
        length++; // increment length since an element was added
        return(true);
    } else {
        cout << "bufBack exceeded buffer length" << endl;
        return(false);
    }
}

/**
 * Removes an integer from front of the FIFO
 * 
 * @returns value removed from FIFO, -999999999 if error
 */
int myFIFO::remove(){
    //if(bufFront < bufLength) {
    if(length > 0) { // bufFront == bufBack means the buffer is empty
        int retVal = buffer[bufFront];
        bufFront++;
        bufFront = bufFront % bufLength;
        length--; // decrement length since an element was removed
        return(retVal);
    } else {
        cout << "Error tried to remove beyond end of buffer" << endl;
        return(-999999999);
    }
}

/**
 * Prints the information about the buffer
 */
void myFIFO::printStats() {
    cout << "------------------" << endl;
    cout << "bufFront = " << bufFront << " stored at " << &bufFront << endl;
    cout << "bufBack = " << bufBack << " stored at " << &bufBack << endl;
//            cout << "buffer stored at " << buffer << " is:" << endl;
    cout << "length = " << length << endl;
    // print front
    for(int ii = 0; ii < bufLength; ii++) {
        if(ii == bufFront)
            cout << 'f';
        cout << '\t';
    }
    cout << endl;
    for(int ii = 0; ii < bufLength; ii++) {
        cout << buffer[ii] << '\t';
    }
    cout << endl;
    for(int ii = 0; ii < bufLength; ii++) {
        if(ii == bufBack)
            cout << 'b';
        cout << '\t';
    }
    cout << endl;
    cout << "==================" << endl;
}

/**
 * Returns the number of full spaces in the fifo
 */
int myFIFO::lenFull() {
    return(length);
}

/**
 * Returns the length of the buffer
 */
int myFIFO::bufLen() {
    return(bufLength);
}

/**
 * Returns iith element of the FIFO
 * 
 * @param ii - which element to return
 */
int myFIFO::getElement(int ii) {
    // check ii for invalid values
    // return the iith element
    return(buffer[(bufFront + ii) % bufLength]);
}