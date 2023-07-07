#include <iostream>
using namespace std;
#include "node.h"
#include "queue.h"

int main(int argc, char *argv[]) {
  Queue q;

  int i, price;
  for (i = 1; i < argc; i += 2) {
    if (argv[i][0] == 'x') 
    {
      price = q.dequeue();
      // ask customer to pay
      cout << "You have to pay " << price << endl;
      int money, change;

      do{
        cout<<"Cash: ";
        cin>>money;
        if (money<price)
          continue;
        if (money>price)
        {
          change=money-price;
          cout<<"Change: "<<change<<endl;
          cout<<"Thank you"<<endl;
          break;
        }
        if(money==price)
        {
          cout<<"Thank you"<<endl;
          break;
        }
      }while(1);
      i--;
    }

    else {
      q.enqueue(atoi(argv[i]), atoi(argv[i + 1]));
      
    }
  }
  cout << "End of program" << endl;
}
