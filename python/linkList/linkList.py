class Node(object):
    def __init__(self, value=None, next=None):
        self.value = value
        self.next = next

    def __str__(self):
        """方便打印调试"""
        return '<Node: value = {}, next = {}'.format(self.value, self.next)

    __repr__ = __str__


class LinkedList(object):
    """单链表类"""

    def __init__(self, size = None):
        """

        :param size: int or None, 如果是None,则没有容量限制
        """
        self.size = size
        self.root = Node()
        # self.root = None
        self.tailNode = None
        self.length = 0

    def __len__(self):
        return self.length

    def append(self, value):
        # self.size 不等于None 说明这个单链表是有容量的
        # self.length >= self.size 说明容量都装满了
        if self.size is not None and len(self) >= self.size:
            raise Exception('LinkedList is Full')
        node = Node(value) # 构造节点
        tail = self.tailNode
        if tail is None:    #说明list还没有节点
            self.root.next = node
        else:
            tail.next = node # 添加新的节点到最后

        self.tailNode = node
        self.length += 1

    def appendleft(self, value):
        if self.size is not None and len(self) >= self.size:
            raise Exception("Linked List is Full")
        node = Node(value)
        if self.tailNode is None: # 如果原链表为空，需要设置tailNode
            self.tailNode = node

        headnode = self.root.next
        self.root.next =  node
        node.next = headnode

        self.length += 1

    def __iter__(self):
        for node in self.iter_node():
            yield node.value

    def iter_node(self):
        """遍历 从head 到tail"""
        curnode = self.root.next
        while curnode is not self.tailNode:
            yield curnode
            curnode = curnode.next
        if curnode is not None:
            yield curnode

    def remove(self, value):
        prevnode = self.root
        for curnode in self.iter_node():
            if curnode.value == value:
                prevnode.next = curnode.next
                if curnode is self.tailnode:
                    self.tailNode = prevnode
                del curnode
                self.length -= 1
                return 1 # 表明删除成功
            else:
                prevnode = curnode
        return -1 # 表明删除失败





if __name__ == '__main__':
    ll = Node()
    print(ll)


