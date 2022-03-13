#include "Shop.h"
#include<iostream>
#include<User.h>
#include<bits/stdc++.h>
#include<ctype.h>
#include<fstream>

using namespace std;
User user("admin","admin");
void Shop::showMenu()
{
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
    cout<<"\t\t\t\t\t\t\t\tWELCOME TO MY Admin Panel"<<endl;
    cout<<"Enter Your Choice"<<endl;
    do{

        cout<<"Add Product"<<endl<<"Modify Product"<<endl<<"Delete Product"<<endl<<"Change User Name and Password"<<endl<<"Back To Main Screen"<<endl;
        cout<<":-";
        cin.ignore();
        getline(cin,choice);
        transform(choice.begin(),choice.end(),choice.begin(),::tolower);
        if(choice=="add product"){
            //add();
            break;
        }
        else if(choice=="modify product"){
            //edit();
            break;
        }
        else if(choice=="delete product"){
            //rem();
            break;
        }
        else if(choice=="change user name and password"){
            user.changeCredentials();
            system ("CLS");
            showMenu();
            break;
        }
        else if(choice=="back to main screen"){
            system ("CLS");
            showMenu();
            break;
        }
        else{
            cout<<"Invaild Selection Please try again"<<endl;
        }

    }while(true);
}
