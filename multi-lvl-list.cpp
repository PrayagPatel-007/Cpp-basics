#include <bits/stdc++.h>
using namespace std;

struct S
{
	int rno;
	struct R *link = NULL;
};

struct C
{
	char cname;
	struct R *link = NULL;
};

union u1
{
	struct S *s;
	struct R *r;
};

union u2
{
	struct C *c;
	struct R *r;
};

struct R
{
	int tag0;
	union u1 snext;
	int tag1;
	union u2 cnext;
};

typedef struct R *rptr;
typedef struct S *sptr;
typedef struct C *cptr;

void insert_s(rptr &s, int n, rptr &t)
{
	if (s == NULL)
	{
		s = new (R);
		s->tag0 = 0;
		s->snext.r = NULL;
		s->tag1 = 0;
		if (t == NULL)
		{
			t = s;
			return;
		}
		t->cnext.r = s;
		return;
	}
	insert_s(s->snext.r, n, t);
}

void null_end(struct S arrs[], int n1, struct C arrc[], int n2)
{
	for (int i = 0; i < n1; i++)
	{
		rptr s = arrs[i].link;
		if (s != NULL)
		{
			while (s->snext.r != NULL)
			{
				s = s->snext.r;
			}
			s->tag0 = 1;
			s->snext.s = &arrs[i];
		}
	}
	for (int i = 0; i < n2; i++)
	{
		rptr s = arrc[i].link;
		if (s != NULL)
		{
			while (s->cnext.r != NULL)
			{
				s = s->cnext.r;
			}
			s->tag1 = 1;
			s->cnext.c = &arrc[i];
		}
	}
}

int print_courses(struct S arrs[], int s, char arr2[])
{
	int i = 0;
	rptr t2 = arrs[s].link;
	while (t2 != NULL)
	{
		rptr t3 = t2;
		while (t3->tag1 == 0)
		{
			t3 = t3->cnext.r;
		}
		arr2[i] = t3->cnext.c->cname;
		i++;
		if (t2->tag0 == 1)
		{
			break;
		}
		t2 = t2->snext.r;
	}
	return i;
}

int print_students(struct C arrc[], char c, int arr1[])
{
	int i = 0;
	rptr t4 = arrc[c - 'A'].link;
	while (t4 != NULL)
	{
		rptr t5 = t4;
		while (t5->tag0 == 0)
		{
			t5 = t5->snext.r;
		}
		arr1[i] = t5->snext.s->rno;
		i++;
		if (t4->tag1 == 1)
		{
			break;
		}
		t4 = t4->cnext.r;
	}
	return i;
}

void printc(char arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}

void printi(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}

int main()
{
	struct S arrs[20];
	struct C arrc[20];
	int arr1[50];
	char arr2[50];
	char c;
	int n;
	cin >> n >> c;
	while (n != -1 || c != '#')
	{
		arrs[n].rno = n;
		arrc[c - 'A'].cname = c;
		rptr &t = arrc[c - 'A'].link;
		if (t != NULL)
		{
			rptr t1 = t;
			while (t1->cnext.r != NULL)
			{
				t1 = t1->cnext.r;
			}
			insert_s(arrs[n].link, n, t1);
		}
		else
		{
			insert_s(arrs[n].link, n, arrc[c - 'A'].link);
		}
		cin >> n >> c;
	}
	null_end(arrs, 20, arrc, 20);
	cin >> n;
	int i = print_courses(arrs, n, arr2);
	sort(arr2, arr2 + i);
	printc(arr2, i);
	cin >> n;
	i = print_courses(arrs, n, arr2);
	sort(arr2, arr2 + i);
	printc(arr2, i);
	cin >> c;
	i = print_students(arrc, c, arr1);
	sort(arr1, arr1 + i);
	printi(arr1, i);
	cin >> c;
	i = print_students(arrc, c, arr1);
	sort(arr1, arr1 + i);
	printi(arr1, i);
	return 0;
}
