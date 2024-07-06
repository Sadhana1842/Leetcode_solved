class Solution:
    def myAtoi(self, s: str) -> int:
        s=s.lstrip(' ')
        ans=''
        ans1=0
        neg=0
        if(s==""):
            return(ans1)
        if(s[0]=='-'):
            neg=1
            s=s[1:]
        elif(s[0]=='+'):
            neg=0
            s=s[1:]

        for character in s:
            if not character.isdigit():
                break
            if(character.isdigit()):
                ans=ans+character
        if(ans==''):
            ans=0
        ans=int(ans)
        if(neg):
            ans=-ans
        if(ans>(2**31)-1):
            ans=2**31-1
        if(ans<-((2**31)-1)):
            ans=-((2**31))
        return ans