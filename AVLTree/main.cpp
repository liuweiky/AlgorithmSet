#include <cstdio>
#include <algorithm>

using namespace std;

//int data[] = {88, 70, 61, 96, 120};
int data[] = {88, 70, 61, 96, 120, 90, 65};

struct node
{
    int data, height;
    node* lc;
    node* rc;
    node() {lc = rc = NULL; height = 1;}
};

int get_height(node* r)
{
    if (r == NULL)
        return 0;
    return r->height;
}

int get_balance_factor(node* r)
{
    return get_height(r->lc) - get_height(r->rc);
}

void update_height(node* r)
{
    r->height = max(get_height(r->lc), get_height(r->rc)) + 1;
}

void L(node* & root)
{
    node* temp = root->rc;
    root->rc = temp->lc;
    temp->lc = root;
    update_height(root);
    update_height(temp);
    root = temp;
}

void R(node* & root)
{
    node* temp = root->lc;
    root->lc = temp->rc;
    temp->rc = root;
    update_height(root);
    update_height(temp);
    root = temp;
}

node* create_node(int data)
{
    node* n = new node;
    n->data = data;
    return n;
}

void insert_avl(node* & root, int data)
{
    if (root == NULL)
    {
        root = create_node(data);
        return;
    }
    if (data < root->data)
    {
        insert_avl(root->lc, data);
        update_height(root);
        if (get_balance_factor(root) == 2)
        {
            if (get_balance_factor(root->lc) == 1)
                R(root);
            else if (get_balance_factor(root->lc) == -1)
            {
                L(root->lc);
                R(root);
            }
        }
    }
    else
    {
        insert_avl(root->rc, data);
        update_height(root);
        if (get_balance_factor(root) == -2)
        {
            if (get_balance_factor(root->rc) == -1)
                L(root);
            else if (get_balance_factor(root->rc) == 1)
            {
                R(root->rc);
                L(root);
            }
        }
    }
}

node* create_avl()
{
    node* root = NULL;
    int sz = sizeof(data) / sizeof(int);

    for (int i = 0; i < sz; i++)
        insert_avl(root, data[i]);
    return root;
}

int main()
{
    node* r = create_avl();
    printf("%d", r->data);
    return 0;
}
