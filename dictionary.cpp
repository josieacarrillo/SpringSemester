// this file is used for implementing dictionary.h

#include "dictionary.h"
#include <stdio.h>
#include <iostream>

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

dictNode::dictNode() {
    isValid = false; //start off invalid
    for (int index = 0; index < NCHILD; index++){ //make sure we start from root node.
        next[index] = nullptr;
    }
}

//Add function - traverse the tree structure to insert the word, one character at a time starting from the root
// Return true if added successfully, or else false

bool dictNode::add(const char *wordBeingInserted = nullptr) {
    dictNode* currentNode = this;
    int nodeVal; // will use this to check if it's valid later on.

    const int endNode = getIndex('\0');

    //first check:

    if (wordBeingInserted == nullptr) {
        return false;
    }

    for (unsigned int i = 0; *(wordBeingInserted + i) != '\0'; ++i) {

        char cha = *(wordBeingInserted + i);

         nodeVal  = getIndex(cha);

         if (nodeVal == 100){ //second check: if the nodes value is invalid off the bat to return false!
            return false;
         }

        if (!currentNode->next[nodeVal]) {

            currentNode->next[nodeVal] = new dictNode();

        }

        currentNode = currentNode->next[nodeVal]; //move pointer to next node

    }

    currentNode->next[endNode] = new dictNode();
    currentNode->isValid = true;
    return true;


}

dictNode* dictNode::findEndingNodeOfAStr(const char *strBeingSearched) {

    dictNode* currNode = this; //this method is initially called on root node to start the search


    for (int i = 0; *(strBeingSearched + i) != '\0'; ++i) { //keep looping until reaching the ending node "\0"
        char nodeChar = *(strBeingSearched + i);
        int mapVal = getIndex(nodeChar); //using the character mapping function from above, return the associated val

        if (!currNode->next[mapVal]) { //returns the node pointer that ends the string if found
            return NULL; // otherwise,  return NULL pointer
        }
        currNode = currNode->next[mapVal];
    }
    if (currNode) {  //root
        return currNode;
    }
    return NULL;
}

//last function that counts the num of times
void dictNode::countWordsStartingFromANode(int &count) {

    dictNode *currNode = this;

    if (currNode == nullptr) // whole new word
        return;

    if (currNode->isValid == true)
        count++;

    for (int i = 0; i < NCHILD; i++) { //iterating whole arr
        if (currNode->next[i] != nullptr)
            currNode->next[i]->countWordsStartingFromANode(count); //recursive call on itselfd
    }
}