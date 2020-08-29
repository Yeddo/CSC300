#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

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

void bstree::in(treenode * t) // private function
{
        if ( t == NULL ) // if end of tree
		{
			return;
		}
        in(t->lchild); // move left
        printf("%2d ", t->dat); // print
        in(t->rchild); // move right
}

void bstree::pre(treenode * t) // private function
{
        if ( t == NULL ) // if end of tree
                 return;

        printf("%2d ", t->dat); // print val
        pre(t->lchild); // go left
        pre(t->rchild); // go right
}

// for you
void bstree::post(treenode * t) // private function
{
	if ( t == NULL ) // if end of tree
	{
			return;
	}
	
	post(t->lchild); // go left
	post(t->rchild); // go right
	printf("%2d ", t->dat); // print val
}

void bstree::paren(treenode * t)
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
void bstree::post() // postorder public class
{
		post(root); // calls private class
}

void bstree::paren() // public class?
{
        paren(root); // calls private class

}
// for you
void bstree::insert( int x ) // public
{
    treenode *t1; // make tree pointer

    t1 = new treenode(); // allocate it
    t1->dat = x; // assign value
    t1->lchild = NULL; // points left to null	
    t1->rchild = NULL; // points right to null
	
	
}

/*
// for you - optional, resursive
void bstree::insert( treenode *t, treenode *n ) // private
{
	if(root == NULL)
	{
		t1 = new treenode(); // allocate it
		t1->data = ?; // assign value. what goes here?
		t1->lchild = NULL;
		t1->rchild = NULL;
	}
	
	if ( n < (*t1)->data)
	{
		insert(&(*t1)->lchild, n);
	}
	else if ( n > (*t1)->data)
	{
		insert(&(*t1)->rchild, n);
	}
}
*/

// for you
treenode *bstree::findval( int x, treenode *t)
{
//	// if given val is not found in BST
//	if ( t == NULL )
//	{
//		return false;
//	}
//	
//	// if given val is found
//	else if ( t->data == x )
//	{
//		return true;
//	}
//	
//	// move left
//	bool res1 = findval(t->lchild, x);
//	
//	// found, no need to continue
//	if(res1)
//	{
//		return true;
//	}
//	
//	// if not found in left tree go right
//	bool res2 = findval(t->rchild, x);
//	
//	return res2;
}


// for you
void bstree::remove( int x )
{
//       treenode *t;
//       treenode *rem, *parent;

//       rem = findval( x, root );

        
}

// for you
int bstree::_numnodes(treenode * t)
{
//	int c = 1; // count the node itself
//	
//	if ( t == NULL ) // if end of tree
//	{
//		return 0;
//	}
//	else
//	{
//		c += _numnodes(t->lchild);
//		c += _numnodes(t->rchild);
//		return c;
//	}
}

int bstree::numnodes()
{
//        int ans;
//        ans = _numnodes(root);
//        return ans;
}

// for you
int bstree::_height(treenode * t)
{
//	if ( t == NULL )
//	{
//		return 0;
//	}
//	else
//	{
//		// find length of each sub tree
//		int lBranch = _height(t->lchild);
//		int rBranch = _height(t->rchild);
//		
//		// user larger one
//		if ( lBranch > rBranch ) // if lBranch is longer
//		{
//			return( lBranch + 1 );
//		}
//		else // if rBranch is longer
//		{
//			return( rBranch + 1 );
//		}
//	}
}

int bstree::height()
{
//        int ans;
//        ans = _height(root);
//        return ans;
}

int main(int argc, char *argv[])
{
        bstree * t;
        int i, x, cmd, a, b;
        ifstream ifp; // create file pointer

        if (argc != 2) // check if there are 2 args
        {
                cout << "ERROR:  no BST CMD file " << endl;
                return 2;
        }

        ifp.open( argv[1] ); // open file

        if ( ! ifp.is_open() ) // if the file could not be opened
        {
                 cout << "ERROR: file " << argv[1] << " could not be opened" << endl;
                 return 3;
        }

        t = new bstree(); // build new tree
		
		// read from command file
		ifp >> a >> b; // get first pair of numbers
		
		while( !ifp.eof() ) // while not the end of file
		{
			if ( a == 0 )
			{
				exit(1);
			}
			else if ( a == 1 ) // insert
			{
				insert(t, b);
			}
			else if ( a == -1 ) // delete
			{
				remove( b );
			}
			else if ( a == 2 ) // search
			{
				findval( b, t );
			}
			else if ( a == 3 ) // preorder
			{
				pre();
			}
			else if ( a == 4 ) // inorder
			{
				in();
			}
			else if ( a == 5 ) // postorder
			{
				post();
			}
			else if ( a == 7 ) // print number of nodes in tree
			{
				cout << "Number of nodes in tree is: " << numnodes();
			}
			else if ( a == 8 ) // print height of tree - number of levels/layers
			{
				height( t );
			}
						
			ifp >> a >> b; // get next pair of numbers			
		}
		

		ifp.close(); // close the file
        return 0;
}
