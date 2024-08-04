Count the number of "stars" (digits in the guess that are in the correct position).
Count the number of "moons" (digits in the guess that are in the secret number but in the wrong position).

  //if the number at the same index are same then it is counted as a star and it is diff number from star element then it is a moon
 SampleInput:
   Input:
            1807
            7810
   Output:
            1A3B

  Input:
            1123
            0111
   Output:
            1A1B
  
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string getHint(string secret, string guess) {
    int n = secret.length();
    int stars = 0;
    int moons = 0;
    vector<int> secretFreq(n, 0);
    vector<int> guessFreq(n, 0);

    // First pass: count stars and build frequency tables for non-star digits
    for (int i = 0; i < secret.size(); ++i) {
        if (secret[i] == guess[i]) {
            stars++;
        } else {
            secretFreq[secret[i] - '0']++;  //counting elements occurence 
            guessFreq[guess[i] - '0']++;
        }
    }

    // Second pass: count moons by comparing frequency tables
    for (int i = 0; i < 10; ++i) {
        moons += min(secretFreq[i], guessFreq[i]);
    }

    return to_string(stars) + "A" + to_string(moons) + "B";
}

int main() {
    string secret, guess;
    cin >> secret >> guess;
    cout << getHint(secret, guess) << endl;
    return 0;
}
