#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int main() {
    int N, E;
    cin >> N >> E;
    
    vector<vector<int>> graph(N);
    
    for (int i = 0; i < E; ++i) {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }
    
    int L;
    cin >> L;
    
    vector<bool> visited(N, false);
    queue<int> q;
    set<int> pizzaShops;
    
    q.push(0); // Start from the first pizza shop
    visited[0] = true;
    
    int level = 0;
    
    while (!q.empty()) {
        int size = q.size();
        
        if (level == L) {
            for (int i = 0; i < size; ++i) {
                pizzaShops.insert(q.front());
                q.pop();
            }
            break;
        }
        
        for (int i = 0; i < size; ++i) {
            int curr = q.front();
            q.pop();
            
            for (int neighbor : graph[curr]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        
        level++;
    }
    
    if (pizzaShops.empty()) {
        cout << -1;
    } else {
        for (int shop : pizzaShops) {
            cout << shop << " ";
        }
    }
    
    return 0;
}
