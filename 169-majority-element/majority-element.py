class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        dict={}
        for ele in nums:
            if(ele in dict):
                dict[ele]+=1
            else:
                dict[ele]=1
        num=len(nums)/2
        for key,value in dict.items():
            if(value>num):
                return key


