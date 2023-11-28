#include"hash.h"
#include"timer.h"
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using std::string;
using std::cout;
using std::vector;
using std::fstream;
using std::ofstream;
using std::endl;

string dirtWord;
string Word;
Timer tim;
Hash<string> Dict(133169);
vector<string>misWord;


long NotChecked = 0;
long corr = 0;
long mis = 0;

string cleanWord(string dirtWord) {
	for (int i = 0; i < dirtWord.size(); i++) {
		if (isalnum(dirtWord[i])) {
			if (isupper(dirtWord[i])) { dirtWord[i] = tolower(dirtWord[i]); }
		}
		else if (dirtWord[i] == '\'') {}
		else {
			dirtWord.erase(i, 1);
			i--;
		}
	}
	return dirtWord;
}

int main() {
	fstream dictionary;
	dictionary.open("dict.txt");
	dictionary >> dirtWord;
	while (!dictionary.eof()) {
		Word = cleanWord(dirtWord);
		Dict.insert(Word);
		dictionary >> dirtWord;
	}
	tim.Start();
	fstream book;
	book.open("book.txt");
	book >> dirtWord;
	while (!book.eof()) {
		Word = cleanWord(dirtWord);
		if (Word.empty());
		else if (Word[0] == '\'' || isdigit(Word[0])) {
			NotChecked++;
		}
		else if (Dict.find(Word)) {
		}
		else {
		}
		book >> dirtWord;
	}

	tim.Stop();
	ofstream mispelt("misspelled.txt");
	for (int i = 0; i < misWord.size(); i++) {
		mispelt << misWord[i] << endl;
	}
	cout << "Dictionary size " << Dict.getSize() << endl;
	cout << "Done checking and these are the results\n";
	cout << "Finished in time: " << tim.Time() << endl;
	cout << "There are " <<  " words found in the dictionary\n";
	cout << "compares. Average: " << endl;
	cout << "There are " << " NOT found in the dictionary\n";
	cout << " compares. Average: " <<  endl;
	cout << "There are " << NotChecked << " words not checked.\n";
	return 0;
}
