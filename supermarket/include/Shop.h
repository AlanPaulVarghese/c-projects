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
    static Shop* instance;
    static  Shop *getInstance();
    void showMenu();
    void showAdminMenu();
    void showUserMenu();
    void addProduct(Product p);
    void editProduct(int index,int ch,string change);
    void removeProduct(int index);
    Product getProduct(int index);
    //void add();
    //void edit();
    //void rem();
     void listItems();
    //void recipt();
     int getPCode();
     int getProductId(int pid);
     int getProductSize();

};


#endif // SHOP_H
