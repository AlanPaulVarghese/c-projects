#ifndef ADMIN_H
#define ADMIN_H
#include<Authentication.h>
#include<Product.h>
#include<Shop.h>
#include<bits/stdc++.h>
class Admin
{
    Authentication authentication;
public:
    Admin(string user_name,string password);
    Authentication auth();
    void add();
    void edit();
    void rem();
    void credentials();
};

#endif // ADMIN_H
