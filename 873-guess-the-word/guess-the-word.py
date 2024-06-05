# """
# This is Master's API interface.
# You should not implement it, or speculate about its implementation
# """
# class Master:
#     def guess(self, word: str) -> int:


from random import random, shuffle


class Solution:
    def findSecretWord(self, words: List[str], master: "Master") -> None:
        def get_match(w1, w2):
            return sum([1 if w1[i] == w2[i] else 0 for i in range(6)])

        while words:
            word = words[int(random() * len(words))]
            x = master.guess(word)
            if x == 6:
                return word
            words = [word2 for word2 in words if get_match(word, word2) == x]
            shuffle(words)

        return None
