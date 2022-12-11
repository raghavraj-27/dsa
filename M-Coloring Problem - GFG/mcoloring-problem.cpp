//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    bool checkWithColor_c(int node, int N, bool graph[101][101], int m, int c, vector<int>& color) {
        for(int i=0; i<N; i++) {
            if(i == node) continue;
            if(graph[i][node] or graph[node][i]) {
                if(color[i] == c) return false;
            }
        }
        return true;
    }
    bool checkPossibility(int node, bool graph[101][101], int m, int n, vector<int>& color) {
        if(node >= n) return true;
        
        for(int c=1; c<=m; c++) {
            if(checkWithColor_c(node, n, graph, m, c, color)) {
                color[node] = c;
                if(checkPossibility(node+1, graph, m, n, color)) return true;
                else color[node] = -1;
            }
        }
        
        return false;
    }
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> colured(n, -1);
        return checkPossibility(0, graph, m, n, colured);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends