class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    //   int lastlargest=INT_MIN;
    //   int count=0;
    //   int longest=1;
    //   int n=nums.size();
    //   sort(nums.begin(),nums.end());
    //   if(n==0) return 0;
    //   for(int i=0;i<n;i++)  {
    //       if(nums[i]-1 == lastlargest){
    //         count+=1;
    //         lastlargest=nums[i];
    //       }
    //    else if(nums[i]==lastlargest){
    //     continue;
    //    }
    //    else {
    //     count=1;
    //     lastlargest=nums[i];
    //    }
    //    longest=max(longest,count);
    //   }
    // //   longest=max(longest,count);
    //   return longest;


    // optimized 
    int n=nums.size();
  
    int longest=1;
    if(n==0) return 0;
    unordered_set<int> st;
    for(int i=0;i<n;i++){
        st.insert(nums[i]);
    }
    for(auto it:st)
    {
        if(st.find(it-1)==st.end())
        {
            int count=1;
            int x=it;
            while(st.find(x+1)!=st.end()){
            x+=1;
            count+=1;
        }
         longest= max(longest,count);
        }
        // longest= max (longest,count);
    }
    
      return longest;
    }
    
};