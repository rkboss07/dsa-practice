class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, freq[26] = {0}, maxfreq = 0, result = 0;
        
        for (int right=0; right < s.size(); right++){
            freq[s[right]-'A']++;

            maxfreq = max(maxfreq, freq[s[right]-'A']);

            int window_size = right- left + 1;

            if (window_size - maxfreq > k){
                freq[s[left]-'A']--;
                left++;
            }
            result = max(result, right-left+1);
        }
        return result;

    }
};