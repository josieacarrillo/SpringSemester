//main program that :
//Read words from a dictionary text file and insert them to a dictionary tree.
//Read words from test text file, and for each word read in: search, count, and print the number of words in the dictionary tree that start with it.

#include "dictionary.h"
using namespace std;
#include <iostream>
#include <stdio.h>
#include <fstream>

int main(int argc, char **argv) {


    //start off with necessary checks: args, file,
    //arg check , takes in 2.

        if (argc != 3) {
            cout << "Er0rr!! Exiting... Not enough parameters used." << endl;
            exit(1);
        }
    // file check
    for (int i = 1; i <= 2; i++) {
        std::ifstream fileCheck(argv[i]);
        if (!fileCheck.is_open()) {
            cout << "Er0rr!! Double check if file exists" , i << endl;
            exit(1);
        }
        fileCheck.close();
    }

// now we can start working with the files..


}