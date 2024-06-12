#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <iomanip>

#include <algorithm>
#include <cmath>

using namespace std;

// Define unit conversion rates and types
//map<string, double> conversionRates = {
//        {"meters",      39.3701},
//        {"centimeters", 0.393700787},
//        {"kilometers",  39370.0787},
//        {"liters",      1.05668821},
//        {"grams",       0.00220462},
//        {"kilograms",   2.20462},
//        {"tonnes",      2204.62},
//        {"inches",      1},
//        {"feet",        12},
//        {"yards",       36},
//        {"miles",       63360},
//        {"quarts",      1},
//        {"gallons",     4},
//        {"pounds",      1},
//        {"tons",        2000}
//};
map<string, double> conversionRates = {
        {"meters",      100},
        {"centimeters", 1},
        {"kilometers",  0.001},
        {"liters",      1000},
        {"grams",       1},
        {"kilograms",   1000},
        {"tonnes",      1000000},
        {"inches",      2.54},
        {"feet",        30.48},
        {"yards",       91.44},
        {"miles",       160934.4},
        {"quarts",      1000},
        {"gallons",     3785.41},
        {"pounds",      453.592},
        {"tons",        907185}
};


map<string, string> unitTypes = {
        {"meters",      "length"},
        {"centimeters", "length"},
        {"kilometers",  "length"},
        {"liters",      "volume"},
        {"grams",       "mass"},
        {"kilograms",   "mass"},
        {"tonnes",      "mass"},
        {"inches",      "length"},
        {"feet",        "length"},
        {"yards",       "length"},
        {"miles",       "length"},
        {"quarts",      "volume"},
        {"gallons",     "volume"},
        {"pounds",      "mass"},
        {"tons",        "mass"}
};

// Function to convert units
// Function to convert units
double convertUnits(string fromUnit, string toUnit, double value) {
    if (unitTypes[fromUnit] != unitTypes[toUnit]) {
        return -1;  // Invalid conversion
    }
    double result = value * conversionRates[fromUnit] / conversionRates[toUnit];
    return result;
}


double parseQuestion(string question) {
    stringstream ss(question);
    string buffer, fromUnit, toUnit;
    double value;

    // Parse question
    while (ss >> buffer) {
        if (buffer == "many") {
            ss >> toUnit;
        } else if (buffer == "are") {
            ss >> buffer;  // Skip "in"
            ss >> value;
            ss >> fromUnit;
            char charToRemove = '?';
            fromUnit.erase(std::remove(fromUnit.begin(), fromUnit.end(), charToRemove), fromUnit.end());
//            ss >> buffer;  // Skip "?"
            break;
        }
    }

    // Convert units
    return convertUnits(fromUnit, toUnit, value);
}

// Main function
int main() {


    string question;
    int T;
    cin >> T;
    cin.ignore();  // Ignore newline after T
    while (T--) {
        getline(cin, question);
        double answer = parseQuestion(question);
//        if (answer == -1) {
//            std::cout << -1 << "\n";
//        } else {
            std::cout << std::fixed << std::setprecision(2) << answer << "\n";
//        }
    }
    return 0;
}
