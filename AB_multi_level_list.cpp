#include <bits/stdc++.h>
using namespace std;

union u
{
	char c;
	struct mnode *p;
};

struct mnode
{
	int tag;
	union u element;
	struct mnode *next;
};

typedef struct mnode *mlptr;

void create_mll(mlptr &ML)
{
	char c;
	cin >> c;
	if (c == '#')
	{
		return;
	}
	if (c != '#')
	{
		if (c == '{')
		{
			ML = new (mnode);
			ML->tag = 1;
			ML->element.p = NULL;
			ML->next = NULL;
			create_mll(ML->element.p);
			create_mll(ML->next);
		}
		else if (c == '}')
		{
			return;
		}
		else
		{
			ML = new (mnode);
			ML->tag = 0;
			ML->element.c = c;
			ML->next = NULL;
			create_mll(ML->next);
		}
	}
}

void print(mlptr ML, char arr[], int index)
{
	if (ML != NULL)
	{
		if (ML->tag == 1)
		{
			cout << arr[index]<<" ";
			print(ML->element.p, arr, index+2);
			cout << arr[index+1]<<" ";
			index+=2;
		}
		else
		{
			cout << ML->element.c << " ";
		}
		print(ML->next, arr, index);
	}
}

int main()
{
	mlptr ML = NULL;
	char arr[8] = {'{', '}', '[', ']', '(', ')', '<', '>'};
	create_mll(ML);
	print(ML, arr, 0);
	return 0;
}


// { A B { C D E } F { G { H I J } K } L M } #