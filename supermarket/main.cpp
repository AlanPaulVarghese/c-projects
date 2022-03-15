#include <iostream>
#include<Shop.h>
#include<User.h>
#include<Authentication.h>
using namespace std;

Shop *Shop::instance=NULL;//Initialize pointer to zero so that it can be initialized in first call to getInstance



int main()
{

    Shop *s=s->getInstance();
    s->showMenu();
    return 0;
}
