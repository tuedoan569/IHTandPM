// File: WordList.h
// Abstract base class for containers of word data
// Known subclasses:
//      WordDataList
// Coming soon: ParallelArrayWordList, WordVectorList, ...

/**
 Author       : Dr. Spiegel
 Date         : April 1, 2019
 File         : WordList.h
 Purpose      : Abstract base class for containers of word data
 */

#ifndef WORDLIST_H
#define WORDLIST_H

#include <fstream>
#include <string>

using namespace std;

/**
 * Abstract base class for containers of WordData
 */
class WordList {
public:

  /**
   Function name: parseIntoList \n
   Description  : Place the line of text into the data structure \n
   Member type  : Mutator \n
   Parameters   : ifstream &inf - input file stream - input & output \n
   Return value : None \n
   */
  virtual void parseIntoList(ifstream &inf)=0;

  /**
   Function name: printInteratively \n
   Description  : print the data iteratively \n
   Member type  : Inspector \n
   Parameters   : None \n
   Return value : None \n
   */
  virtual void printIteratively()=0;
  
  /**
   Function name: printRecursively \n
   Description  : print the data recursively \n
   Member type  : Inspector \n
   Parameters   : None \n
   Return value : None \n
   */
  virtual void printRecursively()=0;
  
  /**
   Function name: printPtrRecursively \n
   Description  : print the data recursively with a pointer \n
   Member type  : Inspector \n
   Parameters   : None \n
   Return value : None \n
   */
  virtual void printPtrRecursively() {}   // not pure virtual; why?
    
};
  
#endif
