
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm> // Make sure to include this for std::min

using namespace std;

int binaryToDecimal(const string& binary) {
    return stoi(binary, 0, 2);
}

double colorDistance(int r1, int g1, int b1, int r2, int g2, int b2) {
    return sqrt(pow(r1 - r2, 2) + pow(g1 - g2, 2) + pow(b1 - b2, 2));
}

string closestColor(int r, int g, int b) {
    struct Color {
        int r, g, b;
        string name;
    };

    const vector<Color> colors = {
        {0, 0, 0, "Black"},
        {255, 255, 255, "White"},
        {255, 0, 0, "Red"},
        {0, 255, 0, "Green"},
        {0, 0, 255, "Blue"}
    };

    double minDistance = numeric_limits<double>::max();
    string closestName = "";

    for (const auto& color : colors) {
        double dist = colorDistance(r, g, b, color.r, color.g, color.b);
        if (dist < minDistance) {
            minDistance = dist;
            closestName = color.name;
        }
    }

    return closestName; // Directly return the closest color (no ambiguity check needed)
}

int main() {
    int n;
    cin >> n;

    vector<string> pixels(n);
    for (int i = 0; i < n; ++i) {
        cin >> pixels[i];
    }

    for (const string& pixel : pixels) {
        int r = binaryToDecimal(pixel.substr(0, 8));
        int g = binaryToDecimal(pixel.substr(8, 8));
        int b = binaryToDecimal(pixel.substr(16, 8));
        cout << closestColor(r, g, b) << endl;
    }

    return 0;
}
