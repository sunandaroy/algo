using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = NULL;
    right = NULL;
  }
};

int getDepthSum(BinaryTree *node, int depth){
	int leftTreeDepthSum, rightTreeDepthSum;
	if(node->left == NULL)
		leftTreeDepthSum = 0;
	else
		leftTreeDepthSum = getDepthSum(node->left, 1+ depth);
	if(node->right == NULL)
		rightTreeDepthSum = 0;
	else
		rightTreeDepthSum = getDepthSum(node->right, 1+ depth);
	return depth + leftTreeDepthSum + rightTreeDepthSum;
}
int nodeDepths(BinaryTree *root) {
  // Write your code here.
	int depthSum = getDepthSum(root, 0);
	
  return depthSum;
}
