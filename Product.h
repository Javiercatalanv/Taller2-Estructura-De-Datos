
#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
using namespace std;



class Product {
private:
    string category,subCategory,price,ID;
public:
    Product(string _category, string _subCategory, string _price, string _ID);
    string getCategory();
    string getSubCategory();
    string getPrice();
    string getID();
    void setCategory(string _Category);
    void setSubCategory(string _subCategory);
    void setPrice(string _price);
    void setId(string _ID);
};



#endif //PRODUCT_H
