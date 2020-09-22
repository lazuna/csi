#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
	int data;
	int key;
	struct node* next;
};

struct node* head = NULL;
struct node* current = NULL;

// Display the list
void printList() {
	struct node* ptr = head;
	printf("\n[ ");

	// Start from the beginning
	while (ptr != NULL) {
		printf("(%d, %d) ", ptr->key, ptr->data);
		ptr = ptr->next;
	}

	printf(" ]");
}

// Insert link at the first location
void insertFirst(int key, int data) {
	// Create a link
	struct node* link = (struct node*)malloc(sizeof(struct node));

	link->key = key;
	link->data = data;

	// Point it to old first node
	link->next = head;

	// Point first to new first node
	head = link;
}

// Delete first item
struct node* deleteFirst() {
	// Save reference to first link
	struct node* tempLink = head;

	// Mark next to first link as first
	head = head->next;

	// Return the deleted link
	return tempLink;
}

// Is list empty?
bool isEmpty() {
	return head == NULL;
}

int length() {
	int length = 0;
	struct node* current;

	for (current = head; current != NULL; current = current->next) {
		length++;
	}
	return length;
}

// Find a link with given key
struct node* find(int key) {
	// Start from the first link
	struct node* current = head;

	// If list is empty
	if (head == NULL) {
		return NULL;
	}

	// Navigate through list
	while (current->key != key) {
		// If it is last node
		if (current->next == NULL) {
			return NULL;
		}
		else {
			// Go to next link
			current = current->next;
		}
	}

	// If data found, return the current link
	return current;
}

// Delete a link with given key
struct node* delete(int key) {
	// Start from the first link
	struct node* current = head;
	struct node* previous = NULL;

	// If list is empty
	if (head == NULL) {
		return NULL;
	}

	// Navigate through list
	while (current->key != key) {
		// If it is last node
		if (current->next != NULL) {
			return NULL;
		}
		else {
			// Store refrence to current link
			previous = current;
			// Move to next link
			current = current->next;
		}
	}

	// Found a match, update the link
	if (current == head) {
		// Change first to point to next link
		head = head->next;
	}
	else {
		// Bypass the current link
		previous->next = current->next;
	}

	return current;
}

void sort() {
	int i, j, k, tempKey, tempData;
	struct node* current;
	struct node* next;

	int size = length();
	k = size;

	for (i = 0; i < size - 1; i++, k--) {
		current = head;
		next = head->next;

		for (j = 1; j < k; j++) {
			tempData = current->data;
			current->data = next->data;
			next->data = tempData;

			tempKey = current->key;
			current->key = next->key;
			next->key = tempKey;
		}

		current = current->next;
		next = next->next;
	}
}

void reverse(struct node** head_ref) {
	struct node* prev = NULL;
	struct node* current = *head_ref;
	struct node* next;

	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	*head_ref = prev;
}

int main() {
	insertFirst(1, 10);
	insertFirst(2, 20);
	insertFirst(3, 30);
	insertFirst(4, 1);
	insertFirst(5, 40);
	insertFirst(6, 56);

	printf("List: ");
	printList();

	while (!isEmpty()) {
		struct node* temp = deleteFirst();
		printf("\nDeleted value: ");
		printf("(%d, %d) ", temp->key, temp->data);
	}

	printf("\nList after deleting all items: ");
	printList();
	insertFirst(1, 10);
	insertFirst(2, 20);
	insertFirst(3, 30);
	insertFirst(4, 1);
	insertFirst(5, 40);
	insertFirst(6, 56);

	printf("\nRestored List: ");
	printList();
	printf("\n");

	struct node* foundLink = find(4);

	if (foundLink != NULL) {
		printf("Element found: ");
		printf("(%d, %d)", foundLink->key, foundLink->data);
		printf("\n");
	}
	else {
		printf("Element not found.");
	}

	delete(4);
	printf("List after deleting an item: ");
	printList();
	printf("\n");
	foundLink = find(4);

	if (foundLink != NULL) {
		printf("Element found: ");
		printf("(%d, %d)", foundLink->key, foundLink->data);
		printf("\n");
	}
	else {
		printf("Element not found.");
	}

	printf("\n");
	sort();

	printf("List after sorting the data: ");
	printList();
	printf("\n");
}
