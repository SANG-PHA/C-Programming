#include<iostream> 
using namespace std;

// B-tree 노드 클래스
class BTreeNode
{
    int* keys;  // 키 값 배열
    int t;      // 차수
    BTreeNode** C; // 자식 포인터 배열
    int n;     // 현재 노드 키 값의 수
    bool leaf; // 현재 노드가 리프 노드인지 판별하는 변수
public:
    BTreeNode(int _t, bool _leaf);   // 생성자

    // 삽입
    void insertNonFull(int k);

    // 자식 노드인 y가 꽉 차있으면 노드를 분할하는 함수
    void splitChild(int i, BTreeNode* y);

    // 순회
    void traverse();

    // private멤버에 접근하기 위한 friend클래스
    friend class BTree;
};

// B-Tree 클래스 
class BTree
{
    BTreeNode* root; // 루트 노드 포인터
    int t;  // 차수
public:
    // 생성자
    BTree(int _t)
    {
        root = NULL;
        t = _t;
    }

    // 순회
    void traverse()
    {
        // 트리가 비어있지 않으면 순회 시작
        if (root != NULL)
            root->traverse();
    }

    // 삽입
    void insert(int k);
};

// BTreeNode의 생성자 구현
BTreeNode::BTreeNode(int t1, bool leaf1)
{
    // 차수, 리프 노드인지 설정
    t = t1;
    leaf = leaf1;

    // 키 값과 자식 포인터 배열 할당
    keys = new int[2 * t - 1];
    C = new BTreeNode * [2 * t];

    // 현재 키 값의 수 = 0
    n = 0;
}

// 순회 알고리즘 구현 
void BTreeNode::traverse()
{
    int i;
    for (i = 0; i < n; i++) // 현재 노드의 키 값 수 만큼 반복
    {
        if (leaf == false) // 리프 노드가 아니면
            C[i]->traverse(); // 자식 노드로 이동
        cout << " " << keys[i];
    }

    // 마지막 자식 노드 출력
    if (leaf == false)
        C[i]->traverse();
}

// 삽입 알고리즘 구현
void BTree::insert(int k)
{
    // 트리가 비어있다면
    if (root == NULL)
    {
        // 루트 노드 할당 
        root = new BTreeNode(t, true);
        root->keys[0] = k;  // 키 삽입
        root->n = 1;  // 키 값의 수 증가
    }
    else // 트리가 비어있지 않다면
    {
        // 루트 노드가 꽉 차있으면 높이 증가
        if (root->n == 2 * t - 1)
        {
            // 새로운 루트노드 할당 
            BTreeNode* s = new BTreeNode(t, false);

            // 원래 루트노드는 자식 노드로 이동
            s->C[0] = root;

            // 원래 루트노드 분할
            s->splitChild(0, root);

            // 새로운 2개의 자식 노드 중에서 키 값을 가질 자식 노드 결정
            int i = 0;
            if (s->keys[0] < k)
                i++;
            s->C[i]->insertNonFull(k);

            // 루트 변경
            root = s;
        }
        else  // 루트 노드가 꽉 차있지 않다면
            root->insertNonFull(k);
    }
}

// 노드가 꽉 차있지 않을 때 삽입 알고리즘
void BTreeNode::insertNonFull(int k)
{
    // 시작 인덱스
    int i = n - 1;

    // 리프 노드 라면
    if (leaf == true)
    {
        // 새로운 키가 삽입될 위치 탐색
        // 키보다 큰 값 한 칸씩 뒤로 이동
        while (i >= 0 && keys[i] > k)
        {
            keys[i + 1] = keys[i];
            i--;
        }

        // 새로운 키 삽입
        keys[i + 1] = k;
        n = n + 1;
    }
    else // 리프 노드가 아니라면
    {
        // 새로운 키가 삽입될 자식노드 탐색
        while (i >= 0 && keys[i] > k)
            i--;

        // 찾은 자식 노드가 꽉 차있다면
        if (C[i + 1]->n == 2 * t - 1)
        {
            // 노드 분할
            splitChild(i + 1, C[i + 1]);

            // 분할 된 노드의 중간 값을 위로 올림
            // 분할 되어 가진 2개의 자식노드 중 새로운 키 값이 삽입될 자식 노드 탐색  
            if (keys[i + 1] < k)
                i++;
        }
        C[i + 1]->insertNonFull(k);
    }
}

// 노드 분할 알고리즘 구현, 자식 노드가 꽉 차있을 때 호출 
void BTreeNode::splitChild(int i, BTreeNode* y)
{
    // 키를 저장할 새로운 노드 z 생성
    BTreeNode* z = new BTreeNode(y->t, y->leaf);
    z->n = t - 1;

    // y의 마지막 값을 z로 복사
    for (int j = 0; j < t - 1; j++)
        z->keys[j] = y->keys[j + t];

    // y의 마지막 자식을 z로 복사
    if (y->leaf == false)
    {
        for (int j = 0; j < t; j++)
            z->C[j] = y->C[j + t];
    }

    // y의 현재 키 값 수 감소
    y->n = t - 1;

    // 새로운 자식을 위한 공간 생성
    for (int j = n; j >= i + 1; j--)
        C[j + 1] = C[j];

    // 새로운 자식 노드 연결
    C[i + 1] = z;

    // y의 키 값 이동, 새로운 키 값의 자리 탐색 및 키 값보다 큰 값 한 칸씩 뒤로 이동
    for (int j = n - 1; j >= i; j--)
        keys[j + 1] = keys[j];

    // y의 중간 키 값 복사
    keys[i] = y->keys[t - 1];

    // 현재 노드의 키 값 수 증가
    n = n + 1;
}

int main()
{
    BTree Tree(3); // 3차 B-tree

    int cnt;
    cout << "입력할 키 값의 갯수 : ";
    cin >> cnt;

    // 노드 삽입
    for (int i = 0; i < cnt; i++)
    {
        int input;
        cout << "값 입력 : ";
        cin >> input;
        Tree.insert(input);
    }

    // 구성된 트리 출력
    cout << "구성된 트리 :  ";
    Tree.traverse();

    return 0;
}
