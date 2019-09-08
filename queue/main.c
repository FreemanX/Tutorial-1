#include "queue.h"

int main(int argc, char** argv){
	int i;
	queue *q = queueCreate(5);
	queuePrint(q);
	if(queueFront(q)) printf("front: %d\n", *queueFront(q)); else printf("front is NULL\n");
	if(queueRear(q))  printf("rear: %d\n",  *queueRear(q));  else printf("rear  is NULL\n");
	if(queueDequeueFront(q, &i)) printf("DQ front: %d\n", i); else printf("Empty q\n");
	if(queueDequeueRear (q, &i)) printf("DQ rear:  %d\n", i); else printf("Empty q\n");

	for (i = 0; i < 3; i++){
		if(queueEnqueue(q, &i)) printf("%d enqueued\n", i);
		else printf("enqueue %d failed\n", i);
	}
	queuePrint(q);
	for (i = 3; i < 7; i++){
		if(queueEnqueue(q, &i)) printf("%d enqueued\n", i);
		else printf("enqueue %d failed\n", i);
	}
	queuePrint(q);

	if(queueFront(q)) printf("front: %d\n", *queueFront(q)); else printf("front is NULL\n");
	if(queueRear(q))  printf("rear: %d\n",  *queueRear(q));  else printf("rear  is NULL\n");

	queuePrint(q); 
	if(queueDequeueFront(q, &i)) printf("DQ front: %d\n", i); else printf("Empty q\n");
	if(queueDequeueFront(q, &i)) printf("DQ front: %d\n", i); else printf("Empty q\n");
	if(queueDequeueRear (q, &i)) printf("DQ rear:  %d\n", i); else printf("Empty q\n");
	queuePrint(q); 
	
	for (i = 5; i < 8; i++){
		if(queueEnqueue(q, &i)) printf("%d enqueued\n", i);
		else printf("enqueue %d failed\n", i);
	}
	queuePrint(q);

	if(queueDequeueFront(q, &i)) printf("DQ front: %d\n", i); else printf("Empty q\n");
	if(queueDequeueRear (q, &i)) printf("DQ rear:  %d\n", i); else printf("Empty q\n");
	queuePrint(q); 

	queueDestroy(q);
	return 0;
}
