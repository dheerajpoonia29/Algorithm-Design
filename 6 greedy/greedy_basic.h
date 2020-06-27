#include "../macro.h"



// KNAPSACK PROBLEM 
/*
	greedy applied: sort all given object in dec order of there profit/weight ratio 
*/
struct bag{
	double ratio;
	double weight;
	double profit;	
};
bool ratioCompare(bag a, bag b){
	return a.ratio>b.ratio;
}
int fractionalKnapsack(int n, int total_weight, vi weight, vi profit){
	double curr_weight = 0;
	vector<double> take(n,0); 	// take: contain the amount of weight we take of given n object weight
	
	vector<bag> temp;
	for(int i=0; i<n; i++){
		temp.pb(bag());
		temp[i].ratio = (double)profit[i]/weight[i];
		temp[i].weight = weight[i];
		temp[i].profit = profit[i];
	}

	// GREEDY : sort profit by weight ratio
	sort(temp.begin(), temp.end(), ratioCompare);
	
	int i=0;
	while(i<n && curr_weight<total_weight){

		// If adding Item won't overflow, add it ratioCompareletely 
        if (curr_weight + temp[i].weight <= total_weight) 
        { 
					curr_weight += temp[i].weight;
					take[i] = 1;
        } 
		
		// If we can't add current Item, add fractional part of it 
        else
        { 
            double fraction = total_weight - curr_weight;
						take[i] = fraction / temp[i].weight;
            break; 
        } 

		i+=1;
	}

	int weight_we_take = 0;
	for(int i=0; i<n; i++){
		weight_we_take+=take[i]*temp[i].weight;
	}

	cout<<"\nweight we taken = "<<weight_we_take<<", given capacity = "<<total_weight<<"\n";
	pv(take);

	int max_profit_earn = 0;
	for(int i=0; i<n; i++){
		max_profit_earn += take[i]*temp[i].profit;
	}
	
	return max_profit_earn;
}


// JOB SEQUENCING WITH DEADLINE
/*
problem:
	- given n slot 
	- worker with there deadline & profit they give to us 
	- find or given them slot which give us maxi profit 

solution:
	* first sort worker data wrt to there max profit 
	* greedy applied: sort in dec order of there profit
	* so the fist worker alway get slot since all slot are free 
	* iterate i to n-1 worker 
		* iterate j = currSlot to lower to slow toward slot id=0
		* greedy applied : alot slot from last to first 
		* if slot[j] is not occupied given that slot[j] to worker ith
Time complexity:
	- brute force: tc(exponential)
		generate all subsets of given set of jobs and check individual subset for feasibility of jobs in that subset. Keep track of maximum profit among all feasible subsets. The time complexity of this solution is exponential. 
*/


// OPTIMAL MERGE PATTERN 
/*
problem: 
	- discribe in note 

solution: 
	* insert size of all array in arr 
	* make this arr as min heap 
	* greedy applied: if we first merge the smallest size array first so it lead to global optimum where cost of merge is min
	* here we use priority queue and every time pop 2 node add them and insert new node 
	* do above step till we left bith 1 node 
*/


// HUFFMAN CODING 
/*
problem:
	- describe in notes 
solution: 
	* make tree 
	* bottom to up/root 
	* left child = 0 
	* right child = 1 
	* tree idea similar to min heap with extra value inserted at each node which is 0/1
	* now traver back from root to given each char to get code in compressed form
*/


// PRIM'S ALGORITHM 
/*
tc: O(V^2)
If the input graph is represented using adjacency list,
then the time complexity of Prim’s algorithm can be reduced to O(E log V)
with the help of binary heap. 
*/
class Prims{

	int V;
	vector<vector<int>> G;	

	vector<pair<bool, int>> visited;
	vector<bool> mst_set; // contian detail of vertex considere into mst

	public:
	
		Prims(vector<vector<int>> G){
			this->V = G.size();
			this->G = G;

			// STEP 1: 
			for(int i=0; i<V; i++){
				visited.pb(mp(false, 99999999));
				mst_set.pb(false);
			}

			// STEP 2:
			visited[0].first = true; 
			visited[0].second = 0;
		}

		int findVisitedLowestNode(int curr){
			int u=-1, min = INT_MAX, v=0;
			
			ff(v,V){
				if(visited[v].first==true && visited[v].second<min && mst_set[v]==false){
					u = v;
					min = visited[v].second;
				}
			}

			return u;
		}

		int solve(){
			int no_edge = 0, min_cost = 0;

			while(no_edge <= V-1){
				// STEP 3.1: pick vertex u which is not visited 
				int u = findVisitedLowestNode(u);  
					if(u==-1)	break;  // no one left to visit

				//cout<<"\n"<<u+1<<" = "<<visited[u].second<<"\n";
						
				// STEP 3.2: find adjacent to u and update 
				for(int v=0; v<V; v++){
					if(G[u][v]){
						// greedy: finding local optimum reach to globla optimum
						visited[v].second = min(visited[v].second, G[u][v]);
						visited[v].first = true;
					}
				}

				min_cost += visited[u].second;
				mst_set[u] = true;

				no_edge += 1;
			}

			return min_cost;
		}
};


