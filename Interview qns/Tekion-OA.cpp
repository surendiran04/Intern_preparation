// 1.Given 2 arrays of size n bandwidth[] and request[] . Also given a int totalBandiwidth which denotes the maximum bandwidth that can be installed and our soln need
// maximize the request  - 75points
 bandwidth = {100,200,300};
 request   = {5,5,5};
 totalBandwidth = 1000;
ans= 15
#include <bits/stdc++.h>
using namespace std;

int maxRequests(vector<int>& bandwidth, vector<int>& request, int totalBandwidth) {  //Classic knapsack dp problem
    int n = bandwidth.size();
    vector<int> dp(totalBandwidth + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int cap = totalBandwidth; cap >= bandwidth[i]; cap--) {
            dp[cap] = max(dp[cap], request[i] + dp[cap - bandwidth[i]]);
        }
    }
    return dp[totalBandwidth];
}

int main() {
    vector<int> bandwidth = {100, 500, 80, 25, 400};
    vector<int> request   = {100, 100, 120, 110, 100};
    int totalBandwidth = 200; //ans = 230 (110+120)

    cout << "Max Requests = " << maxRequests(bandwidth, request, totalBandwidth) << endl;
    return 0;
}

// 2.Divide Players Into Teams of Equal Skill  - 50 points
//Given a skillset array where we need form n/2 teams and each team must have sum of same skill and return product of the skills of the players on that team.
//if not able to make a team return -1
// Input: skill = [1,1,2,3]
// Output: -1
// Input: skill = [3,4]
// Output: 12
// Input: skill = [3,2,5,1,3,4]
// Output: 22

Link: https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/description/
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        unordered_map<long,vector<pair<int,int>>> map;
        int n=skill.size();
        long p;
        for(int i=0;i<n/2;i++){
             p=skill[i]+skill[n-1-i];
            map[p].push_back({skill[i],skill[n-1-i]});
        }
        if(map.size()!=1){
            return -1;
        }
        long long product=0;
        for(auto x:map[p]){
            product+=x.first*x.second;
        }
        return product;
    }
};


MCQ
1. Circular Queue (using array) conditions
Let queue size = n, front = f, rear = r.
Empty condition:
front == -1 && rear == -1
(or simply front == rear == -1)
Full condition:
(rear + 1) % n == front
This ensures that one slot is reserved to differentiate between full & empty.

2. Prefix Expression Evaluation

Given:
* + 2 - 2 1 / - 4 2 + - 5 3 1
Step-by-step:
Write expression clearly:

* ( + 2 ( - 2 1 ) ) ( / ( - 4 2 ) ( + ( - 5 3 ) 1 ) )

Simplify inside:
- 2 1 = 1
+ 2 1 = 3
- 4 2 = 2
- 5 3 = 2
+ 2 1 = 3
/ 2 3 = 0 (integer division)
Final = * 3 0 = 0
✅ Answer = 0

3. Grant and Revoke in DBMS

GRANT → gives permissions (DCL command).
REVOKE → removes permissions (DCL command).
👉 Yes, they are DCL (Data Control Language).

About commits:
DDL (CREATE, DROP, ALTER) → auto-commit after execution.
DML (INSERT, UPDATE, DELETE) → not auto-commit, unless autocommit mode ON.
DCL (GRANT, REVOKE) → also auto-commit in many DBs.

4. let in JavaScript

Scope: Block scoped {} (not global).
Redeclare: ❌ Cannot redeclare in the same scope.
Reassign: ✅ Allowed.
Without declaration: If you just write x=10 without let/var/const, it becomes global (strict mode will throw error).

Example:
let a = 10;
a = 20;   // ✅ allowed
let a = 30; // ❌ error (in same scope)

5. User-level threads vs Kernel-level threads
Aspect	       User-level                 	Kernel-level
Managed by   	User thread library          	OS kernel
Speed	       Faster (no syscall)            Slower (syscall needed)
Blocking	   If one blocks → all block	     One blocks → others can run
Portability   	More portable               	Less portable
Scheduling	     By user library	                 By OS

6. Math: x² - y² = 101 → find x² + y²

We know:
x² - y² = 101
(x² + y²) = ?
But without another relation (like value of xy or x,y themselves), x² + y² cannot be determined uniquely.
Example:
If x=51, y=50, then x² - y²=101, x² + y²=5101. // this was in tha option

If x=101, y=0, then x² + y²=10201.
👉 So, not uniquely solvable unless extra condition given.

7. Fork() process creation
Loop:
for (i=0; i<=10; i++) {
   if (i % 5 == 0)
       fork();
}
Values of i where fork happens = 0,5,10 → total 3 times.
Each fork() doubles processes.

So:
After 1st fork → 2 processes
After 2nd fork → 4 processes
After 3rd fork → 8 processes
✅ Final = 8 processes (7 children + 1 parent).


8. Props in ReactJS
Parent → Child props (with name and children):

// Child.js
export default function Child({ name, children }) {
  return (
    <div>
      <h2>Hello {name}</h2>
      <div>{children}</div>
    </div>
  );
}

// Parent.js
import Child from "./Child";

export default function Parent() {
  return (
    <Child name="Surendiran">
      <p>This is inside children</p>
    </Child>
  );
}
✅ Output:
Hello Surendiran
This is inside children

9. Abstract Class vs Interface
Feature      	Abstract Class	                                           Interface
Methods	      Can have abstract + concrete	             Only abstract (till Java 7), default/static allowed (Java 8+)
Variables      	Can have instance vars	                     Only static final constants
Inheritance   	Single (only 1 abstract class)           	Multiple interfaces can be implemented
Constructor	        Yes	                                                         No
Use case	     “Is-a” relationship, partial implementation	      Pure contract / capability

👉 Limitation:
Abstract class: cannot achieve multiple inheritance.

Interface: cannot hold state (no normal variables).
