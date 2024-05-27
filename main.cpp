#include <bits/stdc++.h>
#include <queue>
#include <vector>
#include "Customer.h"
#include "Map.h"
#include "Ticket.h"
#include "Product.h"
using namespace std;
HashMap hashMap(100);
string adminName = "admin", adminPass = "weworkhere";
int num = 0;
queue<Customer*> normalCustomers, preferredCustomers, auxCustomers;

void addCustomerToQueue(Customer *customer){
    if(customer->getType() == "normal") normalCustomers.push(customer);
    else preferredCustomers.push(customer);
}

string chooseType(){
    int option;
    string type;
    cout << "What type of preferred customer are you?\n";
    cout << "1) I'm a pregnant client\n";
    cout << "2) I'm an elderly customer\n";
    cout << "3) I'm a client with a disability\n";
    cout << "> ";
    cin >> option;

    while(option < 1 || option > 3){
        chooseType();
    }

    if(option == 1){
        type = "pregnant";
        return type;
    }else if(option == 2){
        type = "third age";
        return type;
    }else {
        type = "disability";
        return type;
    }
}

void enterIntoQueue(int myTurn){
    int option, turn;
    string type, rut;
    turn = myTurn;
    cout << "In order to assign a number, first select which group you belong to:\n";
    cout << "1. I'm a Normal Customer\n";
    cout << "2. I'm a Preferred Customer\n";
    cout << "> ";
    cin >> option;

    while(option < 1 || option > 2){
        cout << "ERROR, try again.\n";
        enterIntoQueue(turn);
    }

    cout << "Please, enter your RUT:\n";
    cin >> rut;

    if(option == 1){
        type = "normal";
    } else {
        type = chooseType();
    }

    Customer *customer = new Customer(type, rut, turn);
    addCustomerToQueue(customer);
    cout << "Customer: " << customer->getRut() << " with the number: " << customer->getAttentionNumber() << " has been saved successfully.\n";

}

int deliverNumber() {
    return ++num;
}

bool searchProduct(string nameProduct) {
    return hashMap.containsKey(nameProduct);
}

void giveReceipt(vector<pair<string, int>> cart) {
    Ticket *ticket = new Ticket(cart);
    ticket->calculateTiket();
}

void makeOrder(vector<pair<string, int>> cart,string products,int cant,pair<string,int> med,Customer *customer) {
    int option;
    cout << "Welcome customer :" << customer->getRut() << endl;
    cout << "What medication are you looking for?\n";
    cout << "> ";
    cin >> products;

    if(!searchProduct(products)) {
        cout << "That medicine was not found in our warehouse\n";
    }else {
        cout <<"How many " << products << " medications do you want?\n";
        cout << "> ";
        cin >> cant;
        pair<int,int> medica = hashMap.get(products);
        while(cant > medica.second) {
            cout << "We don't have that amount of medicine.\n";
            cout << "Try to order a smaller amount.\n";
            cout << "> ";
            cin >> cant;
        }

        med.first = products;
        med.second = cant;
        cart.push_back(med);

        cout << "Do you want to order another medicine?\n";
        cout << "1. yes\n";
        cout << "2. no\n";
        cin >> option;
        while(option < 1 || option > 2) {
            cout << "Do you want to order another medicine?\n";
            cout << "1. yes\n";
            cout << "2. no\n";
            cin >> option;
        }

        if(option == 1) {
            makeOrder(cart,products,cant,med,customer);
        }else {
            giveReceipt(cart);
        }
    }
}

void serveCustomer(Customer *customer) {
    vector<pair<string, int>> cart ;
    string products;
    int cant;
    pair<string,int> med;
    makeOrder(cart,products,cant,med,customer);

}

void callNextCustomer(){
    if(normalCustomers.empty() && preferredCustomers.empty()) {
        cout << "there are no clients waiting\n";
    }else if(preferredCustomers.empty()) {
        Customer *customer = normalCustomers.front();
        serveCustomer(customer);
    }else {
        Customer *customer = preferredCustomers.front();
        serveCustomer(customer);
    }
}

