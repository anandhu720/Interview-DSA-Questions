// Implement a Queue using an Array. Queries in the Queue are of the following type:
// (i) 1 x   (a query of this type means  pushing 'x' into the queue)
// (ii) 2     (a query of this type means to pop element from queue and print the poped element)



class MyQueue
{
private:
    int arr[100005];
    int front;
    int rear;

public:
    MyQueue()
    {
        front = 0;
        rear = 0;
    }
    void push(int);
    int pop();
};


/* 

The structure of the class is
class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};
 */

/* The method push to push element into the queue */
void MyQueue ::push(int x)
{
    // Your Code
    arr[rear] = x;
    rear++;
}

/*The method pop which return the element 
  poped out of the queue*/
int MyQueue ::pop()
{
    // Your Code
    if (rear == front)
        return -1;
    else
    {
        int temp = arr[front];
        front++;
        return temp;
    }
}
