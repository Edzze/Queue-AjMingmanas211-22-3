#include "node.h"


class Queue {
  NodePtr headPtr, tailPtr;
  int size;

public:
  void enqueue(int, int);
  int dequeue();
  Queue();
  ~Queue(); // dequeue all
};

Queue::Queue() {
  size = 0;
  headPtr = NULL;
  tailPtr = NULL;
}

Queue::~Queue() {
  int i;
  int n = size;

  // while(size>0)
  for (i = 0; i < n; i++)
    dequeue();
}
void Queue::enqueue(int x, int y) {
  NodePtr new_node = new NODE(x,y); // 1.Create
  // 2 Connect
  if (new_node) {
    if (size == 0) {
      headPtr=new_node;
    }
    else {
      tailPtr->set_next(new_node);
    }
    ++size;
    tailPtr=new_node;
  }
  else cout<<"Not enough memory";
}

int Queue::dequeue() {
  int value;
  NodePtr t;
  if (headPtr) {
    // 1. Save the node to be deleted
    t=headPtr;
    value = t->get_value();
    headPtr=headPtr->get_next();

    // 1.5 take the value out to value
    // 2. move (head)

    if(size==1) tailPtr=NULL;
    size--;
    delete t;
    // 3. delete
    return value;
  }
  return -1;
}