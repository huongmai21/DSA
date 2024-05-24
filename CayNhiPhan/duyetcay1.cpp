//Cho phép duyệt cây nhị phân Inorder và Preorder, 
//hãy đưa ra kết quả phép duyệt Postorder của cây nhị phân. 
//Ví dụ với cây nhị phân có các phép duyệt cây nhị phân của cây dưới đây:
//
//        1
//      /    \    
//     2       3
//   /   \      \
//  4     5      6
//Inorder   : 4  2  5  1  3  6  (left - root - right)

//Preorder  : 1  2  4  5  3  6  (root - left - right)

//Postorder : 4  5  2  6  3  1  (left - right - root)


#include<bits/stdc++.h>

using namespace std;

int search(int* M, int n, int x) {
	for (int i = 0; i < n; i++)
		if (M[i] == x)return i;
}

void Duyet(int*M,int n,int*N) {
	int x = search(M, n, N[0]);
	if (x != 0)	Duyet(M, x, N + 1);
	if (x != n - 1) Duyet(M + x + 1, n - x - 1, N + x + 1);
	cout << N[0] << " ";
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        int I[n], Pr[n];
        for(int &i : I) cin>>i;
        for(int &i : Pr) cin>>i;
        Duyet(I,n,Pr);
        cout<<endl;
    }
}