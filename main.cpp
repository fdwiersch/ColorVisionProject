#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool play = true;
bool isValidHex(string);
string hex1; string hex2; 
float luminosityCompare(string, string);
void lumlosers(vector<string>);
vector<string> hexToRGB(string);
void formatRGB(string&);
string writeRGB(vector<string>);
float luminosity(string);


int main() {
    ofstream writer("colors.txt");
    string line;
    vector<string> palette;
    string input = "";
    while (play==true) {
        //writer.open("colors.txt", ios::out); //open to write in
        if (!writer.is_open()) {
            cout << "file not found" << endl;
        } else {
            while (input != "done") {
                cout << "input hex #RRGGBB (type 'done' once all colors are inputed): ";
                getline(cin, input);
                if (isValidHex(input)) {
                    palette.push_back(input);
                } 
            }
            //cout << palette.size() << endl;
            for (int i = 0; i<(int)palette.size(); i++) {
                writer << "Hex: " << palette[i] << " | RGB: " << writeRGB(hexToRGB(palette[i])) << " | lum: " << luminosity(palette[i]);
                if (i<((int)palette.size()-1)) { //solve for the extra blank line
                    writer << endl;
                }
            }
        }
        writer.close();

        if (palette.size()>1) {
        
            if ( palette.size()>2) {
                cout << "comparing..." << endl;
                for (int i = 0; i<(int)palette.size(); i++) {
                cout << palette[i] << endl;
                }
                //find losers
                lumlosers(palette);
            } else {
                cout << "comparing " << palette[0] << " and " << palette[1] << endl;
                cout << "luminosity difference: " << luminosityCompare(palette[0], palette[1]) << endl;
            }
            cout << "differences lower than 2-3% are generally considered undetectable.";
        } else {
            cout << "I cant to much with that..." << endl;
            // eventually make it so add and take out blahblah
        }
    
        play = false;
          
    }     
}
