class MyCalendar {
    set<pair<int, int>> st;
public:
    MyCalendar() {
        st.clear();
    }
    
    bool book(int start, int end) {
        auto p = st.lower_bound({start, end});
        if (p != st.end()) {
            if (p->first < end) return false;
        }

        if (p != st.begin()) {
            auto pp = prev(p);
            if (pp->second > start) return false;
        }

        st.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */