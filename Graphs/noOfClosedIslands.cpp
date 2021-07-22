class Solution {
public:
    void traverse(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 1) return;
        
        grid[i][j] = 1;
        traverse(grid, i-1, j);
        traverse(grid, i+1, j);
        traverse(grid, i, j-1);
        traverse(grid, i, j+1);
    }
    
    
    int closedIsland(vector<vector<int>>& grid) {
        int count = 0;
        int firstColumn = 0;
        int lastColumn = grid[0].size()-1;
        int firstRow = 0;
        int lastRow = grid.size()-1;
        
	  //here the idea is that if to fill the islands which touch the boundaries with water, so that only the islands that are surrounded with water would be considered
	  
	  //Check if there are any islands on the first and last column
        for(int i = 0; i < grid.size(); i++){
            if(grid[i][firstColumn] == 0){
                traverse(grid, i, firstColumn);
            }
            
            if(grid[i][lastColumn] == 0){
                traverse(grid, i, lastColumn);
            }
        }
        
	  //Check if there are any islands on the first and last row
        for(int i = 0; i < grid[0].size(); i++){
            if(grid[firstRow][i] == 0){
                traverse(grid, firstRow, i);
            }
            
            if(grid[lastRow][i] == 0){
                traverse(grid, lastRow, i);
            }
        }
        
        
		//Once all the islands that touch the boundary are filled with water. Next we will check for islands that are within the boundary
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0){
                    count++;
                    traverse(grid, i, j);
                }
            }
        }
        return count;
    }
};
