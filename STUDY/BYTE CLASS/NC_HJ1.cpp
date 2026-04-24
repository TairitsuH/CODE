//https://www.nowcoder.com/practice/8c949ea5f36f422594b306a2300315da?tpId=37&&tqId=21224&rp=5&ru=/activity/oj&qru=/ta/huawei/question-ranking
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str;
    getline(cin, str);

    int pos = str.rfind(' ');
    if(pos == -1)
    {
        cout << str.size() << endl;
    }
    else
    {
        cout << str.size() - 1 - pos << endl;
    }
    
    return 0;
}

//二刷：还是需要不断理解复盘，学新知识时只做一遍是不够的
//一刷：手感不错，查文档真香(❁´◡`❁)
// #include<iostream>
// #include<string>
// using namespace std;

// int main()
// {
//     string s;
//     getline(cin, s);

//     int pos = s.rfind(' ');

//     if(pos == -1) cout << s.size() << endl;
//     else cout << s.size() - pos - 1 << endl;

//     return 0;
// }