void addProduct(){

    int cant = 0;

    cout << "¿How many medications do you want to add?\n";
    cin >> cant;

    for(int i = 0 ; i < cant ; i++) {
        string name;
        int cantity = 0,value = 0;
        pair<int,int> desc;
        cout << "¿What is the name of the medication?\n";
        cout << "> ";
        cin >> name;
        cout << "How many " << name << " do you want to store?\n";
        cout << "> ";
        cin >> cantity;
        cout << "¿What is the value of the medicine?\n";
        cout << "> ";
        cin >> value;

        desc.first = value;
        desc.second = cantity;
        hashMap.insert(name,desc);
    }

}

void customerMenu(){
    int n;
    cout << "1. Get Attention Number.\n";
    cout << "2. close.\n";
    cout << "> ";
    cin >> n;

    while(n < 1 || n > 2){
        cout << "ERROR\n";
        cout << "Please, select an option:\n";
        cout << "1. Get Attention Number.\n";
        cout << "2. close.\n";
        cout << "> ";
        cin >> n;
    }

    if(n == 1){
        int myTurn = deliverNumber();
        enterIntoQueue(myTurn);
        customerMenu();
    }else{
        cout << "Going back!\n";
    }
}

bool access(){
    string name,password;
    bool checkname,checkpass;
    cout << "Enter your name:\n";
    cout << "> ";
    cin >> name;
    cout << "Enter your password:\n";
    cout << "> ";
    cin >> password;

    if(name == adminName){
        checkname = true;
    }else{
        checkname = false;
    }

    if(password == adminPass){
        checkpass = true;
    }else{
        checkpass = false;
    }

    if(checkname == true && checkpass == true){
        return true;
    } else {
        return false;
    }
}

void workerMenu(){
    int n;
    cout << "You have successfully started the session\n";
    cout << "1. Add products to the warehouse.\n";
    cout << "2. Call to next customer.\n";
    cout << "3. Close.\n";
    cout << "> ";
    cin >> n;

    while(n < 1 || n > 3){
        cout << "You have successfully started the session\n";
        cout << "1. Add products to the warehouse.\n";
        cout << "2. Call to next customer.\n";
        cout << "3. Close.\n";
        cout << "> ";
        cin >> n;
    }

    if(n == 1){
        addProduct();
        workerMenu();
    }else if( n == 2){
        callNextCustomer();
        workerMenu();
    }else if(n == 3){
        cout << "Going back!\n";
    }

}

void saveWareHouse() {
    hashMap.saveToFile("Medicine.txt");
}

void globalMenu(){
    int n;
    cout << "Welcome to the Pharmaceutical organization system\n";
    cout << "Please, select an option:\n";
    cout << "1. Im a customer\n";
    cout << "2. Im a worker\n";
    cout << "3. Close System.\n";
    cout << "> ";
    cin >> n;

    while ( n < 1 || n > 3){
        cout << "Please select a valid option\n";
        cout << "1. Im a customer\n";
        cout << "2. Im a worker\n";
        cout << "3. Close System\n";
        cout << "> ";
        cin >> n;
    }

    if(n == 1){
        customerMenu();
        globalMenu();
    }else if(n == 2){
        bool logIn = access();
        if(logIn) {
            workerMenu();
            globalMenu();
        }else {
            cout << "Login Denied. try again.\n";
            workerMenu();
        }

    }else {
        saveWareHouse();
        cout << "Good Bye!\n";
    }
}

void readFile(string filename, HashMap& hashMap) {
    ifstream file(filename);
    if (!file) {
        cerr << "Could not open file for reading." << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string nombre;
        int cantidad, precio;
        char slash;

        if (ss >> nombre >> slash >> cantidad >> slash >> precio) {
            hashMap.insert(nombre, {cantidad, precio});
        } else {
            cerr << "Error when reading the linea: " << line << endl;
        }
    }

    file.close();
}

int main(){
    hashMap.clear();
    readFile("Medicine.txt",hashMap);
    globalMenu();
}