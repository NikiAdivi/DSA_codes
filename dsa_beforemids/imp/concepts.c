We can use Divide and Conquer to find a peak in O(Logn) time. The idea is Binary Search based, we compare middle element with its neighbors. If middle element is not smaller than any of its neighbors, then we return it. If the middle element is smaller than the its left neighbor, then there is always a peak in left half (Why? take few examples). If the middle element is smaller than the its right neighbor, then there is always a peak in right half (due to same reason as left half). Following are C and Java implementations of this approach.

int findPeakUtil(int arr[], int low, int high, int n) 
{ 
    // Find index of middle element 
    int mid = low + (high - low)/2;  /* (low + high)/2 */
  
    // Compare middle element with its neighbours (if neighbours exist) 
    if ((mid == 0 || arr[mid-1] <= arr[mid]) && 
            (mid == n-1 || arr[mid+1] <= arr[mid])) 
        return mid; 
  
    // If middle element is not peak and its left neighbour is greater  
    // than it, then left half must have a peak element 
    else if (mid > 0 && arr[mid-1] > arr[mid]) 
        return findPeakUtil(arr, low, (mid -1), n); 
  
    // If middle element is not peak and its right neighbour is greater 
    // than it, then right half must have a peak element 
    else return findPeakUtil(arr, (mid + 1), high, n); 
} 
  
// A wrapper over recursive function findPeakUtil() 
int findPeak(int arr[], int n) 
{ 
    return findPeakUtil(arr, 0, n-1, n); 
} 
  
/* Driver program to check above functions */
int main() 
{ 
    int arr[] = {1, 3, 20, 4, 1, 0}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    printf("Index of a peak point is %d", findPeak(arr, n)); 
    return 0; 
} 



//Matrix multiplication
void multiply(int mat1[][N],  
              int mat2[][N],  
              int res[][N]) 
{ 
    int i, j, k; 
    for (i = 0; i < N; i++) 
    { 
        for (j = 0; j < N; j++) 
        { 
            res[i][j] = 0; 
            for (k = 0; k < N; k++) 
                res[i][j] += mat1[i][k] *  
                             mat2[k][j]; 
        } 
    } 
} 
  


void multipvoid multiply(int mat1[][N],  
              int mat2[][N],  
              int res[][N]) 
{ 
    int i, j, k; 
    for (i = 0; i < N; i++) 
    { 
        for (j = 0; j < N; j++) 
        { 
            res[i][j] = 0; 
            for (k = 0; k < N; k++) 
                res[i][j] += mat1[i][k] *  
                             mat2[k][j]; 
        } 
    } 
} 
  void multiply(int mat1[][N],  
              int mat2[][N],  
              int res[][N]) 
{ 
    int i, j, k; 
    for (i = 0; i < N; i++) 
    { 
        for (j = 0; j < N; j++) 
        { 
            res[i][j] = 0; 
            for (k = 0; k < N; k++) 
                res[i][j] += mat1[i][k] *  
                             mat2[k][j]; 
        } 
    } 
} 
  ly(int mat1[][N],  
              int mat2[][N],  
              int res[][N]) 
{ 
    int i, j, k; 
    for (i = 0; i < N; i++) 
    { 
        for (j = 0; j < N; j++) 
        { 
            res[i][j] = 0; 
            for (k = 0; k < N; k++) 
                res[i][j] += mat1[i][k] *  
                             mat2[k][j]; 
        } 
    } 
} 
  
Queues using two stacks:

using namespace std; 
  
struct Queue { 
    stack<int> s1, s2; 
  
    void enQueue(int x) 
    { 
        // Move all elements from s1 to s2 
        while (!s1.empty()) { 
            s2.push(s1.top()); 
            s1.pop(); 
        } 
  
        // Push item into s1 
        s1.push(x); 
  
        // Push everything back to s1 
        while (!s2.empty()) { 
            s1.push(s2.top()); 
            s2.pop(); 
        } 
    } 
  
    // Dequeue an item from the queue 
    int deQueue() 
    { 
        // if first stack is empty 
        if (s1.empty()) { 
            cout << "Q is Empty"; 
            exit(0); 
        } 
  
        // Return top of s1 
        int x = s1.top(); 
        s1.pop(); 
        return x; 
    } 
}; 
  
// Driver code 
int main() 
{ 
    Queue q; 
    q.enQueue(1); 
    q.enQueue(2); 
    q.enQueue(3); 
  
    cout << q.deQueue() << '\n'; 
    cout << q.deQueue() << '\n'; 
    cout << q.deQueue() << '\n'; 
  
    return 0; 
} 

stack using linked lists:

struct Node { 
    int data; 
    struct Node* link; 
}; 
struct Node* top; 
  
// Utility function to add an element data in the stack 
 // insert at the beginning 
void push(int data) 
{ 
    // create new node temp and allocate memory 
    struct Node* temp; 
    temp = (struct Node*)malloc(sizeof(struct Node)); 
  
    // check if stack (heap) is full. Then inserting an element would 
    // lead to stack overflow 
    if (!temp) { 
        printf("\nHeap Overflow"); 
        exit(1); 
    } 
  
    // initialize data into temp data field 
    temp->data = data; 
  
    // put top pointer reference into temp link 
    temp->link = top; 
  
    // make temp as top of Stack 
    top = temp; 
} 
  
