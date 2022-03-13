#include "Shop.h"
#include<iostream>
#include<User.h>
#include<bits/stdc++.h>
#include<ctype.h>
using namespace std;
void Shop::showMenu()
{
    User user("admin","admin");
    string choice;
    cout<<"\t\t\t\t\t\t\t\tWELCOME TO MY SHOP"<<endl;
    cout<<"Enter Your Choice"<<endl;
    do{
        cout<<"Admin"<<endl<<"Buyer"<<endl<<"Exit"<<endl;
        cout<<":-";
        cin>>choice;
        transform(choice.begin(),choice.end(),choice.begin(),::tolower);

        if(choice=="admin"){
            bool status=user.verifyUser();
            if(status){
                cout<<"Logged In";
                admin();
            }
            else{
                cout<<"invalid credentials";
            }
            break;

        }
        else if(choice=="buyer"){
            cout<<"you Seleted Buyer";
            break;
        }
        else if(choice=="exit"){
            exit(0);
        }
        else{
            cout<<"Invaild Selection Please try again"<<endl;
        }

       }
    while(true);
}


void Shop::admin(){
    system ("CLS");
    string choice;
    cout<<"\t\t\t\t\t\t\t\tWELCOME TO MY SHOP"<<endl;
    cout<<"Enter Your Choice"<<endl;
}
