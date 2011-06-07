/* BASIC STUDENT INFORMATION SYSTEM 1.0
 * ================================================================================
 * Pelin Öztürk & Mehmet Akif Tütüncü
 * ================================================================================
 * This project has been compiled with GNOME Compiler Collection under Ubuntu 11.04
 * ================================================================================
 * Abstact Data Types Header File (for stack, queue, linked list and AVL tree)
 * ================================================================================
 */

// ===== Header files =====
#include <malloc.h>				// Header file for allocating memory
// ================================================================================

// ===== Macro definitions =====
#define LH +1					// Left is taller
#define EH  0					// Left and right are equal
#define RH -1					// Right is taller
// ================================================================================

// ===== Function prototypes =====
int compareInt(void *, void *);
int compareLong(void *, void *);
// ================================================================================

//	===== Type definitions =====
typedef struct node
{
	void *data;
	struct node *next;
} NODE;

typedef struct
{
	int count;
	NODE *top;
} STACK;

typedef struct
{
	int count;
	NODE *front;
	NODE *back;
} QUEUE;

typedef struct
{
	int count;
	NODE *front;
	NODE *back;
} LINKEDLIST;

typedef struct binaryNode
{
	void *data;
	int balance;
	struct binaryNode *left;
	struct binaryNode *right;
} BINARYNODE;

typedef struct binaryTree
{
	int count;
	int (*compare) (void *arg1, void *arg2);
	BINARYNODE *root;
} BINARYTREE;
// ================================================================================

//	===== Creation functions =====
NODE *createNode()
{
	NODE *newNode = (NODE *) malloc(sizeof(NODE));
	if(newNode != NULL)
	{
		newNode->data = NULL;
		newNode->next = NULL;
	}
	return newNode; // Will return NULL unless successfully created
}

STACK *createStack()
{
	STACK *newStack = (STACK *) malloc(sizeof(STACK));
	if(newStack != NULL)
	{
		newStack->count = 0;
		newStack->top = NULL;
	}
	return newStack; // Will return NULL unless successfully created
}

QUEUE *createQueue()
{
	QUEUE *newQueue = (QUEUE *) malloc(sizeof(QUEUE));
	if(newQueue != NULL)
	{
		newQueue->count = 0;
		newQueue->front = NULL;
		newQueue->back = NULL;
	}
	return newQueue; // Will return NULL unless successfully created
}

LINKEDLIST *createLinkedList()
{
	LINKEDLIST *newLinkedList = (LINKEDLIST *) malloc(sizeof(LINKEDLIST));
	if(newLinkedList != NULL)
	{
		newLinkedList->count = 0;
		newLinkedList->front = NULL;
		newLinkedList->back = NULL;
	}
	return newLinkedList; // Will return NULL unless successfully created
}

BINARYNODE *createBinaryNode()
{
	BINARYNODE *dummy = (BINARYNODE *) malloc(sizeof(BINARYNODE));
	if(dummy)
	{
		dummy->data = NULL;
		dummy->balance = EH;
		dummy->left = NULL;
		dummy->right = NULL;
	}
	return dummy; // Will return NULL unless successfully created
}

BINARYTREE *createBinaryTree(int (*compare)(void *arg1, void *arg2))
{
	BINARYTREE *dummy = (BINARYTREE *) malloc(sizeof(BINARYTREE));
	if(dummy)
	{
		dummy->count = 0;
		dummy->compare = compare;
		dummy->root = NULL;
	}
	return dummy; // Will return NULL unless successfully created
}
// ================================================================================

//	===== Stack functions =====
void pushStack(STACK *stack, NODE *node)
{
	node->next = stack->top;
	stack->top = node;
	(stack->count)++;
}

int popStack(STACK *stack)
{
	if(stack->count > 0)
	{
		NODE *dummy = stack->top;
		stack->top = stack->top->next;
		free(dummy);
		(stack->count)--;
		return 1; // Success
	}
	else
	{
		return 0; // Failure because stack is empty
	}
}
// ================================================================================

//	===== Queue functions =====
void enqueue(QUEUE *queue, NODE *node)
{
	if(queue->count == 0)
	{
		queue->front = node;
	}
	else if(queue->count > 0)
	{
		queue->back->next = node;
	}
	queue->back = node;
	(queue->count)++;
}

