
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
using namespace std;


class Customer {
private:
    string type,rut;
    int attentionNumber;
public:
    Customer(string _type, string _rut, int _attentionNumber);
    string getType();
    string getRut();
    int getAttentionNumber();
    void setType(string _type);
    void setRut(string _rut);
    void setAttentionNumber(int _attentionNumber);
};



#endif //CUSTOMER_H
