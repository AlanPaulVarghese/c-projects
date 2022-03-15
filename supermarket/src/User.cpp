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
                cout<<"There Is No Product With This Id!:";
            }else{

              this->cartProducts.push_back(s->getProduct(index));
              cout<<"Product Added To Cart"<<endl;

            }
            string choice;
            cout<<"Would You Like To Buy Another Product";
            cin>>choice;
            transform(choice.begin(),choice.end(),choice.begin(),::tolower);
            if(choice!="yes"){
                        return;
                        }
            }while(true);




}
