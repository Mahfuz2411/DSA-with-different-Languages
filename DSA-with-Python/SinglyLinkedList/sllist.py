class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None
        
        
class List:
    def __init__(self):
        self.size = 0
        self.head = None

    def push(self, data):
        u = Node(data)
        u.next = self.head
        self.head = u
        
        self.size+=1

    def pop(self):
        if self.size==0:
            return 0
        u = self.head
        self.head = self.head.next
        
        self.size-=1
        
        return u.data
    
    def printData(self):
        u = self.head
        while u is not None:
            print(u.data)
            u = u.next    
    

def main():
    ob = List()
    
    ob.push(5)
    ob.push(6)
    ob.push(7)
    
    
    print(ob.pop())
    print(ob.pop())
    print('==')
    ob.printData()
    
    
if __name__=="__main__":
    main() 