int dequeue(QUEUE *queue)
{
	if(queue->count > 1) // 2 or more items
	{
		NODE *dummy = queue->front;
		queue->front = queue->front->next;
		free(dummy);
		(queue->count)--;
		return 1; // Success
	}
	else if(queue->count > 0) // 1 item
	{
		free(queue->front);
		queue->front = NULL;
		queue->back = NULL;
		(queue->count)--;
		return 1; // Success
	}
	else // 0 items
	{
		return 0; // Failure because queue is empty
	}
}
// ================================================================================

//	===== Linked list functions =====
NODE *_getItemAtIndexLinkedList(LINKEDLIST *linkedList, int index) // A private function
{
	NODE *dummy = linkedList->front;
	int i;
	for(i = 0; i < index; i++)
	{
		dummy = dummy->next;
	}
	return dummy;
}

NODE *getItemWithIntDataLinkedList(LINKEDLIST *linkedList, int data)
{
	NODE *dummy = linkedList->front;
	int i;
	for(i = 0; i < linkedList->count; i++)
	{
		if(*((int *) dummy->data) == data)
		{
			return dummy;
		}
		dummy = dummy->next;
	}
	return NULL; // Will return NULL if there were no matches
}

int getIndexWithIntDataLinkedList(LINKEDLIST *linkedList, int data)
{
	NODE *dummy = linkedList->front;
	int i;
	for(i = 0; i < linkedList->count; i++)
	{
		if(*((int *) dummy->data) == data)
		{
			return i;
		}
		dummy = dummy->next;
	}
	return -1; // Will return -1 if there were no matches
}

void addToFrontLinkedList(LINKEDLIST *linkedList, NODE *node)
{
	if(linkedList->count == 0) // If linked list is empty
	{
		linkedList->front = node;
		linkedList->back = node;
	}
	else
	{
		node->next = linkedList->front;
		linkedList->front = node;
	}
	(linkedList->count)++;
}

int insertAtIndexLinkedList(LINKEDLIST *linkedList, NODE *node, int index)
{
	if(linkedList->count == 0) // If linked list is empty
	{
		return -1;
	}
	else
	{
		if(index - 1 < 0 || index - 1 >= linkedList->count) // If index is out of range
		{
			return 0;
		}
		else
		{
			NODE *dummy = _getItemAtIndexLinkedList(linkedList, index - 1);
			node->next = dummy->next;
			dummy->next = node;
			(linkedList->count)++;
			return 1;
		}
	}
}

void addToBackLinkedList(LINKEDLIST *linkedList, NODE *node)
{
	if(linkedList->count == 0) // If linked list is empty
	{
		linkedList->front = node;
		linkedList->back = node;
	}
	else
	{
		linkedList->back->next = node;
		linkedList->back = node;
	}
	(linkedList->count)++;
}

int deleteItemAtIndexLinkedList(LINKEDLIST *linkedList, int index)
{
	if(linkedList->count == 0) // If linked list is empty
	{
		return -1;
	}
	else
	{
		NODE *dummy, *dummyPrev;
		if(index == 0) // If item is at front
		{
			dummy = linkedList->front;
			linkedList->front = dummy->next;
			if(dummy->next == NULL) // If dummy is the only item in linked list
			{
				linkedList->back = NULL;
			}
		}
		else if(index > 0 && index < linkedList->count) // If index is in range
		{
			dummyPrev = _getItemAtIndexLinkedList(linkedList, index - 1);
			dummy = _getItemAtIndexLinkedList(linkedList, index);
			if(index == linkedList->count - 1)
			{
				linkedList->back = dummyPrev;
			}
			dummyPrev->next = dummy->next;
		}
		else // If index is out of range
		{
			return 0;
		}
		free(dummy);
		(linkedList->count)--;
		return 1;
	}
}
// ================================================================================

// ===== Internal rotate AVL functions =====
BINARYNODE *_rotateAVLLeft(BINARYNODE *root)
{
	BINARYNODE *dummy;
	dummy = root->right;								// Hold the right subtree of root
	root->right = dummy->left;							// Connect right side of the root to left side of the dummy
	dummy->left = root;									// Then shift root to left side of the dummy
	return dummy;										// Return dummy, the new root
}

