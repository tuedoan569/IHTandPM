/**
 Author       : Dr. Spiegel (with thanks to Adam Tal)
 Update       : Tue Doan
 Date         : April 1, 2019
 Course:      : CIS237 310
 File         : app.cpp
 Purpose      : This Example inputs a string and demonstrates how to store
                it using a subclass of an abstract base class that incorporates
                virtual functions to enable polymorphism. If a file name is
                input through the command line all of the options will be
                done automatically for the first line of the file.
                This Example also time the print functions.
 */

/**
 @file app.cpp
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <chrono>
#include "WordList.h"
#include "WordDataList.h"
#include "WordCList.h"
#include "WordSTL.h"
// #include "WordData.h"        app only knows about the lists!

using namespace std;
using namespace std::chrono;


/**
 Function name: processUserRequest \n
 Description  : regulates the output base on user input \n
 Parameters   : WordList *&TheList - pointer to the base class - input \n
                ifstream &inf: file input stream - input & output \n
                string filename: stored file name - input   \n
 Return value : None \n
 */
void processUserRequest(WordList *&TheList, ifstream &inf, string filename);


/**
 Function name: openFile \n
 Description  : open the user entered file \n
 Parameters   : ifstream &inf: file input stream - input  & output \n
                string filename: stored file name - input   \n
 Return value : bool - true if the file opened, otherwise false \n
 */
bool openFile(ifstream &inf, string &filename);

/**
 Function name: displayMenu \n
 Description  : displays the menu on the screen \n
 Parameters   : None \n
 Return value : char - user input character \n
 */
char displayMenu();

/**
 Function name: printEverything \n
 Description  : output every available options in the menu \n
 Parameters   : char **argv - command line argument - input \n
                ifstream &inf: file input stream - input  & output \n
                WordList *TheList- pointer to the base class - input   \n
 Return value : None \n
 */
void printEverything(char **argv, ifstream &inf,WordList *TheList);

/**
 Function name: initArrayObj \n
 Description  : initialize an array of WordData objects and parse
                file data into the array \n
 Parameters   : WordList *TheList- pointer to the base class - input \n
                ifstream &inf: file input stream - input  & output \n
                string fileName - stored file name - input \n
 Return value : None \n
 */
void initArrayObj(WordList *&TheList, ifstream &inf, string fileName);

/**
 Function name: initLinkedList \n
 Description  : initialize Linked List of WordData objects and parse
                file data into the list \n
 Parameters   : WordList *TheList- pointer to the base class - input \n
                ifstream &inf: file input stream - input  & output \n
                string fileName - stored file name - input \n
 Return value : None \n
 */
void initLinkedList(WordList *&TheList, ifstream &inf, string fileName);

/**
 Function name: initVector \n
 Description  : initialize a vector of WordData objects and parse
                file data into the vector \n
 Parameters   : WordList *TheList- pointer to the base class - input \n
                ifstream &inf: file input stream - input  & output \n
                string fileName - stored file name - input \n
 Return value : None \n
 */
void initVector(WordList *&TheList, ifstream &inf, string fileName);

/**
 Function name: main \n
 Description  : the main program \n
 Parameters   : int argc - number of argument - input \n
                char *argv[] - array of char (argument) - input \n
 Return value : int - return 0 if exit normally \n
 */
int main(int argc,char *argv[]) {
  ifstream inf;
  WordList *TheList;
  string fileName = "";
  bool result;
  if(argc>1) { //if there was an input on the command line

      inf.open(argv[1]); //try and open the file
      if (inf.fail())       //if the file does not open
        {                    //terminate
          cout<<"Sorry, the file failed to open."<<endl;
          return 0;
        }
      printEverything(argv,inf,TheList);
      return 0;
  } else {
    result = openFile(inf, fileName);
    if (!result) {
      cout << "Sorry, the file failed to open." << endl;
    } else {
      processUserRequest(TheList, inf, fileName);
    }
  }
  // TheList is a pointer to a WordList that is pointed at a WordList subclass
  
  return 0;
}

