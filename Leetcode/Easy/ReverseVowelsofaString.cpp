class Solution {
public:
    void reverseString(vector<char>& s) {
        int start = 0;
        int end = s.size() - 1;
        while(start < end) {
            int aux = s[start];
            s[start] = s[end];
            s[end] = aux;

            end--; 
            start++;
        }
    }
};