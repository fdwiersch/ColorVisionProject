#include <iostream>
#include <cctype>
#include <limits>
#include <vector>
#include <string>

using namespace std;

const int HEXADECIMAL = 16;

bool isValidHex(string);
vector<string> hexToRGB(string);
void formatRGB(string&);
float luminosityCompare (string, string);
void lumlosers(vector<string>);
string writeRGB(vector<string>);
float luminosity(string);

bool isValidHex(string hex) { //valid if... 1.) starts with # 2.) 7 chrs long 3.) last 6 are valid hex values
    if (hex == "done") { //getting rid of the need to pop_back() the palette if done isnt allowed to join to start
        return false;
    }
    if (hex.size() != 7 || hex.at(0) != '#') { //reason for order: you check its size 7 before looking to see if the first charcter is '#' is because if your size was 0 nothing exists at location 0 --> error
        cout << hex.size() << hex.at(0) << endl;
        cout << "your input " << hex << " does not meet hex format requirements #RRGGBB" << endl;
        return false; 
    } //stopping here would say smth like #ZYXW10 isValidHex --> True ... so we need to check each charcater individulaly using isxdigit before we can determie its truely a valid hexdec value
    for (int i=1; i < int(hex.size()); i++) { //start at int i=1 to skip '#'
        if ( !isxdigit(hex.at(i))) { //isxdigit coming from the cctype library and is a fucntion that deals investigating a charcter if its a vslid hex color note: accepts upper and lower 0-9 A-F
            cout << "your input " << hex << " does not meet hex character limits 0-9 and A-F " << endl;
            return false;
        }
    }
    return true;
}
 
vector<string> hexToRGB(string hex) { //convert Hex string into a RGB vector of integers

    vector<string> RGBv;
    
    //convert Hex string into RGB int
    string rHex = hex.substr(1, 2);
    string rRGB = to_string(stoi(rHex, nullptr, HEXADECIMAL));

    string gHex = hex.substr(3, 2);
    string gRGB = to_string(stoi(gHex, nullptr, HEXADECIMAL));

    string bHex = hex.substr(5, 2);
    string bRGB = to_string(stoi(bHex, nullptr, HEXADECIMAL));

    //format RGBs
    formatRGB(rRGB); formatRGB(gRGB); formatRGB(bRGB);

    //push foratted RGB values into RGB vector
    RGBv.push_back(rRGB); RGBv.push_back(gRGB); RGBv.push_back(bRGB);

    //cout << RGBv[0] << ", " << RGBv[1] << ", " << RGBv[2] << endl;

    return RGBv;
}

void formatRGB(string & rgb) { //formats the RGB int to be a string formatted with three spaces (ex: 1 --> 001) for display purposes
    
    int size = (int)rgb.size();
    for (int i = size; i<3; i++) {
        rgb = "0" + rgb;
    }
}

string writeRGB(vector<string> rgb) {
    string rgbw;
    int count = 0;
    for (string i : rgb) {
        rgbw = rgbw + i;
        if (count<2) {
            rgbw = rgbw + ", ";
        }
        count++;
    }

    return ("("+rgbw+")");
}

float luminosity(string hex) { //calculate luminosity based on human eye preferences
    //Gray = 0.299 R + 0.587 G + 0.114 B //based on general human eye perseption biases (green bias)
    float lum = (0.299*stoi(hexToRGB(hex)[0]) + 0.587*stoi(hexToRGB(hex)[1]) + 0.114*stoi(hexToRGB(hex)[2]));
    return lum;
}

float luminosityCompare(string hex1, string hex2) { //compares two Hexes luminosity return difference
    
    float lumDif = 0;

    float lum1 = luminosity(hex1);
    float lum2 = luminosity(hex2);

    lumDif = abs(lum1-lum2);
    
    return lumDif;
}

void lumlosers(vector<string> palette) { //idea: sort by lum and then you could see sugenstions on shifting values
    string colora;
    string colorb;
    float lowestlumdif = 1000;
    float lumdif;
    vector<string> losers;
    for (int a = 0; a<((int)palette.size()-1); a++) {
        colora = palette[a];
        for (int b = a+1; b<(int)palette.size(); b++) {
            colorb = palette[b];
            //compare luminosity
            lumdif = luminosityCompare(colora, colorb);
            if (lumdif<lowestlumdif) {
                lowestlumdif = lumdif;
                losers[0]=colora;
                losers[1]=colorb;
            }
        }
    }
    //2-3% luminance diference is generally the smallest detectable difference
    cout << "The Hex values of " << losers[0] << " and " << losers[1] << " have the closest luminosity with a difference of " << lowestlumdif << endl;
}

//sortlum