void processUserRequest(WordList *&TheList, ifstream &inf, string fileName) {
  high_resolution_clock::time_point begin, end;
  duration<double> ticks;
  char selection = displayMenu();
  while (selection != '8') {
    switch(selection) {
      case '1':
        initArrayObj(TheList, inf, fileName);
        begin = high_resolution_clock::now();
        TheList->printIteratively();
        end = high_resolution_clock::now();
        ticks = duration_cast<microseconds>(end-begin);
        cout << "It took me " << ticks.count() << " microseconds." << endl;
        break;
        
      case '2':
        initArrayObj(TheList, inf, fileName);
        begin = high_resolution_clock::now();
        TheList->printRecursively();
        end = high_resolution_clock::now();
        ticks = duration_cast<microseconds>(end-begin);
        cout << "It took me " << ticks.count() << " microseconds." << endl;
        break;
        
      case '3':
        initArrayObj(TheList, inf, fileName);
        begin = high_resolution_clock::now();
        TheList->printPtrRecursively();
        end = high_resolution_clock::now();
        ticks = duration_cast<microseconds>(end-begin);
        cout << "It took me " << ticks.count() << " microseconds." << endl;
        break;
        
      case '4':
        initLinkedList(TheList, inf, fileName);
        begin = high_resolution_clock::now();
        TheList->printIteratively();
        end = high_resolution_clock::now();
        ticks = duration_cast<microseconds>(end-begin);
        cout << "It took me " << ticks.count() << " microseconds." << endl;
        break;
        
      case '5':
        initLinkedList(TheList, inf, fileName);
        begin = high_resolution_clock::now();
        TheList->printRecursively();
        end = high_resolution_clock::now();
        ticks = duration_cast<microseconds>(end-begin);
        cout << "It took me " << ticks.count() << " microseconds." << endl;
        break;
        
      case '6':
        initVector(TheList, inf, fileName);
        begin = high_resolution_clock::now();
        TheList->printIteratively();
        end = high_resolution_clock::now();
        ticks = duration_cast<microseconds>(end-begin);
        cout << "It took me " << ticks.count() << " microseconds." << endl;
        break;
        
      case '7':
        initVector(TheList, inf, fileName);
        begin = high_resolution_clock::now();
        TheList->printRecursively();
        end = high_resolution_clock::now();
        ticks = duration_cast<microseconds>(end-begin);
        cout << "It took me " << ticks.count() << " microseconds." << endl;
        break;
        
      case '8':
        cout<<"Goodbye"<<endl;
        break;
      default:
        cout<<"I cannot understand "<<selection<<".  Try again."<<endl;
        break;
    }
    selection = displayMenu();
  }
}

bool openFile(ifstream &inf, string &fileName) {
  cout<<"Please enter a file name:";
  cin >> fileName;
  inf.open(fileName.c_str());
  return inf.is_open();
}

char displayMenu()
{
  char selection;
  cout<<endl;
  cout<<"How do you want to print your sentence elements?"<<endl;
  cout<<"------------------------------------------------"<<endl;
  cout<<"1. Object Array Iterative"<<endl;
  cout<<"2. Object Array Recursive"<<endl;
  cout<<"3. Object Array Pointer Recursive"<<endl;
  cout<<"4. Circular List Iterator"<<endl;
  cout<<"5. Circular List Iterator Recursive"<<endl;
  cout<<"6. STL Object Iterative"<<endl;
  cout<<"7. STL Object Recursive"<<endl;
  cout<<"8. Quit"<<endl;
  cin >> selection;
  return selection;
}

void printEverything(char **argv, ifstream &inf,WordList *TheList) {
  high_resolution_clock::time_point begin, end;
  duration<double> ticks;
  
  inf.close();
  inf.clear();
  inf.open(argv[1]);
  TheList = new WordDataList;
  TheList->parseIntoList(inf);
  
  begin= high_resolution_clock::now();
  TheList->printIteratively();
  end = high_resolution_clock::now();
  ticks = duration_cast<microseconds>(end-begin);
  cout << "It took me " << ticks.count() << " microseconds." << endl;
  
  begin= high_resolution_clock::now();
  TheList->printRecursively();
  end = high_resolution_clock::now();
  ticks = duration_cast<microseconds>(end-begin);
  cout << "It took me " << ticks.count() << " microseconds." << endl;
  
  begin= high_resolution_clock::now();
  TheList->printPtrRecursively();
  end = high_resolution_clock::now();
  ticks = duration_cast<microseconds>(end-begin);
  cout << "It took me " << ticks.count() << " microseconds." << endl;
  
  inf.close();
  inf.clear();
  inf.open(argv[1]);
  TheList = new WordCList;
  TheList->parseIntoList(inf);
  
  begin= high_resolution_clock::now();
  TheList->printIteratively();
  end = high_resolution_clock::now();
  ticks = duration_cast<microseconds>(end-begin);
  cout << "It took me " << ticks.count() << " microseconds." << endl;
  
  begin= high_resolution_clock::now();
  TheList->printRecursively();
  end = high_resolution_clock::now();
  ticks = duration_cast<microseconds>(end-begin);
  cout << "It took me " << ticks.count() << " microseconds." << endl;
  
  inf.close();
  inf.clear();
  inf.open(argv[1]);
  TheList = new WordSTL;
  TheList->parseIntoList(inf);
  
  begin= high_resolution_clock::now();
  TheList->printIteratively();
  end = high_resolution_clock::now();
  ticks = duration_cast<microseconds>(end-begin);
  cout << "It took me " << ticks.count() << " microseconds." << endl;
  
  begin= high_resolution_clock::now();
  TheList->printPtrRecursively();
  end = high_resolution_clock::now();
  ticks = duration_cast<microseconds>(end-begin);
  cout << "It took me " << ticks.count() << " microseconds." << endl;
  
  inf.close();
  inf.clear();
  
}

void initArrayObj(WordList *&TheList, ifstream &inf, string fileName) {
  inf.close();
  inf.clear();
  inf.open(fileName.c_str());
  TheList = new WordDataList;
  TheList->parseIntoList(inf);
}

void initLinkedList(WordList *&TheList, ifstream &inf, string fileName) {
  inf.close();
  inf.clear();
  inf.open(fileName.c_str());
  TheList = new WordCList;
  TheList->parseIntoList(inf);
}

void initVector(WordList *&TheList, ifstream &inf, string fileName) {
  inf.close();
  inf.clear();
  inf.open(fileName.c_str());
  TheList = new WordSTL;
  TheList->parseIntoList(inf);
}
