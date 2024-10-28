#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int queue[SIZE];
int front = 0, rear = 0;

void insertq(int item);
int deleteq();
int searchq(int item);

int main() {
    int data, opt;
    do {
        printf("\n1.Insert\n");
        printf("2.Delete\n");
        printf("3.Search\n");
        printf("4.Exit\n");
        printf("Enter your option: ");
        scanf("%d", &opt);
        switch(opt) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertq(data);
                break;
            case 2:
                data = deleteq();
                if(data != -1) {
                    printf("Deleted item is %d\n", data);
                }
                break;
            case 3:
                if(rear == front) {
                    printf("Queue is empty\n");
                } else {
                    printf("Enter item to be searched: ");
                    scanf("%d", &data);
                    if(searchq(data)) {
                        printf("Found item\n");
                    } else {
                        printf("Item not found\n");
                    }
                }
                break;
            case 4:
                exit(0);
        }
    } while(1);

    return 0; // Ensure main returns an integer 
}

void insertq(int item) {
    // Calculate next position of rear
    int t = (rear + 1) % SIZE;
    if(t == front) {
        printf("Queue is full\n");
        exit(0);
    } else {
        rear = t; // Increment rear only after checking
        queue[rear] = item; // Now insert the item
    }
}

int deleteq() {
    if(front == rear) {
        printf("Queue is empty\n");
        return -1; // Return -1 to indicate an empty queue
    } else {
        front = (front + 1) % SIZE; // Increment front
        return queue[front]; // Return the item
    }
}

int searchq(int item) {
    int tfront = (front + 1) % SIZE; // Start searching from the first item
    while(tfront != (rear + 1) % SIZE) { // Loop until we reach the next element of front
        if(queue[tfront] == item) {
            return 1; // Found the item
        }
        tfront = (tfront + 1) % SIZE; // Move to the next item
    }
    return 0; // Item not found
}

