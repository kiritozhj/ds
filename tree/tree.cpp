#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct tree{
	char data;
	struct tree *lchild,*rchild;
};

void create(tree **t){
	char c;
	scanf("%c",&c);
	if(c=='#') *t=nullptr;
	else{
		*t=(tree*)malloc(sizeof(tree));
		(*t)->data=c;
		create(&((*t)->lchild));
		create(&((*t)->rchild));
	}
}

void floor_prt(tree *t){  //层次遍历
	if(t==nullptr) return;
	queue<tree*> a;
	a.push(t);
	while(!a.empty()){
		printf("%c",a.front()->data);
		if(a.front()->lchild)
			a.push(a.front()->lchild);
		if(a.front()->rchild)
			a.push(a.front()->rchild);
		a.pop();
	}
}

void pre_prt_1(tree* t){  //前序递归遍历
	if(t==nullptr) return;
	printf("%c",t->data);
	pre_prt_1(t->lchild);
	pre_prt_1(t->rchild);
}

void pre_prt_2(tree* t){ //前序非递归遍历
	if(t==nullptr) return;
	stack<tree*> a;
	tree* temp=t;
	while(temp||!a.empty()){
		while(temp){
			printf("%c",temp->data);
			a.push(temp);
			temp=temp->lchild;
		}
		if(!a.empty()){
			temp=a.top();
			temp=temp->rchild;
			a.pop();
		}
	}
}

void in_prt_1(tree* t){  //中序递归遍历
	if(t==nullptr) return;
	in_prt_1(t->lchild);
	printf("%c",t->data);
	in_prt_1(t->rchild);
}

void in_prt_2(tree* t){  //中序非递归遍历
	if(t==nullptr) return;
	stack<tree*> a;
	tree* temp=t;
	while(temp||!a.empty()){
		while(temp){
			a.push(temp);
			temp=temp->lchild;
		}
		temp=a.top();
		printf("%c",temp->data);
		if(!a.empty()){
			a.pop();
			temp=temp->rchild;
		}
	}
}

void post_prt_1(tree* t){  //后序递归遍历
	if(t==nullptr) return;
	post_prt_1(t->lchild);
	post_prt_1(t->rchild);
	printf("%c",t->data);
}

void post_prt_2(tree* t){  //后续非递归遍历
	if(t==nullptr) return;
	stack<tree*> a;
	tree *temp=t,*r=nullptr;
	while(temp||!a.empty()){
		//从根节点到最下角的左子树都入栈
		if(temp){
			a.push(temp);
			temp=temp->lchild;
		}
		//返回栈顶的两种情况
		else{
			temp=a.top();//取栈顶
			//右子树还未访问，而且右子树不空，第一次栈顶
			if(temp->rchild&&temp->rchild!=r) temp=temp->rchild;
			//右子树已经访问或为空，接下来出栈访问节点
			else{
				temp=a.top();
				a.pop();
				printf("%c",temp->data);
				r=temp;
				temp=nullptr;
			}
		}
	}
}

void post_prt_3(tree* t){  //后序非递归遍历
	//访问一个节点的两种情况：1.它的左右子树均为空 2.它的左右子树均被访问过了
	stack<tree*> a;
	tree* temp=t,*pre=nullptr;
	a.push(temp);
	while(!a.empty()){
		temp=a.top();
		if((temp->lchild==nullptr&&temp->rchild==nullptr)||
			(pre!=nullptr&&(pre==temp->rchild))){
			printf("%c",temp->data);
			a.pop();
			pre=temp;
		}else{
			if(temp->rchild)
				a.push(temp->rchild);
			if(temp->lchild)
				a.push(temp->lchild);
		}
	}
}

int main(int argc, char const *argv[])
{
	tree* t=(tree*)malloc(sizeof(tree));
	create(&t);
	post_prt_1(t);
	return 0;
}

