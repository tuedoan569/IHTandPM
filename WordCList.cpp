/**
 Author       : Tue Doan
 Date         : April 1, 2019
 File         : WordCList.cpp
 Purpose      : Circular Linked List (container) of WordDataObjects.
                Implementations of member functions including inherited pure virtual fns.
 */

#include <assert.h>
#include <iostream>
#include "WordCList.h"

using namespace std;

WordCList::WordCList() {}

void WordCList::parseIntoList(ifstream &inf) {
  WordData word, *p;
  while (inf >> word) {
    p = theWords.insert(word);
    if (p != NULL) {
      (*p).incCount();
    }
  }
}

void WordCList::printIteratively() {
  listItr<WordData> itr(theWords);
  cout<<"--------------------------"<<endl;
  cout<<"|Linked  List  Iterative |"<<endl;
  cout<<"|Word         Occurences |"<<endl;
  cout<<"--------------------------"<<endl;

  if (!itr.isEmpty()) {
    for(itr.begin(); !(itr.isLastNode()); itr++) {
      cout <<(*(itr)) << endl;
    }
    cout << *(itr) << endl;
  }
}

void WordCList::printRecursively() {
  listItr<WordData> itr(theWords);
  cout<<"--------------------------"<<endl;
  cout<<"|Linked  List  Recursive |"<<endl;
  cout<<"|Word         Occurences |"<<endl;
  cout<<"--------------------------"<<endl;
  if (!itr.isEmpty()) {
    itr.begin();
    printRecursivelyHelper(itr);
  }
 
}

void WordCList::printRecursivelyHelper(listItr<WordData> itr) {
  cout << (*(itr)) << endl;
  if (!itr.isLastNode()) {
    printRecursivelyHelper(++itr);
  }
}

