#ifndef ADMIN_H
#define ADMIN_H
#include<Authentication.h>

class Admin
{
    Authentication authentication;
public:
    Admin(string user_name,string password);
    Authentication auth();
    void add();
    void edit();
    void rem();
};

#endif // ADMIN_H
