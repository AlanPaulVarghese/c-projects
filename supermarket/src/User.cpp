#include "User.h"

User::User(string user_name,string password){
this->user_name=user_name;
this->password=password;
}

bool User::verifyUser(){
    string user_name;
    string password;
    cout<<"Enter Your User Name:";
    cin>>user_name;
    cout<<"Enter Your Password:";
    cin>>password;

    if(user_name==this->user_name&& password==this->password){
        return true;
    }
    else{
        return false;
    }
}
