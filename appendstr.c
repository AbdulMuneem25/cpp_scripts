#include <iostream>
#include <string>
using namespace std;


void app(string str1, string str2){

	str1.append(str2);
	cout << " Using append(): ";
	cout << str1 << endl;
}

void appendstr(){

	string str1("Hello world!");
	string str2("This is Japan");
	cout << "Original words" << str1 << endl;
	app(str1, str2);

	return 0;

}
