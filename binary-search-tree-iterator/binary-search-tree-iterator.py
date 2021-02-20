class BSTIterator(object):
    def __init__(self, root):
        """
        :type root: TreeNode
        """
        self.stack=[]
        self.inorder(root)
    def inorder(self,root):
        if not root:
            return 
        self.inorder(root.right)
        self.stack.append(root.val)
        self.inorder(root.left)

    def hasNext(self):
        """
        :rtype: bool
        """
        return len(self.stack)>0

    def next(self):
        """
        :rtype: int
        """
        return self.stack.pop()