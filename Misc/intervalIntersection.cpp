class Solution {
public:
	vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {

		vector<vector<int>>res;

		int l=0;
		int r=0;

		while(l<firstList.size() && r<secondList.size()){
			if(firstList[l][0]<=secondList[r][0]){
				if(firstList[l][1]>=secondList[r][0] && firstList[l][1]<=secondList[r][1]){
					res.push_back({secondList[r][0],firstList[l][1]});
					l++;
				}else if(firstList[l][1]>=secondList[r][0] && firstList[l][1]>secondList[r][1]){
					res.push_back({secondList[r][0],secondList[r][1]});
					r++;
				}else{
					l++;
				}
			}else{
				if(secondList[r][1]>=firstList[l][0] && secondList[r][1]<=firstList[l][1]){
					res.push_back({firstList[l][0],secondList[r][1]});
					r++;
				}else if(secondList[r][1]>=firstList[l][0] && secondList[r][1]>firstList[l][1]){
					res.push_back({firstList[l][0],firstList[l][1]});
					l++;
				}else{
					r++;
				}
			}

		}
		return res;
	}
};

