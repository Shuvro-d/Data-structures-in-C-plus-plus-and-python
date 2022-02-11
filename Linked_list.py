class Node:
    def __init__(self,value):  #passing the value in Node
        self.next=None
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
                        node1.next=node
                    x+=1
                    node1=node1.next


    def delete_node(self,val):
        if self.head is None:
            print("List is empty")
        elif self.head.val==val:
            self.head=self.head.next
            self.size-=1
        else:
            node=self.head
            while node.next is not None:
                if node.next.val==val:
                    node.next=node.next.next
                    if node.next is None:
                        self.tail=node
                    self.size-=1
                    return
                node=node.next





    def print_list(self):
        node=self.head
        while node is not None:
            if node.val is not None:
                print(node.val,end=" ")
            node=node.next
        print()

    def print_list_reverse(self):
        temp=Node(None)
        prev=Node(None)
        current=self.head
        while current is not None:
            temp=current.next
            current.next=prev
            prev=current
            current=temp
        self.head=prev





my_list=doubleLinkedList()
my_list.add_inThe_back(3)
my_list.add_inThe_back(8)
my_list.add_inThe_back(6)
my_list.add_inThe_front(5)
my_list.add_inThe_front(1)
my_list.print_list()
my_list.add_at_nth(11,2)
my_list.print_list()
my_list.delete_node(1)
my_list.print_list()
my_list.print_list_reverse()
my_list.print_list()