class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> mp;
public:
    TimeMap() {
        mp.clear();
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) return "";
        if (timestamp < mp[key][0].first) return "";

        int l = 0, r = mp[key].size() - 1;

        int ind = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (mp[key][m].first <= timestamp) {
                ind = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return mp[key][ind].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */