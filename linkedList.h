
//list or node creating
void* list_genList(void); //generating a Linked List : This must be called once for using a Linked List
int list_addTail(void* obj, void* list); //add a node at the end of the list
int list_addNext(void* obj, void* nd); //add a node at the next of the input node

//check the property of the list/node
int list_isEndNode(void* nd); //tell if the node is the end node (0 : it is NOT the end node, 1 : it is the end node)
int list_len(void* list); //returns the number of nodes in the list

//get the node pointer
void* list_getNextNd(void* nd); //get the next node of the input node
void* list_getNdObj(void* nd); //returns the object of the node

//processing the list
int list_repeatFunc(int (*func)(void* obj, void* arg), void* arg, void* list); //repeat processing func for each node objects


