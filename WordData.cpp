/****************************************************************/
/*   Author:         Adam Tal                                   */
/*   Course:         CIS237 010                                 */
/*   Assignment:     #1                                         */
/*   Due Date:       January 30, 2009                           */
/*   Filename:       WordData.cpp                               */
/*   Purpose:        The Only Addition i made to this file was  */ 
/*                   an overloading of the << operator.         */
/****************************************************************/
/***************************************
 *                                     *
 *    File:    WordData.cpp            *
 *    Author:  Michael Lanciano        *
 *    Date:    2/12/06                 *
 *    Purpose: Member implementation   *
 *             for Word Data class     *
 *                                     *
 ***************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include "WordData.h"

using namespace std;

WordData::WordData(string wrd, int cnt)
{
        setWordData(wrd, cnt);
}

void WordData::setWord(string wrd)
{
        word = wrd;
}

void WordData::setCount(int cnt)
{
        count = cnt;
}

void WordData::setWordData(string wrd, int cnt)
{
        setWord(wrd);
        setCount(cnt);
}
string WordData::getWord() const
{
        return(word);
}

int WordData::getCount() const
{
        return(count);
}

void WordData::incCount(int inc)
{
        count+=inc;
}

bool WordData::operator<(const WordData &right) const {
  return getWord() < right.getWord();
}

bool WordData::operator>(const WordData &right) const {
  return getWord() > right.getWord();
}

bool WordData::operator==(const WordData &right) const {
  return getWord() == right.getWord();
}

ostream &operator<<(ostream& output, const WordData &words) {
  output<<words.getWord()<<"\t\t"<<words.getCount();
  return output;
}

ifstream &operator>>(ifstream& inf, WordData &right) {
  string nextWord;
  inf >> nextWord;
  right.setWord(nextWord);
  right.setCount(1);
  return inf;
}

