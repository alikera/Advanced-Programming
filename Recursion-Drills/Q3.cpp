#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

const int POSSIBLE_MOVES = 4;

void create_gold_mine_board(vector<vector<int> > &gold_mine_board, int m, int n){
    int input;
    for(int i = 0; i < m; i++){
        gold_mine_board.push_back(vector<int>());
        for(int j=0;j<n;j++){
            cin>>input;
            gold_mine_board[i].push_back(input);
        }
    }
    return;
}

void gold_collecting_path(vector<vector<int> > &gold_mine_board,int new_row,int new_col,
                            int &gold_collected,vector<int> &max_gold_collected,int &current_gold){
                                
    current_gold = gold_mine_board[new_row][new_col];
    gold_mine_board[new_row][new_col] = -1;
    gold_collected = gold_collected + current_gold;
    max_gold_collected.push_back(gold_collected);
}

bool find_gold(int current_row, int current_col, int m, int n,int &gold_collected,
                vector<int> &max_gold_collected, vector<vector<int> > &gold_mine_board){

    int row_delta[POSSIBLE_MOVES] = {0, 1, -1, 0};
    int col_delta[POSSIBLE_MOVES] = {-1, 0, 0, 1};
    
    for (int move = 0; move < POSSIBLE_MOVES; move++) {
        int new_row = current_row + row_delta[move];
        int new_col = current_col + col_delta[move];
        
        if (new_row < 0 || new_row >= m || new_col < 0 || new_col >= n)
            continue;
            
        if (gold_mine_board[new_row][new_col] == 0 || gold_mine_board[new_row][new_col] == -1)
            continue;
        
        int current_gold;
        gold_collecting_path(gold_mine_board,new_row,new_col,gold_collected,max_gold_collected,current_gold);
        
        if (find_gold(new_row, new_col,m,n,gold_collected,max_gold_collected,gold_mine_board))
            return true;
            
        gold_collected = gold_collected - current_gold;
        gold_mine_board[new_row][new_col] = current_gold;
    }
    return false;
}

void solve(int init_row, int init_col, int m, int n,int &gold_collected,
            vector<int> &max_gold_collected,vector<vector<int> > &gold_mine_board){
    int current_gold;
    gold_collecting_path(gold_mine_board,init_row,init_col,gold_collected,max_gold_collected,current_gold);
    
    if (!find_gold(init_row, init_col,m,n,gold_collected,max_gold_collected,gold_mine_board)){
        sort(max_gold_collected.begin(),max_gold_collected.end());
        gold_mine_board[init_row][init_col] = current_gold;
        gold_collected=0;
    }
}

int main() {
    int m,n;
    cin>>m;
    cin>>n;
    
    vector<vector<int> > gold_mine_board;
    create_gold_mine_board(gold_mine_board,m,n);
    
    vector<int> max_gold_collected;
    int gold_collected=0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (gold_mine_board[i][j] !=0)
                solve(i,j,m,n,gold_collected,max_gold_collected,gold_mine_board);
        }
    }
    
    cout<<max_gold_collected[max_gold_collected.size()- 1]<<endl;
}



