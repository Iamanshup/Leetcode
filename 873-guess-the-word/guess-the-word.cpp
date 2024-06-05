/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
private:
    int getMatch(string w1, string w2) {
        int c = 0;
        for (int i = 0; i < 6; ++i) {
            c += w1[i] == w2[i];
        }
        return c;
    }

public:
    void findSecretWord(vector<string>& words, Master& master) {
        srand(time(0));
        while (words.size() > 0) {
            vector<string> candidates;
            int ind = rand() % words.size();
            string w = words[ind];
            cout << w << " " << ind << " " << words.size() << endl;
            int match = master.guess(w);
            if (match == 6) {
                return;
            }
            for (string word: words) {
                if (match == getMatch(w, word)) {
                    candidates.push_back(word);
                }
            }
            words = candidates;
        }
    }
};