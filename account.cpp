#include "account.h"

account::account() : name(""), password("") {}

account::account(string n, string p) {
	name = n;
	password = p;
}

string account::getname() {
	return name;
}

string account::getpassword() {
	return password;
}