BINARYNODE *_rotateAVLRight(BINARYNODE *root)
{
	BINARYNODE *dummy;
	dummy = root->left;									// Hold the left subtree of root
	root->left = dummy->right;							// Connect left side of the root to right side of the dummy
	dummy->right = root;								// Then shift root to right side of the dummy
	return dummy;										// Return dummy, the new root
}
// ================================================================================

// ===== Internal insert AVL functions =====
BINARYNODE *_insertAVLLeftBalance(BINARYNODE *root, int *isTaller)
{
	BINARYNODE *leftSubTree;
	BINARYNODE *rightSubTree;
	leftSubTree = root->left;
	switch(leftSubTree->balance)
	{
		case LH:										// Left subtree is also LH, rotate right
			root->balance = EH;
			leftSubTree->balance = EH;
			root = _rotateAVLRight(root);
			*isTaller = 0;
			break;
		case EH:										// This case won't be called unless there is an error
			break;
		case RH:										// Left subtree is RH, double rotation is required, first rotate left, then right
			rightSubTree = leftSubTree->right;
			switch(rightSubTree->balance)
			{
				case LH:								// Right subtree was LH
					root->balance = RH;
					leftSubTree->balance = EH;
					break;
				case EH:								// Right subtree was EH
					root->balance = EH;
					leftSubTree->balance = EH;
					break;
				case RH:								// Right subtree was RH
					root->balance = EH;
					leftSubTree->balance = LH;
					break;
			}
			rightSubTree->balance = EH;
			root->left = _rotateAVLLeft(leftSubTree);
			root = _rotateAVLRight(root);
			*isTaller = 0;
			break;
	}
	return root;
}

BINARYNODE *_insertAVLRightBalance(BINARYNODE *root, int *isTaller)
{
	BINARYNODE *leftSubTree;
	BINARYNODE *rightSubTree;
	rightSubTree = root->right;
	switch(rightSubTree->balance)
	{
		case LH:										// Right subtree is LH, double rotation is required, first rotate right, then left
			leftSubTree = rightSubTree->left;
			switch(leftSubTree->balance)
			{
				case LH:								// Left subtree was LH
					root->balance = LH;
					rightSubTree->balance = EH;
					break;
				case EH:								// Left subtree was EH
					root->balance = EH;
					rightSubTree->balance = EH;
					break;
				case RH:								// Left subtree was RH
					root->balance = EH;
					rightSubTree->balance = RH;
					break;
			}
			leftSubTree->balance = EH;
			root->right = _rotateAVLRight(rightSubTree);
			root = _rotateAVLLeft(root);
			*isTaller = 0;
			break;
		case EH:										// This case won't be called unless there is an error
			break;
		case RH:										// Right subtree is also RH, rotate left
			root->balance = EH;
			rightSubTree->balance = EH;
			root = _rotateAVLLeft(root);
			*isTaller = 0;
			break;
	}
	return root;
}

BINARYNODE *_insertAVL(BINARYTREE *tree, BINARYNODE *root, BINARYNODE *node, int *isTaller)
{
	if(!root)												// Either the correct place is found or the tree was empty
	{
		root = node;
		*isTaller = 1;
	}
	else
	{
		if(tree->compare(root->data, node->data) > 0)		// Go left, the node has a value that is smaller than it's root
		{
			root->left = _insertAVL(tree, root->left, node, isTaller);
			if(*isTaller)
			{
				switch(root->balance)
				{
					case LH:								// Root was LH, node added to left, now balancing is needed
						root = _insertAVLLeftBalance(root, isTaller);
						break;
					case EH:								// Root was EH, node added to left, now LH
						root->balance = LH;
						break;
					case RH:								// Root was RH, node added to left, now EH
						root->balance = EH;
						*isTaller = 0;
						break;
				}
			}
			return root;
		}
		else												// Go right, the node has a value that is either greater than or equal to the value of it's root
		{
			root->right = _insertAVL(tree, root->right, node, isTaller);
			if(*isTaller)
			{
				switch(root->balance)
				{
					case LH:								// Root was LH, node added to right, now EH
						root->balance = EH;
						*isTaller = 0;
						break;
					case EH:								// Root was EH, node added to right, now RH
						root->balance = RH;
						break;
					case RH:								// Root was RH, node added to right, now balancing is needed
						root = _insertAVLRightBalance(root, isTaller);
						break;
				}
			}
			return root;
		}
	}
	return root;
}
// ================================================================================

