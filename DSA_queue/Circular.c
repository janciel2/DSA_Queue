#include<stdio.h>
#include<stdlib.h>
#include "Circular.h"

void initQueue(Queue *q)
{
	q->front = 	7;
	q->rear = 6;
	int i;
	for(i = 0; i < MAX; ++i)
		{
			q->elems[i] = EMPTY;
		}
}


void enqueue(Queue *q, int item)
{
	if(!isFull(*q))
		{
			q->rear = (q->rear + 1) % MAX;
			q->elems[q->rear] = item;
		}
}

void dequeue(Queue *q)
{
	if(!isEmpty(*q))
	{
		q->elems[q->front] = EMPTY;
		q->front = (q->front + 1) % MAX;
	}
}
int front(Queue q)
{
	if(!isEmpty(q))
		{
			return q.elems[q.front];
		}
	return EMPTY;
}

bool isEmpty(Queue q)
{
	return (q.rear + 1) % MAX == q.front; 
}

bool isFull(Queue q)
{
	return (q.rear + 2) % MAX == q.front;
}

void visualize(Queue q)
{
	printf("%5s | %5s | %s \n", "INDEX", "VALUE", "POSITION");
	printf("------------------------\n");
	
	int i;
	for(i = 0; i < MAX; i++)
		{
			printf("%5d | ", i);
				if(q.elems[i] == EMPTY)
					{
						printf("%5d | ", q.elems[i]);	
					}
				else
					{
						printf("%5d |", q.elems[i]);
						}	
				if(i == q.front){
							printf("FRONT");
						}
				if(i == q.rear){
							printf("REAR");
						}
							
						
			printf("\n");
		}
		
	printf("------------------------\n");
}

void display(Queue q)
{
	if(!isEmpty(q))
		{
			int i;	
			for(i = q.front; q.elems[i] != EMPTY && i < MAX; i = (i + 1) % MAX)
				{
					printf("%d", q.elems[i]);
						if(q.elems[(i + 1) % MAX] != EMPTY)
							{
								printf(", ");
							}
						if(q.elems[(i + 1) % MAX] == EMPTY)
							{
								printf("\n");
							}
						
						if(q.elems[(i + 1) % MAX] == EMPTY)
							{
								break;	
							}		
				}
		}
}

bool removeItem(Queue *q, int item)
{
	bool deleted = false;
	int i = front(*q);
	if(!isEmpty(*q))
		{
			while(i != EMPTY)
				{
							dequeue(q);
							enqueue(q,i);
							i = front(*q);
					if(i == item)
						{
							dequeue(q);
							deleted = true;
							display(*q);
							return deleted;
						}
				 	if(i == q->elems[q->rear])
					{
						return deleted;
					}					
				}
			
		}
}

/* Removes all even ad returns all delete item store in Q */

Queue removeEven(Queue *q)
{
	Queue qList;
	initQueue(&qList);
	int count = 0, mainCount = 0;
	
	if(!isEmpty(*q))
		{
			int i, v;
			i = front(*q);
			
			for(v = q->front; q->elems[v] != EMPTY &&  v != (v + 2) % MAX; v = (v + 1) % MAX){count++;}
			while( mainCount < count)
				{
					if(i % 2 == 0)
						{
							dequeue(q);
							enqueue(&qList, i);
							i = front(*q);
						}
					if(i % 2 != 0)
						{
							dequeue(q);
							enqueue(q, i);
							i = front(*q);
						}
					mainCount++;
				}
		}
	return qList;
}

/* Doubles the value in Q that is a multiple of the given value and return how many values have been change */
int doubleTheValue(Queue *q, int value)
{
	int retval = 0, i, count = 0, v, mainCount = 0;
	
	i = front(*q);
	
	for(v = q->front; q->elems[v] != EMPTY &&  v != (v + 2) % MAX; v = (v + 1) % MAX){count++;}
	
	for(; mainCount < count;)
			{
				if(i % value == 0)
					{
						i = i * value;
						dequeue(q);
						enqueue(q, i);
						i = front(*q);
						retval++;	
					}
				else if(i % value != 0)
					{
						dequeue(q);
						enqueue(q, i);
						i = front(*q);	
					}
				mainCount++;
			}
	return retval;
}

