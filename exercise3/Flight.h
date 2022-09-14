#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <time.h>

using namespace std;

#ifndef TRACK
#define TRACK 1

class Flight {
    
    private: 
        time_t flightTime;
        tm *currentTime;
        string aerolinea;
        int numeroVuelo;
        int cantidadPasajeros;
        int hour;
        int minutes;

    public: 
        Flight(string pAerolinea, int pHour, int pMinutes, int pNumeroVuelo, int pCantidadPasajeros) {
            this->hour = pHour;
            this->minutes = pMinutes;
            this->numeroVuelo = pNumeroVuelo;
            this->cantidadPasajeros = pCantidadPasajeros; 
            this->aerolinea = pAerolinea;
            flightTime = time(NULL);
            currentTime = localtime(&flightTime);
            currentTime->tm_hour = pHour;
            currentTime->tm_min = pMinutes;
            
            changeFlightTime();
        }

        char* flightTimeString() {
            char* result = ctime(&flightTime);
            return result;
        }

        int getIntTimeValue() {
            int result = 0, totalSeconds = 0;
            totalSeconds = (getCurrentHour() * 3600) + (getCurretMin() * 60); 
            result = totalSeconds;
            return result;
        }

        string getAerolinea(){
            return aerolinea;
        }

        int getCurrentHour(){
            return hour;
        }

        int getCurretMin(){
            return minutes;
        }

        int getNumeroVuelo(){
            return numeroVuelo;
        }

        int getCantidadPasajeros(){
            return cantidadPasajeros;
        }

        void changeFlightTime(){
            time_t auxFlightTime = flightTime;
            int year=0, day=0, hour=0, minute=0;

            year = auxFlightTime / 31536000;
            auxFlightTime %= 31536000;
            day = auxFlightTime / 86400;
            auxFlightTime %= 86400;
            hour = auxFlightTime / 3600;
            auxFlightTime %= 3600;
            minute = auxFlightTime / 60;
            auxFlightTime %= 60;

            flightTime -= ((hour - 6) * 3600 + (minute * 60));  //se resta 6 a las horas porque el flightime en 0 comienza desde las 18 horas y no desde 0
            flightTime += ((currentTime->tm_hour * 3600) + (currentTime->tm_min * 60));
        }

};

#endif