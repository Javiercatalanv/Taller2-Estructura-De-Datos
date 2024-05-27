
#include "Ticket.h"
#include <iostream>
#include <vector>
using namespace std;

Ticket :: Ticket(vector<pair<string,int>> _cart) {
    this -> cart = _cart;
}

void Ticket::calculateTiket() {
    double cost = 0;
    cout << "The summary of your purchase is:\n";
    cout << "-------------------------------------------\n";
    for(pair<string,int> part : cart) {
        cout << "- Medication: " << part.first << "  | Cant: " << part.second << endl;
    }
    cout << "-------------------------------------------\n";
}
