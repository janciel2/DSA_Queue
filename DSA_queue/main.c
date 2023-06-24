#include <stdio.h>
#include <stdlib.h>
#include "Circular.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Queue myQueue;
	Queue evenQueue;
	bool deleted;
	int choice, value, i, doubleval, frontval;
	String menuOption[10] = {"Enqueue" , "Dequeue" , "isEmpty", 
							"isFull", "Display", 
							"Visualize", "Front", "RemoveItem",
							"GetEven", "DoubleTheValue"	};
	initQueue(&myQueue);
	initQueue(&evenQueue);
	
	do {
		system("cls");
		printf("MENU\n");
			for(i =0; i < 10; ++i)
				{
					printf("[%d] %s\n", i + 1, menuOption[i]);
				}
			printf("Enter your choice <0 to EXIT>: ");
			scanf("%d", &choice);
			
			switch(choice)
				{
					case 1: printf("Enqueue\n");
							printf("Enter a number: ");
							scanf("%d", &value);
							enqueue(&myQueue, value);
							break;
							
					case 2: printf("Dequeue\n");
							dequeue(&myQueue);
							break;
							
					case 3: printf("isEmpty\n");
							if(isEmpty(myQueue))
								{
									printf("LIST IS EMPTY\n");
								}
							else
								{
									printf("LIST IS NOT EMPTY\n");
								}
							break;
							
					case 4: printf("isFull\n");
							if(isFull(myQueue))
								{
									printf("LIST IS FULL\n");
								}
							else
								{
									printf("LIST IS NOT FULL\n");
								}
							break;
							
					case 5: printf("Display\n");
							display(myQueue);
							break;
							
					case 6: printf("Visualize\n");
							visualize(myQueue);
							break;
							
					case 7: printf("Front\n");
							frontval = front(myQueue);
							printf("\n[FRONT]: %d\n", frontval);
							break;
						
					case 8: printf("Remove Item\n");
							printf("Enter a number: ");
							scanf("%d", &value);
							deleted = removeItem(&myQueue, value);
							break;
							
					case 9: printf("Get Even\n");
							evenQueue = removeEven(&myQueue);
							display(evenQueue);
							break;
							
					case 10: printf("Double the Value\n");
							 printf("Enter a number: ");
							 scanf("%d", &value);
							doubleval = doubleTheValue(&myQueue, value);
							printf("\nNumber of affected elements: %d\n", doubleval);
							break;
					
					case 0: printf("Thank you~!\n");
							break;
					default: printf("INVALID CHOICE\n");
				}
			system("pause");
	}while(choice != 0);
	
	printf("BYE !!\n");
	
	return 0;
}
