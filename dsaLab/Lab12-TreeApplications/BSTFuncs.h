typedef struct node {
    int val;
    struct node * left;
    struct node * right;
} node ;

typedef struct node Node;

Node * createNode(int );
void inOrder(Node *);
void postOrder(Node *);
void preOrder(Node *);
void insertBST(Node **,int);