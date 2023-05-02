/*  - Nora Mirabal
    - Student ID: 2370638
    - Student Email: mirabal@chapman.edu
    - CPSC 350-02
    - Assignment 3: Do you see what I see ?
*/

#ifndef SPEAKERVIEW_H
#define SPEAKERVIEW_H
#include "MonoStack.h"

using namespace std;

class SpeakerView {
public:
    SpeakerView(string inputFileName, char order);
    ~SpeakerView();
    void display();
private:
    int P; //number of doubles per line
    int N; //number of lines
};

#endif