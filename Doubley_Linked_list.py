class Node:
    def __init__(self,value):  #passing the value in Node
        self.next=None
        self.prev = None
        self.val=value


class doubleLinkedList:
    def __init__(self):
        self.head=None
        self.tail=None
        self.size=0

    def add_inThe_back(self,val):
        node=Node(val)           #creating a new node with value val
        if self.tail is None:    #checking the list is empty or not
            self.head=node
            self.tail=node
            self.size+=1
        else:                      #if the node is not empty assingning the value at the back of the list
            self.tail.next=node
            node.prev=self.tail
            self.tail=node
            self.size+=1

    def add_inThe_front(self,val):
        node=Node(val)
        if self.tail is None:
            self.head=node
            self.tail=node
            self.size+=1
        else:
            node.next=self.head    #if the node is not empty assingning the value at the front of the list
            self.head.prev=node
            self.head=node
            self.size+=1

    def add_at_nth(self,val,pos):
        node=Node(val)
        if self.tail is None:      #if the list is empty
            self.head=node
            self.tail=node
            self.size+=1
        else:
            if pos==1:              #if given position is 1
                node.next=self.head
                self.head.prev=node
                self.head=node
                self.size+=1
            elif pos>self.size:    #if the given position is the last position
                self.add_inThe_back(val)
            else:                 #if the position is not 1
                x=1
                node1=self.head
                while node1 is not None:
                    if x==pos-1:
                        node.next=node1.next
                        node.prev=node1.next.prev
                        node1.next=node
                        node.next.prev=node
                    x+=1
                    node1=node1.next




    def __remove_node(self,node):
        if node.prev is None:
            self.head=node.next
        else:
            node.prev.next = node.next
        if node.next is None:
            self.tail=node.prev
        else:
            node.next.prev = node.prev
        self.size-=1

    def remove_first(self):
        if self.head is not None:
            self.__remove_node(self.head)

    def remove_last(self):
        if self.tail is not None:
            self.__remove_node(self.tail)


    def remove(self,value):
        node=self.head
        while node is not None:
            if node.val==value:
                self.__remove_node(node)
            node=node.next


    def __str__(self):
        vals=[]
        node=self.head
        while node is not None:
            vals.append(node.val)
            node=node.next
        return f"[{', '.join(str(val) for val in vals)}]"
    
    def back(self):
        return self.tail.val

    def front(self):
        return self.head.val
    
    

my_list=doubleLinkedList()
my_list.add_inThe_back(3)
my_list.add_inThe_back(8)
my_list.add_inThe_back(6)
my_list.add_inThe_front(5)
my_list.add_inThe_front(1)
my_list.remove_last()
print(my_list)
my_list.add_at_nth(11,6)
print(my_list)
