#include <iostream>
#include <cstring>
#include <fstream>
#include <time.h> 
#include <list>
#include <stdlib.h> 
#include "basicFunctions.h"
#include "user.h"

using namespace std;



int main() {
	string username, password;
	int index, k;
	char s('a');
	char w;
	vector<string> wordlist;
	list<string> wordlist2;

	ifstream in, ic;
	string word;
	
	in.open("WordList.txt");
	if (in.fail()) {
		cout << "Cannot open the WordList.txt." << endl;
		exit(1);
	}
	while (!in.eof()) {
		in >> word;
		wordlist.push_back(word);
	}

	in.close();

	in.open("WordList.txt");
	list<string>::iterator it = wordlist2.begin();
	int ac(0);
	while (!in.eof()) {
		in >> word;
		wordlist2.push_back(word);
	}
	in.close();

	ic.open("UserAccountHistory.txt");
	if (ic.fail()) {
		cout << "Cannot open the WordList.txt." << endl;
		exit(1);
	}
	
	string n, p, la, prime;
	int win, lo, ws;
	double wp;

	vector<user> accountlist;
	ic >> word >> word >> word >> word >> word >> word >> word >> word;
	while (ic >> n) {
		if (ic.eof())
			break;
		ic >> p >> win >> lo >> wp >> word >> ws >> la >> prime;
		user u(n, p, win, lo, wp, ws, la, prime);
		accountlist.push_back(u);
	}
	ic.close();
	StartConsole(w);
	int e;
	
	string words;
	while (w != 'q') {
		switch (w) {
		case '1':	srand((unsigned int)time(0));
			index = (int)rand() % (wordlist.size());
			words = wordlist[index];
			playgame(wordlist, words, "0");
			cout << "please select a number to continue, or enter 'q' to quit: ";
			cin >> w;
			if (w == 'q') {
				system("CLS");
				StartConsole(w);
			}
			break;
		case '2':
			checkPassword(accountlist, username, password, k);
			system("CLS");
			userUI(username, w);
			while (w != 'q') {
				switch (w) {
				case '1':	srand((unsigned int)time(0));
					index = (int)rand() % (wordlist.size());
					words = wordlist[index];
					if (accountlist[k].getpremium() == "1") {
						string s = accountlist[k].getpremium();
						e = playgame(wordlist, words, s);
							accountlist[k].setrecord(words, e);
					}
					else if (accountlist[k].getpremium() == "2") {
						e = secondaryplaygame(wordlist, words);
							accountlist[k].setrecord(words, e);
					}
					output(accountlist);
					refresh(username, w);
					break;
				case '2':	accountlist[k].checkinformation();
					refresh(username, w);
					break;
				case '3':	if (accountlist[k].getpremium() == "false") {
					cout << "you are not premium user. You can not do this operation!!!" << endl;
					refresh(username, w);
					break;
				}
						else {
					scorerank(accountlist);
					refresh(username, w);
					break;
				}

				case '4':	system("CLS");
					premiumUI(w);
					system("CLS");
					while (w != 'q') {
						switch (w) {
						case '1':	premiumIntro();
							premiumRefresh(w);
							break;
						case'2':	premiumChoiceUI(w);
							accountlist[k].becomePremium(w);
							premiumRefresh(w);
							break;
						}
					}
					output(accountlist);
					if (w == 'q') {
						system("CLS");
						userUI(username, w);
					}
					break;
				case '5':	if (accountlist[k].getpremium() == "false") {
					cout << "you are not premium user. You can not do this operation!!!" << endl;
					refresh(username, w);
					break;
				}
						else {
					accountlist[k].clearhistory();
					refresh(username, w);
					break;
				}


				default:	cout << "Your command is wrong;" << endl;
					cout << "please select a number to continue, or enter 'q' to quit: ";
					cin >> w;
					break;
				}
			}
			
				if (w == 'q') {
					system("CLS");
					StartConsole(w);
				}
				break;
		case'3':	checkadminpassword();
			system("CLS");
			adminUI(w);
			while (w != 'q') {
				switch (w) {
				case'1':	wordlist2.sort();
					writeoutlist(wordlist2);
					adminrefresh(w);
					break;
				case'2':	addword(wordlist2);
					writeoutlist(wordlist2);
					adminrefresh(w);
					break;
				case'3':	deleteword(wordlist2);
					writeoutlist(wordlist2);
					adminrefresh(w);
					break;
				default:	cout << "Your command is wrong;" << endl;
					cout << "please select a number to continue, or enter 'q' to quit: ";
					cin >> w;
					break;
				}
			}
			if (w == 'q') {
				system("CLS");
				StartConsole(w);
			}
			break;
		default:	cout << "Your command is wrong;" << endl;
			cout << "please select a number to continue, or enter 'q' to quit: ";
			cin >> w;
			break;
			}
		}
	
}