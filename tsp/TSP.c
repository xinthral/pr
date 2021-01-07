// TODO: I break this and will fix it at some point 1/7/2021

/**
* User: Xinthral
* Date: 4/17/2019
* Last: 4/17/2019
* Comments: Travelling Salesmen Problem,
* Visit all nodes in shortest path
*/

#include "TSP.h"		// Gets the Node data type and the function prototypes
#include <stdlib.h>  	// Needed to get the NULL constant
#include <stdio.h>
#include <float.h>
/*
Print out the point stored at the given node.
You can assume node is not NULL.
*/
void printNode(Node* node) {
	printf("(%f,%f)\n", node->x, node->y);
}

/*
Print out all the points in the tour from first to last.
Passed a pointer to the first node in the tour.
If the first is NULL, doesn't print anything.
*/
void printTour(Node* first) {
	Node* currentNode = first->next;
	int tourLen = tourSize(first);

	if (tourLen > 0) {
		printf("(%f, %f)\n", first->x, first->y);
		while (currentNode != first) {
			printf("(%f, %f)\n", currentNode->x, currentNode->y);
			currentNode = currentNode->next;
		}
	}
}

/*
Get the number of points in the tour.
Passed a pointer to the first node in the tour.
If first is NULL, return a size of 0.
*/
int tourSize(Node* first) {
	int nodeSize = 0;
	Node* currentNode = first;

	if (first != NULL) {
		nodeSize++;
		while (currentNode->next != first) {
			currentNode = first->next;
			nodeSize++;
		}
	}
   	return nodeSize;

}

/*
Calculate the Euclidean distance between two nodes.
You can assume both a and b are both not NULL.
*/
double distance(Node* a, Node* b) {
	double dist = 0.0;
	dist = sqrt(pow((b->x - a->x), 2) + pow((b->y - a->y), 2));
	return dist;
}

/*
Calculate the total distance between all points in the tour.
Since the tour is circular, this includes the distance from the last point back to the start.
Passed a pointer to the first node in the tour.
If first is NULL, return a tour length of 0.0.
*/
double tourDistance(Node* first) {
	double sumDistance = 0.0;
	if (first != NULL) {
		Node* currentNode = first->next;
		if (currentNode != first) {
			sumDistance += distance(first, first->next);
			while (currentNode != first) {
				sumDistance += distance(currentNode, currentNode->next);
				currentNode = currentNode->next;
			}
		}
	}
   	return sumDistance;
}

/*
Add a new point after the point that it is closest to.
If there is a tie, insert it after the first such point you find.
Passed a pointer to the first node in the tour, NULL if creating a new tour.
Returns pointer to the first node in the linked list after the addition.
*/
Node* addNearestNeighbor(Node* first, double x, double y) {

	Node* insertAfterNode = NULL;
	Node* currentNode = NULL;
	Node* previousNode = NULL;
	Node* tempNode = NULL;

	if (first == NULL) {
		printf("First is null\n");
		first = malloc(sizeof(Node));
		first->x = 0;
		first->y = 0;
		first->next = first;
	}

	insertAfterNode = first;
	currentNode = first->next;
	previousNode = first;

	double minDistance = DBL_MAX;
	double calDistance = DBL_MAX;

	while (currentNode != first) {
		calDistance = distance(previousNode, currentNode);
		printf("CalDist: %f\n", calDistance);
		if (calDistance < minDistance) {
			printf("Winner, winner, chicken dinner\n");
			minDistance = calDistance;
			insertAfterNode = previousNode;
			currentNode->next = previousNode->next;
			insertAfterNode->next = currentNode;
		}
		previousNode = currentNode;
		currentNode = currentNode->next;
	}
   	return insertAfterNode->next;
}

/*
Add a new point after the point where it results in the least increase in tour length.
If there is a tie, insert it after the first such point you find.
Passed a pointer to the first node in the tour, NULL if creating a new tour.
Returns pointer to the first node in the linked list after the addition.
*/
Node* addSmallestIncrease(Node* first, double x, double y) {
   return NULL;
}

/*
Deallocate all the memory of the Node structures in the linked list.
Passed a pointer to the first node in the tour.
If first is NULL, don't do anything.
*/
void freeTour(Node* first) {
	if (first != NULL) {
		free(first);
	}
}
