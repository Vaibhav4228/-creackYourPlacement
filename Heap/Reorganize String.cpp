Reorganize String
class Info {
public:
    char ch;
    int count;
    
    Info(char ch, int count) : ch(ch), count(count) {}
};

class Compare {
public:
    bool operator() (Info* first, Info* second) {
        return first->count < second->count;
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        priority_queue<Info*, vector<Info*>, Compare> maxHeap;
        for (int i = 'a'; i <= 'z'; i++) {
            if (freq[i] > 0) {
                Info* tempNode = new Info(i, freq[i]);
                maxHeap.push(tempNode);
            }
        }

        string ans = "";
        while (maxHeap.size() >= 2) {
            Info* first = maxHeap.top();
            maxHeap.pop();
            Info* second = maxHeap.top();
            maxHeap.pop();

            ans.push_back(first->ch);
            first->count--;
            ans.push_back(second->ch);
            second->count--;

            if (first->count > 0) maxHeap.push(first);
            if (second->count > 0) maxHeap.push(second);
        }

        if (!maxHeap.empty()) {
            Info* last = maxHeap.top();
            maxHeap.pop();

            ans.push_back(last->ch);
            last->count--;

            if (last->count > 0) {
                return "";
            }
        }

        return ans;
    }
};