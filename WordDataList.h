/**
 Author       : Dr. Spiegel
 Date         : April 1, 2019
 File         : WordDataList.h
 Purpose      : Container of WordData objects.
                Printing can be iterative or recursive.
 */

#ifndef WORDDATALIST_H
#define WORDDATALIST_H

#include <string>
#include "WordList.h"
#include "WordData.h"

using namespace std;

/**
 * Subclass of WordList, implement an array of WordData objects
 */
class WordDataList : public WordList {
public:
  /**
   Function name: WordDataList \n
   Description  : Constructor - construct an empty WordData object array \n
   Member type  : Mutator \n
   Parameters   : None \n
   Return value : None \n
   */
  WordDataList();

  /**
   Function name: parseIntoList \n
   Description  : Put a string of strings into the list object \n
   Member type  : Mutator \n
   Parameters   : ifstream &inf - input file stream - input & output \n
   Return value : None \n
   */
  virtual void parseIntoList(ifstream &inf);

  /**
   Function name: printInteratively \n
   Description  : print the data iteratively \n
   Member type  : Inspector \n
   Parameters   : None \n
   Return value : None \n
   */
  virtual void printIteratively();
  
  /**
   Function name: printRecursively \n
   Description  : print the data recursively \n
   Member type  : Inspector \n
   Parameters   : None \n
   Return value : None \n
   */
  virtual void printRecursively();
  
  /**
   Function name: printPtrRecursively \n
   Description  : print the data recursively with a pointer \n
   Member type  : Inspector \n
   Parameters   : None \n
   Return value : None \n
   */
  virtual void printPtrRecursively();

private:
  WordData TheWords[10];
  int numWords;

  /**
   Function name: incMatch \n
   Description  : Look for a match and increment if found \n
   Member type  : Facilitator \n
   Parameters   : string temp - string being compared against - input \n
   Return value : bool - return true if found, otherwise false \n
   */
  bool incMatch(string temp);
  
  /**
   Function name: printRecursivelyWorker \n
   Description  : Function to actually perform recursive print \n
   Member type  : Inspector \n
   Parameters   : int numWords - number of elements in the array - input \n
   Return value : None \n
   */
  void printRecursivelyWorker(int numWords);

  /**
   Function name: printRecursivelyWorker \n
   Description  : Function to actually perform recursive print using pointer \n
   Member type  : Inspector \n
   Parameters   : int numWords - number of elements in the array - input \n
   Return value : None \n
   */
  void printPtrRecursivelyWorker(int numWords);


};
  
#endif
