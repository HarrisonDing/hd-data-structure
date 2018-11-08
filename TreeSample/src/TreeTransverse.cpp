#include<iostream>
#include<queue>
#include<stack>
using namespace std;

//��������������
typedef struct BiTNode {
	char data;
	struct BiTNode *lchild, *rchild;      //���Һ���
} BiTNode, *BiTree;

//�������������������
//BiTree *CreateBiTree()     //���ؽ��ָ������
//void CreateBiTree(BiTree &root)      //�������͵Ĳ���
void CreateBiTree(BiTNode **root) {    //����ָ����Ϊ��������
	char ch; //Ҫ���������
	scanf("\n%c", &ch);
	//cin>>ch;
	if (ch == '#')
		*root = NULL;
	else {
		*root = (BiTNode *) malloc(sizeof(BiTNode));
		(*root)->data = ch;
		cout << "������%c�����ӣ�" << ch << endl;
		CreateBiTree(&((*root)->lchild));
		cout << "������%c���Һ��ӣ�" << ch << endl;
		CreateBiTree(&((*root)->rchild));
	}
}

//ǰ��������㷨����
void PreOrder(BiTNode *root) {
	if (root == NULL)
		return;
	cout << root->data << endl; //�������
	PreOrder(root->lchild); //�ݹ���ã�ǰ�����������
	PreOrder(root->rchild); //�ݹ���ã�ǰ�����������
}

//����������㷨����
void InOrder(BiTNode *root) {
	if (root == NULL)
		return;
	InOrder(root->lchild); //�ݹ���ã�ǰ�����������
	cout << root->data << endl; //�������
	InOrder(root->rchild); //�ݹ���ã�ǰ�����������
}

//����������㷨����
void PostOrder(BiTNode *root) {
	if (root == NULL)
		return;
	PostOrder(root->lchild);      //�ݹ���ã�ǰ�����������
	PostOrder(root->rchild);      //�ݹ���ã�ǰ�����������
	cout << root->data << endl;    //�������
}

/*
 �������ķǵݹ�ǰ�������ǰ�����˼�룺���ø���ջ��ֻҪջ��Ϊ�գ��Ϳ���������������
 ÿ�ε���һ����㣬�ǵð��������ҽ�㶼��ջ���ǵ��������Ƚ�ջ���������Ա�֤��������ջ���ܴ��������������档
 */
void PreOrder_Nonrecursive(BiTree T) {    //��������ķǵݹ�
	if (!T)
		return;

	stack<BiTree> s;
	s.push(T);

	while (!s.empty()) {
		BiTree temp = s.top();
		cout << temp->data << " ";
		s.pop();
		if (temp->rchild)
			s.push(temp->rchild);
		if (temp->lchild)
			s.push(temp->lchild);
	}
}

void PreOrder_Nonrecursive1(BiTree T) {     //��������ķǵݹ�
	if (!T)
		return;
	stack<BiTree> s;
	BiTree curr = T;
	while (curr != NULL || !s.empty()) {
		while (curr != NULL) {
			cout << curr->data << "  ";
			s.push(curr);
			curr = curr->lchild;
		}
		if (!s.empty()) {
			curr = s.top();
			s.pop();
			curr = curr->rchild;
		}
	}
}

void PreOrder_Nonrecursive2(BiTree T) {    //��������ķǵݹ�
	if (!T)
		return;

	stack<BiTree> s;
	while (T)          // �������ϵĽڵ�ȫ��ѹ�뵽ջ��
	{
		s.push(T);
		cout << T->data << "  ";
		T = T->lchild;
	}

	while (!s.empty()) {
		BiTree temp = s.top()->rchild;  // ջ��Ԫ�ص�������
		s.pop();                        // ����ջ��Ԫ��
		while (temp)          // ջ��Ԫ�ش��������������������ͬ�����������·�
		{
			cout << temp->data << "  ";
			s.push(temp);
			temp = temp->lchild;
		}
	}
}