// ===== Internal delete AVL functions =====
BINARYNODE *_deleteAVLLeftBalance(BINARYNODE *root, int *isShorter)
{
	BINARYNODE *leftSubTree;
	BINARYNODE *rightSubTree;
	switch(root->balance)
	{
		case LH:									// Root was already LH, node deleted from right, rotation needed
			leftSubTree = root->left;
			switch(leftSubTree->balance)
			{
				case LH:
					leftSubTree->balance = EH;
					root->balance = EH;
					break;
				case EH:
					leftSubTree->balance = RH;
					root->balance = LH;
					*isShorter = 0;
					break;
				case RH:							// Left subtree is RH, double rotation is needed, rotate first left then right
					rightSubTree = leftSubTree->right;
					switch(rightSubTree->balance)
					{
						case LH:
							leftSubTree->balance = EH;
							root->balance = RH;
							break;
						case EH:
							leftSubTree->balance = EH;
							root->balance = EH;
							break;
						case RH:
							leftSubTree->balance = LH;
							root->balance = EH;
							break;
					}
					rightSubTree->balance = EH;
					root->left = _rotateAVLLeft(leftSubTree);
					root = _rotateAVLRight(root);
					leftSubTree->balance = EH;
					root->balance = EH;
					break;
			}
			break;
		case EH:									// Root was EH, node deleted from right, now LH
			root->balance = LH;
			*isShorter = 0;
			break;
		case RH:									// Root was RH, node deleted from right, now balanced
			root->balance = EH;
			break;
	}
	return root;
}

BINARYNODE *_deleteAVLRightBalance(BINARYNODE *root, int *isShorter)
{
	BINARYNODE *leftSubTree;
	BINARYNODE *rightSubTree;
	switch(root->balance)
	{
		case LH:									// Root was LH, node deleted from left, now balanced
			root->balance = EH;
			break;
		case EH:									// Root was EH, node deleted from left, now RH
			root->balance = RH;
			*isShorter = 0;
			break;
		case RH:									// Root was already RH, node deleted from left, rotation needed
			rightSubTree = root->right;
			switch(rightSubTree->balance)
			{
				case LH:							// Right subtree is LH, double rotation is needed, rotate first right then left
					leftSubTree = rightSubTree->left;
					switch(leftSubTree->balance)
					{
						case LH:
							rightSubTree->balance = RH;
							root->balance = EH;
							break;
						case EH:
							rightSubTree->balance = EH;
							root->balance = EH;
							break;
						case RH:
							rightSubTree->balance = EH;
							root->balance = LH;
							break;
					}
					leftSubTree->balance = EH;
					root->right = _rotateAVLRight(rightSubTree);
					root = _rotateAVLLeft(root);
					rightSubTree->balance = EH;
					root->balance = EH;
					break;
				case EH:
					rightSubTree->balance = LH;
					root->balance = RH;
					*isShorter = 0;
					break;
				case RH:
					rightSubTree->balance = EH;
					root->balance = EH;
					break;
			}
			break;
	}
	return root;
}

