
#include "Customer.h"
using namespace std;

Customer :: Customer(string _type, string _rut, int _attentionNumber){
    this -> type = _type;
    this -> rut = _rut;
    this -> attentionNumber = _attentionNumber;
}

string Customer :: getType(){
    return type;
}

string Customer :: getRut(){
    return rut;
}

int Customer :: getAttentionNumber(){
    return attentionNumber;
}

void Customer :: setType(string _type){
    type = _type;
}

void Customer :: setRut(string _rut){
    rut = _rut;
}

void Customer :: setAttentionNumber(int _attentionNumber){
    attentionNumber = _attentionNumber;
}
