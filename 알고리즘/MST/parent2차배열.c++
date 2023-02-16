// #include<iostream>
// using namespace std;

// const int MAXN = 6; 
// const int MAXM = 5; 
// struct Node
// {
//     int row, col; 
// };
// Node parent[MAXN][MAXM];
// int sizeOf[MAXN][MAXM]; // root가 관리하도록 

// Node Find(Node now)
// {
//     Node p = parent[now.row][now.col]; 
//     if (now.row == p.row && now.col == p.col)
//     {
//         return now; 
//     }
//     Node ret = Find(parent[now.row][now.col]); 
//     parent[now.row][now.col] = ret; 
//     return ret; 
// }
// int total = 0; 
// void Union(Node a, Node b)
// {
//     Node ra = Find(a); 
//     Node rb = Find(b); 
//     if (ra.row == rb.row && ra.col == rb.col) return; 
//     parent[rb.row][rb.col] = ra; 
//     sizeOf[ra.row][ra.col] += sizeOf[rb.row][rb.col]; 
//     sizeOf[rb.row][rb.col] = 0; 
// }
// void init()
// {
//     for (int r = 0; r < N; r++)
//     {
//         for (int c = 0; c < M; c++)
//         {
//             parent[r][c] = { -1,-1 }; // root가 없음 
//         }
//     }
// }
// int main()
// {
//     init(); 
//     int Q; 
//     cin >> Q; 
//     for (int i = 0; i < Q; i++)
//     {
//         int row, col; 
//         cin >> row >> col; 
//         parent[row][col] = { row,col }; // init 
//         sizeOf[row][col] = 1;
//         for (int t = 0; t < 4; t++)
//         {
//             int nr = row + dr[t];
//             int nc = col + dc[t];
//             if (isOut(nr, nc))continue;
//             // if (Find({ nr,nc }) == {-1, -1})continue; 
//             if (parent[nr][nc].row == -1 && parent[nr][nc].col == -1)continue;
//             Union({ row,col }, { nr,nc }); 
//         }
//     }

//     // root 가 몇개인가 
//     int total = 0;
//     int maxSize = -1; 
//     for (int row = 0; row < N; row++)
//     {
//         for (int col = 0; col < M; col++)
//         {
//             Node r = Find({ row,col }); 
//             if (row == r.row && col == r.col)
//             {
//                 total++; 
//                 maxSize = max(sizeOf[row][col], maxSize);
//             }
//         }
//     }


//     return 0; 
// }