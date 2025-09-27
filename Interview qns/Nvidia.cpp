// One my frnd attended and gave the qns pics and ans: https://gemini.google.com/share/8be34a026206
// the same qn has been asked by nvidia across different colleges for the past 3 years
MCQ were asked in 2 sections like aptitude and CS fundamentals and debugging.
1.unsigned int wrapping concept
2.pointer working like changing the String Literals: The line char *buff = "NVIDIA"(read-onl)  next line, buff[0] = 'n'; //ans segmentation fault.
3.constructor overloading int ,float
4.size of the chracter array in c will always size+1 since '\0' will be added in c
5.process turaround time in OS
6.static variable will be assigned 0 if  a value is not assigned explicitly
7.Character array replace is not valid in c only pointer replace is allowed
// This is different from the code in the question
char *ptr1 = "Hello";
char *ptr2 = "World";
// This is VALID because ptr1 is a variable that can hold a new address
ptr1 = ptr2; 
printf("%s %s", ptr1, ptr2); // This would print "World World"

coding qns were asked: one can be implemented only in c and other one in c/c++
  The exact qn was asked ,qn link: https://leetcode.com/problems/special-binary-string/description/
  then pattern matching in c : check if a given binary string is a powers of 2. regex pattern=^O*1O*$
  
#include <stdio.h>
#include <regex.h>  //In C
int main() {
    const char *pattern = "^0*10*$";
    const char *tests[] = {"0101010", "00100", "1000", "0001", "00010", "101"};
    int n = sizeof(tests) / sizeof(tests[0]);

    regex_t regex;
    regcomp(&regex, pattern, REG_EXTENDED);

    for (int i = 0; i < n; i++) {
        int ret = regexec(&regex, tests[i], 0, NULL, 0);
        printf("%s -> %s\n", tests[i], (ret == 0) ? "True" : "False");
    }

    regfree(&regex);
    return 0;
}

#include <bits/stdc++.h>
using namespace std; //In C++

int main() {
    regex re("^0*10*$");
    vector<string> tests = {"0101010", "00100", "1000", "0001", "00010", "101"};

    for (auto &t : tests) {
        cout << t << " -> " << (regex_match(t, re) ? "True" : "False") << endl;
    }
    return 0;
}
 



