#include "Flight.h"
#include "queuepriority/queue.h"


class Airport{
    private:
        string name;
        Queue<Queue<Flight>>* listTracks; 
    public:
        Airport(string pName, Queue<Queue<Flight>>* plistTracks){
            this->name = pName;
            this->listTracks = plistTracks;
        }

        void realeaseFlights(Queue<Flight> *&track1, Queue<Flight> *&track2, Queue<Flight> *&track3, int nVuelos){
            int currentPriorityMax=999999, priorityMax1=0, priorityMax2=0, priorityMax3=0;
            Flight * flight;
            for(int i=0; i<nVuelos; i++){
                //se encuentra la prioridad mayor
                if(!track1->isEmpty()){
                    priorityMax1 = track1->front()->getIntTimeValue();
                }
                if(!track2->isEmpty()){
                    priorityMax2 = track2->front()->getIntTimeValue();
                }
                if(!track3->isEmpty()){
                    priorityMax3 = track3->front()->getIntTimeValue();
                }
                
                if((!track1->isEmpty()) && (priorityMax1 < priorityMax2) && (priorityMax1 < priorityMax3)){
                    currentPriorityMax = priorityMax1;
                }else if((!track2->isEmpty()) && (priorityMax2 < priorityMax1) && (priorityMax2 < priorityMax3)){
                    currentPriorityMax = priorityMax2;
                }else if(!track3->isEmpty()){
                    currentPriorityMax = priorityMax3;
                }
                
                //buscar cuales prioridades son iguales a dicha maxima prioridad actual
                if((!track1->isEmpty()) && (priorityMax1 == currentPriorityMax)){
                    flight = track1->dequeue();
                    cout<<"\nVuelo: " << flight->getNumeroVuelo() << " sale " << flight->flightTimeString() << " pista 1 " << endl;
                }

                if((!track2->isEmpty()) && (priorityMax2 == currentPriorityMax)){
                    flight = track2->dequeue();
                    cout<<"\nVuelo: " << flight->getNumeroVuelo() << " sale " << flight->flightTimeString() << " pista 2 " << endl;
                }
                
                if((!track3->isEmpty()) && (priorityMax3 == currentPriorityMax)){
                    flight = track3->dequeue();
                    cout<<"\nVuelo: " << flight->getNumeroVuelo() << " sale " << flight->flightTimeString() << " pista 3 " << endl;
                }
                
                currentPriorityMax=999999;
                priorityMax1=999999;
                priorityMax2=999999;
                priorityMax3=999999;
            }
        }
};
