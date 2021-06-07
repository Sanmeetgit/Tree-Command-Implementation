
#include "tree.h"

//To find middle node in a linked list in single traversal
node* midNode(tnode p) {
    if(p == NULL || p->next_ptr == NULL)
        return p;
    node *fast = p;
    node *slow = p;
    while(fast->next_ptr && fast->next_ptr->next_ptr) {
        slow = slow->next_ptr;
        fast = fast->next_ptr->next_ptr;
    }
	
	//returning pointer to middle node
    return slow;
}


/* ---            sort alphabetically             ----*/

//To merge two sorted linked lists
tnode MergeTwoSLL_alpha(tnode L1, tnode L2) {
	//if any one list is empty and other non-empty then return non-empty
	//if both empty then return NULL
    if(!L1 || !L2)
        return L1 != NULL ? L1 : L2;

    node *p = L1, *q = L2, *r = NULL;
    node *head = NULL;
	
	//to set head pointer
    if(strcasecmp(p->fname, q->fname) < 0) {
        head = p;
        r = p;
        p = p->next_ptr;
    }
    else {
        head = q;
        r = q;
        q = q->next_ptr;
    }
	
    while(p && q) {
    	//comparing file names
        if(strcasecmp(p->fname, q->fname) < 0) {
            r->next_ptr = p;
            p = p->next_ptr;
        }
        else {
            r->next_ptr = q;
            q = q->next_ptr;
        }
        r = r->next_ptr;
    }
    if(p)
        r->next_ptr = p;
    if(q)
        r->next_ptr = q;
    return head;
}

//Merge sort
tnode mergeSort_alpha(tnode head) {
	//if head is NULL or only one node present in linked list then return
    if(head == NULL || head->next_ptr == NULL)
        return head;
        
    //find middle node and make two separate linked lists
    node *mid = midNode(head);
    node *Nhead = mid->next_ptr;
    mid->next_ptr = NULL;
	
	//recursive call for two separated linked lists
    node *l1 = mergeSort_alpha(head);
    node *l2 = mergeSort_alpha(Nhead);

    return MergeTwoSLL_alpha(l1, l2);

}

tnode sort_alpha(tnode pt) {
	node *sorted = mergeSort_alpha(pt);
	node *p = sorted;
	
	//to sort subdirectory entries
	while(p) {
		if(p->inner_ptr)
			p->inner_ptr = sort_alpha(p->inner_ptr);
		p = p->next_ptr;
	}
	return sorted;
}

/* ---------------------------------------------------------------------------- */


/* ---            sort reverse alphabetically             ----*/

//To merge two sorted linked lists
tnode MergeTwoSLL_rev_alpha(tnode L1, tnode L2) {
	//if any one list is empty and other non-empty then return non-empty
	//if both empty then return NULL
    if(!L1 || !L2)
        return L1 != NULL ? L1 : L2;

    node *p = L1, *q = L2, *r = NULL;
    node *head = NULL;
	
	//to set head pointer
    if(strcasecmp(p->fname, q->fname) > 0) {
        head = p;
        r = p;
        p = p->next_ptr;
    }
    else {
        head = q;
        r = q;
        q = q->next_ptr;
    }
	
    while(p && q) {
    	//comparing file names
        if(strcasecmp(p->fname, q->fname) > 0) {
            r->next_ptr = p;
            p = p->next_ptr;
        }
        else {
            r->next_ptr = q;
            q = q->next_ptr;
        }
        r = r->next_ptr;
    }
    if(p)
        r->next_ptr = p;
    if(q)
        r->next_ptr = q;
    return head;
}

//Merge sort
tnode mergeSort_rev_alpha(tnode head) {
	//if head is NULL or only one node present in linked list then return
    if(head == NULL || head->next_ptr == NULL)
        return head;
        
    //find middle node and make two separate linked lists
    node *mid = midNode(head);
    node *Nhead = mid->next_ptr;
    mid->next_ptr = NULL;
	
	//recursive call for two separated linked lists
    node *l1 = mergeSort_rev_alpha(head);
    node *l2 = mergeSort_rev_alpha(Nhead);

    return MergeTwoSLL_rev_alpha(l1, l2);

}

