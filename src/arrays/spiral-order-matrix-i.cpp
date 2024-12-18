#include <iostream> 
#include <vector>

using namespace std;

/*
    Problem : https://www.interviewbit.com/problems/spiral-order-matrix-i/
*/ 


// T(n) : O(n) ; S(n) : O(n)
vector<int> solveSpiralOrder(const vector<vector<int> >& A) {

    vector<int> spiralOrder;
    int m=A.size(), n=A[0].size();
    int rs=0, re=m-1, cs=0, ce=n-1;
    while (rs <= re && cs <= ce) {

        for (int i=cs; i<=ce; i++) {
            spiralOrder.push_back(A[rs][i]);
        }
        rs++;

        for (int i=rs; i<=re; i++) {
            spiralOrder.push_back(A[i][ce]);
        }
        ce--;

        if (rs > re) break;
        for (int i=ce; i>=cs; i--) {
            spiralOrder.push_back(A[re][i]);
        }
        re--;

        if (cs > ce) break;
        for (int i=re; i>=rs; i--) {
            spiralOrder.push_back(A[i][cs]);
        }
        cs++;
    }
   
    
    return spiralOrder;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    cin >> M >> N;
    vector<vector<int> > matrix(M, vector<int>(N));
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<int> spiralOrder = solveSpiralOrder(matrix);
    for (int i=0; i<spiralOrder.size(); i++) {
        cout << spiralOrder[i] << " ";
    }

    cout << "\n";

    return 0;
}