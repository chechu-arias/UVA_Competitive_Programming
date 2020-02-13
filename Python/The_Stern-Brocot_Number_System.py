class tree:

    def __init__(self):
        self.left = (0, 1)
        self.val = (1, 1)
        self.right = (1, 0)
    
    def compare(self, a, b):
        #print(a, self.val[1], b, self.val[0])
        calc = a*self.val[1] - b*self.val[0]
        #print(calc)
        if calc < 0:
            return -1
        if calc > 0:
            return 1
        else:
            return 0

    def moveL(self):
        print("L", end="")
        self.right = self.val
        self.val = (self.right[0]+self.left[0], self.right[1]+self.left[1])
    
    def moveR(self):
        print("R", end="")
        self.left = self.val
        self.val = (self.right[0]+self.left[0], self.right[1]+self.left[1])

while True:
    inp = list(map(int, input().strip().split(" ")))

    num = inp[0]
    denom = inp[1]
    if num == 1 and denom == 1:
        break
    else:
        movements = tree()
        
        while True:
            comp = movements.compare(num, denom)
            if comp < 0:
                movements.moveL()
            elif comp > 0:
                movements.moveR()
            elif comp == 0:
                print()
                break
            else:
                assert "Error"
            
        