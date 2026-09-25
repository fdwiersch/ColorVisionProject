#include <iostream>
using namespace std;
int red1 = 0; int blue1 = 0; int green1 = 0;
int red2 = 0; int blue2 = 0; int green2 = 0;

int reddif = 0; int bluedif = 0; int greendif =0;
int totaldif = 0;
bool play = true;

int main()
{
    while (play==true) {
        bool input = false;
        
        // valid entry check
        while (input==false) { 
            cout << "R G B #1: ";
            cin >> red1; cin >> blue1; cin >> green1;
            //cout << red1 << " " << blue1 << " " << green1 << endl;
            cout << "R G B #2: ";
            cin >> red2; cin >> blue2; cin >> green2;
            //cout << red2 << " " << blue2 << " " << green2 << endl;
            if (0<=red1 && red1<=225 && 0<=blue1 && blue1<=225 && 0<=green1 && green1<=225 && 0<=red2 && red2<=225 && 0<=blue2 && blue2<=225 && 0<=green2 && green2<=225) {
                input = true;
            } else {
                cout << "Invalid input. Numbers must be between 0 and 225. Try again. " << endl;
            }
        }
        
        // compare the difference
        reddif = abs(red1-red2); bluedif = abs(blue1-blue2); greendif = abs(green1-green2);
        totaldif = reddif + bluedif + greendif;
        cout << "Red difference: " << reddif << "\nBlue difference: " << bluedif << "\nGreen difference: " << greendif << "\n\nTotal difference: " << totaldif << endl << endl;
        //cout << totaldif << endl;
        
        // based on difference give user recomendations?
        if (totaldif >= 50) {
            cout << "ur good";
        } else if (50 > totaldif && totaldif > 20) {
            cout << "iffy";
        } else {
            cout << "DANGER";
        } //only a arbritary guess at what ranges would be good/iffy/ and dangerous further testing req plus color blind lens

        cout << "\n\ncontinue? (1/0): ";
        cin >> play;
    }        
}
