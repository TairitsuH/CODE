#include"String.h"
 using namespace std;
using namespace tairitsu_h;

int main()
{
    String str = "hello";

    // String::iterator it = str.begin();
    // while(it != str.end())
    // {
    //     cout << *it;
    //     it++;
    // }
    // cout << endl;

    cout << str << endl;

    str.push_back(' ');
    str.push_back('w');
    str.push_back('o');
    str.push_back('r');
    str.push_back('l');
    str.push_back('d');

    // for(auto ch : str)
    // {
    //     cout << ch;
    // }
    // cout << endl;

    cout << str << endl;
    

    str.append(" hello, C++");
    str.insert(11, '!');
    str.insert(str.size(), '.');
    str.insert(0, "Hello bit! ");
    // str.erase(0, 1);

    cout << str << endl;

    // for(size_t i=0; i<str.size(); i++)
    // {
    //     cout << str[i];
    // }
    // cout << endl;

    cout << str.find('C') << endl;
    cout << str.find('w') << endl;
    cout << str.find('+') << endl;
    cout << str.find("world") << endl;
    cout << str.find("C++") << endl;

    // for(size_t i=0; i<=str.size(); i++)
    // {
    //     String ret1 = str.substr(0, i);
    //     cout << ret1 << endl;
    // }

    // for(size_t i=str.size()-1; i>=0; i--)
    // {
    //     str.erase(i, 1);
    //     cout << str << endl;
    // }

    String str1 = "hello";
    String str2 = "hello";
    String str3 = "Hello bit! hello world! hello, C++.";
    String str4 = "helloa";
    String str5 = "hellob";

    cout << (str == str3) << endl; // 1
    cout << (str1 == str2) << endl; // 1
    cout << (str4 > str5) << endl; // 0
    cout << (str4 < str5) << endl; // 1
    cout << (str4 >= str3) << endl; // 1
    cout << (str4 <= str2) << endl; // 0

    String str6;
    cin >> str6;
    cout << str6;

    
    return 0;
}