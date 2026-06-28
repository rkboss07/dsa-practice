class Solution {
public:
    int compress(vector<char>& chars) {

        int count = 1;
        int write = 0;

        for (int i = 1; i <= chars.size(); i++) {
            if (i < chars.size() && chars[i] == chars[i - 1]) {
                count++;
            } else {
                chars[write] = chars[i - 1];
                write++;

                if (count > 1){
                    string cnt = to_string(count);
                    for (int j = 0; j < cnt.size(); j++) {
                        chars[write] = cnt[j];
                        write++;
                    }
                }
                    count = 1;
            }
        }
        return write;
    }
};