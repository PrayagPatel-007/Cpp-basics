#include <bits/stdc++.h>
using namespace std;

struct mnode
{
	int mdata;
	struct node *dlink;
	struct mnode *mnext;
};

struct node
{
	int data;
	struct node *next;
};

typedef struct mnode *mlptr;
typedef struct node *lptr;

mlptr mnode_insert(mlptr &ML, int n)
{
	if (ML == NULL)
	{
		ML = new (mnode);
		ML->mdata = n;
		ML->dlink = NULL;
		ML->mnext = NULL;
		return ML;
	}
	mnode_insert(ML->mnext, n);
}

void node_insert(lptr &L, int n)
{
	if (L == NULL)
	{
		L = new (node);
		L->data = n;
		L->next = NULL;
		return;
	}
	node_insert(L->next, n);
}

void print(mlptr ML)
{
	if (ML != NULL)
	{
		cout << "( ";
		cout << ML->mdata << " ";
		lptr p = ML->dlink;
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << ") ";
		print(ML->mnext);
	}
}

int main()
{
	int n, tag;
	mlptr ML = NULL, p;
	lptr L = NULL;
	cin >> n;
	while (n != -2)
	{
		cin >> tag;
		p = mnode_insert(ML, n);
		if (tag == 1)
		{
			cin >> n;
			while (n != -1)
			{
				node_insert(p->dlink, n);
				cin >> n;
			}
		}
		cin >> n;
	}
	print(ML);
	return 0;
}

// 3 1 8 9 -1 4 1 5 -1 7 0 18 0 45 1 6 2 -1 36 0 -2