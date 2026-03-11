class Solution {
public:
    int majorityElement(vector<int>& nums) {
    //     map<int,int>mp;
    //     for(int i=0;i<nums.size();i++){
    //         mp[nums[i]]++;
    //     }
    //    for(auto it:mp){
    //     if(it.second> (nums.size()/2)) return it.first;
    //    }
    //    return -1;


    // second method 
    int candidate;
    int count=0;
    for(int i=0;i<nums.size();i++){
        if(count==0){
            count=1;
            candidate=nums[i];

        }
        else{
            if(nums[i]==candidate) count++;
            else count--;
        }
    }
    return candidate;
    }
};