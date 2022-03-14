#ifndef SHOP_H
#define SHOP_H
#include<iostream>
#include<Product.h>
#include<vector>
using namespace std;
class Shop{

vector<Product> products;
int product_id_gen;
public:
    Shop();
    void showMenu();
    void admin();
    void buyer();
    void add();
    void edit();
    void rem();
    void listItems();
    void recipt();
    int getPCode();

};


#endif // SHOP_H
