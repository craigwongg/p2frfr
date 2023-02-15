#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "queue.h"

typedef struct queue {
	/* TODO Phase 1 */
	struct node *head, *tail;
	int size;
}queue;

typedef struct node {
	void* data;
	struct node *next, *prev;
}node;

queue_t queue_create(void)
{
	/* TODO Phase 1 */

	// Dynamically allocate space for queue 
	queue* q = (queue*)malloc(sizeof(queue));

	// In case of failure when allocating the new queue
	if (q == NULL) {
		return NULL;
	}

	// Initializing head/tail to NULL and size to q
	q -> head = NULL;
	q -> tail = NULL;
	q -> size = 0;

	// Return new queue
	return q;
}

int queue_destroy(queue_t queue)
{
	/* TODO Phase 1 */

	// Checking if queue is null or queue is not empty
	if (queue == NULL || queue -> size != 0) {
		return -1;
	}
	
	// Deallocate
	free(queue);
	return 0;
}

int queue_enqueue(queue_t queue, void *data)
{ 
	/* TODO Phase 1 */

	// Checking to see if queue is NULL
	if (queue == NULL) {
		return -1;
	}

	// Allocating a new node for data
	node *n = malloc(sizeof(node));
	if (n == NULL) {
		return -1;
	}

	// Initializing new node
	n -> data = data;
	n -> next = NULL;
	n -> prev = queue -> tail;

	// If queue empty, set head and tail to the new node
	if (queue -> size == 0) {
		queue -> head = n;
		queue -> tail = n;
	}

	// Else, add the new node to end of queue
	else {
		queue -> tail -> next = n;
		n -> prev = queue -> tail;
		queue -> tail = n;
	}

	// Increment size of queue
	queue -> size++;
	return 0;
	
}

int queue_dequeue(queue_t queue, void **data)
{
	/* TODO Phase 1 */
	if (queue == NULL || data == NULL) {
		return -1;
	}
	if (queue -> size == 0) {
		return -1;
	}

	struct node *oldest = queue -> head; 
	queue -> head = oldest -> next;
	queue -> size--;
	*data = oldest -> data;

	free(oldest);
	return 0;
}

int queue_delete(queue_t queue, void *data)
{
	/* TODO Phase 1 */
	if (queue == NULL || data == NULL) {
		return -1;
	}
	// curr points to head
	node *curr = queue -> head;
	// loop through entire queue
	for (int i = 0; i < queue -> size; i++) {
		// check if data is equal to input data
		if (curr -> data == data) {
			if (curr == queue -> head) {
				queue -> head = curr -> next;
			}
			if (curr == queue -> tail) {
				queue -> tail = curr -> prev;
			}
			curr -> prev -> next = curr -> next;
			curr -> next -> prev - curr -> prev;
			queue -> size--;
			free(curr);
			return 0;
		}
	curr = curr -> next;
	}
	return -1;
}

int queue_iterate(queue_t queue, queue_func_t func)
{
	/* TODO Phase 1 */

}

int queue_length(queue_t queue)
{
	/* TODO Phase 1 */
	// Return -1 when queue is NULL
	if (queue == NULL) {
		return -1;
	}
	// Return queue length
	return queue -> size;	
}

