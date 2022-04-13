https://practice.geeksforgeeks.org/problems/min-coin5549/1#

int MinCoin(vector<int>nums, int amount)
	{
	    vector<int> table(amount + 1, INT_MAX);
	    table[0] = 0;
	    sort(nums.begin(), nums.end());
	    for(int i = 1; i <= amount; ++i) {
	        for(int j = nums.size() - 1; j >= 0; --j) {
	            if(nums[j] <= i) {
	                int s = table[i - nums[j]];
	                if(s != INT_MAX && s + 1 < table[i]) {
	                    table[i] = s + 1;
	                }
	            }
	        }
	    }
	    if(table[amount] == INT_MAX)
	      return -1;
	    return table[amount];
	 }
