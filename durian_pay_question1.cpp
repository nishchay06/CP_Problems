/*
[15:08] Gautam Chawla
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
 
Input:
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
Output :8
Explanation : 
The largest rectangle with only 1's is from 
(1, 0) to (2, 3) which is
1 1 1 1
1 1 1 1 
Input:
0 1 1  
1 1 1  
0 1 1  

Output:6
Explanation : 
The largest rectangle with only 1's is from 
(0, 1) to (2, 2) which is
1 1
1 1
1 1
 

Constraints:
rows == matrix.length
cols == matrix[i].length
1 <= row, cols <= 200
matrix[i][j] is '0' or '1'.

 */




#include<iostream>
#include<vector>
#include<stack>
using namespace std;


int getMaxFromHist(vector<int> heights){
    int ans = 0;
    int n = size(heights);

    // Get the indices of previous smaller element and the next smallest element
    vector<int> pse(n,-1);
    vector<int> nse(n,n);
    stack<int> st;

    for(int i = 0; i < n; i++) {
        while(size(st) and heights[st.top()] >= heights[i]){
            st.pop();
        }
        if(size(st)) pse[i] = st.top();
        st.push(i);
    }

    // Empty the stack
    while(size(st)) st.pop();

    for(int i = n-1; i >= 0; i--) {
        while(size(st) and heights[st.top()] >= heights[i]){
            st.pop();
        }
        if(size(st)) nse[i] = st.top();
        st.push(i);
    }

    // for(int i = 0; i < n; i++){
    //     cout<<pse[i]<<" ";
    // }
    // cout<<endl;
    // for(int i = 0; i < n; i++){
    //     cout<<nse[i]<<" ";
    // }
    // cout<<endl;

    for(int i = 0; i < n; i++) {
        int crht = heights[i];
        if(crht == 0) continue;
        int crwd = (nse[i]-1)-(pse[i]+1)+1;
        int crArea = crht*crwd;
        // cout<<i<<" : "<<crwd<<" , "<<crArea<<endl;
        ans = max(ans,crArea);
    }

    return ans;
}

int maxSize(vector<vector<int>> matrix){
    int n = size(matrix);
    int m = size(matrix[0]);
    int ans = 0;

    // Get the heights vector of the current histogram
    vector<int> heights(m);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){ 
            if(matrix[i][j] == 0){
                heights[j] = 0;
            }
            else heights[j] += 1;

            // cout<<heights[j]<<" ";
        }
        // cout<<endl;
        int crAns = getMaxFromHist(heights);
        
        // maximise the answer 
        ans = max(ans,crAns);
        // cout<<"________________\n";
    }
    return ans;
}

int main(){
    int n,m;
    // Enter the rows and columns
    cin >> n >> m;
    vector<vector<int>> matrix(n,vector<int>(m));
    // Enter the matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    cout<<maxSize(matrix);
    return 0;
}
