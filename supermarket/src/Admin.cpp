#include "Admin.h"

Admin::Admin(string user_name,string password)
{
    this->authentication.setUserCredentials(user_name,password);
}


Authentication Admin::auth(){

return this->authentication;

}

void Admin::add(){
    Shop *s=s->getInstance();
    do{
        string choice;
        Product p;
        cout<<"Enter Product Name:";
        cin>>p.pname;
        cout<<"Enter price:";
        cin>>p.price;
        cout<<"Enter discount:";
        cin>>p.discount;
    p.pcode=s->getPCode();
    s->addProduct(p);
    cout<<"Do You Want To Add New Product:";
    cin>>choice;
    transform(choice.begin(),choice.end(),choice.begin(),::tolower);
    if(choice!="yes"){
        return;
    }
}while(true);
}
