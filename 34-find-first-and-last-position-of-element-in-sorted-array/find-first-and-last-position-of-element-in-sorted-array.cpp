class Solution {
public:
int firstoc(vector<int>& nums, int target){
    int ans=-1;
    int start=0;
    int end=nums.size()-1;
    
    while(start<=end)
    {
         int mid = start+ (end-start)/2;
        if(nums[mid]==target){
            ans=mid;
            end=mid-1;
        }
        else if(nums[mid]<target){
            start=mid+1;
        }
        else end=mid-1;

    }
    return ans;
}
int lastoc(vector<int>& nums, int target){
    int ans=-1;
    int start=0;
    int end=nums.size()-1;
    
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(nums[mid]==target){
            ans=mid;
            start=mid+1;
        }
        else if(nums[mid]<target){
            start=mid+1;
        }
        else end=mid-1;

    }
    return ans;
}

    vector<int> searchRange(vector<int>& nums, int target) {
    //  int n=nums.size();
    //  int first=-1;
    //  int last=-1;
    //  int start=0;
    //  int end=n-1;
    //  int mid=start +(end-start)/2;
    //  while(start<=end)
    //  {
    //     if(nums[mid]==target){
    //         first=mid;
    //         end=mid-1;
    //     }
    //     else if(nums[mid]<target){
    //         start=mid+1;
    //     }
    //     else end=mid-1;
    //  }
    //  start=0;
    //  end=n-1;
    //  while(start<=end)
    //  {
    //     if(nums[mid]==target){
    //         first=mid;
    //         start=mid-1;
    //     }
    //     else if(nums[mid]<target){
    //         start=mid+1;
    //     }
    //     else end=mid-1;
    //  }
    //  return{first,last};
    return{firstoc(nums,target),lastoc(nums,target)};
    }

};