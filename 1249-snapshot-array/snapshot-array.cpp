class SnapshotArray {
    vector<vector<pair<int, int>>> v;
    int snapId;
    int n;
public:
    SnapshotArray(int length) {
        v.clear();
        v.resize(length);
        snapId = 0;
        n = length;

        for (int i = 0; i < n; ++i) {
            v[i].push_back({0, 0});
        }
    }
    
    void set(int index, int val) {
        v[index].push_back({snapId, val});
    }
    
    int snap() {
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        auto it = upper_bound(v[index].begin(), v[index].end(), make_pair(snap_id, INT_MAX));
        // auto it = upper_bound(v[index].begin(), v[index].end(), make_pair(snap_id, INT_MAX));
        return prev(it)->second;

        // int l = 0, r = v[index].size() - 1;
        // int ind = 0;
        // while (l <= r) {
        //     int m = l + (r - l) / 2;
        //     if (v[index][m].first == snap_id) {
        //         ind = m;
        //         l = m + 1;
        //     } else if (v[index][m].first < snap_id) l = m + 1;
        //     else r = m - 1;
        // }
        // return v[index][ind].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */