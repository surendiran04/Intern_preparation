class MyCalendar {
public:
vector<pair<int,int>>range;
    MyCalendar() {}
    bool book(int start, int end) {
        for(auto p:range){
            if(start< p.second && end>p.first){
                return false;
            }
        }
        range.push_back(make_pair(start,end));
        return true;
    }
};
class MyCalendar { //another approach
    map<int, int> intervals; // Stores intervals with start as key and end as value
public:
    MyCalendar() {}

    bool book(int start, int end) {  //O(logn)
        auto next = intervals.lower_bound(start); // Find next interval
        if (next != intervals.end() && next->first < end) {
            return false; // Overlaps with next interval
        }
        if (next != intervals.begin() && prev(next)->second > start) {
            return false; // Overlaps with previous interval
        }
        intervals[start] = end; // No overlap, add interval
        return true;
    }
};
