#include <iostream>
#include <string>
#include <map>


using namespace std;

bool isFloat(string str)  {
    int count{ 0 };
    for (char c : str) {
        if(c == '.') {
            count++;
            continue;
        }
        if(!isdigit(c)) {
            return false;
        }
    }
    return count < 2;
}


float exchange(string input, string output, float currency, map<string, float>Exchanges)
{
    return (Exchanges.find(input)->second * currency) / Exchanges.find(output)->second;
}

int main() 
{

    map<string, float>Exchanges;

    Exchanges["USD"] = 1;
    Exchanges["EUR"] = 0.98;
    Exchanges["JPY"] = 0.0069;
    Exchanges["GBP"] = 1.11;
    Exchanges["AUD"] = 0.64;
    Exchanges["CAD"] = 0.72;
    Exchanges["WON"] = 0.00069;

    string inputcur{ };
    string outputcur{ };
    string cur{ };
    while (true) {
        cout << "What currency are you trying to exchange from (Type \"list\" for list of currencies): ";
        cin >> inputcur;
        for (auto & c: inputcur) c = toupper(c);
        if (Exchanges.find(inputcur) == Exchanges.end()) {
            cout << "Please put a valid currency.\n";
            continue;
        }
        break;
    }
    while (true) {
        cout << "What currency are you trying to exchange to (Type \"list\" for list of currencies): ";
        cin >> outputcur;
        for (auto & c: outputcur) c = toupper(c);
        if (Exchanges.find(outputcur) == Exchanges.end()) {
            cout << "Please put a valid currency.\n";
            continue;
        }
        break;
    }
    while (true) {
        cout << "How much of the currency you are exchanging from do you have: ";
        cin >> cur;
        if (!isFloat(cur)) {
            cout << "Please put a valid value.\n";           
            continue; 
        }
        break;
    }




    cout << exchange(inputcur, outputcur, stof(cur), Exchanges) << " " << outputcur;
    return 0;
} 