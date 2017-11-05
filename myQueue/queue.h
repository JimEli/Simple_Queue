/*************************************************************************
* Title: myQueue
* File: queue.h
* Author: James Eli
* Date: 9/15/2017
*
* Implement of the queue.h (declarations).
*
* Notes:
*  (1) Compiled with MS Visual Studio 2017 Community (v141), using C
*      language options.
*
* Submitted in partial fulfillment of the requirements of PCC CIS-265.
*************************************************************************
* Change Log:
*   09/15/2017: Initial release. JME
*************************************************************************/
#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// typedefs which hide implementation details.
typedef struct Node_ *Node;   // Pointer to node.
typedef struct Queue_ *Queue; // Pointer to queue.

// Create new queue.  Note: return from this function is used in calls to all other queue functions.
Queue createQueue(void);
// Free queue and all of its nodes.
void destroyQueue(Queue);

// Add new node to head of queue.
bool enQueue(Queue, const int);
// Remove queue node from tail.
bool deQueue(Queue, int *);

// Determine if queue is empty.
int emptyQueue(const Queue);
// Return queue node count.
size_t sizeQueue(Queue);

// Return head of queue.
Node headQueue(const Queue);
// Return tail of queue.
Node tailQueue(const Queue);

// Return head of queue value or NULL if empty.
bool peekHeadQueue(const Queue, int *);
// Return tail of queue value or NULL if empty.
bool peekTailQueue(const Queue, int *);

// Print contents of queue from head to tail.
void printFromHeadQueue(const Queue);
// Print contents of queue from tail to head.
void printFromTailQueue(const Queue);
// Basic print in forward direction.
#define printQueue(q) printFromHeadQueue(q)

#endif /* _QUEUE_H_ */

