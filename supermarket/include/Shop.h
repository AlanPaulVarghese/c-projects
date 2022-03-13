#ifndef SHOP_H
#define SHOP_H
#include<iostream>
using namespace std;
class Shop{

    int pcode;
    float price;
    float discount;
    string pname;
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
