#include<iostream>
#include<string>

using namespace std;

int tree[100010];
int NUM = 100005;
/* 
注意这个NUM，实际上是不能取这么大的值的，NUM应该是
原数组的长度，可以设成全局变量，在最初构造树状数组
的时候手动累加。
*/

void update(int index,int n){
    for(int i = index;i < NUM;i += (i&-i)){
        tree[i] += n;
    }
}

int query_sum(int n){
    int ans = 0;
    for(int i = n;i > 0;i -= (i&-i)){
        ans += tree[i];
    }
    return ans;
}

int main() {
    
    system("pause");
    return 0;
}

/*hdoj 1166 C++ 可以看成树状数组的应用模板*/
#include<iostream>
#include<string>
#include<queue>
#define MAX_Tot 500005

using namespace std;

int tree[50010];
int NUM = 2;

void update(int index, int n) {
    for (int i = index; i <= NUM; i += (i&-i)) {
        tree[i] += n;
    }
}

int query_sum(int n) {
    int ans = 0;
    for (int i = n; i > 0; i -= (i&-i)) {
        ans += tree[i];
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int I = 1; I <= T; I++) {
        memset(tree, 0, sizeof(tree));
        cout << "Case " << I << ":" << endl;
        int N;
        int end = 0;
        scanf("%d", &N);
        NUM = N;
        for (int i = 1; i <= N; i++) {
            int num;
            scanf("%d", &num);
            update(i, num);
        }
        string com;
        int i, j;
        while (1) {
            cin >> com;
            int flag = com[0] - 'A';
            switch (flag) {
                case 0: {
                    scanf("%d%d", &i, &j);
                    update(i, j);
                }break;
                case 4: end = 1; break;
                case 16: {
                    scanf("%d%d", &i, &j);
                    cout << query_sum(j) - query_sum(i - 1) << endl;
                }break;
                case 18: {
                    scanf("%d%d", &i, &j);
                    update(i, -j);
                }break;
            }
            if (end == 1) break;
        }
    }

    system("pause");
    return 0;
}