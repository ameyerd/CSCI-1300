#include <iostream>
#include <string>
using namespace std;

//Counting words in a user input sequence
int main()
{
	int short_words = 0;
	string input;
	cout << "Enter some words, please:" << endl;
	while (cin >> input)
	{
		if (input.length() <= 3)
		{
			short_words++;
		}
	}
	cout << endl << "There are " << short_words << " words with 3 or fewer characters" << endl;
	return 0;
}


// control + D to exit when it keeps accepting strings