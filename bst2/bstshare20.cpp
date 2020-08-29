#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

bool z = false;

struct treenode
{
	int dat;
	treenode *lchild;
	treenode *rchild;
};

class bstree
{
	public:
		bstree();
		void in( );
		void pre( );
		void post( );
		void paren( );
		void insert( int x );
		void search( int x );
		void remove( int x );
		int numnodes();
		int height();
	private:
		treenode *root; // header of linked structure. points to node that represents root of tree and everything else branches from there.
		void in( treenode *t );
		void pre( treenode *t );
		void post( treenode *t );
		void paren( treenode *t );
		void insert( treenode *t, treenode *n );
		treenode *findval( int x, treenode *t);
		int _numnodes(treenode *t);
		int _height(treenode *t);
};

bstree::bstree()
{  
	root = NULL;
}


void bstree::insert( treenode *t, treenode *n ) // insert private method
{
	if ( t->dat < n->dat ) // move right
	{
		if ( t->rchild == NULL )
		{
			t->rchild = n;
		}
		else
		{
			t = t->rchild;
			insert(t,n); // call insert after moving
		}
	}
	else if ( t->dat > n->dat ) // move left
	{
		if ( t->lchild == NULL )
		{
			t->lchild = n;
		}
		else
		{
			t = t->lchild;
			insert(t, n); // call insert after moving
		}
	}
}


void bstree::in(treenode * t) // private function
{
	if ( t == NULL ) // if end of tree
		 return;

	in(t->lchild); // move left
	printf("%2d ", t->dat); // print val
	in(t->rchild); // move right
}


void bstree::pre(treenode * t) // private function
{
	if ( t == NULL ) // if end of tree
		 return;

	printf("%2d ", t->dat); // print val
	pre(t->lchild); // move left
	pre(t->rchild); // move right
}


// for you
void bstree::post(treenode * t)
{
	if ( t == NULL ) // if end of tree
		return;
	
	post(t->lchild); // move left
	post(t->rchild); // move right
	printf("%2d ", t->dat); // print val
}


void bstree::paren(treenode * t) // private function
{

}


void bstree::in() // inorder public function
{
	in(root); // calls private function
}


void bstree::pre() // preorder public function
{
	pre(root); // calls private function
}


// for you
void bstree::post() // post order public function
{
	post(root); // calls private function
}


void bstree::paren() // parent public function
{
	paren(root); // calls private function
}


// for you
void bstree::insert( int x ) // insert public function
{
	treenode *t1; // declare pointer
	
	t1 = new treenode(); // make a new node t1
	t1->dat = x; // assign x val
	t1->lchild = NULL; // point to NULL
	t1->rchild = NULL; // point to NULL
	
	if ( root == NULL ) // if there isn't anything in the root
	{
		root = t1; // make node the new node the root node
	}
	else // if root isn't empty
	{
		insert( root, t1 ); // call private method and pass tree and new node
	}
}


/*
// for you - optional recursive
void bstree::insert( treenode *t, treenode *n )
{
	
}
*/


void bstree::search( int x ) // public method
{
	if ( findval( x, root ) )
	{
		cout << "Value: " << x << " found in tree." << endl;
	}
	else 
	{
		cout << "Value: " << x << " not found in tree." << endl;
	}
}

// for you
treenode *bstree::findval( int x, treenode *t) // findval private method
{
	if ( t == NULL ) // empty or node not in the tree
	{
		return 0;
	}
	if ( x < t->dat ) // if value is less than node go Left
	{
		findval( x, t->lchild ); // call again
	} 
	else if ( x > t->dat ) // if value is greater than node go Right
	{ 
		findval( x, t->rchild ); // call again
	} 
	else // if not greater or less than it's equal. found it
	{ 
		return t; // return found node
	}
}