tnode sort_rev_alpha(tnode pt) {
	node *sorted = mergeSort_rev_alpha(pt);
	node *p = sorted;
	
	//to sort subdirectory entries
	while(p) {
		if(p->inner_ptr)
			p->inner_ptr = sort_rev_alpha(p->inner_ptr);
		p = p->next_ptr;
	}
	return sorted;
}

/* ---------------------------------------------------------------------------- */

/* ---       sort by last time modification            ----*/

//To merge two sorted linked lists
tnode MergeTwoSLL_last_mod(tnode L1, tnode L2) {
	//if any one list is empty and other non-empty then return non-empty
	//if both empty then return NULL
    if(!L1 || !L2)
        return L1 != NULL ? L1 : L2;

    node *p = L1, *q = L2, *r = NULL;
    node *head = NULL;
	
	//to set head pointer
    if(!last_mod_compare(p, q)) {
        head = p;
        r = p;
        p = p->next_ptr;
    }
    else {
        head = q;
        r = q;
        q = q->next_ptr;
    }
	
    while(p && q) {
    	//comparing file names
        if(!last_mod_compare(p, q)) {
            r->next_ptr = p;
            p = p->next_ptr;
        }
        else {
            r->next_ptr = q;
            q = q->next_ptr;
        }
        r = r->next_ptr;
    }
    if(p)
        r->next_ptr = p;
    if(q)
        r->next_ptr = q;
    return head;
}

//Merge sort
tnode mergeSort_last_mod(tnode head) {
	//if head is NULL or only one node present in linked list then return
    if(head == NULL || head->next_ptr == NULL)
        return head;
        
    //find middle node and make two separate linked lists
    node *mid = midNode(head);
    node *Nhead = mid->next_ptr;
    mid->next_ptr = NULL;
	
	//recursive call for two separated linked lists
    node *l1 = mergeSort_last_mod(head);
    node *l2 = mergeSort_last_mod(Nhead);

    return MergeTwoSLL_last_mod(l1, l2);

}

tnode sort_last_mod(tnode pt) {
	node *sorted = mergeSort_last_mod(pt);
	node *p = sorted;
	
	//to sort subdirectory entries
	while(p) {
		if(p->inner_ptr)
			p->inner_ptr = sort_last_mod(p->inner_ptr);
		p = p->next_ptr;
	}
	return sorted;
}


//comparing last modification time details
//comparing in this sequence => year - month - date - hour - minute - seconds - file name
int last_mod_compare(tnode n1, tnode n2) {
	if(n1->info.last_mod.fyear > n2->info.last_mod.fyear)
		return 1;
	else if(n1->info.last_mod.fyear < n2->info.last_mod.fyear)
		return 0;
	else {
		if(n1->info.last_mod.fmon > n2->info.last_mod.fmon)
			return 1;
		else if(n1->info.last_mod.fmon < n2->info.last_mod.fmon)
			return 0;
		else {
			if(n1->info.last_mod.fdate > n2->info.last_mod.fdate)
				return 1;
			else if(n1->info.last_mod.fdate < n2->info.last_mod.fdate)
				return 0;
			else {
				if(n1->info.last_mod.fhour > n2->info.last_mod.fhour) 
					return 1;
				else if(n1->info.last_mod.fhour < n2->info.last_mod.fhour)
					return 0;
				else {
					if(n1->info.last_mod.fmin > n2->info.last_mod.fmin)
						return 1;
					else if(n1->info.last_mod.fmin < n2->info.last_mod.fmin)
						return 0;
					else {
						if(n1->info.last_mod.fsec > n2->info.last_mod.fsec)
							return 1;
						else if(n1->info.last_mod.fsec < n2->info.last_mod.fsec)
							return 0;
						else {
							if(strcasecmp(n1->fname, n2->fname) >= 0)
								return 1;
							else
								return 0;
						}
					}
				}
			}
		}
	}

}
