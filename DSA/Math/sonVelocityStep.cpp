#include <iostream>
#include <vector>
using namespace std;

vector<int> commonFootSteps(int fatherPos, int martinPos, int velFather, int steps) {
    vector<int> answer(2, 0);
    vector<int> temp(steps + 1);

    // Precompute father's positions relative to martin
    for (int i = 0; i <= steps; i++){
        temp[i] = fatherPos + velFather * i - martinPos;
    }

    // Find best velocity for Martin
    for (int i = 0; i <= steps; i++) {
        if (temp[i] <= 0)
            continue;

        int v2 = temp[i];
        int count = 0;

        for (int j = i; j <= steps; j++) {
            if (temp[j] % v2 == 0)
                count++;
        }

        if (answer[0] <= count) {
            answer[0] = count;
            answer[1] = v2;
        }
    }

    return answer;
}

int main() {
    vector<int> result = commonFootSteps(13, 5, 9, 4); //steps:1,velocity:14
    
    for (int i : result)
        cout << i << " ";
    cout << endl;
    result = commonFootSteps(3, 2, 2, 20); //steps:21,velocity:1
    
    for (int i : result)
        cout << i << " ";
    cout << endl;
    return 0;
}
