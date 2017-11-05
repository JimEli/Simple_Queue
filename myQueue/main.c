/*************************************************************************
* Title: myQueue
* File: main.c
* Author: James Eli
* Date: 11/5/2017
*
* A queue.
*
* Notes:
*  (1) Compiled with MS Visual Studio 2017 Community (v141), using C
*      language options.
*
* Submitted in partial fulfillment of the requirements of PCC CIS-265.
*************************************************************************
* Change Log:
*   11/05/2017: Initial release. JME
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"
#include "utils.h"

// C/C++ Preprocessor Definitions: _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996) 

// Program starts here.
int main(void) {
	Queue queue; // Our test queue.
	
	// Attempt to create a new queue.
	if ((queue = createQueue()) == NULL) {
		fputs("Could not create a Queue.\n", stdout);
		exit(EXIT_FAILURE);
	}
	
	// Main command dispatch loop.
	while (1) {
		int i;  // Temporary holds queue values.

		switch (fetchCommand("123456qQ")) {
		case '1': // Add item to queue.
			if (getInteger("\nEnter an integer: ", MIN_INPUT, MAX_INPUT, &i)) {
				enQueue(queue, i);
				fputs("Queue contents: ", stdout);
				printQueue(queue);
			}
			break;

		case '2': // Remove item from queue.
			if (deQueue(queue, &i))
				fprintf(stdout, "\nRemoved: %d from queue.", i);
			if (!sizeQueue(queue))
				fputs("\nQueue is empty.\n", stdout);
			else {
				fputs("\nQueue contents: ", stdout);
				printQueue(queue);
			}
			break;

		case '3': // Display head of queue.
			if (peekHeadQueue(queue, &i))
				fprintf(stdout, "\nHead of queue: %d\n", i);
			else
				fputs("\nQueue is empty.\n", stdout);
			break;

		case '4': // Display tail of queue.
			if (peekTailQueue(queue, &i))
				fprintf(stdout, "\nTail of queue: %d\n", i);
			else
				fputs("\nQueue is empty.\n", stdout);
			break;

		case '5': // Display size of queue.
			if (!(i = (int)sizeQueue(queue)))
				fputs("\nQueue is empty.\n", stdout);
			else
				printf("\nSize of queue: %d\n", i);
			break;

		case '6':
			/* no break */
		case 'q':
			/* no break */
		case 'Q': // Quit.
			fputs("\nTerminating program.\n", stdout);
			destroyQueue(queue);
			exit(EXIT_SUCCESS);
			break;

		case '\0':
			/* no break */
		default:
			// Unsupported command.
			fputs("\nUnsupported command entered.\n", stdout);
			break;
		}
	}
}

