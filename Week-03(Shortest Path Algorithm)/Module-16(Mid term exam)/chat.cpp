#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

// Possible knight moves
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isValid(int x, int y, int N, int M)
{
    return x >= 0 && x < N && y >= 0 && y < M;
}

int minStepsToAttackQueen(int N, int M, int ki, int kj, int qi, int qj)
{
    bool visited[N][M];
    memset(visited, false, sizeof(visited));

    queue<pair<int, int>> q;
    q.push({ki, kj});
    visited[ki][kj] = true;

    int steps = 0;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; ++i)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == qi && y == qj)
            {
                return steps;
            }

            for (int j = 0; j < 8; ++j)
            {
                int newX = x + dx[j];
                int newY = y + dy[j];

                if (isValid(newX, newY, N, M) && !visited[newX][newY])
                {
                    visited[newX][newY] = true;
                    q.push({newX, newY});
                }
            }
        }
        steps++;
    }

    return -1;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N, M, ki, kj, qi, qj;
        cin >> N >> M >> ki >> kj >> qi >> qj;
        cout << minStepsToAttackQueen(N, M, ki, kj, qi, qj) << endl;
    }

    return 0;
}