// for you - THIS DOESN'T WORK RIGHT
void bstree::remove( int x ) // remove public method
{
    treenode *t, *rem, *parent; // declare pointers for nodes
    t = root; // assign tree pointer to t
    rem = NULL; // point rem to NULL
	z = findval( x, root ); // for T/F for main. Doesn't do anything for this function.

    if( t == NULL ) // if tree is empty
	{
		return;
	}
	
    while( 1 ) // while true. Finds parent node.
	{  
        if( t->dat == x ) // find the node
		{
            rem = t; // make the fouund node the target to be deleted
		}
		
        if( x < t->dat ) // if it's a left leaf
		{
            
            if( t->lchild == NULL ) // remove it
			{
                break; // break from loop
			}
            parent = t; // assign the reference to the parent
            t = t->lchild; // move left
        }
        else // if it's a right leaf
		{   
            if( t->rchild == NULL ) // remove it  
			{
                break; // break from loop
			}
            parent = t; // assign the reference to the parent
            t = t->rchild; // move right
        }
    }
	
    if( rem == NULL ) // check if rem is valid
	{
        return;
    }
    else
	{
        if( parent == NULL ) // check if root node
		{
            delete t; // remove node
            root = NULL; // set root to NULL
        }
        else  
		{
            rem->dat = t->dat; // move value to the root
            if( parent->lchild == t )
			{
                parent->lchild = t->rchild; // move value to parent
            }
            else
			{
                parent->rchild = t->lchild;
                delete t; // remove node
            }
        }
    }
}


// for you
int bstree::_numnodes(treenode * t) // _numnodes private method
{
	int c = 1; // count the node itself
	
	if ( t == NULL ) // if end of tree
	{
		return 0;
	}
	else
	{
		if ( t->lchild != NULL )
		{
			c += _numnodes(t->lchild); // count all left nodes
		}
		if ( t->rchild != NULL )
		{
			c += _numnodes(t->rchild); // cout all right nodes
		}
		return c; // return the count
	}
}


int bstree::numnodes() // numnodes public method
{
	int ans;
	ans = _numnodes(root);
	return ans;
}


// for you
int bstree::_height(treenode * t) //_height private method
{
	int left, right;
	
	if ( t == NULL ) // if tree is empty
	{
		return 0;
	}
	else // find length of each sub tree
	{
		left = _height(t->lchild); // left tree
		right = _height(t->rchild); // right tree
		
		// user larger one
		if ( left > right ) // if left branch is longer
		{
			return( left + 1 );
		}
		else // if right branch is longer
		{
			return( right + 1 );
		}
	}
}

int bstree::height() // height public method
{
	int ans;
	ans = _height(root);
	return ans;
}


int main(int argc, char *argv[])
{
	bstree * t;
	int i, x, cmd, a, b;
	ifstream ifp;
	
	if (argc != 2) // make sure there are 2 args passed
	{
		cout << "ERROR:  no BST CMD file " << endl;
		return 2;
	}

	ifp.open( argv[1] ); // open passed file

	if ( ! ifp.is_open() ) // if I can't find/open file
	{
		 cout << "ERROR: file " << argv[1] << " could not be opened" << endl;
		 return 3;
	}

	t = new bstree(); // create new tree

	// read from command file
	
	ifp >> a; // grab first number in file
	
	while( a != 0 ) // read line by line and parse numbers
	{	
		if ( a == 0 )
		{
			exit(1);
		}
		else if ( a == 1 ) // insert
		{
			ifp >> b; // grab the second number
			t->insert( b );
		}
		else if ( a == -1 ) // delete
		{
			ifp >> b;
			t->remove( b );
			
			if( z ) // if the value is found in the tree
			{
				cout<<"Value: " << b << " removed from tree." << endl;
			}
			else // otherwise
			{
				cout<<"Node not found."<< endl;
			}
		}
		else if ( a == 2 ) // find value
		{
			ifp >> b; // grab the second number
			t->search( b );
		}
		else if ( a == 3 ) // preorder
		{
			t->pre( );
			printf("\n");
		}
		else if ( a == 4 ) // inorder
		{
			t->in( );
			printf("\n");
		}
		else if ( a == 5 ) // postorder
		{
			t->post( );
			printf("\n");
		}
		else if ( a == 7 ) // print number of nodes in tree
		{
			cout << "Number of nodes in tree is: " << t->numnodes( );
			printf("\n");
		}
		else if ( a == 8 ) // print height of tree - number of levels/layers
		{
			cout << "The height of the tree is: " << t->height( );
			printf("\n");
		}
		
		ifp >> a; // get next line
	}
	
	ifp.close(); // close the file

	return 0;
}


