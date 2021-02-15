#include <string>
using namespace std;

class account {
private:
	string name, password;
public:
	account();
	account(string n, string p);
	string getname();
	string getpassword();
};