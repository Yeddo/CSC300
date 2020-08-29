#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

struct treenode

        int dat;
        treenode *lchild;
        treenode *rchild;
};

class bstree

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
                treenode *root;
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

void bstree::in(treenode * t)

        if ( t == NULL )
                 return;

        in(t->lchild);
        printf("%2d ", t->dat);
        in(t->rchild);
}

void bstree::pre(treenode * t)

        if ( t == NULL )
                 return;

        printf("%2d ", t->dat);
        pre(t->lchild);
        pre(t->rchild);
}

void bstree::post(treenode * t)

        // for you
}

void bstree::paren(treenode * t)
{
}

void bstree::in()

        in(root);
}

void bstree::pre()

        pre(root);
}

void bstree::post()

        // for you
}

void bstree::paren()

        paren(root);
}

void bstree::insert( int x )

        treenode *t1;

        t1 = new treenode();
        t1->dat = x;
        t1->lchild = NULL;
        t1->rchild = NULL;

        // for you
}

void bstree::insert( treenode *t, treenode *n )

        // for you
}

treenode *bstree::findval( int x, treenode *t)

        // for you
}


void bstree::remove( int x )

        treenode *t;
        treenode *rem, *parent;

        rem = findval( x, root );

        // for you
}


int bstree::_numnodes(treenode * t)

        // for you
}

int bstree::numnodes()

        int ans;
        ans = _numnodes(root);
        return ans;
}

int bstree::_height(treenode * t)

        // for you
}

int bstree::height()

        int ans;
        ans = _height(root);
        return ans;
}


int main(int argc, char *argv[])

        bstree * t;
        int i, x, cmd;
        ifstream ifp;

        if (argc != 2)
        {
                cout << "ERROR:  no BST CMD file " << endl;
                return 2;
        }

        ifp.open( argv[1] );

        if ( ! ifp.is_open() )
        {
                 cout << "ERROR: file " << argv[1] << " could not be opened" << endl;
                 return 3;
        }

        t = new bstree();

        // read the command file

        return 0;
}
