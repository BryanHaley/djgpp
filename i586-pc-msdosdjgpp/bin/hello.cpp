#include <iostream>

using namespace std;

int main()
{
	string answer = "NA";
	
	while (answer != "Y" && answer != "y")
	{
		cout << "Hello, DOS!" << endl;
		
		cout << "Quit the program? (Y/N): ";
		cin >> answer;
	}
	
	return 0;
}