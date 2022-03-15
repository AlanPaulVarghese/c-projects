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
    void showAdminMenu();
    void showUserMenu();
    //void add();
    //void edit();
    //void rem();
    //void listItems();
    //void recipt();
    //int getPCode();
    //int getProduct(int pid);
    //int getProductSize();

};


#endif // SHOP_H
