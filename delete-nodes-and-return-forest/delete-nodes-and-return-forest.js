/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number[]} to_delete
 * @return {TreeNode[]}
 */
let isDelete = false;

var delNodes = function(root, to_delete) {
    const forest = new Map([[root.val, root]]);
    to_delete.forEach(val => {
        isDelete = false;
        deleteNode(val, forest);
    });
    
    return [...forest.values()];
};

function deleteNode(val, forest){
    const forestNodes = [...forest.values()];
    for(let i = 0; i < forestNodes.length; i++){
        const root = forestNodes[i];
        findAndDelete(val, root, forest);
        if(isDelete){
            return;
        }
    }
}

function findAndDelete(val, root, forest){
    if(root === null){
        return;
    }
    
    if(val === root.val){
        forest.delete(root.val);
        
        if(root.left){            
            forest.set(root.left.val, root.left);
        }
        
        if(root.right){            
            forest.set(root.right.val, root.right);
        }
        
        isDelete = true;
        return;
    }
    
    if(root.left){
        findAndDelete(val, root.left, forest);
        if(root.left.val === val){            
            root.left = null;
        }
    }
    
    if(root.right){      
        findAndDelete(val, root.right, forest);
        if(root.right.val === val){
            root.right = null;
        }
    }
}