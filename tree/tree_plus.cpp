#include<iostream>
#include<stack>
#include<queue>
using namespace std;
typedef struct BTNode{
    struct BTNode *lchild,*rchild;
    char data;
    int ltag,rtag;
}BTNode;
const int N=20;

BTNode* pre_init(){
    char c;
    scanf("%c",&c);
    if(c=='#') return NULL;
    BTNode* root=new BTNode;
    root->data=c;
    root->lchild=pre_init();
    root->rchild=pre_init();
    return root;
}
BTNode* pre_in_init_1(char preod[],char inod[],int n){
    if(n==0) return NULL;
    BTNode* p=new BTNode;
    p->data=preod[0];
    char lpreod[N],rpreod[N],linod[N],rinod[N];
    int n1=0,n2=0;
    for(int i=0;i<n;++i){
        if(i<=n1&&inod[i]!=p->data)
            linod[n1++]=inod[i];
        else if(inod[i]!=preod[0])
            rinod[n2++]=inod[i];
    }
    int m1=0,m2=0;
    for(int i=1;i<n;++i){
        if(i<n1+1)
            lpreod[m1++]=preod[i];
        else
            rpreod[m2++]=preod[i];
    }
    p->lchild=pre_in_init_1(lpreod,linod,n1);
    p->rchild=pre_in_init_1(rpreod,rinod,n2);
    return p;
}
BTNode* pre_in_init_2(char preod[],char inod[],int l1,int r1,int l2,int r2){
    BTNode* p=new BTNode;
    p->data=preod[l1];
    int i;
    for(i=l2;inod[i]!=p->data;++i);
    int llen=i-l2,rlen=r2-i;
    if(llen)
        p->lchild=pre_in_init_2(preod,inod,l1+1,l1+llen,l2,l2+llen-1);
    else
        p->lchild=NULL;
    if(rlen)
        p->rchild=pre_in_init_2(preod,inod,r1-rlen+1,r1,r2-rlen+1,r2);
    else
        p->rchild=NULL;
    return p;
}
BTNode* post_in_init_1(char postod[],char inod[],int n){
    if(n==0) return NULL;
    BTNode* p=new BTNode;
    p->data=postod[n-1];
    char linod[N],rinod[N],lpostod[N],rpostod[N];
    int n1=0,n2=0;
    for(int i=0;i<n;++i){
        if(i<=n1&&inod[i]!=p->data)
            linod[n1++]=inod[i];
        else if(inod[i]!=postod[n-1])
            rinod[n2++]=inod[i];
    }
    int m1=0,m2=0;
    for(int i=0;i<n-1;++i){
        if(i<n1)
            lpostod[m1++]=postod[i];
        else
            rpostod[m2++]=postod[i];
    }
    p->lchild=post_in_init_1(linod,lpostod,n1);
    p->rchild=post_in_init_1(rinod,rpostod,n2);
    return p;
}
BTNode* post_in_init_2(char postod[],char inod[],int l1,int r1,int l2,int r2){
    BTNode* p=new BTNode;
    p->data=postod[r1];
    int i;
    for(i=l2;inod[i]!=p->data;++i);
    int llen=i-l2,rlen=r2-i;
    if(llen)
        p->lchild=post_in_init_2(postod,inod,l1,l1+llen-1,l2,l2+llen-1);
    else
        p->lchild=NULL;
    if(rlen)
        p->rchild=post_in_init_2(postod,inod,r1-rlen,r1-1,r2-rlen+1,r2);
    else
        p->rchild=NULL;
    return p;
}
BTNode* level_in_init(char levelod[],char inod[],int levelsize,int l,int r){
    if(levelsize==0) return NULL;
    BTNode* p=new BTNode;
    p->data=levelod[0];
    int k,i,j;
    for(k=l;k<=r;++k)
        if(levelod[0]==inod[k]) 
            break;
    char llevelod[N],rlevelod[N];
    int m=0,n=0;
    for(i=1;i<levelsize;++i){
        bool isLeft=false;
        for(j=l;j<k;++j){
            if(levelod[i]==inod[j]){
                isLeft=true;
                break;
            }
        }
        if(isLeft){
            llevelod[m++]=levelod[i];
        }
        else
            rlevelod[n++]=levelod[i];
    }
    p->lchild=level_in_init(llevelod,inod,m,l,k-1);
    p->rchild=level_in_init(rlevelod,inod,n,k+1,r);
    return p;
}
void level_prt(BTNode* p){
    if(!p) return;
    queue<BTNode*> q;
    q.push(p);
    while(!q.empty()){
        p=q.front();
        printf("%c",p->data);;
        if(p->lchild)
            q.push(p->lchild);
        if(p->rchild)
            q.push(p->rchild);
        q.pop();
    }
}
void pre_prt_r(BTNode* p){
    if(p){
        printf("%c",p->data);
        pre_prt_r(p->lchild);
        pre_prt_r(p->rchild);
    }
}
void pre_prt(BTNode* p){
    stack<BTNode*> s;
    while(p||!s.empty()){
        while(p){
            printf("%c",p->data);
            s.push(p);
            p=p->lchild;
        }
        if(!s.empty()){
            p=s.top()->rchild;
            s.pop();
        }
    }
}
void pre_prt_2(BTNode* p){
    stack<BTNode*> s;
    while(p||!s.empty()){
        if(p){
            printf("%c",p->data);
            s.push(p);
            p=p->lchild;
        }else{
            p=s.top()->rchild;
            s.pop();
        }
    }
}
void in_prt_r(BTNode* p){
    if(p){
        in_prt_r(p->lchild);
        printf("%c",p->data);
        in_prt_r(p->rchild);
    }
}
void in_prt_1(BTNode* p){
    stack<BTNode*> a;
    while(p||!a.empty()){
        while(p){
            a.push(p);
            p=p->lchild;
        }
        printf("%c",a.top()->data);
        if(!a.empty()){
            p=a.top()->rchild;
            a.pop();
        }
    }
}
void in_prt_2(BTNode* p){
    stack<BTNode*> s;
    while(p||!s.empty()){
        if(p){
            s.push(p);
            p=p->lchild;
        }else{
            p=s.top();
            s.pop();
            printf("%c",p->data);
            p=p->rchild;
        }
    }
}
void post_prt_r(BTNode* p){
    if(p){
        post_prt_r(p->lchild);
        post_prt_r(p->rchild);
        printf("%c",p->data);
    }
}
void post_prt_1(BTNode* p){
    stack<BTNode*> s;
    BTNode* pre=NULL;
    while(p||!s.empty()){
        if(p){
            s.push(p);
            p=p->lchild;
        }else{
            p=s.top();
            if(p->rchild&&p->rchild!=pre)
                p=p->rchild;
            else{
                s.pop();
                printf("%c",p->data);
                pre=p;
                p=NULL;
            }
        }
    }
}
void post_prt_2(BTNode* p){
    stack<BTNode*> s;
    BTNode* pre;
    s.push(p);
    while(!s.empty()){
        p=s.top();
        if((p->lchild==NULL&&p->rchild==NULL)||(pre!=NULL&&pre==p->rchild)){
            printf("%c",p->data);
            s.pop();
            pre=p;
        }else{
            if(p->rchild)
                s.push(p->rchild);
            if(p->lchild)
                s.push(p->lchild);
        }
    }
}
void InThread(BTNode*& p,BTNode*& pre){
    if(p){
        InThread(p->lchild,pre);
        if(p->lchild==NULL){
            p->lchild=pre;
            p->ltag=1;
        }
        if(pre!=NULL&&pre->rchild==NULL){
            pre->rchild=p;
            pre->rtag=1;
        }
        pre=p;
        InThread(p->rchild,pre);
    }
}
void CreateInThread(BTNode*& p){
    BTNode* pre=NULL;
    if(p){
        InThread(p,pre);
        pre->rchild=NULL;
        pre->rtag=1;
    }
}
BTNode* first_node(BTNode* p){
    while(p->ltag==0)
        p=p->lchild;
    return p;
}
BTNode* next_node(BTNode* p){
    if(p->rtag==0) 
        return first_node(p->rchild);
    return p->rchild;
}
void in_thread_prt(BTNode* p){
    for(BTNode* t=first_node(p);t!=NULL;t=next_node(t))
        printf("%c",t->data);
}
int get_height_r(BTNode* p){
    if(!p) return 0;
    int ldep=get_height_r(p->lchild);
    int rdep=get_height_r(p->rchild);
    if(ldep>rdep)
        return ldep+1;
    else
        return rdep+1;
}
int get_height_1(BTNode* p){
    if(!p) return 0;
    int pre=1,nex=0,height=0;
    queue<BTNode*>q;
    q.push(p);
    while(!q.empty()){
        p=q.front();
        if(p->lchild){
            q.push(p->lchild);
            ++nex;
        }
        if(p->rchild){
            q.push(p->rchild);
            ++nex;
        }
        q.pop();
        --pre;
        if(pre==0){
            ++height;
            pre=nex;
            nex=0;
        }
    }
    return height;
}
int get_height_2(BTNode* p){
    if(!p)
        return 0;
    int front=-1,rear=-1;
    int last=0,level=0;
    BTNode* q[N];
    q[++rear]=p;
    BTNode* t;
    while(front<rear){
        t=q[++front];
        if(t->lchild)
            q[++rear]=t->lchild;
        if(t->rchild)
            q[++rear]=t->rchild;
        if(front==last){
            level++;
            last=rear;
        }
    }
    return level;
}
int get_width(BTNode* p){
    if(p){
        int pre=1,nex=0,width=1;
        queue<BTNode*> q;
        q.push(p);
        while(!q.empty()){
            p=q.front();
            if(p->lchild){
                nex++;
                q.push(p->lchild);
            }
            if(p->rchild){
                nex++;
                q.push(p->rchild);
            }
            pre--;
            q.pop();
            if(pre==0){
                width=width>nex?width:nex;
                pre=nex;
                nex=0;
            }
        }
        return width;
    }
    return -1;
}
int swap_child(BTNode* p){
    if(p){
        BTNode* temp=p->lchild;
        p->lchild=p->rchild;
        p->rchild=temp;
        swap_child(p->lchild);
        swap_child(p->rchild);
    }
    return 0;
}
int main(){
    BTNode* p=pre_init();
    swap_child(p);
    pre_prt(p);
}
