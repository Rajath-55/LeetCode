class Solution {
public:
  
  int maxProduct(vector<int>& nums) {
    int negative_prod{ 1 };
    int positive_prod{ 1 };
    int max_prod_so_far{ std::numeric_limits<int>::min() };
    
    for (const auto& num : nums) {
      int prod1 = positive_prod * num;
      int prod2 = negative_prod * num;
      
      positive_prod = std::max(num, std::max(prod1, prod2));
      negative_prod = std::min(num, std::min(prod1, prod2));
      
      max_prod_so_far = std::max(max_prod_so_far, positive_prod);
    }
    
    return max_prod_so_far;
  }
};
