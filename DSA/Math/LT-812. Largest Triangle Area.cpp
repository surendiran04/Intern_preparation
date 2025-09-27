class Solution {
private:
    double calcArea(vector<int>& x,vector<int>& y,vector<int>& z){ 
        //Gauss's area formula and surveyor's formula
        return (double)0.5*abs(x[0]*(y[1]-z[1])+y[0]*(z[1]-x[1])+z[0]*(x[1]-y[1]));
    }
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n=points.size();
        double maxarea=0.0;
        for (int i = 0; i < n; ++i)
            for (int j = i+1; j < n; ++j)
                for (int k = j+1; k < n; ++k)
                        maxarea=max(maxarea,calcArea(points[i],points[j],points[k]));

        return maxarea;
    }
};
