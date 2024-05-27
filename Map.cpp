#include "map.h"
#include <iostream>
#include <fstream>
using namespace std;

Node::Node(const string& k, const pair<int, int>& v) : key(k), value(v), next(nullptr) {}


HashMap::HashMap(int s) : size(s), count(0) {
    table.resize(size, nullptr);
}

HashMap::~HashMap() {
    for (int i = 0; i < size; ++i) {
        Node* current = table[i];
        while (current != nullptr) {
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        }
    }
}


int HashMap::hashFunction(const string& key) const {
    hash<string> hashFunc;
    return hashFunc(key) % size;
}

void HashMap::rehash() {
    int oldSize = size;
    size *= 2;
    vector<Node*> oldTable = table;
    table.resize(size, nullptr);
    count = 0;

    for (int i = 0; i < oldSize; ++i) {
        Node* current = oldTable[i];
        while (current != nullptr) {
            insert(current->key, current->value);
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        }
    }
}

void HashMap::insert(const string& key, const pair<int, int>& value) {
    if (count >= size * 0.7) {
        rehash();
    }

    int index = hashFunction(key);
    Node* newNode = new Node(key, value);

    if (table[index] == nullptr) {
        table[index] = newNode;
    } else {
        Node* current = table[index];
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                delete newNode;
                return;
            }
            prev = current;
            current = current->next;
        }
        prev->next = newNode;
    }
    count++;
}

pair<int, int> HashMap::get(const string& key) const {
    int index = hashFunction(key);
    Node* current = table[index];

    while (current != nullptr) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return {-1, -1};
}

bool HashMap::remove(const string& key) {
    int index = hashFunction(key);
    Node* current = table[index];
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->key == key) {
            if (prev == nullptr) {
                table[index] = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            count--;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

void HashMap::display() const {
    for (int i = 0; i < size; ++i) {
        Node* current = table[i];
        cout << "Bucket " << i << ": ";
        while (current != nullptr) {
            cout << "(" << current->key << ", (" << current->value.first << ", " << current->value.second << ")) -> ";
            current = current->next;
        }
        cout << "None" << endl;
    }
}

void HashMap::saveToFile(const string& filename) const {
    ofstream file(filename);
    if (!file) {
        cerr << "No se pudo abrir el archivo para escribir." << endl;
        return;
    }
    for (int i = 0; i < size; ++i) {
        Node* current = table[i];
        while (current != nullptr) {
            file << current->key << " " << current->value.first << " " << current->value.second << endl;
            current = current->next;
        }
    }
    file.close();
}


bool HashMap::containsKey(const string& key) const {
    int index = hashFunction(key);
    Node* current = table[index];

    while (current != nullptr) {
        if (current->key == key) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void HashMap::clear() {
    for (int i = 0; i < size; ++i) {
        Node* current = table[i];
        while (current != nullptr) {
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        }
        table[i] = nullptr;
    }
    count = 0;
}

