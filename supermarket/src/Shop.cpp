#include "Shop.h"
#include<iostream>
#include<User.h>
#include<bits/stdc++.h>
#include<ctype.h>
#include<fstream>
#include<Product.h>
#include<iomanip>//for tables;
#include<Admin.h>
using namespace std;

Admin admin("admin","admin");
User user("user","user");

Shop::Shop(){
this->product_id_gen=0;
}


Shop* Shop::getInstance(){
if(!Shop::instance){
    Shop::instance=new Shop;
    return Shop::instance;
}

return Shop::instance;
}


void Shop::addProduct(Product p){

this->products.push_back(p);
return;
}

void Shop::showMenu(){
     int choice;

    do{
        system ("CLS");

        cout<<"\t\t\t\t\t\t\t\tWELCOME TO MY SHOP"<<endl;
        cout<<"Enter Your Choice"<<endl;
        cout<<"1-Admin"<<endl<<"2-Buyer"<<endl<<"3-Exit"<<endl;
        cout<<":-";
        cin>>choice;
        switch(choice){
        case 1:
               showAdminMenu();
               break;
        case 2:
               showUserMenu();
               break;
        case 3:
               exit(0);
        default:
             cout<<"Invaild Selection Please try again"<<endl;
             cin.ignore();
             getchar();
             choice=-1;
        }

    }while(choice<3);


return;
}




void Shop::showAdminMenu(){



if(admin.auth().verifyUser()){
    int choice;
    do{
        //gotolabel:
        system ("CLS");
        cout<<"\t\t\t\t\t\t\t\tWELCOME TO Admin Panel"<<endl;
        cout<<"Enter Your Choice"<<endl;
        cout<<"1-Add Product"<<endl<<"2-Modify Product"<<endl<<"3-Remove"<<endl<<"4-Display Products"<<endl<<"5-Back To Main Main"<<endl;
        cout<<":-";
        cin>>choice;
        switch(choice){

         case 1:
                admin.add();
                //goto gotolabel;
                break;
         case 2:
               admin.edit();
               break;
         case 3:
            admin.rem();
            break;
         case 4:
                listItems();
                cin.ignore();
                getchar();
                break;
                //goto gotolabel;
         //case 5:
               //admin.credentials();
         case 5:
                return;
         default:
             cout<<"Invaild Selection Please try again"<<endl;
             cin.ignore();
             getchar();
             choice=-1;
        }
    }while(choice<6);
}
else{
    cout<<"no Welcomed";
}
cin.ignore();
getchar();
}




void Shop::showUserMenu(){

if(user.auth().verifyUser()){
int ch;
    do{
        system ("CLS");
        cout<<"\t\t\t\t\t\t\t\tWelcome TO User Panel"<<endl;
        cout<<"Enter Your Choice"<<endl;
        cout<<"1-Buy Product"<<endl<<"2-See Cart"<<endl<<"3-See Orders"<<endl<<"4-Back To Main Main"<<endl;
        cin>>ch;
        switch(ch){

    case 1:
            user.buyProduct();
            break;


        }
    }while(false);
}
else{
    cout<<"no Welcomed";
}
cin.ignore();
getchar();
}

int Shop::getProductSize(){
return this->products.size();
}

void Shop::listItems(){
int products_size=this->getProductSize();
if(products_size==0){
    cout<<"No Products To display!";
    return;
}
 cout<<left<<setw(10)<< "Name"<<setw(5)<< "Id"<< setw(8)<< "Price"<<setw(8)<<"Discount"<< endl;
for(int i=0;i<products_size;i++){
    cout<<setw(10)<<products[i].pname<< setw(5)<<products[i].pcode<<setw(8)<<products[i].price<<setw(8)<<products[i].discount<< endl;
}
}


int Shop::getPCode(){
this->product_id_gen++;
return this->product_id_gen;
}

int Shop::getProductId(int pid){
int products_size=this->getProductSize();
for(int i=0;i<products_size;i++){
    if(pid==products[i].pcode){
        return i;
    }
}
return -1;

}

void Shop::editProduct(int index,int ch,string change){

if(ch==1){

    this->products[index].pname=change;
    return;
}

if(ch==2){
    this->products[index].price=stoi(change);
    return;
}

if(ch==3){
    this->products[index].discount=stoi(change);
    return;
}

return;
}

void Shop::removeProduct(int index){

this->products.erase(products.begin()+index);
return;

}


Product Shop::getProduct(int index){

return this->products[index];

}

/*

Shop::Shop(){
this->product_id_gen=0;

}

int Shop::getPCode(){
this->product_id_gen++;
return this->product_id_gen;

}

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
                exit(0);
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
        if(choice==1){
            add();
            return;
        }
        else if(choice==2){
            system ("CLS");
            edit();
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
    //cout<<"Enter Product Code:";
    //cin>>p.pcode;
    cout<<"Enter price:";
    cin>>p.price;
    cout<<"Enter discount:";
    cin>>p.discount;
    p.pcode=this->getPCode();
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

int Shop::getProductSize(){
return this->products.size();
}

void Shop::listItems(){
int products_size=this->getProductSize();
if(products_size==0){
    cout<<"No Products To display!";
    return;
}
 cout<<left<<setw(10)<< "Name"<<setw(5)<< "Id"<< setw(8)<< "Price"<<setw(8)<<"Discount"<< endl;
for(int i=0;i<products_size;i++){
    cout<<setw(10)<<products[i].pname<< setw(5)<<products[i].pcode<<setw(8)<<products[i].price<<setw(8)<<products[i].discount<< endl;
}
}

int Shop::getProduct(int pid){
int products_size=this->getProductSize();
for(int i=0;i<products_size;i++){
    if(pid==products[i].pcode){
        return i;
    }
}
return -1;
}

void Shop::edit(){
int pid;
do{
    int ch=-1;
    system ("CLS");
    cout<<"Enter the Pcode of Product to Modify:";
    cin>>pid;
    int index=this->getProduct(pid);
    if(index!=-1){
        cout<<"1-Edit Product Name"<<endl<<"2-Edit Product Price"<<endl<<"3-Edit Product Discount"<<endl<<"4-Go To Admin Pannel"<<endl;
        cout<<":-";
        cin>>ch;
        if(ch==1){
            string temp;
            cout<<"Enter New Name:";
            cin>>temp;
            products[index].pname=temp;
        }
        else if(ch==2){
            int temp;
            cout<<"Enter New Price:";
            cin>>temp;
            products[index].price=temp;
        }
        else{
            int temp;
            cout<<"Enter New Discount:";
            cin>>temp;
            products[index].discount=temp;
        }
         system ("CLS");
         showMenu();

    }

    else{
        cout<<"No Product With This PCode Please Try Again Later Or Press 1 To Go To Main Screen or Any Other Number To Try Again!:";
        cin>>ch;
        if(ch==1){
            system ("CLS");
            showMenu();

            return;
        }
        //cin.ignore();
        //getchar();

    }
   }while(true);
}

*/
