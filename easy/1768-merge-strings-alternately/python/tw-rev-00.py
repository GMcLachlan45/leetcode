#runtime: 30 ms 
#memory: 13.9 MB

class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        short = min(len(word1), len(word2))
        alt =''
        for x in range(short):
            alt += word1[x]
            alt += word2[x]
        
        if(len(word1)>len(word2)):
            alt += word1[short:]
        else:
            alt += word2[short:]   
        return alt