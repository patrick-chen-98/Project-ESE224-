#include<time.h> 
#include "basicFunctions.h"		
#include <fstream>



vector<char> guesses;
vector<char> misses;

template <typename T>
void GameConsole(T a) {

	cout << "+---------------------------------+" << endl;
	cout << "|             HANGMAN             |" << endl;
	cout << "+---------------------------------+" << endl;
	cout << "|                |                |" << endl;
	cout << "|                                 |" << endl;
	cout << "|                                 |" << endl;
	cout << "|                                 |" << endl;
	cout << "|                                 |" << endl;
	cout << "|                                 |" << endl;
	cout << "+---------------------------------+" << endl;
	cout << "|";
	for (int i = 0; i < (33 - 2 * a) / 2 + 1; i++) {
		cout << " ";
	}
	for (int i = 0; i < a; i++) {
		cout << "_ ";
	}
	for (int i = 0; i < (33 - 2 * a) / 2; i++) {
		cout << " ";
	}
	cout << "|" << endl;
	cout << "+---------------------------------+" << endl;
}

void StartConsole(char &w) {
	cout << "+---------------------------------+" << endl;
	cout << "|           Hangman Ganme         |" << endl;
	cout << "+---------------------------------+" << endl;
	cout << "|           ESE FALL 2019         |" << endl;
	cout << "+---------------------------------+" << endl;
	cout << "|           Group Members:        |" << endl;
	cout << "|           Patrick Chen          |" << endl;
	cout << "|          Bassel EI Amine        |" << endl;
	cout << "|            Ammad Mehdi          |" << endl;
	cout << "+---------------------------------+" << endl;
	cout << "|       1. start a new game       |" << endl;
	cout << "|       2. sign in as user        |" << endl;
	cout << "|       3. sign in as admin       |" << endl;
	cout << "+---------------------------------+" << endl;
	cout << "please select a number to continue, or enter 'q' to quit: ";
	cin >> w;
}

void display(int a, vector<char> guesses, vector<char> misses, string words) {
	cout << "+---------------------------------+" << endl;
	cout << "|             HANGMAN             |" << endl;
	cout << "+---------------------------------+" << endl;
	cout << "|                |                |" << endl;
	if (misses.size() == 0) {
		cout << "|                                 |" << endl;
		cout << "|                                 |" << endl;
		cout << "|                                 |" << endl;
	}
	else if (misses.size() == 1) {	
		cout << "|                o                |" << endl;
		cout << "|                                 |" << endl;
		cout << "|                                 |" << endl;
	}
	else if (misses.size() == 2) {
		cout << "|                o                |" << endl;
		cout << "|                |                |" << endl;
		cout << "|                                 |" << endl;
	}
	else if (misses.size() == 3) {
		cout << "|                o                |" << endl;
		cout << "|               /|                |" << endl;
		cout << "|                                 |" << endl;
	}
	else if (misses.size() == 4) {
		cout << "|                o                |" << endl;
		cout << "|               /|\\               |" << endl;
		cout << "|                                 |" << endl;
	}
	else if (misses.size() == 5) {
		cout << "|                o                |" << endl;
		cout << "|               /|\\               |" << endl;
		cout << "|               /                 |" << endl;
	}
	else if (misses.size() == 6) {
		cout << "|                o                |" << endl;
		cout << "|               /|\\               |" << endl;
		cout << "|               / \\               |" << endl;
	}

	cout << "|                                 |" << endl;
	cout << "|                                 |" << endl;
	cout << "+---------------------------------+" << endl;
	cout << "|";
	for (int i = 0; i < (33 - 2 * a) / 2 + 1; i++) {
		cout << " ";
	}
	
	vector<int> count;
	vector<char> list;
	for (int j = 0; j < guesses.size(); j++) {
		for (int i = 0; i < words.size(); i++) {
			if (words[i] == guesses[j]) {
				count.push_back(i);
				list.push_back(guesses[j]);
			}
		}
	}
	if (list.size() > 0) {
		int m(0);
		for (int i = 0; i < list.size() - 1; i++) {
			m = i;
			for (int j = i + 1; j < list.size(); ++j) {
				if (count[j] < count[m])
					m = j;
			}

			int temp = count[m];
			count[m] = count[i];
			count[i] = temp;

			char t = list[m];
			list[m] = list[i];
			list[i] = t;
		}
	}
	
	int k = 0;
	if (guesses.size() == 0) {
		for (int i = 0; i < words.size(); i++) {
			cout << "_ ";
		}
	}
	else {
		for (int i = 0; i < words.size(); i++) {
			if (k < count.size() && i == count[k]) {

				cout << list[k] << " ";
				k++;

			}
			else
				cout << "_ ";
		}
	}
	for (int i = 0; i < (33 - 2 * a) / 2; i++) {
		cout << " ";
	}
	cout << "|" << endl;
	cout << "+---------------------------------+" << endl;
}

