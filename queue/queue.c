#include "queue.h"

queue* queueCreate(unsigned capacity){ 
	queue* q = malloc(sizeof(queue)); 
	//q->capacity = 
	//q->front = 
	//q->rear = 
	//q->array = 
	return q;
}

void queueDestroy(queue* q){
	//free array in q
	//free q
}

int queueIsFull(queue* q){

}

int queueIsEmpty(queue* q){

}

int queueEnqueue(queue* q, int* value){ 

}

int queueDequeueFront(queue* queue, int* container){ 

}

int queueDequeueRear(queue* queue, int* container){

}

int* queueFront(queue* queue){

}

int* queueRear(queue* queue){ 

}

void queuePrint(queue* q){
	printf("queue(^: front, *: rear): [");
	int i;
	for(i = 0; i < q->capacity; i++){
		printf("%d", q->array[i]);
		if(i == q->front) printf("^");
		if(i == q->rear) printf("*");
		i == q->capacity - 1 ? printf("] ") : printf(", ");
	}
	printf("size=%d, capacity=%d\n", q->size, q->capacity);
}

