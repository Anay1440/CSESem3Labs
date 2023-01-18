typedef struct node {
    int val;
    struct node * left;
    struct node * right;
} Node ;

typedef struct {
    Node * nodes[100];
    int tos;
} Stack;

typedef struct node Node;

Node * createNode(int );
void inOrder(Node *);
void postOrder(Node *);
void preOrder(Node *);
void createBT(Node **);
void push(Stack * , Node * );
Node * pop(Stack * );