int playgame(vector<string> wordlist, string words, string s) {
	system("CLS");
	int wordlength;
	wordlength = words.length();
	int miss(0);
	char guess;
	vector<char> guesses(0);
	vector<char> misses(0);
	if (s == "1")
		cout << words << endl;
	GameConsole(wordlength);
	cout << "Guess a letter: ";
	cin >> guess;
	int p = 0;

	for (int i = 0; i < wordlength; i++) {
		if (guess == words[i]) {
			p = 1;
			guesses.push_back(guess);
			break;
		}
	}
	int g(0);
	for (int i = 0; i < wordlength; i++)
		if (guess == words[i])
			g++;

	if (p == 0) {
		misses.push_back(guess);
		miss++;
	}

	system("CLS");
	while (miss < 7) {
		if (s == "1")
			cout << words << endl;
		display(wordlength, guesses, misses, words);
		if (miss == 6)
			break;
		if (g == words.size())
			break;
		cout << "Guess:";
		for (int j = 0; j < guesses.size(); j++) {
			cout << " " << guesses[j];
		}
		cout << endl;
		cout << "misses:";
		for (int j = 0; j < misses.size(); j++) {
			cout << " " << misses[j];
		}
		cout << endl;
		cout << "Guess a letter: ";
		cin >> guess;
		for (int i = 0; i < guesses.size(); i++) {
			if (guess == guesses[i]) {
				cout << "The character has been guessed already! please enter another one: ";
				cin >> guess;
				i--;
			}
		}
		for (int i = 0; i < misses.size(); i++) {
			if (guess == misses[i]) {
				cout << "The character has been guessed already! please enter another one: ";
				cin >> guess;
				i--;
			}
		}
		if (miss < 6) {
			system("CLS");
		}

		int p = 0;

		for (int i = 0; i < wordlength; i++) {
			if (guess == words[i]) {
				p = 1;
				guesses.push_back(guess);
				break;
			}
		}
		for (int i = 0; i < wordlength; i++)
			if (guess == words[i])
				g++;

		if (p == 0) {
			misses.push_back(guess);
			miss++;
		}
	}

	if (miss == 6) {
		cout << "|            You lost!            |" << endl;
		cout << "|       The correct word is:      |" << endl;
		cout << "|";
		for (int i = 0; i < (33 - 2 * words.length()) / 2 + 1; i++) {
			cout << " ";
		}
		for (int i = 0; i < words.length(); i++) {
			cout << words[i] << " ";
		}
		for (int i = 0; i < (33 - 2 * words.length()) / 2; i++) {
			cout << " ";
		}
		cout << "|" << endl;
		cout << "+---------------------------------+" << endl;
		return 1;
	}
	else {
		
		cout << "|            You win!             |" << endl;
		cout << "+---------------------------------+" << endl;
		return 0;
	}
}

template <typename T>
void  userUI(T name, char &w) {
	int a = name.length();
	cout << "+---------------------------------+" << endl;
	cout << "|";
	for (int i = 0; i < (33 - 2 * a) / 2 + 1; i++) {
		cout << " ";
	}
	for (int i = 0; i < a; i++) {
		cout << name[i] << " ";
	}
	for (int i = 0; i < (33 - 2 * a) / 2; i++) {
		cout << " ";
	}
	cout << "|" << endl;
	cout << "+---------------------------------+" << endl;
	cout << "|         1. Play a game          |" << endl;
	cout << "|     2. Check your history       |" << endl;
	cout << "|        3. Check ranking         |" << endl;
	cout << "|    4. Become a premium user     |" << endl;
	cout << "|        5. clear history         |" << endl;
	cout << "+---------------------------------+" << endl;
	cout << "please select a number to continue, or enter 'q' to quit: ";
	cin >> w;
}


void refresh(string username, char &w) {
	system("pause");
	system("CLS");
	userUI(username, w);
}

void adminUI(char &w) {
	cout << "+---------------------------------+" << endl;
	cout << "|      Manage Your Word List      |" << endl;
	cout << "+---------------------------------+" << endl;
	cout << "| 1. Sort the list alphabetically |" << endl;
	cout << "|  2. Add a new word to the list  |" << endl;
	cout << "|  3. Delete a word from the list |" << endl;
	cout << "+---------------------------------+" << endl;
	cout << "please select a number to continue, or enter 'q' to quit: ";
	cin >> w;
}


