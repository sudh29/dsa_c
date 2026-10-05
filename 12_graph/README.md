# Graph Algorithms in Pure C (C11)

| File | Problem | Pattern(s) |
|------|---------|------------|
| [0_Create_Graph_print.c](0_Create_Graph_print.c) | Create Graph and Print | Graph Representation / Adjacency List |
| [1_Create_Graph.c](1_Create_Graph.c) | Build Adjacency List from Edges | Graph Representation / Arrays |
| [2_Implement_BFS_algorithm.c](2_Implement_BFS_algorithm.c) | Breadth First Search (BFS) | BFS / Queue Traversal |
| [3_Implement_DFS_Algo.c](3_Implement_DFS_Algo.c) | Depth First Search (DFS) | DFS / Recursive Traversal |
| [4_Detect_Cycle_Directed_Graph.c](4_Detect_Cycle_Directed_Graph.c) | Detect Cycle in Directed Graph | DFS / Recursion Stack Tracking |
| [5_Detect_Cycle_UnDirected_Graph.c](5_Detect_Cycle_UnDirected_Graph.c) | Detect Cycle in Undirected Graph | DFS / Parent Node Tracking |
| [6_Search_in_Maze.c](6_Search_in_Maze.c) | Rat in a Maze (Path Search) | Backtracking / Grid DFS |
| [7_Minimum_Step_by_Knight.c](7_Minimum_Step_by_Knight.c) | Minimum Steps by Knight | BFS / Shortest Path on Grid |
| [8_Flood_fill_algo.c](8_Flood_fill_algo.c) | Flood Fill Algorithm | Connected Components / Grid DFS |
| [9_Clone_a_graph.c](9_Clone_a_graph.c) | Clone Graph | BFS / Graph Node Cloning |
| [10_Making_wired_Connections.c](10_Making_wired_Connections.c) | Number of Operations to Make Network Connected | Connected Components / DFS |
| [12_Dijkstra_algo.c](12_Dijkstra_algo.c) | Dijkstra's Shortest Path Algorithm | Greedy / Shortest Path |
| [13_Implement_Topological_Sort.c](13_Implement_Topological_Sort.c) | Topological Sort (Kahn's Algorithm) | In-degree Tracking / BFS |
| [14_Minimum_time_taken_job_completed_Directed_Acyclic_Graph.c](14_Minimum_time_taken_job_completed_Directed_Acyclic_Graph.c) | Minimum Time for DAG Jobs | DAG / In-degree Level Traversal |
| [16_Find_the_no_of_islands.c](16_Find_the_no_of_islands.c) | Number of Islands (8-Connected) | Connected Components / Grid DFS |
| [18_Implement_Kruskals_Algorithm.c](18_Implement_Kruskals_Algorithm.c) | Kruskal's Minimum Spanning Tree | Greedy / Disjoint Set Union (DSU) |
| [36_M-Colouring_Problem.c](36_M-Colouring_Problem.c) | Graph M-Colouring Problem | Backtracking / Vertex Coloring |
| [graph_adj_matrix_bfs.c](graph_adj_matrix_bfs.c) | Adjacency Matrix & BFS | Matrix Representation / Queue |
| [graph_iterative_bfs_dfs.c](graph_iterative_bfs_dfs.c) | Iterative BFS and DFS | Stack and Queue Traversal |
| [graph_floyd_warshall.c](graph_floyd_warshall.c) | Floyd-Warshall All-Pairs Shortest Path | Dynamic Programming / All-Pairs Shortest Path |

## Compilation
All programs can be compiled using C11:
```bash
gcc -std=c11 -Wall -Wextra -Werror -O2 filename.c -o app
./app
```
