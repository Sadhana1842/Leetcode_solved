class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        s=list(s)
        t=list(t)
        
        s=sorted(s)
        t=sorted(t)
        
        if(s==t):
            return True
        else:
            return False