// Utility function to check if the stack is empty or not 
int isEmpty() 
{ 
    return top == NULL; 
} 
  
// Utility function to return top element in a stack 
int peek() 
{ 
    // check for empty stack 
    if (!isEmpty(top)) 
        return top->data; 
    else
        exit(EXIT_FAILURE); 
} 
  
// Utility function to pop top element from the stack 
  
void pop() 
{ 
    struct Node* temp; 
  
    // check for stack underflow 
    if (top == NULL) { 
        printf("\nStack Underflow"); 
        exit(1); 
    } 
    else { 
        // top assign into temp 
        temp = top; 
  
        // assign second node to top 
        top = top->link; 
  
        // destroy connection between first and second 
        temp->link = NULL; 
  
        // release memory of top node 
        free(temp); 
    } 
} 
  
void display() // remove at the beginning 
{ 
    struct Node* temp; 
  
    // check for stack underflow 
    if (top == NULL) { 
        printf("\nStack Underflow"); 
        exit(1); 
    } 
    else { 
        temp = top; 
        while (temp != NULL) { 
  
            // print node data 
            printf("%d->", temp->data); 
  
            // assign temp link to temp 
            temp = temp->link; 
        } 
    } 
} 
  
// main function 
  
int main(void) 
{ 
    // push the elements of stack 
    push(11); 
    push(22); 
    push(33); 
    push(44); 
  
    // display stack elements 
    display(); 
  
    // print top elementof stack 
    printf("\nTop element is %d\n", peek()); 
  
    // delete top elements of stack 
    pop(); 
    pop(); 
  
    // display stack elements 
    display(); 
  
    // print top elementof stack 
    printf("\nTop element is %d\n", peek()); 
    return 0; 
} 



SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode* temp=head;
    SinglyLinkedListNode* n1=create_singly_linked_list_node(data);
    if(temp==NULL)
    {
        head=n1;
        return head;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n1;
    return head;
}


SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
    SinglyLinkedListNode* n1=create_singly_linked_list_node(data);
    if(llist==NULL)
    {
        llist=n1;
        return llist;
    }
    n1->next=llist;
    llist=n1;
    return llist;

}

void reversePrint(SinglyLinkedListNode* head) {
    if(head==NULL)
    {
        return;
    }
    reversePrint(head->next);
    printf("%d\n",head->data);

}


SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
    if(head==NULL)
    {
        return head;
    }
    SinglyLinkedListNode* p=NULL;
    SinglyLinkedListNode* c=head;
    SinglyLinkedListNode* n;
    while(c!=NULL)
    {
        n=c->next;
        c->next=p;
        p=c;
        c=n;
        n=n->next;
    }
    head=p;
    return head;
}

bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    while (head1!=NULL && head2!=NULL)
    {
        if(head1->data!=head2->data)
            return 0;
        head1=head1->next;
        head2=head2->next;
    }
    if(head1==head2)
    {
        return 1;
    }
    else
    return 0;

}

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* l=head1;
    SinglyLinkedListNode* r=head2;
    SinglyLinkedListNode* temp=NULL;
    SinglyLinkedListNode* new_head;
    
    if(l->data < r->data)
    {
        temp=l;
        new_head=l;
        l=l->next;
    }
    else
    {
        temp=r;
        new_head=r;
        r=r->next;
    }

    while(l!=NULL && r!=NULL)
    {
        if(l->data<r->data)
        {
            temp->next=l;
            temp=l;
            l=l->next;
        }
        else
        {
            temp->next=r;
            temp=r;
            r=r->next;
        }
        
    }
    if(l==NULL)
    {
        temp->next=r;
    }

    if(r==NULL)
    {
        temp->next=l;
    }
    return new_head;
}


bool has_cycle(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* l=head;
    SinglyLinkedListNode* r=head;

    while(r!=NULL && r->next!=NULL)//As r is moving at a speed of 2 it might land up at NULL or a place before NULL.So r can become null before r->next becoming null.
    {
        l=l->next;
        r=r->next->next;
        if(l==r)
        {
            return 1;
        }
        
    }
    return 0;

}

SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* temp=head;
    if(head==NULL)
    return head;
    while(temp->next!=NULL)
    {
    while(temp->data == temp->next->data )
    {
        SinglyLinkedListNode* l=temp->next;
        temp->next=temp->next->next;
        l->next=NULL;
        free(l);
        if(temp->next==NULL)
        break;
    }
    if(temp->next!=NULL)
    temp=temp->next;
    }
    return head;
}
/*
SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* temp=head;
    while(temp->next!=NULL)
    {
    if(temp->data == temp->next->data )
    {
        SinglyLinkedListNode* l=temp->next;
        temp->next=temp->next->next;
        l->next=NULL;
        free(l);
    }
    else
    temp=temp->next;//increment only when a node is not deleted.
    }
    return head;
}*/
