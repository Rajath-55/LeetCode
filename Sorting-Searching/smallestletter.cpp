class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(target >= letters[letters.size()-1]) return letters[0];
        for(auto x : letters){
            if(target < x) return x;
        }
        return ' ';
        
        
        
    }
};

//stl solution:
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int idx = upper_bound(letters.begin(), letters.end(), target) - letters.begin();
        if(idx > letters.size() - 1) return letters[0];
        return letters[idx];
        
        
        
    }
};