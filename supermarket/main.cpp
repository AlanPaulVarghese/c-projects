#include <iostream>
#include<Shop.h>
#include<User.h>
#include<Authentication.h>
using namespace std;





int main()
{
    User u("alan","alan");
    cout<<u.auth().verifyUser();
    //Shop shop;
    //shop.showMenu();
    return 0;
}
