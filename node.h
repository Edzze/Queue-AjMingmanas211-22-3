#ifndef node_h
#define node_h

class NODE {
  // int data;
  int order_number, qty;
  NODE *nextPtr;

public:
  NODE(int, int);
  ~NODE();
  int get_value();
  void set_next(NODE *);
  NODE *get_next();
};
typedef NODE *NodePtr;

NODE::NODE(int x, int y) {
  order_number = x;
  qty=y;
  nextPtr = NULL;
}

int NODE::get_value() {
  int price;
  switch (order_number)
    {
      case 1:
        price = 100 * qty;
        break;
      case 2:
        price= 20* qty;
        break;
      case 3:
        price = 50*qty;
        break;
    }
  

  return price;
}

NODE *NODE::get_next() { return nextPtr; }

void NODE::set_next(NODE *t) { nextPtr = t; }

NODE::~NODE() { cout << "Your Order is " << order_number << endl; }

#endif