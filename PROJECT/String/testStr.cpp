#include"String.h"
#include"String.cpp"
using namespace std;
using namespace tairitsu_h;

int main()
{
    String str = "hello";

    String::iterator it = str.begin();
    while(it != str.end())
    {
        cout << *it;
        it++;
    }
    cout << endl;

    str.push_back(' ');
    str.push_back('w');
    str.push_back('o');
    str.push_back('r');
    str.push_back('l');
    str.push_back('d');

    for(auto ch : str)
    {
        cout << ch;
    }
    cout << endl;
    

    str.append(" hello, C++");
    str.insert(11, ',');
    str.insert(str.size(), '.');
    str.insert(0, "Hello bit! ");
    str.erase(0, 11);

    for(size_t i=0; i<str.size(); i++)
    {
        cout << str[i];
    }
    cout << endl;


    
    return 0;
}