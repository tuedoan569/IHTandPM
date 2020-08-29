/**
 Author       : Tue Doan
 Date         : April 1, 2019
 File         : WordCList.h
 Purpose      : Circular Linked List (container) of WordData objects.
                 Printing can be iterative or recursive.
 */

#ifndef _WordCList_
#define _WordCList_
#include <assert.h>
#include <iostream>
#include "LinkedList.h"
#include "WordList.h"
#include "WordData.h"

using namespace std;

/**
 * Subclass of WordList, implement Circular Linked List of WordData objects
 */
class WordCList : public WordList
{
public:
  
  /**
   Function name: WordCList \n
   Description  : Constructor - construct an empty Circular Linked List of WordData objects \n
   Member type  : Mutator \n
   Parameters   : None \n
   Return value : None \n
   */
  WordCList();
  
  /**
   Function name: parseIntoList \n
   Description  : insert & increment string (WordData) into the Circular Linked List \n
   Member type  : Mutator \n
   Parameters   : ifstream &inf - input file stream - input & output \n
   Return value : None \n
   */
  void parseIntoList(ifstream &inf);
  
  /**
   Function name: printIteratively \n
   Description  : print the data iteratively \n
   Member type  : Inspector \n
   Parameters   : None \n
   Return value : None \n
   */
  void printIteratively();
  
  /**
   Function name: printRecursively \n
   Description  : print the data recursively \n
   Member type  : Inspector \n
   Parameters   : None \n
   Return value : None \n
   */
  void printRecursively();
  
  
private:
  LinkedList<WordData> theWords;
  
  /**
   Function name: printRecursivelyHelper \n
   Description  : function to actually perform recursive print \n
   Member type  : Inspector \n
   Parameters   : None \n
   Return value : None \n
   */
  void printRecursivelyHelper(listItr<WordData> itr);
};

#endif

