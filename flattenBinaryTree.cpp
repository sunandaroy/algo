#given a binary tree flatten it and make a linkedlist out of it.
#concept: while traversing each node, connect this node with it's left and right pointer. 
# node's left pointer = node's let subtree's right most node 
#node's right pointer = node's right subtree's left most node
#T(n) = o(n)
#space complexity = o(depth of the tree)
public:
  int value;
  BinaryTree *left = NULL;
  BinaryTree *right = NULL;

  BinaryTree(int value);
};
vector<BinaryTree* >flattenTree(BinaryTree *node){
	BinaryTree *leftmost;
	BinaryTree *rightmost;
	if(node->left == NULL)
		leftmost = node;
	else{
		vector<BinaryTree *> leftMostRightMost = flattenTree(node->left);
		leftmost = leftMostRightMost[0];
		node->left = leftMostRightMost[1]; 
		leftMostRightMost[1]->right = node;	
	}
		
	if(node->right == NULL)
		rightmost = node;
	else{
		vector<BinaryTree *> leftMostRightMost = flattenTree(node->right);
		rightmost = leftMostRightMost[1];
		node->right = leftMostRightMost[0];
		leftMostRightMost[0]->left = node;	
	}
	return {leftmost, rightmost};	
}
BinaryTree *flattenBinaryTree(BinaryTree *root) {
  BinaryTree *node = flattenTree(root)[0];
  return node;
}

