/****************************************************************/
/*   Author:         Adam Tal                                   */
/*   Course:         CIS237 010                                 */
/*   Assignment:     #1                                         */
/*   Due Date:       April 9, 2019                              */
/*   Filename:       WordData.h                                 */
/*   Purpose:        The Only Addition i made to this file was  */ 
/*                   an overloading of the << operator.         */
/****************************************************************/

#ifndef WORDDATA_H
#define WORDDATA_H
#include <iostream>
#include <string>

using namespace std;

/**
 * WordData object, hold a string and its occurrence
 */
class WordData {

public:

        /**
         Function name: WordData \n
         Description  : Constructor - construct an WordData object \n
         Member type  : Mutator \n
         Parameters   : string wrd - a string - input \n
                        int cnt - string occurrence - input \n
         Return value : None \n
         */
        WordData(string wrd = "", int cnt = 1);

        //Sets
        /**
         Function name: WordData \n
         Description  : set word \n
         Member type  : Mutator \n
         Parameters   : string wrd - a string - input \n
         Return value : None \n
         */
        void setWord(string wrd);
  
        /**
         Function name: WordData \n
         Description  : set count \n
         Member type  : Mutator \n
         Parameters   : int cnt - string occurrence - input \n
         Return value : None \n
         */
        void setCount(int cnt);

        /**
         Function name: setWordData \n
         Description  : set whole WordData object \n
         Member type  : Mutator \n
         Parameters   : string wrd - a string - input \n
                        int cnt - string occurrence - input \n
         Return value : None \n
         */
        void setWordData(string,int);

        //Gets
        /**
         Function name: getWord \n
         Description  : get word \n
         Member type  : Inspector \n
         Parameters   : None
         Return value : string - string (word) \n
         */
        string getWord() const;
  
        /**
         Function name: getCount \n
         Description  : get string occurrence \n
         Member type  : Inspector \n
         Parameters   : None
         Return value : int - string occurrence \n
         */
        int getCount() const;

        //Increment
        /**
         Function name: incCount \n
         Description  : increment string occurrence \n
         Member type  : Mutator \n
         Parameters   : int inc = 1 - increment occurrence by 1 \n
         Return value : None \n
         */
        void incCount(int inc = 1);
  
        /**
         Function name: operator< \n
         Description  : overload less than operator, compare 2 words \n
         Member type  : Facilitator \n
         Parameters   : const WordData &right - WordData object - input \n
         Return value : bool - return true if less than, otherwise false \n
         */
        bool operator<(const WordData &right) const;
        /**
         Function name: operator> \n
         Description  : overload greater than operator, compare 2 words \n
         Member type  : Facilitator \n
         Parameters   : const WordData &right - WordData object - input \n
         Return value : bool - return true if greater than, otherwise false \n
         */
        bool operator>(const WordData &right) const;
        /**
         Function name: operator== \n
         Description  : overload double equal operator, compare 2 words \n
         Member type  : Facilitator \n
         Parameters   : const WordData &right - WordData object - input \n
         Return value : bool - return true if equal, otherwise false \n
         */
        bool operator==(const WordData &right) const;

private:

        //variables
        string word;
        int count;


};

/**
 Function name: operator<< \n
 Description  : overload output stream \n
 Parameters   : ostream &output - output stream - input & output \n
                const WordData &words - WordData object - input \n
 Return value : ostream - output stream \n
 */
ostream &operator<<(ostream& output, const WordData &words);

/**
 Function name: operator>> \n
 Description  : overload input file stream \n
 Parameters   : ifstream &inf - input file stream - input & output \n
                WordData &right - WordData object - input \n
 Return value : ifstream - input file stream \n
 */
ifstream &operator>>(ifstream& inf, WordData &right);

#endif