BINARYNODE *_deleteAVL(BINARYTREE *tree, BINARYNODE *root, BINARYNODE *node, int *isShorter, int *isSuccessful)
{
	BINARYNODE *nodeToDelete;
	BINARYNODE *nodeToExchange;
	BINARYNODE *newRoot;
	if(!root)												// Node couldn't be found
	{
		*isShorter = 0;
		*isSuccessful = 0;
		return NULL;
	}
	else
	{
		if(tree->compare(root->data, node->data) > 0)		// Go left, the node has a value that is smaller than it's root
		{
			root->left = _deleteAVL(tree, root->left, node, isShorter, isSuccessful);
			if(*isShorter)
			{
				root = _deleteAVLRightBalance(root, isShorter);
			}
		}
		else if(tree->compare(root->data, node->data) < 0) // Go right, the node has a value that greater than it's root
		{
			root->right = _deleteAVL(tree, root->right, node, isShorter, isSuccessful);
			if(*isShorter)
			{
				root = _deleteAVLLeftBalance(root, isShorter);
			}
		}
		else												// The node is found
		{
			nodeToDelete = root;
			if(!(root->right))								// Only left subtree exists
			{
				newRoot = root->left;
				*isShorter = 1;
				*isSuccessful = 1;
				free(nodeToDelete);
				return newRoot;
			}
			else
			{
				if(!(root->left))							// Only right subtree exists
				{
					newRoot = root->right;
					*isShorter = 1;
					*isSuccessful = 1;
					free(nodeToDelete);
					return newRoot;
				}
				else										// Both left and right subtrees exist
				{
					nodeToExchange = root->left;
					while(nodeToExchange->right)
					{
						nodeToExchange = nodeToExchange->right;
					}
					root->data = nodeToExchange->data;
					root->left = _deleteAVL(tree, root->left, nodeToExchange, isShorter, isSuccessful);
					if(*isShorter)
					{
						root = _deleteAVLRightBalance(root, isShorter);
					}
				}
			}
		}
	}
	return root;
}
// ================================================================================

// ===== Internal retrieve AVL functions =====
BINARYNODE *_retrieveAVL(BINARYTREE *tree, BINARYNODE *root, void *data)
{
	if(root)
	{
		if(tree->compare(root->data, data) > 0)					// Value of root is greater than value of node, go left
		{
			return _retrieveAVL(tree, root->left, data);
		}
		else if(tree->compare(root->data, data) < 0)			// Value of root is less than value of node, go right
		{
			return _retrieveAVL(tree, root->right, data);
		}
		else													// Value of root is equal to value of node, found
		{
			return root;
		}
	}
	else
	{
		return NULL;
	}
}
// ================================================================================

// ===== Internal traverse AVL functions =====
void _traverseAVLPre(BINARYNODE *root, void (*process)(void *data))
{
	if(root)
	{
		process(root->data);
		_traverseAVLPre(root->left, process);
		_traverseAVLPre(root->right, process);
	}
	return;
}

void _traverseAVLIn(BINARYNODE *root, void (*process)(void *data))
{
	if(root)
	{
		_traverseAVLIn(root->left, process);
		process(root->data);
		_traverseAVLIn(root->right, process);
	}
	return;
}

void _traverseAVLPost(BINARYNODE *root, void (*process)(void *data))
{
	if(root)
	{
		_traverseAVLPost(root->left, process);
		_traverseAVLPost(root->right, process);
		process(root->data);
	}
	return;
}
// ================================================================================

// ===== Public AVL tree functions =====
void insertAVL(BINARYTREE *tree, BINARYNODE *node)
{
	int isTaller = 0;
	tree->root = _insertAVL(tree, tree->root, node, &isTaller);
	(tree->count)++;
}

int deleteAVL(BINARYTREE *tree, BINARYNODE *node)
{
	int isShorter = 0, isSuccessful = 0;
	BINARYNODE *newRoot;
	newRoot = _deleteAVL(tree, tree->root, node, &isShorter, &isSuccessful);
	if(isSuccessful)
	{
		tree->root = newRoot;
		(tree->count)--;
	}
	return isSuccessful;
}

BINARYNODE *retrieveAVL(BINARYTREE *tree, void *data)
{
	if(tree->root)
	{
		return _retrieveAVL(tree, tree->root, data);
	}
	else
	{
		return NULL;
	}
}

void traverseAVL(BINARYTREE *tree, void (*process)(void *data), int type)
{
	switch(type)
	{
		case 1:										// Pre-order traverse
			_traverseAVLPre(tree->root, process);
			break;
		case 2:										// In-order traverse
			_traverseAVLIn(tree->root, process);
			break;
		case 3:										// Post-order traverse
			_traverseAVLPost(tree->root, process);
			break;
		default:
			return;
	}
}
// ================================================================================

// ===== Compare functions =====
int compareInt(void *arg1, void *arg2)
{
	if(*(int *)arg1 < *(int *)arg2)
	{
		return -1;
	}
	else if(*(int *)arg1 > *(int *)arg2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int compareLong(void *arg1, void *arg2)
{
	if(*(long *)arg1 < *(long *)arg2)
	{
		return -1;
	}
	else if(*(long *)arg1 > *(long *)arg2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
