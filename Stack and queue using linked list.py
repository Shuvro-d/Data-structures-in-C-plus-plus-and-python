from Doubly_Linked_List import doubleLinkedList

class Stack:
    def __init__(self):
        self.__list=doubleLinkedList()

    def push(self,val):
        self.__list.add_inThe_back(val)

    def pop(self):
        val=self.__list.back()
        self.__list.remove_last()
        return val

    def is_empty(self):
        return self.__list.size == 0

    def peek(self):
        return self.__list.back()

    def __len__(self):
        return self.__list.size



class Queue:
    def __init__(self):
        self.__list=doubleLinkedList()

    def enqueue(self,val):
        self.__list.add_inThe_back(val)

    def deque(self):
        val=self.__list.front()
        self.__list.remove_first()
        return val

    def front(self):
        return self.__list.front()

    def __len__(self):
        return  self.__list.size

    def is_empty(self):
        return self.__list.size==0




my_stack=Stack()
my_stack.push(1)
my_stack.push(2)
my_stack.push(3)
my_stack.push(4)
print(my_stack.peek())
my_stack.push(5)
print(len(my_stack))
print(my_stack.pop())
print(len(my_stack))

my_queue= Queue()
my_queue.enqueue(1)
my_queue.enqueue(2)
my_queue.enqueue(3)
my_queue.enqueue(4)
print(len(my_queue))
print(my_queue.front())
print(my_queue.deque())
print(my_queue.deque())
