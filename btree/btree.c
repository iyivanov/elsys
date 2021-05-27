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

void print_bst_internal(struct node_t *root, int detailed, int level)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d at level %d\n", root->value, level);
    if (detailed)
    {
        if (root->left != NULL)
        {
            printf("%d at level %d has a left child %d\n", root->value, level, root->left->value);
        }
        else
        {
            printf("%d at level %d has no left child\n", root->value, level);
        }
        if (root->right != NULL)
        {
            printf("%d at level %d has a right child %d\n", root->value, level, root->right->value);
        }
        else
        {
            printf("%d at level %d has no right child\n", root->value, level);
        }
    }

    if (root->left != NULL)
    {
        print_bst_internal(root->left, detailed, level + 1);
    }
    if (root->right != NULL)
    {
        print_bst_internal(root->right, detailed, level + 1);
    }
}

void print_bst(struct node_t *root, int detailed)
{
    print_bst_internal(root, detailed, 0);
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

int search(struct node_t *root, int search_value)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->value == search_value)
    {
        return 1;
    }

    if (search_value > root->value)
    {
        return search(root->right, search_value);
    }
    if (search_value < root->value)
    {
        return search(root->left, search_value);
    }
    return 0;
}

int search_bst(struct tree_t *tree, int search_value)
{
    return search(tree->root, search_value);
}

void populate_bst_arr_dfs(struct node_t *node, int *arr, int *index)
{
    // go left
    if (node->left != NULL)
    {
        populate_bst_arr_dfs(node->left, arr, index);
    }

    // use the current value
    arr[*index] = node->value;
    *index = *index + 1;

    // go right
    if (node->right != NULL)
    {
        populate_bst_arr_dfs(node->right, arr, index);
    }
}

int *get_sorted_array(struct tree_t *tree)
{
    int *arr = malloc(sizeof(int) * tree->size);
    int index = 0;

    populate_bst_arr_dfs(tree->root, arr, &index);

    return arr;
}

struct node_t *construct_bst_node_from_sorted_array(int *arr, int start, int end, struct node_t *parent)
{
    if (start > end)
    {
        return NULL;
    }

    int midIndex = (start + end) / 2;
    int midValue = arr[midIndex];

    struct node_t *new_node = malloc(sizeof(struct node_t));
    new_node->value = midValue;
    new_node->parent = parent;

    new_node->left = construct_bst_node_from_sorted_array(arr, start, midIndex - 1, new_node);
    new_node->right = construct_bst_node_from_sorted_array(arr, midIndex + 1, end, new_node);

    return new_node;
}

struct tree_t *construct_bst_from_sorted_array(int *arr, int size)
{
    struct tree_t *tree = malloc(sizeof(struct tree_t));

    tree->root = construct_bst_node_from_sorted_array(arr, 0, size - 1, NULL);
    tree->size = size;

    return tree;
}

struct node_t *find(struct node_t *root, int search_value)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->value == search_value)
    {
        return root;
    }

    if (search_value > root->value)
    {
        return find(root->right, search_value);
    }
    if (search_value < root->value)
    {
        return find(root->left, search_value);
    }
    return NULL;
}

struct node_t *find_bst(struct tree_t *tree, int search_value)
{
    return find(tree->root, search_value);
}

void remove_bst(struct tree_t *tree, struct node_t *node)
{
    struct node_t *parent = node->parent;

    if (node->left == NULL && node->right == NULL)
    {
        // node has no children - simply delete it
        if (parent != NULL)
        {
            if (parent->right == node)
            {
                parent->right = NULL;
            }
            else
            {
                parent->left = NULL;
            }
        }
        else
        {
            tree->root = NULL;
        }

        free(node);
        tree->size--;
    }
    else if (node->left != NULL && node->right != NULL)
    {
        // node has two children
        // pick it's left or right child, swap the two nodes, recursively call the function
        // eventually will lead to one of the two other cases

        int temp = node->value;
        node->value = node->right->value;
        node->right->value = temp;

        remove_bst(tree, node->right);
    }
    else
    {
        // node has one child
        // swap with the child & remove the node
        struct node_t *child = node->left;
        if (child == NULL)
        {
            child = node->right;
        }

        if (parent != NULL)
        {
            if (parent->right == node)
            {
                parent->right = child;
            }
            else
            {
                parent->left = child;
            }
        }
        else
        {
            tree->root = child;
        }

        child->parent = parent;

        free(node);
        tree->size--;
    }
}

void change_bst_values(struct node_t *node1, struct node_t *node2)
{
    node1->value = node1->value + node2->value;
    node2->value = node1->value - node2->value;
    node1->value = node1->value - node2->value;
}

