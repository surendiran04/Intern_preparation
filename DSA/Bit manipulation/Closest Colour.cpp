// Given a RGB pixel color as 24bit string find the nearest color to it ,if there are colors with the minimum distance then it is Ambiguous
// Distance formula d=sqrt(pow(r1-r2,2)+pow(g1-g2,2)+pow(b1-b2,2))
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Structure to store RGB values
struct Color {
    string name;
    int r, g, b;
};

// Predefined pure colors
vector<Color> pureColors = {
    {"Black", 0, 0, 0},
    {"White", 255, 255, 255},
    {"Red", 255, 0, 0},
    {"Green", 0, 255, 0},
    {"Blue", 0, 0, 255}
};

// Function to calculate Euclidean distance
double calculateDistance(int r1, int g1, int b1, int r2, int g2, int b2) {
    return sqrt(pow(r1 - r2, 2) + pow(g1 - g2, 2) + pow(b1 - b2, 2));
}

// Function to convert a 24-bit binary string to an integer
int binaryToDecimal(string binary) {
    return stoi(binary, nullptr, 2);
}

// Function to find the closest pure color
string findClosestColor(int r, int g, int b) {
    double minDistance = numeric_limits<double>::max();
    string closestColor;
    int count = 0;

    for (const auto& color : pureColors) {  //Checking  for all colors
        double distance = calculateDistance(r, g, b, color.r, color.g, color.b);
        if (distance < minDistance) {
            minDistance = distance;
            closestColor = color.name;
            count = 1;
        } else if (distance == minDistance) {  //if there 2 colors of same min distance then it is ambiguous
            count++;
        }
    }

    return (count > 1) ? "Ambiguous" : closestColor;
}

int main() {
    string binaryString;
    cout << "Enter a 24-bit binary string: ";
    cin >> binaryString;

    if (binaryString.length() != 24) {
        cout << "Invalid input! The binary string must be 24 bits long.\n";
        return 1;
    }

    // Extract RGB components
    int r = binaryToDecimal(binaryString.substr(0, 8));
    int g = binaryToDecimal(binaryString.substr(8, 8));
    int b = binaryToDecimal(binaryString.substr(16, 8));

    // Find and print the closest pure color
    string closestColor = findClosestColor(r, g, b);
    cout << "Closest color: " << closestColor << endl;

    return 0;
}
