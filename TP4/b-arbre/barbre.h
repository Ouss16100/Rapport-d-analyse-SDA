#define TRUE 1
#define FALSE 0
#define EMPTY 0

#define NODE_ORDER		3 /*The degree of the tree.*/
#define NODE_POINTERS	(NODE_ORDER*2)
#define NODE_KEYS		NODE_POINTERS-1

typedef unsigned char bool;

typedef struct tree_node {
	int key_array[NODE_KEYS];
	struct tree_node *child_array[NODE_POINTERS];
	unsigned int key_index;
	bool leaf;
} node_t;

typedef struct {
	node_t *node_pointer;
	int key;
	bool found;
	unsigned int depth;
} result_t;

typedef struct {
	node_t *root;
	unsigned short order;
	bool lock;
	int capacity;
	int count;
} btree_t;

static int BTreeGetLeftMax(node_t *T);
static int BTreeGetRightMin(node_t *T);
static node_t *create_node();
btree_t *create_btree();
static result_t *get_resultset();
result_t *search(int key, node_t *node);
static void split_child(node_t *parent_node, int i, node_t *child_array);
static void insert_nonfull(node_t *n, int key);
node_t *insert(int key, btree_t *b);
static void merge_children(node_t *root, int index, node_t *child1, node_t *child2);
static void BTreeDeleteNoNone(int X, node_t *root);
node_t *delete(int key, btree_t *b);





