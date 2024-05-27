
#ifndef TICKET_H
#define TICKET_H
#include <iostream>
#include <vector>
using namespace std;

class Ticket {
private:
    vector<pair<string,int>> cart;
public :
    Ticket(vector<pair<string,int>> cart);
    void calculateTiket();

};

#endif //TICKET_H
