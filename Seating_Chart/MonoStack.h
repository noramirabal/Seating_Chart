/*  - Nora Mirabal
    - Student ID: 2370638
    - Student Email: mirabal@chapman.edu
    - CPSC 350-02
    - Assignment 3: Do you see what I see ?
*/

#ifndef MONOSTACK_H
#define MONOSTACK_H
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class MonoStack{
public:
  MonoStack();
  MonoStack(int iSize, char order);
  ~MonoStack();
  int size();
  bool isEmpty();
  void push(T c);
  T pop();
  T peek();
  int getSize();
  string display();
protected:
  T* MonoStackArr;
  int count; //number of things in MonoStack
  int max; //most things we can hold
  int top;
  bool isFull();
  char o;
};

template <typename T>
MonoStack<T>::MonoStack(){ //O(1)
  top = -1;
  count = 0;
  max = 0;
  MonoStackArr = NULL;
}

template <typename T>
MonoStack<T>::MonoStack(int iSize, char order){ //O(1)
  top = -1;
  count = 0;
  max = iSize;
  MonoStackArr = new T[max];
  o = order;
}

template <typename T>
MonoStack<T>::~MonoStack(){ //O(1)
  delete[] MonoStackArr;
}

template <typename T>
int MonoStack<T>::size(){ //O(1)
  return count;
}

template <typename T>
bool MonoStack<T>::isEmpty(){ //O(1)
  return (count==0);
}

template <typename T>
bool MonoStack<T>::isFull(){ //O(1)
  return (count==max);
}

template <typename T>
void MonoStack<T>::push(T c){ //O(max) linear
//if the MonoStack is full, doubles the size of the MonoStack
    if (isFull()){
        T* temp = new double[2*max];
        for (int i = 0; i < max; ++i){
            temp[i] = MonoStackArr[i];
        }
        max *= 2;
        delete[] MonoStackArr;
        MonoStackArr = temp;
    } //checking if the value is already in the MonoStack
    for (int i = 0; i < max; ++i){
        if (MonoStackArr[i] == c){
            c = -1.0;
        }
    }
    if (c != -1.0){
        if (o == 'i'){
            int i = top;
            while (c < MonoStackArr[i] && !isEmpty()){
                pop();
                --i;
            }
            MonoStackArr[++top] = c;
        } else {
            int i = top;
            while (c > MonoStackArr[i] && !isEmpty()){
                pop();
                --i;
            }
            MonoStackArr[++top] = c;
        }
        ++count;
    }
}

template <typename T>
T MonoStack<T>::pop(){ 
    if (!isEmpty()){
        --count;
        return MonoStackArr[top--];
    }
    return 0.0;
}

template <typename T>
T MonoStack<T>::peek(){ 
    if (!isEmpty()){
        return MonoStackArr[top];
    }
    return 0.0;
}

template <typename T>
string MonoStack<T>::display(){
    string displayS = "";
    for (int i = 0; i < count; ++i){
        if (i > 0){
            displayS += ", ";
        }
        string temp = to_string(MonoStackArr[i]);
        displayS += temp.substr(0,temp.find(".")+2);
    }
    return displayS;
}
#endif