void InOrderTraverse1(BiTree T) {  // ��������ķǵݹ�
	if (!T)
		return;
	BiTree curr = T;    // ָ��ǰҪ���Ľڵ�
	stack<BiTree> s;
	while (curr != NULL || !s.empty()) {
		while (curr != NULL) {
			s.push(curr);
			curr = curr->lchild;
		}    //while
		if (!s.empty()) {
			curr = s.top();
			s.pop();
			cout << curr->data << "  ";
			curr = curr->rchild;
		}
	}
}

void InOrderTraverse(BiTree T) {  // ��������ķǵݹ�
	if (!T)
		return;
	stack<BiTree> s;
	BiTree curr = T->lchild;    // ָ��ǰҪ���Ľڵ�
	s.push(T);
	while (curr != NULL || !s.empty()) {
		while (curr != NULL)    // һֱ������
		{
			s.push(curr);
			curr = curr->lchild;
		}
		curr = s.top();
		s.pop();
		cout << curr->data << "  ";
		curr = curr->rchild;
	}
}

void PostOrder_Nonrecursive1(BiTree T) {  // ��������ķǵݹ�
	stack<BiTree> S;
	BiTree curr = T;           // ָ��ǰҪ���Ľڵ�
	BiTree previsited = NULL;    // ָ��ǰһ�������ʵĽڵ�
	while (curr != NULL || !S.empty())  // ջ��ʱ����
	{
		while (curr != NULL)            // һֱ������ֱ��Ϊ��
		{
			S.push(curr);
			curr = curr->lchild;
		}
		curr = S.top();
		// ��ǰ�ڵ���Һ������Ϊ�ջ����Ѿ������ʣ�����ʵ�ǰ�ڵ�
		if (curr->rchild == NULL || curr->rchild == previsited) {
			cout << curr->data << "  ";
			previsited = curr;
			S.pop();
			curr = NULL;
		} else
			curr = curr->rchild;      // ��������Һ���
	}
}

void PostOrder_Nonrecursive(BiTree T) {  // ��������ķǵݹ�     ˫ջ��
	stack<BiTree> s1, s2;
	BiTree curr;           // ָ��ǰҪ���Ľڵ�
	s1.push(T);
	while (!s1.empty())  // ջ��ʱ����
	{
		curr = s1.top();
		s1.pop();
		s2.push(curr);
		if (curr->lchild)
			s1.push(curr->lchild);
		if (curr->rchild)
			s1.push(curr->rchild);
	}
	while (!s2.empty()) {
	cout << s2.top()->data << endl;
		s2.pop();
	}
}

int visit(BiTree T) {
	if (T) {
	cout << T->data << endl;
		return 1;
	} else
		return 0;
}

void LeverTraverse(BiTree T) {   //����һ���ǵݹ��α���������
	queue<BiTree> Q;
	BiTree p;
	p = T;
	if (visit(p) == 1)
		Q.push(p);
	while (!Q.empty()) {
		p = Q.front();
		Q.pop();
		if (visit(p->lchild) == 1)
			Q.push(p->lchild);
		if (visit(p->rchild) == 1)
			Q.push(p->rchild);
	}
}
void LevelOrder(BiTree BT) {     //���������ǵݹ��α���������
	BiTNode *queue[10];     //���������ʮ���ռ�
	if (BT == NULL)
		return;
	int front, rear;
	front = rear = 0;
	queue[rear++] = BT;
	while (front != rear)     //�����βָ�벻���ڶ�ͷָ��ʱ
	{
		cout << queue[front]->data << "  ";  //����������
		if (queue[front]->lchild != NULL)  //�����׽�������ָ�������
		{
			queue[rear] = queue[front]->lchild;
			rear++;    //��βָ�����һλ
		}
		if (queue[front]->rchild != NULL) {
			queue[rear] = queue[front]->rchild;    //�����׽����Һ���ָ�������
			rear++;   //��βָ�����һλ
		}
		front++;    //��ͷָ�����һλ
	}
}