void addword(list<string> &a) {
	string word;
	cout << "please enter the word you want to add: ";
	cin >> word;
	a.push_back(word);
	a.sort();
}

void writeoutlist(list<string>& a) {
	ofstream out;
	out.open("WordList.txt");
	list<string>::iterator it = a.begin();
	for (it; it != a.end(); it++) {
		out << *it << endl;
	}
	out.close();
}

void deleteword(list<string> &a) {
	string word;
	cout << "please enter the word you want to delete: ";
	cin >> word;
	int k = 0;
	list<string>::iterator it = a.begin();
	for (it; it != a.end(); it++) {
		if (*it == word) {
			k = 1;
			a.erase(it);
			break;
		}
	}
	if (k == 0) {
		cout << "The word you entered is not in the list." << endl;;
		deleteword(a);
	}
	else if (k == 1) {
		cout << "The word you entered has been removed from the list." << endl;
	}
	
}

void adminrefresh(char& w) {
	system("pause");
	system("CLS");
	adminUI(w);
}

void checkadminpassword() {
	string word;
	cout << "please enter password:";
	cin >> word;
	if (word.compare("admin12345") == 0) {
		system("CLS");
	}
	else {
		cout << "Your password is wrong,";
		checkadminpassword();
	}
}

void premiumUI(char& w) {
	cout << "+---------------------------------+" << endl;
	cout << "|   1. know more about premium    |" << endl;
	cout << "|    2. Become a premium user     |" << endl;
	cout << "+---------------------------------+" << endl;
	cout << "please select a number to continue, or enter 'q' to quit: ";
	cin >> w;
}

void premiumIntro() {
	cout << "There are two type premim user:" << endl;
	cout << "	1. first level premim user." << endl;
	cout << "	2. secondary level premim user." << endl << endl;
	cout << "first level premim user: You can know the word you will guess before the game start." << endl;
	cout << "secondary level premim user: You will have three more chances than ordinary user to guess the word." << endl;
}

void premiumChoiceUI(char& w) {
	cout << "+---------------------------------+" << endl;
	cout << "|   1. first level premim user    |" << endl;
	cout << "| 2. secondary level premim user  |" << endl;
	cout << "+---------------------------------+" << endl;
	cout << "please select a number to continue: ";
	cin >> w;
}

void premiumRefresh(char& w) {
	system("pause");
	system("CLS");
	premiumUI(w);
}

int secondaryplaygame(vector<string> wordlist, string words) {
	system("CLS");
	int wordlength;
	wordlength = words.length();
	int miss(0);
	char guess;
	vector<char> guesses(0);
	vector<char> misses(0);
	GameConsole(wordlength);
	cout << "Guess a letter: ";
	cin >> guess;
	int p = 0;

	for (int i = 0; i < wordlength; i++) {
		if (guess == words[i]) {
			p = 1;
			guesses.push_back(guess);
			break;
		}
	}
	int g(0);
	for (int i = 0; i < wordlength; i++)
		if (guess == words[i])
			g++;

	if (p == 0) {
		misses.push_back(guess);
		miss++;
	}

	system("CLS");
	while (miss < 10) {
		secondarydisplay(wordlength, guesses, misses, words);
		if (miss == 9)
			break;
		if (g == words.size())
			break;
		cout << "Guess:";
		for (int j = 0; j < guesses.size(); j++) {
			cout << " " << guesses[j];
		}
		cout << endl;
		cout << "misses:";
		for (int j = 0; j < misses.size(); j++) {
			cout << " " << misses[j];
		}
		cout << endl;
		cout << "Guess a letter: ";
		cin >> guess;
		for (int i = 0; i < guesses.size(); i++) {
			if (guess == guesses[i]) {
				cout << "The character has been guessed already! please enter another one: ";
				cin >> guess;
				i--;
			}
		}
		for (int i = 0; i < misses.size(); i++) {
			if (guess == misses[i]) {
				cout << "The character has been guessed already! please enter another one: ";
				cin >> guess;
				i--;
			}
		}
		if (miss < 9) {
			system("CLS");
		}

		int p = 0;

		for (int i = 0; i < wordlength; i++) {
			if (guess == words[i]) {
				p = 1;
				guesses.push_back(guess);
				break;
			}
		}
		for (int i = 0; i < wordlength; i++)
			if (guess == words[i])
				g++;

		if (p == 0) {
			misses.push_back(guess);
			miss++;
		}
	}

	if (miss == 9) {
		cout << "|            You lost!            |" << endl;
		cout << "|       The correct word is:      |" << endl;
		cout << "|";
		for (int i = 0; i < (33 - 2 * words.length()) / 2 + 1; i++) {
			cout << " ";
		}
		for (int i = 0; i < words.length(); i++) {
			cout << words[i] << " ";
		}
		for (int i = 0; i < (33 - 2 * words.length()) / 2; i++) {
			cout << " ";
		}
		cout << "|" << endl;
		cout << "+---------------------------------+" << endl;
		return 1;
	}
	else {

		cout << "|            You win!             |" << endl;
		cout << "+---------------------------------+" << endl;
		return 0;
	}
}

