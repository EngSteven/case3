#include "../DlinkedListPriority/List.h"

#ifndef QUEUE

#define QUEUE 1

template <class T>
class Queue {
    private:
        List<T>* queueList;
        int maxPriority;
        int minPriority;
    
    public:
        Queue() {
            queueList = NULL;
            queueList = new List<T>();
        }

        // agregar al final
        void enqueue(T* pValue, int pPriority) {
            if(!queueList->isEmpty()){

                if(pPriority < maxPriority){
                    maxPriority = pPriority;
                    queueList->addAtBegining(pValue, pPriority);  

                }else if(pPriority > minPriority){
                    minPriority = pPriority;
                    queueList->add(pValue, pPriority);

                }else{
                    for(int indexQueue=0; indexQueue<queueList->getSize(); indexQueue++){             
                        if(queueList->findPriority(indexQueue) >= pPriority){
                            queueList->insert(indexQueue, pValue, pPriority);
                            break;
                        }
                    }
                }
            }else{
                maxPriority = pPriority;
                minPriority = pPriority;
                queueList->add(pValue, pPriority);
            }
        }

        T* dequeue() {
            T* result = NULL;
            if (!queueList->isEmpty()) {
                result = queueList->remove(0);          
            }
            return result;            
        }

        T* front() {
            T* result = NULL;
            if (!queueList->isEmpty()) {
                result = queueList->find(0);
            }
            return result;
        }

        bool isEmpty() {
            return queueList->isEmpty();
        }
};

#endif