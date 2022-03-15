#include "Authentication.h"

Authentication::Authentication()
{
    this->user_name="Admin";
    this->password="Admin";

}


void Authentication::setUserCredentials(string user_name,string password){

    this->user_name=user_name;
    this->password=password;

}

bool Authentication::verifyUser(){
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

void Authentication::changeCredentials(){

    string user_name;
    string password;
    cout<<"Enter Your New User Name:";
    cin>>user_name;
    cout<<"Enter Your New Password:";
    cin>>password;
    this->password=password;
    this->user_name=user_name;
    return;
}
