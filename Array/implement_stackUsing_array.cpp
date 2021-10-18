// Write a program to implement a Stack using Array.
// Your task is to use the class as shown in the comments in the code editor and complete the functions push() and pop() to implement a stack.


class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};

 */

/* The method push to push element into the stack */
void MyStack ::push(int x)
{
    // Your Code
    if (top >= 1000)
    {
        cout << "Stack Overflow";
    }
    else
    {
        top++;
        arr[top] = x;
    }
}

/*The method pop which return the element 
  poped out of the stack*/
int MyStack ::pop()
{
    
    if (top == -1)
    {
        return -1;
    }
    else
    {
        int x = arr[top];
        arr[top] = 0;
        top--;
        return x;
    }
}
