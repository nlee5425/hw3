 #include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
	
	if ( head == nullptr) { //base case
		smaller = nullptr;
		larger = nullptr;
		return;
	}
	llpivot( head->next, smaller, larger, pivot); //head recurison going through all values
	int value = head->val;
	if (value <= pivot) { //if less, add to smaller node
		head->next = smaller;
		smaller = head;
		head = nullptr;
	}
	else { //if greater, add to larger node
		head->next = larger;
		larger = head;
		head = nullptr;
	}
}


