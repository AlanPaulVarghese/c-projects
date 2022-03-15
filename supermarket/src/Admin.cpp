#include "Admin.h"

Admin::Admin(string user_name,string password)
{
    this->authentication.setUserCredentials(user_name,password);
}


Authentication Admin::auth(){

return this->authentication;

}
