//Given distance in x,y coordinates we have to find the optimal centre and then the min cost to reach the farm
// cost+=dist[i]*pre[i]
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include<bits/stdc++.h>
using namespace std;

int calculate_min_cost(const vector<int>& x, const vector<int>& y, const vector<int>& premium) {
    int min_cost = numeric_limits<int>::max();  // Initialize min_cost to a very high value
    int optimal_cx = -1;
    int optimal_cy = -1;

    // Loop through possible cx and cy values based on the given coordinates
    for (int cx = *min_element(x.begin(), x.end()); cx <= *max_element(x.begin(), x.end()); ++cx) {
        for (int cy = *min_element(y.begin(), y.end()); cy <= *max_element(y.begin(), y.end()); ++cy) {
            int total_cost = 0;
            for (size_t i = 0; i < x.size(); ++i) {
                total_cost += premium[i] * (abs(x[i] - cx) + abs(y[i] - cy));
            }
            if (total_cost < min_cost) {
                min_cost = total_cost;
                optimal_cx = cx;
                optimal_cy = cy;
            }
        }
    }
    
    cout << "Optimal Control Center: (" << optimal_cx << ", " << optimal_cy << ")";
    return min_cost;
}

int main() {
    vector<int> x = {1,2};
    vector<int> y = {1,2};
    vector<int> premium = {1, 10};

    auto result = calculate_min_cost(x, y, premium);
    cout << " Min Cost: " << result << endl; //2
    return 0;
}
//x=[5,2,3],y=[3,4,7],premium=[1,1,1] op:7
//x=[2,3,5],y=[1,1,1],premium=[1,1,1] op:3
//x=[1,3,2,4],y=[1,3,2,4],premium=[1,3,2,4] op:17
