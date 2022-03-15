#include "User.h"


User::User(string user_name,string password){

  this->authentication.setUserCredentials(user_name,password);
}

Authentication User::auth(){
return this->authentication;
}
