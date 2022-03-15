#include "User.h"

    Shop *s=s->getInstance();
User::User(string user_name,string password){

  this->authentication.setUserCredentials(user_name,password);
}

Authentication User::auth(){
return this->authentication;
}


void User::buyProduct(){
            do{
                system("CLS");
                int pid;
            if(s->getProductSize()==0){
                cout<<"No Products To Display!";
                return;
            }
            s->listItems();
            cout<<endl;
            cout<<"Please Enter The Pcode Of Product To Buy:"<<endl;
            cin>>pid;
            int index=s->getProductId(pid);
            if(index==-1){
                cout<<"There Is No Product With This Id!:"<<endl;
            }else{

              this->cartProducts.push_back(s->getProduct(index));
              cout<<"Product Added To Cart"<<endl;

            }
            string choice;
            cout<<"Would You Like To Buy Another Product:";
            cin>>choice;
            transform(choice.begin(),choice.end(),choice.begin(),::tolower);
            if(choice!="yes"){
                        return;
                        }
            }while(true);


}

int User::getCartSize(){
return this->cartProducts.size();

}

void User::cart(){
int cart_size=this->getCartSize();
if(cart_size==0){
    cout<<"No Products To display!";
    cin.ignore();
    getchar();
    return;
}
 cout<<left<<setw(10)<< "Name"<<setw(5)<< "Id"<< setw(8)<< "Price"<<setw(8)<<"Discount"<< endl;
for(int i=0;i<cart_size;i++){
    cout<<setw(10)<<this->cartProducts[i].pname<< setw(5)<<this->cartProducts[i].pcode<<setw(8)<<this->cartProducts[i].price<<setw(8)<<this->cartProducts[i].discount<< endl;
}

cout<<endl;

int ch;
cout<<"Press 1 To Order, 2-Do Nothing Or Press Any Other Number To Discard Products:";
cin>>ch;
switch(ch){

case 1:
       for(int i=0;i<cart_size;i++){
        this->oderProducts.push_back(this->cartProducts[i]);
       }

       cartProducts.clear();
       break;
case 2:
       return;
default:
       cartProducts.clear();
}

return;
}


int User::getOderProductsSize(){

return this->oderProducts.size();
}

void User::oders(){

int oder_size=getOderProductsSize();

if(oder_size==0){
    cout<<"No Products To display!";
    cin.ignore();
    getchar();
    return;
}

cout<<left<<setw(10)<< "Name"<<setw(5)<< "Id"<< setw(8)<< "Price"<<setw(8)<<"Discount"<< endl;
for(int i=0;i<oder_size;i++){
    cout<<setw(10)<<this->oderProducts[i].pname<< setw(5)<<this->oderProducts[i].pcode<<setw(8)<<this->oderProducts[i].price<<setw(8)<<this->oderProducts[i].discount<< endl;
}

cin.ignore();
getchar();
}
