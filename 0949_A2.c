#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "a2.h"
typedef struct node{
	int data;
	struct node * next;
}node;
static void print(node *);
static void print(node *root)//code to print the list
{
	node * current = root;
	while(current){
		printf("%d ",current -> data);
		current = current -> next;
	}
}
void sec_big(int *a,int n)
{
    int first = 0;
    node *ptr3 = NULL;
    node *root1 = NULL;
    int second;
	int second_big;
	node * ptr1 = NULL;
	node * ptr2 = NULL;
	node * root = NULL;
	node * current = NULL;
	int size = (int)ceil(log(n) / log(2)) + 1;
	node * binaryCounter[size];
	for(int i = 0;i < size;i++){
		binaryCounter[i] = NULL;
	}
	for(int i = 0;i < n;i++){
		node * newNode = (node *)malloc(sizeof(node));
		newNode -> data = a[i];
		newNode -> next = NULL;
		root = newNode;
		int j = 0;
		while(binaryCounter[j]){
			if(binaryCounter[j] -> data > root -> data) //competetion between two list
			{
				print(binaryCounter[j]);
			    printf("x ");
			    print(root);
			    printf(" = ");
				current = binaryCounter[j] -> next;
			    binaryCounter[j] -> next = root;
			    root -> next = current;
			    root = binaryCounter[j];
			    print(root);
			    printf("\n");
			} 
			else{
				print(binaryCounter[j]);
			    printf("x ");
			    print(root);
			    printf(" = ");
				current = root -> next;
				root -> next = binaryCounter[j];
				binaryCounter[j] -> next = current;
			    print(root);
			    printf("\n");
			}
			binaryCounter[j] = NULL;
			j += 1;
		}
		binaryCounter[j] = root;
	}
	if((n & (n - 1))) // check if the number of element is exact power of two if its not execute if condition
 	{
		while(!binaryCounter[first])//using two pointer method to find the two lists for competetion
		{
			first += 1;
		}
		ptr1 = binaryCounter[first];
		first += 1;
		while(!binaryCounter[first]){
			first += 1;
		}
		ptr2 = binaryCounter[first];
		if(ptr1 -> data > ptr2 -> data){
			print(ptr1);
			printf("x ");
			print(ptr2);
			printf(" = ");
			current = ptr1 -> next;
			ptr1 -> next = ptr2;
			ptr2 -> next = current;
			print(ptr1);
			printf("\n");
		}
		else{
			print(ptr1);
			printf("x ");
			print(ptr2);
			printf(" = ");
			current = ptr2 -> next;
			ptr2 -> next = ptr1;
			ptr1 -> next = current;
			ptr1 = ptr2;
			print(ptr1);
			printf("\n");
		}
        second = first + 1; // now ptr1 will be the winner 
        while(second <= size - 3)//update ptr1 by competing it with rest of the competetors
        {
        	while(!binaryCounter[second]){
        		second += 1;
        	}
        	ptr3 = binaryCounter[second];
        	if((ptr1 -> data > ptr3 -> data )){
        	    print(ptr3);
			    printf("x ");
			    print(ptr1);
			    printf(" = ");
        		current = ptr1 -> next;
        		ptr1 -> next = ptr3;
        		ptr3 -> next = current;
        		print(ptr1);
        		printf("\n");
        		second += 1;
        	}
        	else{
        		print(ptr3);
			    printf("x ");
			    print(ptr1);
			    printf(" = ");
        		current = ptr3 -> next;
        		ptr3 -> next = ptr1;
        		ptr1 -> next = current;
        		ptr1 = ptr3;
        		print(ptr1);
        		printf("\n");
        		second += 1;
        	}
        }
        node* ptr4 = binaryCounter[size - 2];//competition for the last list
       	if((ptr1 -> data > ptr4 -> data )){
        	    print(ptr4);
			    printf("x ");
			    print(ptr1);
			    printf(" = ");
        		current = ptr1 -> next;
        		ptr1 -> next = ptr4;
        		ptr4 -> next = current;
        		print(ptr1);
        		printf("\n");
        	}
        	else{
        		print(ptr4);
			    printf("x ");
			    print(ptr1);
			    printf(" = ");
        		current = ptr4 -> next;
        		ptr4 -> next = ptr1;
        		ptr1 -> next = current;
        		ptr1 = ptr4;
        		print(ptr1);
        		printf("\n");
        	}
        binaryCounter[size - 1] = ptr1;


	}
	//find the second largest
	second_big = binaryCounter[size - 1] -> next -> data;
	current = binaryCounter[size - 1] -> next -> next; 
	while(current){
		if(current -> data > second_big){
			second_big = current -> data;
		}
		current = current -> next;
	}
	printf("\n%d",second_big);
}
