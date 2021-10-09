#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        using Event = pair<pair<int,int>,bool>; // x, y, e/l
        auto E = [&](const Event& e){ return e.second; };
        auto X = [&](const Event& e){ return e.first.first; };
        auto Y = [&](const Event& e){ return e.first.second; };
        auto is_enter = [&](const Event& e){ return e.second; };
        // less: smaller x
        // if same x, enter event earlier than leave event
        // if same x and event, bigger y if enter, smaller y if leave
        auto comp = [&](const Event& ea, const Event& eb){
            return X(ea) != X(eb) ? X(ea) < X(eb) : \
                E(ea) != E(eb) ? E(ea) > E(eb) : \
                is_enter(ea) ? Y(ea) > Y(eb) : Y(ea) < Y(eb);
        };
        vector<vector<int>> ret;
        vector<Event> events;
        for (const auto& b : buildings) {
            events.push_back({{b[0], b[2]}, true});
            events.push_back({{b[1], b[2]}, false});
        }
        sort(events.begin(), events.end(), comp);
        map<int,int> heights; // height, count
        heights[0] = 1; // ground
        for (const auto& e : events) {
            if (is_enter(e)) {
                // check if occluded by other buildings, record if not
                int mh = heights.rbegin()->first;
                if (Y(e) > mh) ret.push_back({X(e), Y(e)});
                // add h to height list
                ++heights[Y(e)];
            } else {
                // remove h from height list
                auto iter = heights.find(Y(e));
                if (--(iter->second) == 0) heights.erase(iter);
                // check if occluded by other buildings, record if not
                int mh = heights.rbegin()->first;
                if (Y(e) > mh) ret.push_back({X(e), mh});
            }
        }
        return ret;
    }
};
int main()
{
    // https://leetcode.com/problems/the-skyline-problem/
    return 0;
}