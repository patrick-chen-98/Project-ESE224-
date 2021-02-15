#include "user.h"
#include <fstream>

user::user() : account() {
	wins = 0;
	losses = 0;
	winpct = 0;
	winnstreak = 0;
	lastplay = "emptyword";
	premium = "false";
}


user::user(string n, string p, int w, int l, double wi, signed int s, string word, string prime) : account(n, p) {
	wins = w;
	losses = l;
	winpct = wi;
	winnstreak = s;
	lastplay = word;
	premium = prime;
}

int user::getwins() {
	return wins;
}

int user::getloses() {
	return losses;
}

double user::getwinPct() {
	return winpct;
}

signed int user::getwinnstreak() {
	return winnstreak;
}

string user::getlastplay() {
	return lastplay;
}

string user::getpremium() {
	return premium;
}

void user::setwins() {
	++wins;
}
void user::setloses() {
	++losses;
} 

void user::setwinPct() {
	winpct = (double)wins / ((double)wins + (double)losses) * 100;
}

void user::setwinnstreak(int e) {
	if ((winnstreak <= 0 ) && (e == 1)) {
		winnstreak--;
	}else if ((winnstreak <= 0) && (e == 0)) {
		winnstreak = 1;
	}else if ((winnstreak >= 0) && (e == 1)) {
		winnstreak = -1;
	}else if((winnstreak >= 0) && (e == 0)) {
		winnstreak++;	
	}
}

void user::setlastplay(string i) {
	lastplay = i;
}

void user::clearhistory() {
	wins = 0;
	losses = 0;
	winnstreak = 0;
	winpct = 0;
	lastplay = "emptyword";
	cout << "CLEARED!!!" << endl;
}

void user::becomePremium(char w) {
	if (premium == "false") {
		if (w == '1') {
			premium = '1';
			cout << "You are a first level prmium user now!!!" << endl;
		}
		else if (w == '2') {
			premium = '2';
			cout << "You are a secondary level prmium user now!!!" << endl;
		}
	}
	else {
		cout << "You were alreay a premium user." << endl;
	}
}

void user::checkinformation() {
	cout << "Name    Password      Wins    Losses    WinPct     WinStreak  LastPlay    Premium" << endl;
	cout << getname() << "   " << getpassword() <<
		"        " << getwins() << "         " << getloses() <<
		"      " << getwinPct() << " %" << "         " <<
		getwinnstreak() << "         " << getlastplay() << "     "
		<< getpremium() << endl;
}

void user::setrecord(string words, int e) {
	if (e == 0) {
		setwins();
	}
	else if (e == 1) {
		setloses();
	}
	setwinPct();
	setwinnstreak(e);
	setlastplay(words);
}

void checkPassword(vector<user>& a, string& username, string& password, int& k) {

	cout << "please enter the username: ";
	cin >> username;
	int t = 0;
	for (k = 0; k < a.size(); k++) {
		if (a[k].getname().compare(username) == 0) {
			t = 1;
			break;
		}
	}
	if (t == 0) {
		cout << "The username is incorrect." << endl;
		checkPassword(a, username, password, k);
	}
	else
	{
		cout << "please enter the password: ";
		cin >> password;
		if (a[k].getpassword().compare(password) != 0) {
			cout << "Password is wrong!" << endl;
			checkPassword(a, username, password, k);
		}
		else if (a[k].getpassword().compare(password) == 0) {
			cout << "correct" << endl;
		}
	}
}

void output(vector<user>& accountlist) {
	ofstream out;
	out.open("UserAccountHistory.txt");
	out << "Name  Password      Wins    Losses    WinPct WinStreak  LastPlay    premium" << endl;
	for (int i = 0; i < accountlist.size(); i++) {
		out << accountlist[i].getname() << "    " << accountlist[i].getpassword() << "    " << accountlist[i].getwins()
			<< "    " << accountlist[i].getloses() << "    " << accountlist[i].getwinPct() << "%" << "    " <<
			accountlist[i].getwinnstreak() << "    " << accountlist[i].getlastplay() << "    " << accountlist[i].getpremium() << endl;
	}
	out.close();
}

void scorerank(vector<user>& accountlist) {
	user temp;
	vector<user> b;
	for (int i = 0; i < accountlist.size(); i++) {
		b.push_back(accountlist[i]);
	}
	
	int m;
	for (int i = 0; i < b.size() - 1; i++) {
		m = i;
		for (int j = i + 1; j < b.size(); ++j) {
			if (b[j].getwinPct() > b[m].getwinPct())
				m = j;
		}
		temp = b[m];
		b[m] = b[i];
		b[i] = temp;
	}

	for (int i = 0; i < b.size(); i++) {
		cout << b[i].getname() << endl;
	}
}



