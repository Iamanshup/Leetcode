class Compare {
public:
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        return p1.first * p1.first + p1.second * p1.second < p2.first * p2.first + p2.second * p2.second;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

        for (auto v : points) {
            pq.push({v[0], v[1]});
            while (pq.size() > k) pq.pop();
        }
        vector<vector<int>> ans;

        while (!pq.empty()) {
            ans.push_back({pq.top().first, pq.top().second});
            pq.pop();
        }
        return ans;
    }
};