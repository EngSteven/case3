/*
notacion infija   ->  5*(8-4+(5*2))/4
notacion postfija ->  584-52*+*4/

RULES
igual precedencia se cambia, se coloca en output y se deja el nuevo operador en operations
mayor precedencia se agrega al output
menor precedencia se sacan los operadores y se colocan en output y se deja el nuevo operador en operations
() se colocan los operadores que esten dentro de los parentesis y se remueven de operations
*/
#include <algorithm> 
#include "infijo.h"
#include <iostream>

using namespace std;

int main(){

    Infijo * infijo = new Infijo("5*(8-4+(5*2))/4");
    Stack<string>* posfijo = infijo->toPosfijo();
    Stack<string>* posfijoReverse = new Stack<string>();
    Stack<string>* posfijoAux = new Stack<string>();

    string * currentChar;
    string  text, invertText;

    int result;

    cout<<"\nNotacion infija: "<<infijo->getInfijo()<<endl;
    cout<<"Notacion posfija: ";

    while(! posfijo->isEmpty()){
        currentChar = posfijo->pop();
        posfijoReverse->push(currentChar);
        posfijoAux->push(currentChar);
    }

    while(! posfijoAux->isEmpty()){     
        cout<<*posfijoAux->pop();
    }
    result = 0;
    result = infijo->evaluation(posfijoReverse);
    cout<<"\nEl resultado de la evaluacion es: "<<result<<endl;

    cout<<"\n\n";
    return 0;
}