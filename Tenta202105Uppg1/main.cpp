#include <iostream>
#include <vector>
#include <cstdlib>
#include<windows.h>
using namespace std;

vector <string>bokstaver = { "A", "B","C", "D", "E", "F", "G", "H", "I", "J", "K","L","M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "�", "�","�" };

void svenska() {
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
}
int randIndex() {
	srand(time(0));
	int randInd = rand() % 29;
	return randInd;
}

string bokstavReturn(int index) {
	return bokstaver[index];
}

void vokalOrCons(string bokstav) {
	string vokaler = "A O U � E I Y � �";
	if (vokaler.find(bokstav)) {
		cout << "Den hemliga bokstaven �r en vokal.." << endl;
	}
	else {
		cout << "Bokstaven �r en konsonant..." << endl;
	}
}
void firstOrSecondHalf(int index){
	if (index < 14) {
		cout << "Bokstaven �r i f�rsta halvan av alfabetet!" << endl;
	}
	else {
		cout << "Bokstaven �r i andra halvan av alfabetet! " << endl;
	}
}

int main() {
	svenska();
	bool run = true;

	while (run) {
		string gissning;
		int randInd = randIndex();
		string guessLetter = bokstavReturn(randInd);
		cout << guessLetter;
		int antal_gissningar = 0;
		while (run) {

			cout << "Gissa bokstav: ";
			cin >> gissning;
			antal_gissningar++;
			if (gissning == "0") {
				cout << "Den r�tta bokstaven var: " << guessLetter;
				break;
			}
			else if (gissning == guessLetter) {
				cout << "Bra jobbat du gissade r�tt!" << endl;
			}
			else if (antal_gissningar == 5) {
				vokalOrCons(guessLetter);
			}
			else if (antal_gissningar == 10) {
				firstOrSecondHalf(randInd);
			}
			else if (antal_gissningar == 15) {
				cout << "Bokstaven har plats " << randInd << "i alfabetet!" << endl;
			}

			else if (antal_gissningar == 29) {
				cout << "N� nu tr�ttnar jag, du har kunnat gissa p� ALLA bokst�ver, nu f�r du b�rja om.." << endl;
				cout << "Den r�tta bokstaven var " << guessLetter << endl;
				break;
			}
		}
		
	}


}