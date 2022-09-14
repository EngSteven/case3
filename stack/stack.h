#include "../DLinkedList/list.h"

#ifndef STACK 

#define STACK 1

template <class T>

class Stack{
    private: 
        List<T> * stackList;
        int quantity;
    public:
        Stack(){
            stackList = new List<T>();
            quantity = 0;
        }

        int getSize(){
            return quantity;
        }
        
        T* top(){
            T* result = NULL;
            
            if(!stackList->isEmpty()){
                result = stackList->find(0);
            }
            
            return result;
        }

        //agregar al principio
        void push(T *pValue){
            stackList->insert(0, pValue);
            quantity++;
        }

        T* pop(){
            T* result = NULL;
            if(!stackList->isEmpty()){
                result = stackList->remove(0);
                quantity--;
            }
            return result;
        }

        bool isEmpty(){
            return stackList->isEmpty();
        }
};

#endif