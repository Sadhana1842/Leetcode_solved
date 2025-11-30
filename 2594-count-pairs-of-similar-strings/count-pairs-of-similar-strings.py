class Solution:
    def similarPairs(self, words: List[str]) -> int:
        set_of_words=[]
        for word in words:
            set_of_words.append(set(word))
        count=0
        for i in range(0,len(set_of_words)):
            for j in range(i+1,len(set_of_words)):
                if(set_of_words[i]==set_of_words[j]):
                    count+=1

        return count


