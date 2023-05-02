/*  - Nora Mirabal
    - Student ID: 2370638
    - Student Email: mirabal@chapman.edu
    - CPSC 350-02
    - Assignment 3: Do you see what I see ?
*/

#include "SpeakerView.h"
#include "MonoStack.h"
#include "Stack.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
// #include <iomanip>
using namespace std;

SpeakerView::SpeakerView(string inputFileName, char order){
    string line;
    string tempHeight;
    string height;
    int Pcount = 0;
    int Ncount = 0;

    Stack<double> *stackArr; //array of stacks
    MonoStack<double> *monoStackArray; //array of mono stacks


    fstream inputFile;
    inputFile.open(inputFileName, ios::in);
    if (inputFile.is_open()){
        while (getline(inputFile, line)){
            if (Ncount == 0) {
                //a first pass through the first line to get the stack arrays initialized
                istringstream tt(line);
                while (tt >> tempHeight){
                    ++Pcount;
                }
                stackArr = new Stack<double>[Pcount];
                monoStackArray = new MonoStack<double>[Pcount];
            }
            istringstream ss(line);
            Pcount = 0;
            while (ss >> height){
                if (Ncount == 0){
                    //initialize the stacks the first time
                    Stack<double> *stack;
                    stack = new Stack<double>(5);
                    stackArr[Pcount] = *stack; 
                    MonoStack<double> *monoStack;
                    monoStack = new MonoStack<double>(5,'d');
                    monoStackArray[Pcount] = *monoStack;                  
                }
                stackArr[Pcount].push(stod(height)); //push all values to the regular stack
                ++Pcount;
            } 
            ++Ncount;
        }
        //now we process the array of regular stacks to populate the mono stacks
        for (int i = 0; i < Pcount; i++){
            for (int j = 0; j < Ncount; j++){
                double value = stackArr[i].pop();
                monoStackArray[i].push(value);
            }
        }
        //final cout comments
        for (int i = 0; i < Pcount; ++i){
            string tempDisplay = monoStackArray[i].display();
            cout << "In column " << i << " there are " << monoStackArray[i].size() << " that can see. Their heights are: " << tempDisplay << " inches." << endl;
        }
    }
}

SpeakerView::~SpeakerView(){}

