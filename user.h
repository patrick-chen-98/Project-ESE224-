#include <string>
#include <vector>
#include <iostream>
#include "account.h"
using namespace std;


class user : public account
 {
private:
	string lastplay, premium;
	int wins, losses;
	signed int winnstreak;
	double winpct;
public:
	user();//default constructor
	user(string n, string p, int win, int lo, double wp, signed int s, string word, string preimum);//parameterized constructor
	//Accessor
	int getwins();
	int getloses();
	double getwinPct();
	signed int getwinnstreak();
	string getlastplay();
	string getpremium();
	//Mutatotr
	void setwins();
	void setloses();
	void setwinPct();
	void setwinnstreak(int e);
	void setlastplay(string i);
	void clearhistory();//Clear user's history, number of wins, losses, winpct and winnstreak are set to 0, last played word is set to "emptyword" 
	void becomePremium(char w);//upated the user to primium user
	void checkinformation();//output user's information	
	void setrecord( string words, int e);//after user play a game, set their record according to their result
};
void checkPassword(vector<user>& a, string& username, string& password, int& k);//check user's username and password
void output(vector<user>& a);//output to the "UserAccountHistory.txt"
void scorerank(vector<user>& a);//display the rank according user's winning percentage, uses bubble sort



