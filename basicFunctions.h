#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <vector>

using namespace std;
template <typename T>
void GameConsole(T a);//according the length of word, dislay the UI before user start to guess a alphabet
void StartConsole(char& w);//the first UI user would see when they open the program
int playgame(vector<string> wordlist, string words, string s);//count the number of alphabet user missed or guessed correctlly, 
															  //the string 's' passed to the this function, is used to detect whether
															  //the user is a premium user
void display(int a, vector<char> guesses, vector<char> misses, string words);//according to the word user guessed, display the "hang man"
																			 // and the word user gussed wrong and correctly
template <typename T>
void userUI(T name, char &w);// After user input their username and password correctly, it will display this UI
void refresh(string username, char &w);//used to implement the function "enter any key and key to continue...", and then go back to "userUI"
void adminUI(char& w);//UI for the administrator
void addword(list<string> &a);//used to add word user typed
void writeoutlist(list<string>& a);//output to "WordList.txt"
void deleteword(list<string> &a);//delete a word user typed
void adminrefresh(char& w);//used to implement the function "enter any key and key to continue...", and then go back to "adminUI"
void checkadminpassword();// used to check password of administrator
void premiumUI(char& w);//UI for the option "Become a premium user "
void premiumIntro();//display the information of premium user
void premiumChoiceUI(char& w);//UI for "Become a premium user"
void premiumRefresh(char& w);//used to implement the function "enter any key and key to continue...", and then go back to "premiumUI"
int secondaryplaygame(vector<string> wordlist, string words);//This is for the "secodndary premium user"count the number of alphabet 
															  //user missed or guessed correctlly, the string 's' passed to the this 
															  //function, is used to detect whether the user is a premium user
void secondarydisplay(int a, vector<char> guesses, vector<char> misses, string words);//according to the word secondary premium user guessed, display the "hang man"
																			         // and the word user gussed wrong and correctly