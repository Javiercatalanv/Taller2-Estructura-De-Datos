
#include "Product.h"
using namespace std;

Product :: Product(string _category, string _subCategory, string _price, string _ID){
    this -> category = _category;
    this -> subCategory = _subCategory;
    this -> price = _price;
    this -> ID = _ID;
}

string Product :: getCategory(){
    return category;
}

string Product :: getSubCategory(){
    return subCategory;
}

string Product :: getPrice(){
    return price;
}

string Product :: getID(){
    return ID;
}

void Product :: setCategory(string _Category){
    category = _Category;
}

void Product :: setSubCategory(string _subCategory){
    subCategory = _subCategory;
}

void Product :: setPrice(string _price){
    price = _price;
}

void Product :: setId(string _ID){
    ID = _ID;
}