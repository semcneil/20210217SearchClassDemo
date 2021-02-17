/**
 * @file fifo.h
 * @brief This is a simple implementation of a FIFO queue
 * @details This only uses arrays, no STL
 * @author Seth McNeill
 * @date 2021 February 02
 * 
 */

// Safeguard for multiple inclusions
#ifndef MY_FIFO_H
#define MY_FIFO_H
#include <iostream>

/**
 * Implements an integer FIFO
 */
class myFIFO {
    public:
        /** 
         * Constructor
         */
        myFIFO();

        /**
         * Adds a integer to the back of the FIFO
         * 
         * @param x Integer to add to the FIFO
         * @returns true if successful, false otherwise
         */
        bool add(int x);

        /**
         * Removes an integer from front of the FIFO
         * 
         * @returns value removed from FIFO, -999999999 if error
         */
        int remove();

        /**
         * Prints the information about the buffer
         */
        void printStats();

        /**
         * Returns the number of full spaces in the fifo
         */
        int lenFull();

        /**
         * Returns the length of the buffer
         */
        int bufLen();

        /**
         * Returns iith element of the FIFO
         * 
         * @param ii - which element to return
         */
        int getElement(int ii);

    private:
        static const int bufLength = 5; //!< length of the buffer
        int buffer[bufLength]; //!< Buffer that stores the FIFO data
        int bufFront = 0; //<! Index to front of FIFO where items are removed to next item to remove
        int bufBack = 0; //<! Index to to back of FIFO where items are added to next location to fill
        int length = 0; //<! Running total of full elements
}; // don't forget the trailing semicolon


#endif