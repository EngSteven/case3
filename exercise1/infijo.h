#include "../stack/stack.h"
#include <string>
#include <string.h>
#include <iostream>
#include <sstream>

using namespace std;

#ifndef INFIJO
#define INFIJO 1
#define UNO 1

class Infijo{
    private: 
        string text;

    public:
        Infijo(string pText){
            this->text = pText;
        }

        string getInfijo(){
            return text;
        }

        int getSize(){
            return text.size();
        }

        void changePrecedence(string *precedenceCharacter, Stack<string>*& operations, Stack<string>*& output){
            precedenceCharacter = operations->pop();         //se quita la precedencia de operations
            output->push(precedenceCharacter);               //se coloca la precedencia en la salida
        }

        bool areEqual(string * x, string y){
            bool equal = false;
            if(x->compare(y) == 0){
                equal = true;
            }
            return equal;
        }

        //tranformacion a postfijo
        Stack<string>* toPosfijo(){
            Stack<string>* operations = new Stack<string>();    //pila que almacena las operaciones
            Stack<string>* output = new Stack<string>();        //pila que almanena la salida 
            
            string currentCharacter, *precedenceCharacter;

            for(int indexChar=0; indexChar<text.size(); indexChar++){

                currentCharacter = text[indexChar];

                switch(text[indexChar]){
                    
                    case '+':
                    case '-':
                        if(!operations->isEmpty()){
                            precedenceCharacter = operations->top();

                            if(areEqual(precedenceCharacter, "+") || areEqual(precedenceCharacter, "-")){
                                changePrecedence(precedenceCharacter,operations,output);
                                
                            }else if(areEqual(precedenceCharacter,"*") || areEqual(precedenceCharacter,"/")){
                                
                                for(int cont; cont<operations->getSize(); cont++){ //siempre y cuando no hayan parentesis de apertura   
                                    changePrecedence(precedenceCharacter,operations,output); 
                                }

                            }
                        }
                        operations->push(new string(currentCharacter));  //se coloca el char actual en operations
                        break;
                    
                    case '%':
                    case '*':
                    case '/':
                        if(!operations->isEmpty()){
                            precedenceCharacter = operations->top();

                            if(areEqual(precedenceCharacter, "*") || areEqual(precedenceCharacter,"/")){
                                changePrecedence(precedenceCharacter,operations,output);
                            }
                        }
                        operations->push(new string(currentCharacter));  //se coloca el char actual en operations
                        break;
                    
                    case '(':
                        if(!operations->isEmpty()){
                            precedenceCharacter = operations->top();
                            operations->push(new string(currentCharacter));
                        }
                        break;

                    case ')':
                        if(!operations->isEmpty()){
                            precedenceCharacter = operations->top();

                            do{ 
                                precedenceCharacter = operations->pop();
                                if(!areEqual(precedenceCharacter, "(")){
                                    output->push(precedenceCharacter);
                                }

                            }while(!areEqual(precedenceCharacter, "("));
                        }
                        break;
                    
                    default: 
                        output->push(new string(currentCharacter)); //en caso de que sean numeros
                        break;
                }
            }

            if(!operations->isEmpty()){
                while(!operations->isEmpty()){
                    precedenceCharacter = operations->pop();
                    output->push(precedenceCharacter);
                }
            }
            
            return output;
        }

        int calculateResult(int operation, int number1, int number2){
            int result = 0;
            switch (operation){
                case 1:
                    result = number1 - number2;
                    break;
                case 2:
                    result = number1 + number2;
                    break;
                case 3:
                    result = number1 * number2;
                    break;
                case 4:
                    result = number1 / number2;
                    break; 

                case 5:
                    result = number1 % number2;
            }
            return result;
            
        }

        int evaluation(Stack<string> * postfijo){
            int result = 0, number1, number2, operation = 0;
            string operand1, operand2, strResult, currentCharacter;
            
            Stack<string>* operations = new Stack<string>();

            while(!postfijo->isEmpty()){
                currentCharacter = *postfijo->pop();

                switch(currentCharacter[0]){
                    
                    case '-':
                        operation = 1;
                        break;
                    case '+':
                        operation = 2;
                        break;
                    case '*':
                        operation = 3;
                        break;
                    case '/':
                        operation = 4;
                        break;

                    case '%':
                        operation = 5;

                    default:    //en caso de que sean numeros
                        operation = 0;
                        operations->push(new string(currentCharacter));
                        break;
                }
                if((operation != 0) && (!operations->isEmpty())){
                    operand2 = *operations->pop();
                    operand1 = *operations->pop();
                    stringstream(operand2) >> number2;
                    stringstream(operand1) >> number1;
                    result = calculateResult(operation, number1, number2);
                    strResult = to_string(result);
                    operations->push(new string(strResult));
                }
            }
            
            return result;
        }
};

#endif