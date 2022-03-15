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


void Admin::edit(){
Shop *s=s->getInstance();
do{
    system("CLS");
    int pid;
    cout<<"Enter Product Code:";
    cin>>pid;
    int index=s->getProductId(pid);
    if(index!=-1){
        int ch;
        cout<<"Product Found:"<<endl;
        cout<<"1-Edit Product Name"<<endl<<"2-Edit Product Price"<<endl<<"3-Edit Product Discount"<<endl<<"4-Go To Admin Pannel"<<endl;
        cout<<":-";
        cin>>ch;
        string temp;
        if(ch==1){
            cout<<"Enter New Name:";
            cin.ignore();
            getline(cin,temp);
        }
        else if(ch==2){
            cout<<"Enter New Price:";
            cin.ignore();
            getline(cin,temp);
        }
        else{
            cout<<"Enter New Discount:";
            cin.ignore();
            getline(cin,temp);
        }
        s->editProduct(index,ch,temp);
    }
    else{
        cout<<"No Product By This Code!:"<<endl;
    }
    string choice;
    cout<<"Would You Like To Modify Another Product:";
    cin>>choice;
    transform(choice.begin(),choice.end(),choice.begin(),::tolower);
    if(choice!="yes"){
        return;
    }
}while(true);


}




void Admin::rem(){
Shop *s=s->getInstance();
do{
    system("CLS");
    int pid;
    cout<<"Enter Product Code To Remove:"<<endl;
    cin>>pid;
    int index=s->getProductId(pid);
    if(index!=-1){
      s->removeProduct(index);
      cout<<"Product Removed!"<<endl;
    }
    else{
            cout<<"No Product By This Code!:"<<endl;
        }
    string choice;
    cout<<"Would You Like To Remove Another Product:";
    cin>>choice;
    transform(choice.begin(),choice.end(),choice.begin(),::tolower);
    if(choice!="yes"){
        return;
    }

}while(true);

}



void Admin::credentials(){
this->auth().changeCredentials();
return;
}
