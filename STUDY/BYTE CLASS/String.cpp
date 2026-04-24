#include<iostream>
#include<string>
using namespace std;

int main(int argc, char *argv[])

{

	string strText = "How are you?";

	string strSeparator = " ";

	string strResult;

	int size_pos = 0;

	int size_prev_pos = 0;

	while((size_pos=strText.find_first_of(strSeparator, size_pos)) != string::npos)

	{
        // are(0,3,4,3)
		strResult = strText.substr(size_prev_pos, size_pos-size_prev_pos);
        // How are 
		cout<<strResult<<" ";
        // 4,4,8,8
		size_prev_pos = ++size_pos;

	}
    // 8 != size()
	if(size_prev_pos != strText.size())

	{

		strResult = strText.substr(size_prev_pos, size_pos-size_prev_pos);
        // you?
		cout<<strResult<<" ";

	}

	cout<<endl;

	return 0;

}