struct node_t *find_node(struct node_t *root, struct node_t *node)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root == node)
    {
        return root;
    }

    struct node_t *result = find_node(root->left, node);

    if (result == NULL)
    {
        result = find_node(root->right, node);
    }
    return result;
}

struct node_t *find_node_parent(struct node_t *root, struct node_t *node)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->left == node || root->right == node)
    {
        return root;
    }

    struct node_t *result = find_node_parent(root->left, node);

    if (result == NULL)
    {
        result = find_node_parent(root->right, node);
    }
    return result;
}

void change_bst(struct tree_t *tree, struct node_t *node1, struct node_t *node2)
{
    if (node1 == node2)
    {
        return;
    }
    struct node_t **current1p = NULL;
    struct node_t *current1 = find_node_parent(tree->root, node1);
    if (current1 == NULL)
    {
        if (tree->root == node1)
        {
            current1p = &(tree->root);
        }
    }
    else
    {
        current1p = &(current1->left);
        if (current1->right == node1)
        {
            current1p = &(current1->right);
        }
    }
    struct node_t **current2p = NULL;
    struct node_t *current2 = find_node_parent(tree->root, node2);
    if (current2 == NULL)
    {
        if (tree->root == node2)
        {
            current2p = &(tree->root);
        }
    }
    else
    {
        current2p = &(current2->left);
        if (current2->right == node2)
        {
            current2p = &(current2->right);
        }
    }
    struct node_t *current_left1 = node1->left;
    struct node_t *current_right1 = node1->right;
    struct node_t *current_left2 = node2->left;
    struct node_t *current_right2 = node2->right;
    if (node1->left == node2)
    {
        *current1p = node2;
        node1->right = current_right2;
        node2->right = current_right1;
        node1->left = current_left2;
        node2->left = node1;
        node1->parent = current2;
        node2->parent = current1;
    }
    else if (node1->right == node2)
    {
        *current1p = node2;
        node1->left = current_left2;
        node2->left = current_left1;
        node1->right = current_right2;
        node2->right = node1;
        node1->parent = current2;
        node2->parent = current1;
    }
    else if (node2->left == node1)
    {
        *current2p = node1;
        node2->right = current_right1;
        node1->right = current_right2;
        node2->left = current_left1;
        node1->left = node2;
        node2->parent = current1;
        node1->parent = current2;
    }
    else if (node2->right == node1)
    {
        *current2p = node1;
        node2->left = current_left1;
        node1->left = current_left2;
        node2->right = current_right1;
        node1->right = node2;
        node2->parent = current1;
        node1->parent = current2;
    }
    else
    {
        *current1p = node2;
        *current2p = node1;
        node1->left = current_left2;
        node1->right = current_right2;
        node1->parent = current2;
        node2->parent = current1;
        node2->left = current_left1;
        node2->right = current_right1;
    }
}

int main()
{
    struct tree_t tree;
    tree.root = NULL;
    tree.size = 0;

    insert_bst(&tree, 1);
    insert_bst(&tree, 3);
    insert_bst(&tree, 4);
    insert_bst(&tree, 8);
    insert_bst(&tree, 9);
    insert_bst(&tree, 10);
    insert_bst(&tree, 12);

    print_bst(tree.root, 0);
    printf("\n=======================\n");
    print_bst_tree(tree.root, 0);
    printf("\n=======================\n");

    int *arr = get_sorted_array(&tree);
    for (int i = 0; i < tree.size; i++)
    {
        printf("%d\n", arr[i]);
    }

    struct tree_t *balanced = construct_bst_from_sorted_array(arr, tree.size);
    print_bst(balanced->root, 0);

    printf("\n+++++++++++++++++\n");
    print_bst_tree(balanced->root, 0);
    printf("\n+++++++++++++++++\n");

    struct node_t *node1 = find_bst(balanced, 3);
    struct node_t *node2 = find_bst(balanced, 8);
    change_bst(balanced, node1, node2);

    printf("\n+++++       +++++\n");
    print_bst_tree(balanced->root, 0);
    printf("\n+++++ ^ ^ ^ ^ ++++\n");

    /*
    printf("trying to remove element 4\n");
    remove_bst(balanced, find_bst(balanced, 4));
    print_bst(balanced->root, 0);

    printf("trying to remove element 3\n");
    remove_bst(balanced, find_bst(balanced, 3));
    print_bst(balanced->root, 0);

    printf("trying to remove element 10\n");
    remove_bst(balanced, find_bst(balanced, 10));
    print_bst(balanced->root, 0);
*/
    return 0;
}
