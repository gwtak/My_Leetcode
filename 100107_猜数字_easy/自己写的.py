class Solution:
    def game(self, guess: List[int], answer: List[int]) -> int:
        res=0
        for i in range(0,3):
            if guess[i]==answer[i]:
                res+=1
        return res