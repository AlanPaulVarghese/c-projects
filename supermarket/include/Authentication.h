#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H
#include<iostream>
using namespace std;

class Authentication
{

    string user_name;
    string password;
public:
    Authentication();
    bool verifyUser();
    void changeCredentials();
    void setUserCredentials(string user_name,string password);
};

#endif // AUTHENTICATION_H
