class Stack:
    def __init__(self):
        self.arr = []
        self.size = 0
        
    def __init__(self, x):
        self.arr = []
        self.arr.append(x)
        self.size = 1;
        
    def push_back(self, x):
        self.arr.append(x)
        self.size += 1
        
    def pop_back(self):
        if self.size<=0:
            return -1
        else:
            temp = self.arr[-1]
            self.arr.pop()
            self.size -= 1
            return temp
        
    def Print(self):
        print(self.arr)
        

ob = Stack(5)
ob.Print()
ob.push_back(10)
ob.push_back(100)
ob.push_back(50)
ob.push_back(30)
ob.Print()
print(ob.pop_back())
print(ob.pop_back())
print(ob.pop_back())
print(ob.pop_back())
print(ob.pop_back())
print(ob.pop_back())
ob.Print()