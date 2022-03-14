#include "Shop.h"
#include<iostream>
#include<User.h>
#include<bits/stdc++.h>
#include<ctype.h>
#include<fstream>
#include<Product.h>
#include<iomanip>//for tables;
using namespace std;
User user("admin","admin");
void Shop::showMenu()
{
    int choice;
    cout<<"\t\t\t\t\t\t\t\tWELCOME TO MY SHOP"<<endl;
    cout<<"Enter Your Choice"<<endl;
    do{
        cout<<"1-Admin"<<endl<<"2-Buyer"<<endl<<"3-Exit"<<endl;
        cout<<":-";
        cin>>choice;
        //transform(choice.begin(),choice.end(),choice.begin(),::tolower);

        if(choice==1){
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
        else if(choice==2){
            cout<<"you Seleted Buyer";
            break;
        }
        else if(choice==3){
            exit(0);
        }
        else{
            cout<<"Invaild Selection Please try again"<<endl;
            getchar();
        }

       }
    while(true);
}


void Shop::admin(){
    system ("CLS");
    cout<<"\t\t\t\t\t\t\t\tWELCOME TO MY Admin Panel"<<endl;
    cout<<"Enter Your Choice"<<endl;
    do{
        int choice;
        cout<<"1-Add Product"<<endl<<"2-Modify Product"<<endl<<"3-Delete Product"<<endl<<"4-List Products"<<endl<<"5-Change User Name and Password"<<endl<<"6-Back To Main Screen"<<endl;
        cout<<":-";
        cin>>choice;
        //cin.ignore();
        //getline(cin,choice);
        //transform(choice.begin(),choice.end(),choice.begin(),::tolower);
        if(choice==1){
            add();
            return;
        }
        else if(choice==2){
            //edit();
            return;
        }
        else if(choice==3){
            //rem();
            return ;
        }
        else if(choice==5){
            user.changeCredentials();
            system ("CLS");
            showMenu();
            return;
        }
        else if(choice==6){
            system ("CLS");
            showMenu();
            return;
        }
        else if(choice==4){
            listItems();
            cin.ignore();
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
//cout<<"Product_Name"<<"          "<<"Product_code"<<"           "<<"Price"<<endl;
 cout<<left<<setw(10)<< "Name"<<setw(5)<< "Id"<< setw(8)<< "Price"<<setw(8)<<"Discount"<< endl;
for(int i=0;i<products_size;i++){
   // cout<<this->products[i].pname<<"                   "<<products[i].pcode<<"                      "<<products[i].price<<endl;
    cout<<setw(10)<<products[i].pname<< setw(5)<<products[i].pcode<<setw(8)<<products[i].price<<setw(8)<<products[i].discount<< endl;
}
}
