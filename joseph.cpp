/*************************************************************************
    > File Name: joseph.cpp
    > Author: liuwei
    > Mail: 271551048@qq.com 
    > Created Time: 2015年09月01日 星期二 01时15分00秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

typedef struct node
{
	int data;
	struct node *pNext;
}Node, *pNode;

//创建含有n个节点的循环单链表
pNode CreateCircleList(int n)
{
	int i = 1;
	pNode pHead = new Node;  
	pNode p = pHead;
	pNode s = NULL;

	if(0 != n)
	{
		while(i <= n)
		{
			s = new Node;	
			s->data = i++;
			p->pNext = s;
			p = s;
		}
		s->pNext = pHead->pNext;
	}

	delete pHead;
	return s->pNext;
}

int main() 
{
	int n = 41;  //Joseph问题中一共41个人
	int m = 3;   //Joseph问题中每隔3个人消灭一个人

	m %= n;
	pNode p = CreateCircleList(41);

	while(p->pNext != p)
	{
		for(int i = 1; i < m - 1; i++)
			p = p->pNext;
		cout << p->pNext->data << "->";

		pNode temp = p->pNext;
		p->pNext = temp->pNext;
		delete temp;

		p = p->pNext;
	}
	cout << p->data << endl;
	getchar();
	return 0;
}
