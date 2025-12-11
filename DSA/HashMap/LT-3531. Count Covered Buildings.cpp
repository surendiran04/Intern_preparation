class Solution {
public:
    unordered_map<int,vector<int>> x_map,y_map;
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) { //Got TLE at 623/634
        sort(begin(buildings),end(buildings));
        for(auto b:buildings){
            x_map[b[0]].push_back(b[1]);
            y_map[b[1]].push_back(b[0]);
        }
        int covered=0;
        for(auto b:buildings){
            cout<<b[0]<<"-"<<b[1]<<" ";
            if(buildingsExistence(b[0],b[1])){
                covered++;
            }
            cout<<endl;
        }
        return covered;

    }
    bool buildingsExistence(int x,int y){ //the building is not the first and last building in that row or col
        int x_axis=lower_bound(y_map[y].begin(),y_map[y].end(),x)-y_map[y].begin();
        int y_axis=lower_bound(x_map[x].begin(),x_map[x].end(),y)-x_map[x].begin();
        cout<<x_axis<<"-"<<y_axis;
        if(x_axis==0 || x_axis>=y_map[y].size()-1 || y_axis==0 || y_axis>=x_map[x].size()-1){
            return false;
        }
        return true;
    }
};

class Solution {
public:
    unordered_map<int,pair<int,int>> x_map,y_map;
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        // sort(begin(buildings),end(buildings));
        for(auto b:buildings){
            if(x_map.find(b[0])==x_map.end()){
                x_map[b[0]]={b[1],b[1]}; //need to 
            }else{
                x_map[b[0]]={min(x_map[b[0]].first,b[1]),max(x_map[b[0]].second,b[1])};
            }
            if(y_map.find(b[1])==y_map.end()){
                y_map[b[1]]={b[0],b[0]};
            }else{
                y_map[b[1]]={min(y_map[b[1]].first,b[0]),max(y_map[b[1]].second,b[0])};
            }
            //storing only the min and max building coordinate 
        }
        int covered=0;
        for(auto b:buildings){
            if(buildingsExistence(b[0],b[1])){
                covered++;
            }
        }
        return covered;

    }
    bool buildingsExistence(int x,int y){
        if(x_map[x].first==y || x_map[x].second==y || y_map[y].first==x || y_map[y].second==x){
            return false;
        }
        return true;
    }
};

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) { //clean soln
        vector<int> maxRow(n + 1);
        vector<int> minRow(n + 1, n + 1);
        vector<int> maxCol(n + 1);
        vector<int> minCol(n + 1, n + 1);

        for (auto& p : buildings) {
            int x = p[0], y = p[1];
            maxRow[y] = max(maxRow[y], x);
            minRow[y] = min(minRow[y], x);
            maxCol[x] = max(maxCol[x], y);
            minCol[x] = min(minCol[x], y);
        }

        int res = 0;
        for (auto& p : buildings) {
            int x = p[0], y = p[1];
            if (x > minRow[y] && x < maxRow[y] && y > minCol[x] &&
                y < maxCol[x]) {
                res++;
            }
        }

        return res;
    }
};
