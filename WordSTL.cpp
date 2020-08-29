/**
 Author       : Tue Doan
 Date         : April 1, 2019
 File         : WordSTL.cpp
 Purpose      : Vector List of WordData Objects.
                Implementations of member functions including inherited pure virtual fns.
 */

#include <assert.h>
#include <iostream>
#include "WordSTL.h"
#include "SortSearch.h"

using namespace std;

WordSTL::WordSTL() {}

bool WordSTL::incMatch(WordData temp) {
  for(int idx = 0; idx < TheWords.size(); idx++) {
    if (temp.getWord() == TheWords[idx].getWord()) {
      TheWords[idx].incCount();
      return true;
    }
  }
  return false;
}

void WordSTL::parseIntoList(ifstream &inf) {
  WordData word;
  while (inf >> word) {
    if (!incMatch(word.getWord())) {
      TheWords.push_back(word);
    }
  }
  WordData *p = &TheWords.front();
  selSort(p, TheWords.size());
}

void WordSTL::printIteratively() {
  vector<WordData>::iterator itr;
  cout<<"--------------------------"<<endl;
  cout<<"|Vector  List  Iterative |"<<endl;
  cout<<"|Word         Occurences |"<<endl;
  cout<<"--------------------------"<<endl;

  for (itr = TheWords.begin(); itr != TheWords.end(); itr++) {
    cout << (*itr) << endl;
  }
}

void WordSTL::printRecursively() {
  printPtrRecursively();
}

void WordSTL::printPtrRecursively() {
  vector<WordData>::iterator itr;
  cout<<"--------------------------"<<endl;
  cout<<"|Vector  List  Recursive |"<<endl;
  cout<<"|Word         Occurences |"<<endl;
  cout<<"--------------------------"<<endl;
  if (!TheWords.empty()) {
    itr = TheWords.begin();
    printPtrRecursivelyHelper(itr);
  }
}

void WordSTL::printPtrRecursivelyHelper(vector<WordData>::iterator itr) {
  cout << (*(itr)) << endl;
  if (++itr != TheWords.end()) {
    printPtrRecursivelyHelper(itr);
  }
}

