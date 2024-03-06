#include "fila.h"
#include <stdbool.h>
#include <stdio.h>

void queue_init(queue *q){
	q->start = q->end = q->size = 0;
}

bool queue_empty(queue q){
	return q.size == 0;
}
bool queue_full(queue q){
	return q.size == MAX_TAM;
}

bool queue_add(queue *q, t_data data){
	if(queue_full(*q)) return false;
	q->itens[q->end] = data;
	q->end = (q->end+1)%MAX_TAM;
	q->size++;

}

bool queue_remove(queue *q, t_data * data){
	if(queue_empty(*q)) return false;
	*data = q->itens[q->start];
	q->start = (q->start+1)%MAX_TAM;
	q->size--;
}

void queue_print(queue q){
	int i, j;
	
	for(i = q.start, j=0 ; j < q.size ; j++, i++) printf("%d\n",q.itens[i%(MAX_TAM-1)]);

}
