// this file is used for implementing dictionary.h

#include "dicttree.h"

// helper function that maps characters to an index :
// A’ and ‘a’ correspond to index 0, while the \0 null terminator is mapped to index 29
// ' , - , _ are mapped by my choice
//if 100 is returned, we know the char was invalid.

int getIndex(char character){
    switch(character){
        case 'a':
        case 'A':
            return 0;
        case 'b':
        case 'B':
            return 1;
        case 'c':
        case 'C':
            return 2;
        case 'd':
        case 'D':
            return 3;
        case 'e':
        case 'E':
            return 4;
        case 'f':
        case 'F':
            return 5;
        case 'g':
        case 'G':
            return 6;
        case 'h':
        case 'H':
            return 7;
        case 'i':
        case 'I':
            return 8;
        case 'j':
        case 'J':
            return 9;
        case 'k':
        case 'K':
            return 10;
        case 'l':
        case 'L':
            return 11;
        case 'm':
        case 'M':
            return 12;
        case 'n':
        case 'N':
            return 13;
        case 'o':
        case 'O':
            return 14;
        case 'p':
        case 'P':
            return 15;
        case 'q':
        case 'Q':
            return 16;
        case 'r':
        case 'R':
            return 17;
        case 's':
        case 'S':
            return 18;
        case 't':
        case 'T':
            return 19;
        case 'u':
        case 'U':
            return 20;
        case 'v':
        case 'V':
            return 21;
        case 'w':
        case 'W':
            return 22;
        case 'x':
        case 'X':
            return 23;
        case 'y':
        case 'Y':
            return 24;
        case 'z':
        case 'Z':
            return 25;
        case '-':
            return 26;
        case '_':
            return 27;
        case '\'':
            return 28;
        case '\0':
            return 29;
        default:
            return 100;
    }
};

