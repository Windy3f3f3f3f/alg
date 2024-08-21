#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

const int N = 5;
const int MAX_STEPS = 4;

vector<vector<int>> directions = {{0, 0}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
unordered_set<string> reachable_states;

void flip(vector<vector<int>>& grid, int x, int y) {
    for (const auto& dir : directions) {
        int nx = x + dir[0], ny = y + dir[1];
        if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
            grid[nx][ny] = 1 - grid[nx][ny];
        }
    }
}

string grid_to_string(const vector<vector<int>>& grid) {
    string s;
    for (const auto& row : grid) {
        for (int cell : row) {
            s += to_string(cell);
        }
    }
    return s;
}

void dfs(vector<vector<int>>& grid, int steps, int last_x, int last_y) {
    if (steps > MAX_STEPS) return;
    
    string state = grid_to_string(grid);
    reachable_states.insert(state);
    
    for (int x = 0; x < N; ++x) {
        for (int y = 0; y < N; ++y) {
            if (x == last_x && y == last_y) continue;
            flip(grid, x, y);
            dfs(grid, steps + 1, x, y);
            flip(grid, x, y);  // backtrack
        }
    }
}

int main() {
    // Generate all reachable states
    vector<vector<int>> start_grid(N, vector<int>(N, 1));
    dfs(start_grid, 0, -1, -1);
    
    int n;
    cin >> n;
    
    while (n--) {
        vector<vector<int>> grid(N, vector<int>(N));
        for (int i = 0; i < N; ++i) {
            string row;
            cin >> row;
            for (int j = 0; j < N; ++j) {
                grid[i][j] = row[j] - '0';
            }
        }
        
        string target_state = grid_to_string(grid);
        if (reachable_states.find(target_state) != reachable_states.end()) {
            // Binary search to find the minimum steps
            int left = 0, right = MAX_STEPS;
            while (left < right) {
                int mid = left + (right - left) / 2;
                vector<vector<int>> temp_grid = start_grid;
                dfs(temp_grid, 0, -1, -1);
                if (reachable_states.find(target_state) != reachable_states.end()) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
                reachable_states.clear();
            }
            cout << left << endl;
        } else {
            cout << -1 << endl;
        }
    }
    
    return 0;
}
