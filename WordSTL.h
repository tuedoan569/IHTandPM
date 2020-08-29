/**
 Author       : Tue Doan
 Date         : April 1, 2019
 File         : WordSTL.h
 Purpose      : Circular Linked List (container) of WordData objects.
                 Printing can be iterative or recursive.
 */

#ifndef _WordSTL_
#define _WordSTL_
#include <iostream>
#include <vector>
#include "WordList.h"
#include "WordData.h"

using namespace std;

/**
 * Subclass of WordList, implement vector of WordData objects
 */
class WordSTL : public WordList
{
public:
  
  /**
   Function name: WordSTL \n
   Description  : Constructor - construct an empty vector of WordData objects \n
   Member type  : Mutator \n
   Parameters   : None \n
   Return value : None \n
   */
  WordSTL();
  
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
  
  void printRecursively();
  
  /**
   Function name: printPtrRecursively \n
   Description  : print the data recursively \n
   Member type  : Inspector \n
   Parameters   : None \n
   Return value : None \n
   */
  void printPtrRecursively();
  
  
private:
  vector<WordData> TheWords;
  
  /**
   Function name: incMatch \n
   Description  : Look for a match and increment if found \n
   Member type  : Facilitator \n
   Parameters   : string temp - string being compared against - input \n
   Return value : bool - return true if found, otherwise false \n
   */
  bool incMatch(WordData temp);
  
  /**
   Function name: printRecursivelyHelper \n
   Description  : function to actually perform recursive print \n
   Member type  : Inspector \n
   Parameters   : None \n
   Return value : None \n
   */
  void printPtrRecursivelyHelper(vector<WordData>::iterator itr);
};

#endif

