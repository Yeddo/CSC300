#include "q.h"

int main()
{

 queue s;
 queue t;
 s = makeq();
 t = makeq();

 int x;

 enq(s, 4);
 enq(s, 6);
 enq(t, 7);
 enq(t, 5);
 enq(t, 3);
 enq(s, 8);
 printf("s starting \n");
 showq(s);
 printf("t starting\n");
 showq(t);
// return 0;
 x = deq(s); 
 printf("%d deqd from s\n", x);
 printf("s after deq\n");
 showq(s);
// return 0;

 x = deq(t); 
 printf("%d deqd from t\n", x);
 printf("t after deq\n");
 showq(t);
 x = deq(t); 
 printf("%d deqd from t\n", x);
 printf("t after deq\n");
 showq(t);
 if (isEmptyq(t))
   printf("-- ^ t is empty\n");
 else
   printf("-- ^ t is not empty\n");
 
 x = deq(t); 
 printf("%d deqd from t\n", x);
 printf("t after deq\n");
 showq(t);
 if (isEmptyq(t))
   printf("-- ^ t is empty\n");
 else
   printf("-- ^ t is not empty\n");

 return 0; 
}
