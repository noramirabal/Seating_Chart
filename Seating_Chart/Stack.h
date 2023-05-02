/*  - Nora Mirabal
    - Student ID: 2370638
    - Student Email: mirabal@chapman.edu
    - CPSC 350-02
    - Assignment 3: Do you see what I see ?
*/

#ifndef STACK_H
#define STACK_H

using namespace std;

template <typename T>
class Stack{
public:
  Stack();
  Stack(int iSize);
  ~Stack();
  int size();
  bool isEmpty();
  void push(T c);
  T pop();
  T peek();
  void display();
private:
  T* stackArr;
  int count; //number of things in stack
  int max; //most things we can hold
  int top;
  bool isFull();
};

template <typename T>
Stack<T>::Stack(){ //O(1)
  top = -1;
  count = 0;
  max = 0;
  stackArr = NULL;
}

template <typename T>
Stack<T>::Stack(int iSize){ //O(1)
  top = -1;
  count = 0;
  max = iSize;
  stackArr = new T[max];
}

template <typename T>
Stack<T>::~Stack(){ //O(1)
  delete[] stackArr;
}

template <typename T>
int Stack<T>::size(){ //O(1)
  return count;
}

template <typename T>
bool Stack<T>::isEmpty(){ //O(1)
  return (count==0);
}

template <typename T>
bool Stack<T>::isFull(){ //O(1)
  return (count==max);
}

template <typename T>
void Stack<T>::push(T c){ //O(max) linear
  if(isFull()){
    T* temp = new T[2*max];
    for(int i = 0; i < max; ++i){
      temp[i] = stackArr[i];
    }
  }
  max *= 2;
  stackArr[++top] = c;
  ++count;
}

template <typename T>
T Stack<T>::pop(){ //O(1) better tell user to check if empty first
    if (!isEmpty()){
        --count;
        return stackArr[top--];
    }
    return 0.0;
}

template <typename T>
T Stack<T>::peek(){ //O(1) what about if empty?
    if (!isEmpty()){
        return stackArr[top];
    }
    return 0.0;
}

template <typename T>
void Stack<T>::display(){
    for (int i = 0; i < count; ++i){
        cout << stackArr[i] << " ";
    }
    cout << endl;
}

#endif