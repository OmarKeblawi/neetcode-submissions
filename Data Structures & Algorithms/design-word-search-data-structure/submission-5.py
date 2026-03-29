class WordDictionary:
    class Node:
        def __init__(self , val):
            self.val = val
            self.hist = {}

    def __init__(self):
        self.head = self.Node(None)

    def search_help(self, word , length , cnt , cur):
        
        if cnt == length or (word[0] not in cur.hist and word[0] != "."):
            return (cur,cnt)
        if word[0] == ".":
            for key in cur.hist:
                tmp_tail, tmp_cnt = self.search_help(word[1: ], length , cnt+1 , cur.hist[key])
                if tmp_cnt == length:
                    return (tmp_tail, tmp_cnt)
            return (cur,cnt)
        
        return self.search_help(word[1:] , length , cnt+1 , cur.hist[word[0]])

    def addWord(self, word: str) -> None:
        tail , cnt = self.search_help(word + "$" , len(word) + 1, 0 , self.head)
        if cnt == len(word) + 1 and tail.val == "$":
            return
        
        for i in range(cnt , len(word)):
            next = self.Node(word[i])
            tail.hist[word[i]] = next
            tail = next
        end = self.Node("$")
        tail.hist["$"] = end 
        return 


    def search(self, word: str) -> bool:
        print("Now searching for: "+word+ "$")
        tail , cnt = self.search_help(word + "$", len(word) + 1 , 0 ,self.head)
        return True if cnt == len(word) + 1 else False
    

        
            

        




