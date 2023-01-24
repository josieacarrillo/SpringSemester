#ifndef DICTIONARY_H
#define DICTIONARY_H

#define NCHILD 30 /* a-z, ', -, _, terminator of word */

//using C++ instead ...
class dictNode
{
// Children nodes represent mapping to possible characters
// of a word and the terminator character of a word.
// Note the C string ends with a null \0 character.
// Essentially, the index of each node in the next[] dictNode*
// array is mapped to a particular valid character
// or the terminator character.
// For example, say index 0 is mapped
// to character ‘a’, index 29 is mapped to the terminator
// character. If the next character of the word is a, a new node
// would be created and assigned to next[0]. Setting next[0]
// from a null pointer to a new node means setting the next
// character of the word to ‘a’.
// Note all nodes in the next[] are initialized with a null
// pointer.
// After setting the last node corresponding to the last
// character of the word, to terminate a word, you would
// set the child node of the next [] of last character node
// at the terminator index position to a new node, to indicate
// the end of the word.
//
dictNode *next[NCHILD];
};