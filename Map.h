#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>
#include <utility>
using namespace std;

struct Node {
    string key;
    pair<int, int> value;
    Node* next;

    Node(const string& k, const pair<int, int>& v);
};

class HashMap {
private:
    vector<Node*> table;
    int size;
    int count;

    int hashFunction(const string& key) const;
    void rehash();

public:
    HashMap(int s = 10);
    ~HashMap();

    void insert(const string& key, const pair<int, int>& value);
    pair<int, int> get(const string& key) const;
    bool remove(const string& key);
    void display() const;
    void saveToFile(const string& filename) const;
    bool containsKey(const string& key) const;
    void clear();
};

#endif // MAP_H
