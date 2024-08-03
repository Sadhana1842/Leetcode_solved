class Solution:
    def countAndSay(self, n: int) -> str:
        def helper(s):
            ans=""
            count=1
            for i in range(len(s)):
                if (i==len(s)-1 or s[i]!=s[i+1]):
                    ans+=str(count)+s[i]
                    count=1
                else:
                    count+=1
            return ans

        ans="1"
        for i in range(2,n+1):
            ans=helper(ans)
        return ans

        