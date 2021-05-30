#include <iostream>
using namespace std;


struct Node
{
    int Data;
    Node* LeftNode;
    Node* RightNode;
    Node* Rod;

    Node* GetRod() {
        return Rod;
    }
    Node* GetLeft() {
        return LeftNode;
    }
    Node* GetRight() {
        return RightNode;
    }
};


void Add(int aData, Node*& aNode, Node*& Rod)
{
    if (!aNode)
    {
        aNode = new Node;
        aNode->Data = aData;
        aNode->Rod = Rod;
        aNode->LeftNode = 0;
        aNode->RightNode = 0;
        return;
    }
    else
        if (aNode->Data > aData)
        {
            Add(aData, aNode->LeftNode, aNode);
        }
        else
        {
            Add(aData, aNode->RightNode, aNode);
        };
}

void DropTree(Node* aNode)
{
    if (!aNode) return;
    DropTree(aNode->LeftNode);
    DropTree(aNode->RightNode);
    delete aNode;
    return;
}


void list(Node* aNode) {
    if (aNode == 0) return;
    if (aNode->LeftNode == NULL && aNode->RightNode == NULL) {
        cout << aNode->Data << endl;
        return;
    }
    list(aNode->LeftNode);
    list(aNode->RightNode);
}

int findLevel(Node* root, int k, int level)
{

    if (root == NULL)
        return -1;
    if (root->Data == k)
        return level;

    int l = findLevel(root->LeftNode, k, level + 1);
    return (l != -1) ? l : findLevel(root->RightNode, k, level + 1);
}

Node* findDistUtil(Node* root, int n1, int n2, int& d1, int& d2, int& dist, int lvl) {

    if (root == NULL) return NULL;
    if (root->Data == n1)
    {
        d1 = lvl;
        return root;
    }
    if (root->Data == n2)
    {
        d2 = lvl;
        return root;
    }

    Node* left_l = findDistUtil(root->LeftNode, n1, n2,
        d1, d2, dist, lvl + 1);
    Node* right_l = findDistUtil(root->RightNode, n1, n2,
        d1, d2, dist, lvl + 1);

    if (left_l && right_l)
    {
        dist = d1 + d2 - 2 * lvl;
        return root;
    }

    return (left_l != NULL) ? left_l : right_l;
}


int search(Node* aNode, int one, int two) {
    int d1 = -1, d2 = -1, dist;
    Node* lca = findDistUtil(aNode, one, two, d1, d2, dist, 1);

    if (d1 != -1 && d2 != -1)
        return dist;
    if (d1 != -1)
    {
        dist = findLevel(lca, two, 0);
        return dist;
    }

    if (d2 != -1)
    {
        dist = findLevel(lca, one, 0);
        return dist;
    }

    return -1;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    Node* Root = 0;

    int a, b;
    int s[] = {6,3,2,8,4,1,5,7,9};


    for (int i = 0; s[i]; i++)
    {
        Add(s[i], Root, Root);
    }
    
    cout << "Напишите между какими листами вам нужен путь" << endl;
    cout << "Введите первый лист" << endl;
    cin >> a;
    cout << "Введите второй лист" << endl;
    cin >> b;
    cout << "Минимальный путь" << endl;
    cout << search(Root, a, b) << " ребра" << endl;
    DropTree(Root);

    cin.get();
    return 0;
}
