// CSC 300 Summer 2020
/*
 - class for introducing graphs & graph algorithms
 - for simplification, we have the following restrictions:
    - less than 100 nodes
    - no self edges
    - all graph description files will be weighted
    - all weights > 0

 - node order
    print out the nodes, on 1 line, in the order dictated by algorithm
 - spanning tree
    print out edges     start-end   in the order dictated by algorithm



Graph Description File format
  Number of Nodes
  Number of Edges
  Source  Destination  Weight     [ for each edge ] 

*/

#include <iostream>
#include <fstream>
using namespace std;


class graph
{
	public:
		graph();
		graph( int n );              // constructor, x is # of nodes
		graph( int n, int e );       // constructor, n is # of nodes	
                                     //              e is # of edges
		void bfs( int x, int n );           // breadth-first node order
		void bfssp( int x );         // breadth-first spanning tree
		void dfs( int x, int n );           // depth-first node order
		void dfssp( int x );         // depth-first spanning tree
		void mprint(int n);               // print representation 
		void fill( ifstream& file ); // fill graph from data file
               // file is open;pay attention to read before & in 
	private:
		int **graphArr;
		int **edgeArr;
		
		int numnodes;
};


graph::graph()
{
	graphArr = new int*[101]; // create array/pointer
	for ( int i = 0; i <= 100; ++i )
	{
		graphArr[i] = new int[101]; // create array of pointers
	}
	numnodes = 100;
}

graph::graph( int n )
{
	graphArr = new int*[n]; // create array/pointer
	for ( int i = 1; i <= n; ++i )
	{
		graphArr[i] = new int[n+1]; // create array of pointers
	}
    numnodes = n;
}


graph::graph( int n, int e )
{
	graphArr = new int*[n]; // create the matrix array/pointer
	for ( int i = 0; i <= n; ++i ) 
	{
		graphArr[i] = new int[n+1]; // create array of pointers
	}
	edgeArr = new int*[e+1]; // create the edge array/pointer for what, I don't know
	for ( int i = 0; i <= e; ++i ) 
	{
		edgeArr[i] = new int[e+1]; // create array of pointers
	}
	
	numnodes = n;
}

// isn't right .... but kind of works.
void graph::bfs( int x, int n )           // breadth-first node order
/*
Breadth First Search (BFS)
- Starting from node v
- Identify all nodes adjacent to v
- Add these to the set
- Determine set of unvisited nodes which are adjacent to this set
- Add these to the set
- Continue until no new nodes are encountered
*/
{
	int *visited = new int[n]; // array to keep track of visited spots
    int queue[n]; // array to store visited order
	int a = -1, b = 0; // matrix vars
	int i;
	
	for (i=0;i <n ; i ++)   // set all to 0
	{
	     queue[i] = 0;
	     visited[i] = 0;
    }

		
	
    cout<<"Traversing the graph with BFS : " << endl;
    queue[b] = x; // make the start var the current position in queue
    visited[x] = 1; // mark that position visited ^
    

    
    while( a != b ) 
    {
        if ( queue[++a] != 0 ) // increment queue and if that value isn't 0
		{
			cout << queue[a] << " "; // print to screen
		}
		
        i = queue[a]; // make i the current number in queue
        for( int j = 0; j < n; j++) // loop to track visited nodes
            if( graphArr[i][j] != 0 && visited[j] != 1 ) // if the matrix isn't 0 and hasn't been visited
            {
              queue[++b] = j; // increment queue position with b var and make that what's in the j counter
              visited[j] = 1; // make that position visited
            }
    }
}

void graph::bfssp( int x )         // breadth-first spanning tree
{

}

// doesn't work ...
void graph::dfs( int x, int n )           // depth-first node order
/*
Depth First Search (DFS)
- Starting from vertex v
- Mark v as marked
- Select u as an unmarked node adjacent to v
- If no u, quit
- If u, begin depth first search from u
- When search from u quits, select another node from v
*/
{
	int j;
	int *visited = new int[n]; // array to keep track of visited spots
	visited[x] = 1; // mark the starting position visited
	
	for ( j = 0; j < n; j++ )
	{
		if ( graphArr[x][j] == 1 && visited[j] == 0 )
		{
			cout << x+1 << " ";
		}
	}
	cout << endl;
}
	
void graph::dfssp( int x )         // depth-first spanning tree
{

}
	
void graph::mprint(int n)
{
	int h, i, j;
	
	cout << endl;
	// all spaces below are tabs for row/column alignment
	cout << "0|	"; // start row/column header
	for ( h = 1; h <= n; h++ ) // build column headers based on input file nodes/verticies
	{
		cout << h << "	"; 
	}
	cout << endl;
	
	for ( h = 1; h <=n ; h++ ) // make it pretty
	{
		cout << "---------";
	}
	cout << endl;	
	
	for ( i = 1; i <= n; i++ ) // numnode (vertices)
	{
		cout << i << "|	"; // build row headers
		for ( j = 1; j <= n; j++ ) // numnode (verticies)
		{
			cout <<  graphArr[i][j] << "	";
			
		}
		cout << endl;
	}
	cout << "	" << endl;
}


void graph::fill( ifstream& file )
{
	int firstVert, secondVert, weight;
	
	//  set all weitghts to 0
	
	for (int i = 1; i <= numnodes; i++)
	   for (int j=1; j<=numnodes; j++)
	      graphArr[i][j] = 0;
		  	
	while( true )
	{
		file >> firstVert; // read 1st number
		file >> secondVert; // read 2nd number
		file >> weight; // read 3rd number
		if ( file.eof() ) // checks for EOF in loop to prevent grabbing last line in file twice
		{
			break;
		}
		
		//cout << firstVert << " " << secondVert << " Weight is: " << weight << endl; // test print for debugging
		
		graphArr[firstVert][secondVert] = weight; // add weighted edge value into the matrix
		graphArr[secondVert][firstVert] = weight; // other direction/because undirected
	}
	
}


int main( int argc, char *argv[] )
{
	int size, numnode, numedge;
	int location;
	ifstream ifp;
	
	//checking to see if file was entered on command line
	if ( argc != 2 )
	{
		cout << "File was not entered\n";
		return 2;
	}

	ifp.open( argv[1] );

	// checking to see if file was opened successfully
	if( ! ifp.is_open() )
	{
		cout << "File could not be opened\n";
		return 3;
	}

	// reading in number of nodes
	ifp >> numnode;
	// reading in number of edge 
	ifp >> numedge;

	//create graph with an an adjadceny matrix of 
    // size = num of nodes x num of nodes
	// array can be bigger if needed so you can make it work
	graph g( numnode, numedge );

	//fill adjacency matrix
	g.fill( ifp );

	//print the matrix
	g.mprint(numnode);
	//cout << endl << endl;

	//ask for starting location
	cout << "Enter the starting location: ";
	cin >> location;

	// calculate BFS
	g.bfs( location, numnode );
	cout << endl << endl;

	//calculate DFS-SP
//	g.dfssp( location );
//	cout << endl << endl;

	//calculate DFS
//	g.dfs( location, numnode );
//	cout << endl << endl;
//
	//calculate BFS-SP
//	g.bfssp( location );
//	cout << endl << endl;

	ifp.close(); // close file
	return 0;
}