void secondarydisplay(int a, vector<char> guesses, vector<char> misses, string words) {
	cout << "+---------------------------------+" << endl;
	cout << "|             HANGMAN             |" << endl;
	cout << "+---------------------------------+" << endl;
	cout << "|                |                |" << endl;
	if (misses.size() == 0) {
		cout << "|                                 |" << endl;
		cout << "|                                 |" << endl;
		cout << "|                                 |" << endl;
	}
	else if (misses.size() == 1) {
		cout << "|               --                |" << endl;
		cout << "|                                 |" << endl;
		cout << "|                                 |" << endl;
	}
	else if (misses.size() == 2) {
		cout << "|               ---               |" << endl;
		cout << "|               |                 |" << endl;

		cout << "|                                 |" << endl;
	}
	else if (misses.size() == 3) {
		cout << "|               ---               |" << endl;
		cout << "|               | |               |" << endl;
		cout << "|                                 |" << endl;
		cout << "|                                 |" << endl;
	}
	else if (misses.size() == 4) {
		cout << "|               ---               |" << endl;
		cout << "|               | |               |" << endl;
		cout << "|               ---               |" << endl;
		cout << "|                                 |" << endl;
	}
	else if (misses.size() == 5) {
		cout << "|               ---               |" << endl;
		cout << "|               | |               |" << endl;
		cout << "|               ---               |" << endl;
		cout << "|               /                 |" << endl;
	}
	else if (misses.size() == 6) {
		cout << "|               ---               |" << endl;
		cout << "|               | |               |" << endl;
		cout << "|               ---               |" << endl;
		cout << "|               /|                |" << endl;

	}
	else if (misses.size() == 7) {
		cout << "|               ---               |" << endl;
		cout << "|               | |               |" << endl;
		cout << "|               ---               |" << endl;
		cout << "|               /|\\               |" << endl;
	}
	else if (misses.size() == 8) {
		cout << "|               ---               |" << endl;
		cout << "|               | |               |" << endl;
		cout << "|               ---               |" << endl;
		cout << "|               /|\\               |" << endl;
		cout << "|               /                 |" << endl;
	}
	else if (misses.size() == 9) {
		cout << "|               ---               |" << endl;
		cout << "|               | |               |" << endl;
		cout << "|               ---               |" << endl;
		cout << "|               /|\\               |" << endl;
		cout << "|               / \\               |" << endl;
	}

	cout << "|                                 |" << endl;
	cout << "|                                 |" << endl;
	cout << "+---------------------------------+" << endl;
	cout << "|";
	for (int i = 0; i < (33 - 2 * a) / 2 + 1; i++) {
		cout << " ";
	}

	vector<int> count;
	vector<char> list;
	for (int j = 0; j < guesses.size(); j++) {
		for (int i = 0; i < words.size(); i++) {
			if (words[i] == guesses[j]) {
				count.push_back(i);
				list.push_back(guesses[j]);
			}
		}
	}
	if (list.size() > 0) {
		int m(0);
		for (int i = 0; i < list.size() - 1; i++) {
			m = i;
			for (int j = i + 1; j < list.size(); ++j) {
				if (count[j] < count[m])
					m = j;
			}

			int temp = count[m];
			count[m] = count[i];
			count[i] = temp;

			char t = list[m];
			list[m] = list[i];
			list[i] = t;
		}
	}

	int k = 0;
	if (guesses.size() == 0) {
		for (int i = 0; i < words.size(); i++) {
			cout << "_ ";
		}
	}
	else {
		for (int i = 0; i < words.size(); i++) {
			if (k < count.size() && i == count[k]) {

				cout << list[k] << " ";
				k++;

			}
			else
				cout << "_ ";
		}
	}
	for (int i = 0; i < (33 - 2 * a) / 2; i++) {
		cout << " ";
	}
	cout << "|" << endl;
	cout << "+---------------------------------+" << endl;
}