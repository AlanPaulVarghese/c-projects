#ifndef USER_H
#define USER_H

#include<iostream>
using namespace std;
class User
{
    string user_name;
    string password;
    public:
    User(string user_name,string password);
    bool verifyUser();
};

#endif // USER_H