// KRUSKAL ALGORITHM 
/*
idea:
	- every time iterate over all egde  pick one edge 
		- check 
				. picked edge not form a cycle 
				. then at it to mst 
	 	- tc(n.e) worst case (n.n=>n^2)

	- but if we use min heap then every time smallest edge 
	- we get in logn 
	- we do this operation n time 
	- so tc(nlogn)
*/
class Kruskal{

	int V;

	vector<pair<int, pair<int, int>>> ed;   // edge: weight : u-v
	vector<vector<int>> mst; // mst graph

	public:

		static bool comp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
			return a.first<b.first;
		}
	
		Kruskal(vector<vector<int>> G){
			this->V = G.size();
			this->mst.resize(V, vector<int>(V,0));

			int i,j;
			i=0;
			ff(i, G.size()){
				j=0;
				ff(j, G.size()){
					if(G[i][j])
						ed.pb(mp(G[i][j], mp(i,j)));
				}
			}

			// greedy: sort based on weight 
			sort(vall(ed), comp);

		}

		void addEdge(vector<int> adj[], int u, int v) 
		{ 
				adj[u].push_back(v); 
				adj[v].push_back(u); 
		} 

		bool isCyclic(vector<int> adj[], int s, int V, vector<bool>& visited) 
		{ 
				// Set parent vertex for every vertex as -1. 
				vector<int> parent(V, -1); 
			
				queue<int> q; 
			
				// Mark the current node as visited and enqueue it 
				visited[s] = true; 
				q.push(s); 
			
				while (!q.empty()) { 
			
						int u = q.front(); 
						q.pop(); 
			
						for (auto v : adj[u]) { 
								if (!visited[v]) { 
										visited[v] = true; 
										q.push(v); 
										parent[v] = u; 
								} 
								else if (parent[u] != v) 
										return true; 
						} 
				} 
				return false; 
		} 

		bool checkCycle(){
			// create adjacency list 
			vector<int> adj[V];
			int i,j;
			i=0;
			ff(i, V){
				j=0;
				ff(j, V){
					if(mst[i][j])
						addEdge(adj, i,j);
				}
			}

			// Mark all the vertices as not visited 
			vector<bool> visited(V, false); 
		
			for (int i = 0; i < V; i++) 
					if (!visited[i] && isCyclic(adj, i,V, visited)) 
							return true; 
			return false; 
		}

		int solve(){
			int no_edge=0, min_cost=0;

			int i=0;
			while(no_edge != V-1 && i<ed.size()){
				pair<int, int> curr_edge = ed[i].second;
				
				mst[curr_edge.first][curr_edge.second] = 1;
				// now check if curr_edge + mst create cycle or not  
				if(checkCycle()){
					// this check cycle is very costly 
					/*
					alternate we use 
					https://www.youtube.com/watch?v=6j-vHQMXXiA
					10:00
					*/
					mst[curr_edge.first][curr_edge.second] = 0;
				}
				else{
					min_cost += ed[i].first;
					no_edge += 1;
				}

				i+=1;
			}
			
			return min_cost;
		}
};


// DIJKSTRA ALGORITHM  - pending
/*
sortest path -> minimization problem -> optimization problem -> solved using greedy method 
mm: tc(n*e) worst case tc(n*n) => tc(n^2)
*/
class Dijkstra{
	int V;
	vector<vector<int>> G;	
	vector<vector<int>> W;

	vector<pair<bool, int>> visited;
	
	vector<int> spt_set;	// contain detail of vertex including in shortest path: shortest path tree

	public:
	
		Dijkstra(vector<vector<int>> G, vector<vector<int>> W){
			this->V = G.size();
			this->G = G;
			this->W = W;

			// STEP 1: 
			for(int i=0; i<V; i++){
				visited.pb(mp(false, 99999999));
				spt_set.pb(false);
			}

			// STEP 2:
			visited[0].first = true; 
			visited[0].second = 0;
		}

		int findVisitedLowestCostNode(int curr){
			int u=-1, min = INT_MAX, v=0;
			
			ff(v,V){
				if(visited[v].first==true && visited[v].second<min && spt_set[v]==false){
					u = v;
					min = visited[v].second;
				}
			}

			return u;
		}

		int solve(){
			int min_cost = 0;
			// let assume source is vertex 1 and destination is vertex n 

			int v=1;  // source vertex 

			// first check loop : optional
			// dijkstra not work for negative value 

				while(v!=V){

					// STEP 3.1: pick vertex u which is not visited 
					int u = findVisitedLowestCostNode(u);  
						if(u==-1)	break;  // no one left to visit

					//cout<<"\n"<<u+1<<" = "<<visited[u].second<<"\n";
							
					// STEP 3.2: find adjacent to u and update 
					for(int v=0; v<V; v++){
						if(G[u][v]){
							// greedy: finding local optimum reach to globla optimum
							if(visited[u].second+W[u][v] < W[u][v])
								W[u][v] = visited[u].second
							visited[v].first = true;
						}
					}

					min_cost += visited[u].second;
					spt_set[u] = true;

					v += 1;
				}

			return min_cost;
		}

};
