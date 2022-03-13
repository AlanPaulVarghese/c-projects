#include <iostream>
#include<fstream>
using namespace std;

class Shop{

    int pcode;
    float price;
    float discount;
    string pname;
public:
    void showMenu();
    void admin();
    void buyer();
    void add();
    void edit();
    void rem();
    void listItems();
    void recipt();

};





int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
