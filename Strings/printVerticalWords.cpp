class Solution {
public:
    vector<string>splitWords,res;
    
    void split(string s, char delim){
        stringstream ss(s);
        string item;
        while(getline(ss,item,delim))
            splitWords.push_back(item);
    }
    void stripRight(string &s){
            int rightIdx = s.length()-1;
            while(s[rightIdx] == ' ') rightIdx--;
            s = s.substr(0, rightIdx + 1);
            
    }
    vector<string> printVertically(string s) {
        split(s, ' ');
        // for(auto x : splitWords) cout<<x<<" ";
        int maxLength = 0;
        for(int i = 0; i < splitWords.size(); ++i){
            maxLength = max(maxLength, (int)splitWords[i].length());
        }
        
        for(int i = 0; i < maxLength; ++i){
            string temp = "";
            cout<<i<<"\n";
            for(auto x : splitWords){
                if(i < x.length()){
                    temp+=x[i];
                }else{
                    temp+=' ';
                }
            }
            stripRight(temp);
            res.push_back(temp);
        }
        return res;
    }
};

/*

standard split and strip and then print all indices
O(n*max(all_lengths));
*/

/*A 100% solution that works brute same way 
 *
 */
class Solution {
public:
    int max(int a,int b)
    {
        if(a>b)return a;
        return b;
    }
    vector<string> printVertically(string s)
    {
        unordered_map<int,string>mp;
        int count=0;
        int maxi=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            {
                count=0;
            }
            else
            {
                count++;
            }
            maxi=max(maxi,count);
        }
        count=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            {
                while(count<maxi)
                {
                   mp[count].push_back(s[i]);
                   count++;
                }
                count=0;
            }
            else
            {
                mp[count++].push_back(s[i]);
            }
        }
        vector<string>ans;
        for(auto x:mp)
        {
            int j=x.second.length()-1;
            while(j>=0)
            {
                if(x.second[j]!=' ')break;
                j--;
                x.second.pop_back();
            }
            
            ans.push_back(x.second);
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};
