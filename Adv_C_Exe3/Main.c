#include <stdio.h>
#include "Stack.h"
#include "Queue.h"
#include <string.h>

//#define STACK_Q1    //
//#define STACK_Q2   //Polindrome
//#define STACK_Q3     //Stack Rotation

//#define QUEUE_PART1 //all manage functions: init, enqueue, dequeue,destroyQueue, isEmptyQueue
//#define QUEUE_PART2 // rotateQueue
//#define QUEUE_PART3 //cutAndReplace
#define QUEUE_PART4

void main()
{
#ifdef STACK_Q1

    printf("\n\n");
    printf("////**** Tests for  Stack flipBetweenHashes ****////\n\n\n");


    //Text test1//

    printf("Test1: \n");
    char textTest1[] = { "Remem#reb# thi#carp s#tice" };
    printf("Before : %s\n", textTest1);

    printf("After: ");
    flipBetweenHashes(&textTest1);
    printf("\n\n");
    //Text test2//
    printf("Test2: \n");
    char textTest2[] = { "#meR#embe#siht r# practice" };
    printf("Before : %s\n", textTest2);
    printf("After: ");
    flipBetweenHashes(&textTest2);
    printf("\n\n");

    printf("Test3: \n");
    char textTest3[] = { "#remember this practice" };
    printf("Before : %s\n", textTest3);
    printf("After: ");
    flipBetweenHashes(&textTest3);

    printf("\n\n");

#endif // STACK_Q1

#ifdef STACK_Q2

    ////#### Tests for  Stack Polindrom ####////
    printf("\n\n");
    printf("                          ////**** Tests for  Stack Polidrome ****////\n\n\n");

    char pol[] = { "NOON" };
    int polindrom = 0;
    Stack newStack;
    Stack newStack2;
    Stack newStack3;

    initStack(&newStack);
    initStack(&newStack2);
    initStack(&newStack3);

    for (int i = 0; i < strlen(pol); i++)
    {
        push(&newStack, pol[i]);
    }
    printf("**********************************\n");
    printf("Stack values: \n");
    display(&newStack);
    printf("\n\n");


    printf("Test 1: \n ");
    polindrom = isPalindrome(&newStack);

    if (polindrom)
        printf("Polindrom\n");
    else
        printf("Not palindrome\n");

    destroyStack(&newStack);

    ///Test 2 : Polindrom
    char pol2[] = { "MADAM" };

    for (int i = 0; i < strlen(pol2); i++)
    {
        push(&newStack2, pol2[i]);
    }

    printf("\n");
    printf("**********************************\n");

    printf("Stack values: \n");
    display(&newStack2);
    printf("\n\n");

    printf("Test 2: \n ");

    polindrom = isPalindrome(&newStack2);

    if (polindrom)
        printf("Polindrom\n");
    else
        printf("Not palindrome\n");

    destroyStack(&newStack2);


    ///Test 3: Not Polindrom
    char pol3[] = { "MAD1AM" };

    for (int i = 0; i < strlen(pol2); i++)
    {
        push(&newStack3, pol3[i]);
    }

    printf("\n");
    printf("**********************************\n");
    printf("Stack values: \n");
    display(&newStack3);
    printf("\n\n");

    printf("Test 3:\n ");

    polindrom = isPalindrome(&newStack3);

    if (polindrom)
        printf("Polindrom\n");
    else
        printf("Not palindrome\n");

    destroyStack(&newStack3);

    printf("**********************************\n");
    //Test 4: Empty Polindrom
    printf("\n ");
    printf("Test 4:Empty Stack\n");
    newStack3.head = NULL;

    printf("Stack values: \n");
    display(&newStack3);
    polindrom = isPalindrome(&newStack3);

    if (polindrom)
        printf("Polindrom\n");
    else
        printf("Not palindrome\n");



#endif // STACK_Q2

#ifdef STACK_Q3

    char textRotate[] = { "DEFABC" };

    Stack StackTest1;
    Stack StackTest2;
    Stack StackTest3;



    initStack(&StackTest1);
    initStack(&StackTest2);
    initStack(&StackTest3);


    for (int i = 0; i < strlen(textRotate); i++)
    {
        push(&StackTest1, textRotate[i]);
        push(&StackTest2, textRotate[i]);
        push(&StackTest3, textRotate[i]);
    }

    ////#### Tests for  Stack Rotation ####////
    printf("\n\n");
    printf("                          ////**** Tests for  Stack Rotation ****////\n\n\n");
    // size 3 //
    printf("Original Stack values : \n");
    display(&StackTest1);

    printf("\n\n");

    printf("Test 1 : Rotate 3 values \n ");
    rotateStack(&StackTest1, 3);
    printf("\n\n");

    // bigger then stack size //
    printf("Test 2 : input size  bigger then the stack size \n ");
    rotateStack(&StackTest2, 7);
    printf("\n\n");
    // Size equla to the stack size //

    printf("Test 3 :Rotate max size stack \n");
    rotateStack(&StackTest3, 6);
    printf("\n\n");
    // Empty stack //

    StackTest1.head = NULL;
    printf("Test 3 :Empty stack \n");
    rotateStack(&StackTest1, 6);
    printf("\n\n");
    printf(" \n");

#endif // STACK_Q3

#ifdef QUEUE_PART1
    Queue sQueueData;
    initQueue(&sQueueData);
    enqueue(&sQueueData,10);
    enqueue(&sQueueData, 20);
    enqueue(&sQueueData, 30);
    enqueue(&sQueueData, 40);
    printf("Queue is %s\n", (isEmptyQueue(&sQueueData) ? "empty" : "not empty"));
    printQueue(&sQueueData);
    printf("Dequeu value %d from queue\n", dequeue(&sQueueData));
    printQueue(&sQueueData);
    printf("Dequeu value %d from queue\n", dequeue(&sQueueData));
    printQueue(&sQueueData);
    printf("Destroy queue\n");
    destroyQueue(&sQueueData);
    printf("Queue is %s\n", (isEmptyQueue(&sQueueData) ? "empty" : "not empty"));

#endif /*QUEUE_PART1*/

#ifdef QUEUE_PART2
    Queue sQueueData;
    initQueue(&sQueueData);
    enqueue(&sQueueData, 10);
    enqueue(&sQueueData, 20);
    enqueue(&sQueueData, 30);
    enqueue(&sQueueData, 40);

    printf("Before rotate(first try)\n");
    printQueue(&sQueueData);
    rotateQueue(&sQueueData);
    printf("After rotate(first try)\n");
    printQueue(&sQueueData);

    printf("Before rotate(sec try)\n");
    printQueue(&sQueueData);
    rotateQueue(&sQueueData);
    printf("After rotate(sec try)\n");
    printQueue(&sQueueData);

    printf("Before rotate(third try)\n");
    printQueue(&sQueueData);
    rotateQueue(&sQueueData);
    printf("After rotate(third try)\n");
    printQueue(&sQueueData);
#endif

#ifdef QUEUE_PART3
    Queue sQueueData;
    initQueue(&sQueueData);
    enqueue(&sQueueData, 6);
    enqueue(&sQueueData, 1);
    enqueue(&sQueueData, 5);
    enqueue(&sQueueData, 2);
    enqueue(&sQueueData, 3);
    enqueue(&sQueueData, 1);
    enqueue(&sQueueData, 9);

    printf("Before cutAndReplace(first try)\n");
    printQueue(&sQueueData);
    cutAndReplace(&sQueueData);
    printf("After cutAndReplace(first try)\n");
    printQueue(&sQueueData);

    destroyQueue(&sQueueData);
    enqueue(&sQueueData, 6);
    enqueue(&sQueueData, 5);
    enqueue(&sQueueData, 2);
    enqueue(&sQueueData, 3);
    enqueue(&sQueueData, 1);
    enqueue(&sQueueData, 9);

    printf("Before cutAndReplace(sec try)\n");
    printQueue(&sQueueData);
    cutAndReplace(&sQueueData);
    printf("After cutAndReplace(sec try)\n");
    printQueue(&sQueueData);

#endif

#ifdef QUEUE_PART4
    Queue sQueueData;
    initQueue(&sQueueData);
    enqueue(&sQueueData, 3);
    enqueue(&sQueueData, 5);
    enqueue(&sQueueData, 1);
    enqueue(&sQueueData, 2);
    enqueue(&sQueueData, 4);
    enqueue(&sQueueData, 6);
    enqueue(&sQueueData, 7);

    printf("Before sortKidsFirst\n");
    printQueue(&sQueueData);
    sortKidsFirst(&sQueueData);
    printf("After sortKidsFirst\n");
    printQueue(&sQueueData);
#endif
}