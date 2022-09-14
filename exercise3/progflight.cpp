//#include "Flight.h"
#include "Airport.h"
//#include "queuepriority/queue.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

#define KTRACKS 3
#define NVUELOS 6
#define STARHOUR 1
#define ENDHOUR 2

void fillFlights(int pCantidad, int pStartHour, int pEndHour, List<Flight> *& listFlights) {
    
    int randHour=0, randMinutes=0, randDelayMinutes=0, nPasajeros=0, priority=0;
    srand(time(0));
    for(int indexFlight=0; indexFlight<pCantidad; indexFlight++){
        randHour = rand() % (pEndHour-pStartHour) + pStartHour;  //hora
        randMinutes = 0 + rand() % (42);            //minutos 
        randDelayMinutes = 0 + rand() % (17);       //minutos de atraso
        randMinutes += randDelayMinutes;            //minutos finales
        nPasajeros = rand() % (40-20) + 20;
        Flight *flight = new Flight("TEC Airline", randHour, randMinutes, indexFlight+1, nPasajeros);
        priority = flight->getIntTimeValue();
        listFlights->add(flight, priority);
    }
}

void fillTracks(List<Flight> *& listFlights, Queue<Flight> *&track1, Queue<Flight> *&track2, Queue<Flight> *&track3){
    int posTrack=0, priority=0;
    Flight * flight;
    while(!listFlights->isEmpty()){
        for(int indexFlight = 0; indexFlight<KTRACKS; indexFlight++){
            posTrack = indexFlight % KTRACKS;
            if(!listFlights->isEmpty()){
                flight = listFlights->remove(0);
                priority = flight->getIntTimeValue();
                switch (posTrack){
                    case 0:
                        track1->enqueue(flight, priority); break;
                    case 1:
                        track2->enqueue(flight, priority); break;
                    case 2:
                        track3->enqueue(flight, priority); break;
                }

            }else{
                break;
            }
        }
    }
}

int main() {
    List<Flight> * listFlights = new List<Flight>();
    Queue<Flight> * track1 = new Queue<Flight>();
    Queue<Flight> * track2 = new Queue<Flight>();
    Queue<Flight> * track3 = new Queue<Flight>();
    Queue<Queue<Flight>> * tracks = new Queue<Queue<Flight>>();

    tracks->enqueue(track1, 0);
    tracks->enqueue(track2, 1);
    tracks->enqueue(track3, 2);
    Airport * airport = new Airport("Tec Airlines", tracks);   

    fillFlights(NVUELOS, STARHOUR, ENDHOUR, listFlights);
    fillTracks(listFlights, track1, track2, track3);
    airport->realeaseFlights(track1, track2, track3, NVUELOS);
}