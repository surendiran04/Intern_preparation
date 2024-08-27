#include <iostream>
#include <string>
using namespace std;
int minimizeDefectRate(std::string str) {
    int defectRate = 0;
    
    // First pass to replace 'x' with optimal values
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == 'x') {
            if (i > 0 && str[i - 1] != 'x') {
                // Replace 'x' to match the previous character to avoid a defect
                str[i] = str[i - 1];
            } else if (i < str.size() - 1 && str[i + 1] != 'x') {
                // Replace 'x' to match the next character if previous was 'x' or doesn't exist
                str[i] = str[i + 1];
            } else {
                // Arbitrary choice, if both neighbors are 'x' or we're at the start
                str[i] = '0';  // Default to '0'
            }
        }
    }

    // Second pass to count defects
    for (int i = 1; i < str.size(); ++i) {
        if (str[i] != str[i - 1]) {
            defectRate++;
        }
    }

    return defectRate;
}

int main() {
    std::string str = "0100x011x10xx";
    int result = minimizeDefectRate(str);
    std::cout << "Output: " << result << std::endl;
    return 0;
}
