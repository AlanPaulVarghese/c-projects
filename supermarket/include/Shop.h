#ifndef SHOP_H
#define SHOP_H
#include<iostream>
#include<Product.h>
#include<vector>
using namespace std;
class Shop{

vector<Product> products;

public:
    void showMenu();
    void admin();
    void buyer();
    void add();
    void edit();
    void rem();
    void listItems();
    void recipt();

};


#endif // SHOP_H