int depth(BiTNode *T)   //�������
		{
	if (!T)
		return 0;
	int d1, d2;
	d1 = depth(T->lchild);
	d2 = depth(T->rchild);
	return (d1 > d2 ? d1 : d2) + 1;
	//return (depth(T->lchild)>depth(T->rchild)?depth(T->lchild):depth(T->rchild))+1;
}
int CountNode(BiTNode *T) {
	if (T == NULL)
		return 0;
	return 1 + CountNode(T->lchild) + CountNode(T->rchild);
}

int main(void) {
	BiTNode *root = NULL; //����һ�������
	int flag = 1, k;
	cout << "                     ������ʵ�ֶ������Ļ���������" << endl;
	cout << "���Խ��н������������ݹ��������򡢺���������ǵݹ���������������ǵݹ��������Ȳ�����" << endl;

	while (flag) {
		cout << "\n" << endl;
		cout << "|---------------------------------------|" << endl;
		cout << "|              �������Ļ�����������:           |" << endl;
		cout << "|              0.����������                              |" << endl;
		cout << "|              1.�ݹ��������                          |" << endl;
		cout << "|              2.�ݹ��������                          |" << endl;
		cout << "|              3.�ݹ�������                          |" << endl;
		cout << "|              4.�ǵݹ��������                      |" << endl;
		cout << "|              5.�ǵݹ��������                      |" << endl;
		cout << "|              6.�ǵݹ�������                      |" << endl;
		cout << "|              7.�ǵݹ�������                      |" << endl;
		cout << "|              8.�����������                          |" << endl;
		cout << "|              9.�������Ľ�����                  |" << endl;
		cout << "|             10.�˳�����                                  |" << endl;
		cout << "|---------------------------------------|" << endl;
		cout << "                        ��ѡ���ܣ�" << endl;
		scanf("%d", &k);
		switch (k) {
		case 0:
		cout << "�뽨��������������������ĸ��ڵ㣺" << endl;
			CreateBiTree(&root);
			break;
		case 1:
			if (root) {
			cout << "�ݹ���������������Ľ��Ϊ��" << endl;
				PreOrder(root);
			cout << "\n" << endl;
			} else
			cout << "          ������Ϊ�գ�\n" << endl;
			break;
		case 2:
			if (root) {
			cout << "�ݹ���������������Ľ��Ϊ��" << endl;
				InOrder(root);
			cout << "\n" << endl;
			} else
			cout << "          ������Ϊ�գ�\n" << endl;
			break;
		case 3:
			if (root) {
			cout << "�ݹ��������������Ľ��Ϊ��" << endl;
				PostOrder(root);
			cout << "\n" << endl;
			} else
			cout << "          ������Ϊ�գ�\n" << endl;
			break;
		case 4:
			if (root) {
			cout << "�ǵݹ����������������" << endl;
				PreOrder_Nonrecursive1(root);
			cout << "\n" << endl;
			} else
			cout << "          ������Ϊ�գ�\n" << endl;
			break;
		case 5:
			if (root) {
			cout << "�ǵݹ����������������" << endl;
				InOrderTraverse1(root);
			cout << "\n" << endl;
			} else
			cout << "          ������Ϊ�գ�\n" << endl;
			break;
		case 6:
			if (root) {
			cout << "�ǵݹ���������������" << endl;
				PostOrder_Nonrecursive(root);
			cout << "\n" << endl;
			} else
			cout << "          ������Ϊ�գ�\n" << endl;
			break;
		case 7:
			if (root) {
			cout << "�ǵݹ���������������" << endl;
				//LeverTraverse(root);
				LevelOrder(root);
			cout << "\n" << endl;
			} else
			cout << "          ������Ϊ�գ�\n" << endl;
			break;
		case 8:
			if (root)
			cout << "��ö����������Ϊ��" << depth(root) << endl;
			else
		cout << "          ������Ϊ�գ�\n" << endl;
			break;
		case 9:
			if (root)
			cout << "��ö������Ľ�����Ϊ��" << CountNode(root) << endl;
			else
		cout << "          ������Ϊ�գ�\n" << endl;
			break;
		default:
			flag = 0;
		cout << "�������н�������������˳���\n" << endl;
		}
	}
system("pause");
	return 0;
}
