/**
 Author       : Dr. Spiegel
 Date         : April 1, 2019
 File         : WordDataList.cpp
 Purpose      : Container of WordData objects.
                Implementations of member functions including inherited pure virtual fns.
 */

#include <sstream>
#include <iostream>
#include "WordDataList.h"
#include "SortSearch.h"

using namespace std;

  WordDataList::WordDataList()
  { numWords=0; }

  bool WordDataList::incMatch(string temp)
  { for(int i=0; i<numWords; i++) {
      if (temp==TheWords[i].getWord()) {
        TheWords[i].incCount();
        return true;
      }
    }  
    return false;
  }

  void WordDataList::parseIntoList(ifstream &inf)
  { string temp;
    while (inf >> temp) 
      if (!incMatch(temp) && numWords < 10) {
          TheWords[numWords].setWord(temp);
          TheWords[numWords++].setCount(1);
      }
    selSort(TheWords, numWords);
  }

  // Print the data iteratively
  void WordDataList::printIteratively()
//  void printObjectArrayIterator(WordData TheWords[], int numWords)
{
  cout<<"--------------------------"<<endl;
  cout<<"|Object  Array  Iterative|"<<endl;
  cout<<"|Word         Occurences |"<<endl;  
  cout<<"--------------------------"<<endl;
  for(int i=0; i<numWords; i++) {
    cout<<" "<<TheWords[i]<<endl;}
}

  
  // Print the data recursively
  void WordDataList::printRecursivelyWorker(int numWords)
  //void printObjectArrayRecursive(WordData TheWords[], int numWords)
  {
    if (numWords > 0) {
      if (numWords==1) {
        cout<<"--------------------------"<<endl;
        cout<<"|Object  Array  Recursive|"<<endl;
        cout<<"|Word         Occurences |"<<endl;
        cout<<"--------------------------"<<endl;
        cout<<" "<<TheWords[numWords-1]<<endl;
        return;
      }
      printRecursivelyWorker(numWords-1);
      cout<<" "<<TheWords[numWords-1]<<endl;
    }
    
  }

  // Call worker function to print the data recursively
  void WordDataList::printRecursively()
  {  printRecursivelyWorker(numWords); }


  // Print the data recursively with a pointer
  void WordDataList::printPtrRecursivelyWorker(int numWords)
  //void printObjectArrayPointerRecursive(WordData* TheWords, int numWords)
  {if (!numWords)
    { cout<<"--------------------------"<<endl;
      cout<<"|Object  Array  Pointer  |"<<endl;
      cout<<"|Word         Occurences |"<<endl;  
      cout<<"--------------------------"<<endl;
      return;
    }
    printPtrRecursivelyWorker(numWords-1);
    cout<<" "<<*(TheWords+(numWords-1))<<endl;
  }

  // Call worker function to print the data recursively
  void WordDataList::printPtrRecursively()
  { printPtrRecursivelyWorker(numWords); }
