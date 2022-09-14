#include "../stack/stack.h"

#ifndef QUEUE 

#define QUEUE 1

template <class T>

class Queue{
    private: 
        Stack<T> * stackList1 = new Stack<T>();
        Stack<T> * stackList2 = new Stack<T>();
    public:
        Queue(){
            stackList1 = new Stack<T>();
            stackList2 = new Stack<T>();
        }

        void enqueue(T *pValue){
            stackList1->push(pValue);
        }

        T* dequeue(){
            T* result = NULL;
            T* current = NULL;
            if(!stackList1->isEmpty()){
                
                while(stackList1->getSize() != 1){      //sacamos los elementos y los ponemos en la lista 2, menos el elemento a retornar
                    current = stackList1->pop();        
                    stackList2->push(current);          //de esta manera rotamos la pila, sin el elemento a retornar
                }
                result = stackList1->pop();             //sacamos el elemento a retornar y se coloca en el result
                
                while(stackList2->getSize() != 0){      //devolvemos los elementos de la lista 1 en orden de pila
                    current = stackList2->pop();    
                    stackList1->push(current);          //sin el elemento a retornar, ya que este debe ser eliminado
                }
                
            }
            
            return result;
        }

        T* front(){
            T* result = NULL;
            T* current = NULL;

            if(!stackList1->isEmpty()){
                
                while(!stackList1->isEmpty()){      
                    current = stackList1->pop();        
                    stackList2->push(current);         
                }           
                result = stackList2->top();

                while(!stackList2->isEmpty()){      
                    current = stackList2->pop();    
                    stackList1->push(current);       
                }   
            }
            return result;
        }

        bool isEmpty(){
            return stackList1->isEmpty();
        }
};

#endif