class TimeMap {
   public:
    unordered_map<string, pair<vector<string>, vector<int>>> mp;
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        mp[key].first.push_back(value);
        mp[key].second.push_back(timestamp);
    }

    string get(string key, int timestamp) {
        if (!mp.count(key)) return "";
        int left = 0, right = mp[key].first.size() - 1;
        int ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mp[key].second[mid] <= timestamp) {
                ans = mid;
                left = mid + 1;
            }

            else
                right = mid - 1;
        }
        return ans == -1 ? "" : mp[key].first[ans];
    }
};
