#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

/** 
 * Class DAG models the '<=' operator as a directed acyclic graph
 */
class DAG
{
    private:
        int rows;
        int cols;
        int size;
        vector< vector<int> > grid;
        vector< vector<int> > adj;		//adjacent List

    public:
        DAG(int r, int c, vector< vector<int> > g);	
        void updateNode(int r, int c, int curr, vector<int> &vec);
        void buildAdjList();
        void topologyFromNode(int node, bool visited[], stack<int> &stack);
        int pathLength(int source);	
};

DAG::DAG(int r, int c, vector< vector<int> > g){
    rows = r;
    cols = c;
    size = r * c;
    grid = g; 
    buildAdjList();

}

void DAG::updateNode(int r, int c, int curr, vector<int> &vec){
    int element = grid[r][c];
    int flat_idx = r * cols + c; //2-D index to 1-D index
    if(curr <= element)
        vec.push_back(flat_idx);
}

void DAG::buildAdjList(){
    // controls to check if there is a matrix element in a certain 
    //direction from the current element
    bool left, right, down, up;
    int current;

    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            left = (c > 0);
            right = (c < cols-1); 
            down = (r < rows-1);
            up = (r > 0);

            current = grid[r][c];

            int up_row = r - 1;
            int down_row = r + 1;
            int left_col = c -1 ;
            int right_col = c + 1;
            vector<int> tmp_vec;

            if (up){//check adjacent elements in the upper row
                if(left)
                    updateNode(up_row, left_col, current, tmp_vec);
                updateNode(up_row, c, current, tmp_vec);
                if(right)
                    updateNode(up_row, right_col, current, tmp_vec);						
            }				

            if(left)//check left element
                updateNode(r, left_col, current, tmp_vec);

            if(right)//check right element
                updateNode(r, right_col, current, tmp_vec);

            if(down){//check elements in the the row below
                if(left)
                    updateNode(down_row, left_col, current, tmp_vec);
                updateNode(down_row, c, current, tmp_vec);				
                if(right)
                    updateNode(down_row, right_col, current, tmp_vec);					
            }

            adj.push_back(tmp_vec);

        }
    }
}

void DAG::topologyFromNode(int node, bool visited[], stack<int> &stack){
    visited[node] = true;
    vector<int> currList = adj[node];

    //Recursively visit all elements adjacent to the current node
    //and order them topologically such that for a given directed 
    //edge a--->b, a always comes before b.
    for(vector<int>::iterator it = currList.begin(); it != currList.end(); it++){
        int next = (*it);
        if(!visited[next])
            topologyFromNode(next, visited, stack);
    }
    stack.push(node);
}

int DAG::pathLength(int source){

    //Initially mark or vetices/nodes as not visited
    bool visited[size];
    for(int i = 0; i < size; i++)
        visited[i] = false;
	
    stack<int> stack;	
    topologyFromNode(source, visited, stack);

    //Initialize the path length from all nodes to zero. 
    //Path from source to source has to be 0.
    int length[size];
    for(int i = 0; i < size; i++){
        length[i] = 0;
    }

    //Go through the stack popping out the top element and updating 
    //the length of the nodes adjacent to the top one.
    vector<int> visited_vec;
    int local_max = 0;
    while(!stack.empty()){        
        
        //pop top node and save it in a vector to prevent counting
        //cyclic edges.
        int curr_node = stack.top();
        stack.pop();
        visited_vec.push_back(curr_node);
        
        vector<int> curr_list = adj[curr_node];
        for(vector<int>::iterator it = curr_list.begin(); it != curr_list.end(); it++){
            int adj_node = *it;
            if(stack.size() == size_t (size -1))  
                length[adj_node]++;
            else{
                int tmp = length[curr_node] + 1;
                if(tmp > length[adj_node]){
					vector<int>::iterator iter = find(visited_vec.begin(), visited_vec.end(), adj_node);
					if(iter == visited_vec.end())
						length[adj_node] = tmp;
				}
			}
            if(local_max < length[adj_node])//update max length
                local_max = length[adj_node];
        }
    }

    //number of elements along a path is number of edges plus 1 (max + 1)
    return local_max + 1; 
}


/**
 * Take a rectangular grid of numbers and find the length
 * of the longest non-decreasing sub-sequence.
 * Return the length as an integer.
 * This function creates a DAG object and then invokes its 
 * pathLength member function
 */
int longest_subsequence(vector< vector<int> > grid) {
    int num_rows = grid.size();
    int num_cols = grid[0].size();
    DAG numbers = DAG(num_rows, num_cols, grid);
    int max = 0; 
    for(int i = 0; i < num_cols*num_rows; i++){
		int local_max = numbers.pathLength(i);
		if(max < local_max)
			max = local_max;
	}
    return max;
}

int main() {
    int res;

    int num_rows = 0;
    int num_cols = 0;
    cin >> num_rows;
    cin >> num_cols;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    vector< vector<int> > grid;
    int grid_item;
    for (int row = 0; row < num_rows; row++) {
        vector<int> grid_row;

        for (int col = 0; col < num_cols; col++) {
            cin >> grid_item;
            grid_row.push_back(grid_item);
        }
        grid.push_back(grid_row);
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    res = longest_subsequence(grid);
    cout << res << endl;

    return 0;
}
