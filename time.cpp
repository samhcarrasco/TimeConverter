#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//class that will return invalid if the user inputs the time in the wrong format
class TimeFormatMistake : public exception
{
	virtual const char* what() const throw()
	{
		return "Time is invalid";
	}
};

//function that will determin if the format is incorrect

void getTimes(string str, int& hours, int& minutes) {
	//time must be 5 characters long anything outside of that is incorrect i.e 23:40 (5 characters)
	if (str.length() != 5) {
		throw TimeFormatMistake();
	}
	//the first number must be >= 0 or <= 9
	if (str[0] < '0' || str[0] > '9') {
		throw TimeFormatMistake();
	}
	//second number must be >=0 and <=9
	if (str[1] < '0' || str[1] > '9') {
		throw TimeFormatMistake();
	}
	//the third character must be a :
	if (str[2] != ':') {
		throw TimeFormatMistake();
	}
	//4th character must be >=0 and <= 9
	if (str[3] < '0' || str[3] > '9') {
		throw TimeFormatMistake();
	}
	//5th character must be >=0 and <= 9
	if (str[4] < '0' || str[4] > '9') {
		throw TimeFormatMistake();
	}

	//converting time to standard

	hours = (10 * (str[0] - '0')) + (str[1] - '0');
	minutes = (10 * (str[3] - '0')) + (str[4] - '0');
	//if the time to be converted is incorrect (hours greater than 24, less than zero and minutes less than 0 greater than 59) the it will return incorrect format.
	if ((hours < 0 || hours > 24) || (minutes < 0 || minutes > 59)) {
		throw TimeFormatMistake();
	}
}

int main() {
	string str;
	string zone;
	int hours, mins;
	//initiate input
	while (true) {
		cout << "Enter time in 24-hour notation: ";
		cin >> str;
		try {
			//determine time of day based on input of time
			getTimes(str, hours, mins);
			if (hours >= 12) {
				zone = "PM";
			}
			else {
				zone = "AM";
			}
			hours %= 12;
			if (hours == 0) {
				hours = 12;
			}
			cout << "That is the same as " << hours << ":" << setfill('0') << setw(2) << mins << " " << zone << endl;
		}
		//wrong time
		catch (exception& e) {
			cout << "There is no such time as " << str << endl;
		}
		cout << "Again?(y/n)";
		cin >> str;
		if (str != "y") {
			break;
		}
	}
	return 0;
}