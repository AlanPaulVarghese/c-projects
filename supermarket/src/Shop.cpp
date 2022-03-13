#include "Shop.h"
#include<iostream>
#include<User.h>
#include<bits/stdc++.h>
#include<ctype.h>
#include<fstream>
#include<Product.h>
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
                return;
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
        cout<<"Add Product"<<endl<<"Modify Product"<<endl<<"Delete Product"<<endl<<"List Products"<<endl<<"Change User Name and Password"<<endl<<"Back To Main Screen"<<endl;
        cout<<":-";
        //cin.ignore();
        getline(cin,choice);
        transform(choice.begin(),choice.end(),choice.begin(),::tolower);
        if(choice=="add product"){
            add();
            return;
        }
        else if(choice=="modify product"){
            //edit();
            return;
        }
        else if(choice=="delete product"){
            //rem();
            return ;
        }
        else if(choice=="change user name and password"){
            user.changeCredentials();
            system ("CLS");
            showMenu();
            return;
        }
        else if(choice=="back to main screen"){
            system ("CLS");
            showMenu();
            return;
        }
        else if(choice=="list products"){
            listItems();
            getchar();
            system ("CLS");
            cout<<"\t\t\t\t\t\t\t\tWELCOME TO MY Admin Panel"<<endl;
            cout<<"Enter Your Choice"<<endl;

        }
        else{
             cout<<choice<<endl;
            cout<<"Invaild Selection Please try again"<<endl;
            getchar();
            system ("CLS");
            cout<<"\t\t\t\t\t\t\t\tWELCOME TO MY Admin Panel"<<endl;
            cout<<"Enter Your Choice"<<endl;
        }

    }while(true);
}
void Shop::add(){
do{
    string choice;
    Product p;
    cout<<"Enter Product Name:";
    cin>>p.pname;
    cout<<"Enter Product Code:";
    cin>>p.pcode;
    cout<<"Enter price:";
    cin>>p.price;
    cout<<"Enter discount:";
    cin>>p.discount;
    this->products.push_back(p);
    cout<<"Do You Want To Add New Product:";
    cin>>choice;
    transform(choice.begin(),choice.end(),choice.begin(),::tolower);
    if(choice!="yes"){
        admin();
        return;
    }
}while(true);
}


void Shop::listItems(){
int products_size=this->products.size();
if(products_size==0){
    cout<<"No Products To display!";
    return;
}
for(int i=0;i<products_size;i++){
    cout<<this->products[i].pname;
}
}
