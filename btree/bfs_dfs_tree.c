#include <stdlib.h>
#include <stdio.h>

struct node_t
{
    int value;

    struct node_t *parent;

    struct node_t *left;
    struct node_t *right;
};

struct tree_t
{
    int size;

    struct node_t *root;
};

// insert
// contains
// print
// get_sorted_array
// construct_bst_from_sorted_array

void insert(struct node_t *root, int value)
{
    if (value > root->value)
    {
        if (root->right == NULL)
        {
            struct node_t *new_node = malloc(sizeof(struct node_t));
            new_node->value = value;
            new_node->left = NULL;
            new_node->right = NULL;

            new_node->parent = root;

            root->right = new_node;
        }
        else
        {
            insert(root->right, value);
        }
    }
    else
    {
        if (root->left == NULL)
        {
            struct node_t *new_node = malloc(sizeof(struct node_t));
            new_node->value = value;
            new_node->left = NULL;
            new_node->right = NULL;

            new_node->parent = root;

            root->left = new_node;
        }
        else
        {
            insert(root->left, value);
        }
    }
}

void insert_bst(struct tree_t *tree, int value)
{
    if (tree->root == NULL)
    {
        struct node_t *new_node = malloc(sizeof(struct node_t));
        new_node->value = value;
        new_node->left = NULL;
        new_node->right = NULL;

        new_node->parent = NULL;

        tree->root = new_node;
    }
    else
    {
        insert(tree->root, value);
    }

    tree->size++;
}

void print_spaces(int offset)
{
    for (int i = 0; i < offset; i++)
    {
        printf(" ");
    }
}

int print_bst_tree(struct node_t *stub, int offset)
{
    if (stub == NULL)
    {
        return offset;
    }

    int offset_left = print_bst_tree(stub->left, offset);
    offset = print_bst_tree(stub->right, offset_left + 1);
    print_spaces(offset_left);
    printf("%d\n", stub->value);
    return offset;
}

int height(struct node_t* root) 
{
    if (root == NULL) 
    {
        return 0;
    }
    else 
    {
        int lh = height(root->left);
        int rh = height(root->right);
        if (lh > rh)
        {
            return 1 + lh;
        }
        else
        {
            return 1 + rh;
        }
    }
}

void print_bfs_current_level(struct node_t* root, int level) 
{
    if (root == NULL)
    {
        return;
    }
    if (level == 1)
    {
        printf(" %d ", root->value);
    } 
    else if (level > 1) 
    {
        print_bfs_current_level(root->left, level - 1);
        print_bfs_current_level(root->right, level - 1);
    }

}

void print_bfs(struct node_t* root) 
{
    int h = height(root);
    for (int level = 1; level <= h; level++) 
    {
        print_bfs_current_level(root, level);
    }
}

enum bfs_order {
    PRE, IN, POST
};

void print_dfs(struct node_t* root, enum bfs_order order) 
{
    if (root == NULL) 
    {
        return;
    }
    switch (order)
    {
        case PRE:
        // print the root first
            printf(" %d ", root->value);
        // print the left sub-tree    
            print_dfs(root->left, order);
        // print the right sub-tree    
            print_dfs(root->right, order);
            break;
        case IN:
        // print the left sub-tree    
            print_dfs(root->left, order);
        // print the root first
            printf(" %d ", root->value);
        // print the right sub-tree    
            print_dfs(root->right, order);
            break;
        case POST:
        // print the left sub-tree    
            print_dfs(root->left, order);
        // print the right sub-tree    
            print_dfs(root->right, order);
        // print the root first
            printf(" %d ", root->value);
            break;
    }
}

int main()
{
    struct tree_t tree;
    tree.root = NULL;
    tree.size = 0;

    insert_bst(&tree, 8);
    insert_bst(&tree, 10);
    insert_bst(&tree, 4);
    insert_bst(&tree, 3);
    insert_bst(&tree, 1);
    insert_bst(&tree, 9);
    insert_bst(&tree, 12);
    insert_bst(&tree, 7);

    printf("\n=======================\n");
    print_bst_tree(tree.root, 0);
    printf("\n=======================\n");

    int h = height(tree.root);
    printf("\n height is : %d \n", h);

    printf("\n==== BFS ==============\n");
    print_bfs(tree.root);
    printf("\n=======================\n");

    printf("\n==== DFS PRE-ORDER ====\n");
    print_dfs(tree.root, PRE);
    printf("\n=======================\n");

    printf("\n==== DFS IN-ORDER =====\n");
    print_dfs(tree.root, IN);
    printf("\n=======================\n");

    printf("\n==== DFS POST-ORDER ===\n");
    print_dfs(tree.root, POST);
    printf("\n=======================\n");
}