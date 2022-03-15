#ifndef USER_H
#define USER_H
#include<iostream>
#include<Product.h>
#include<vector>
#include<Authentication.h>
#include<Shop.h>
#include<bits/stdc++.h>
using namespace std;

class User
{
    vector<Product> cartProducts;
    vector<Product> oderProducts;
    Authentication authentication;
public:
    User(string user_name,string password);
    Authentication auth();
    void buyProduct();
    void cart();
    int getCartSize();

};

#endif // USER_H
