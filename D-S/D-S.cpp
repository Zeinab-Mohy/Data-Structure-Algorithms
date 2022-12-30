#include <iostream>
using namespace std;
//node structure
struct node {
	int data;
	node* link;
};
//Array Operation (start)
void selection_sort(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int mm = i;
		for (int ii = i + 1; ii < size; ii++)
		{
			if (arr[mm] > arr[ii])
				mm = ii;
		}
		swap(arr[mm], arr[i]);
	}
}
void print_selection_sort(int arr[], int size)
{
	selection_sort(arr, size);
	cout << "Selection sort sort is activated successfully ....!\n";
	cout << "The sorted array is : [ ";
	for (int i = 0; i < size; i++)
	{
		if (i == size - 1)
			cout << arr[i] << " ]";
		else
			cout << arr[i] << ", ";
	}
}
void insertion_sort(int arr[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >=0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}
void print_insertion_sort(int arr[], int size)
{
	insertion_sort(arr, size);
	cout << "Insertion sort sort is activated successfully ....!\n";
	cout << "The sorted array is : [ ";
	for (int i = 0; i < size; i++)
	{
		if (i == size - 1)
			cout << arr[i] << " ]";
		else
			cout << arr[i] << ", ";
	}
}
void bubble_sort(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int ii = i + 1; ii < size; ii++)
		{
			if (arr[i] > arr[ii])
				swap(arr[i], arr[ii]);
			else
				continue;
		}
	}
}
void print_bubble_sort(int arr[], int size)
{
	bubble_sort(arr, size);
	cout << "Bubble sort is activated successfully ....!\n";
	cout << "The sorted array is : [ ";
	for (int i = 0; i < size; i++)
	{
		if (i == size - 1)
			cout << arr[i] << " ]";
		else
			cout << arr[i] << ", ";
	}
}
int partition_quick_sort(int arr[], int l, int h)
{
	int i = 0, j = h, pivot = arr[l];
	while (i < j)
	{
		while (arr[i] <= pivot)
		{
			i++;
		}
		while (arr[j] > pivot)
		{
			j--;
		}
		if (i < j)
			swap(arr[i], arr[j]);
	}
	swap(arr[l], arr[j]);
	return j;
}
void quick_sort(int arr[], int l, int h)
{
	if (l < h)
	{
		int p = partition_quick_sort(arr, l, h);
		quick_sort(arr, l, p - 1);
		quick_sort(arr, p + 1, h);
	}
}
void print_quick_sort(int arr[], int size, int l, int h)
{
	quick_sort(arr, l, h);
	cout << "Quick sort is activated successfully ....!\n";
	cout << "The sorted array is : [ ";
	for (int i = 0; i < size; i++)
	{
		if (i == size - 1)
			cout << arr[i] << " ]";
		else
			cout << arr[i] << ", ";
	}
}
void binary_search(int arr[], int size)
{
	int key, l = 0, h = size - 1, mid;
	cout << "Binary search is activated successfully ....!\n";
	cout << "Please, enter an element to search using binary search : ";
	cin >> key;
	while (l <= h)
	{
		mid = (l + h) / 2;
		if (key == arr[mid])
		{
			cout << "The element " << key << " is found at index : " << mid << endl;
			break;
		}
		else if (key > arr[mid])
			l = mid + 1;
		else
			h = mid - 1;
	}
}
void linear_search(int arr[], int size)
{
	int key, choice;
	cout << "Linear search is activated successfully ....!\n";
	cout << "Please, enter an element to search using linear search : ";
	cin >> key;
	for (int i = 0; i < size; i++)
	{
		if (key == arr[i])
		{
			cout << "The element " << key << " is found at index : " << i << endl;
			break;
		}
		else
			continue;
	}
	string option;
	cout << "-----------------------------------------\n";
	cout << "-----------------------------------------\n";
	cout << "Do you want to make anthor operation on this array?\n";
	cout << "Type Yes or yes -> for continue\n";
	cout << "Type No or no -> for exit from the array  option only !\n";
	cin >> option;
	if (option == "Yes" || option == "yes")
	{
		cout << "Type  1-> to make a linear search.\n      2-> to make a binary search.\n";
		cin >> choice;
		switch (choice)
		{
			case 1:
				linear_search(arr, size);
				break;
			case 2:
				binary_search(arr, size);
				break;
		}
	}
}
void check_sorted_array(int arr[], int size)
{
	int acount = 1, dcount = 1, choice, exchoice, l = 0, h = size - 1;
	cout << "Checking if the array is sorted or not : ....\n";
	for (int i = 0, j = i + 1; i < size, j < size; i++, j++)
	{
		if (arr[i] < arr[j])
			acount++;
		else if (arr[i] > arr[j])
			dcount++;
	}
	if (acount == size || dcount == size)
	{
		cout << "This array is sorted !\n";
		cout << "The operation available on sorted array are : \n";
		cout << "Type  1-> to make a linear search.\n      2-> to make a binary search.\n";
		cin >> choice;
		switch (choice)
		{
			case 1:
				linear_search(arr, size);
				break;
			case 2:
				binary_search(arr, size);
				break;
		}
	}
	else
	{
		cout << "This array is unsorted !\n";
		cout << "The operation available on unsorted array are : \n";
		cout << "Type  1-> to make a linear search.\n      2-> to make a binary search.(Note you shoud sort it first)!\n      3-> to make a quick sort.\n      4-> to make a bubble sort.\n      5-> to make an insertion sort.\n      6-> to make an selection sort.\n";
		cin >> choice;
		switch (choice)
		{
			case 1:
				linear_search(arr, size);
				break;
			case 2:
				cout << "Binary search is activated successfully but this array is unsorted you must sort it....!\n";
				cout<< " Type 1->to make a quick sort.\n      2->to make a bubble sort.\n      3->to make an insertion sort.\n      4->to make an selection sort.\n";
				cin >> exchoice;
				switch (exchoice)
				{
					case 1:
						print_quick_sort(arr, size, l, h);
						cout << "\n";
						binary_search(arr, size);
						break;
					case 2:
						print_bubble_sort(arr, size);
						cout << "\n";
						binary_search(arr, size);
						break;
					case 3:
						print_insertion_sort(arr, size);
						cout << "\n";
						binary_search(arr, size);
						break;
					case 4:
						print_selection_sort(arr, size);
						cout << "\n";
						binary_search(arr, size);
						break;
				}
				break;
			case 3:
				print_quick_sort(arr, size, l, h);
				break;
			case 4:
				print_bubble_sort(arr, size);
				break;
			case 5:
				print_insertion_sort(arr, size);
				break;
			case 6:
				print_selection_sort(arr, size);
				break;
		}
	}
}
void enter_print_array()
{
	cout << "Array is activated successfully ....!\n";
	int size;
	cout << "Please, enter the size of this array :\n";
	cin >> size;
	int* arr = new int[size];
	cout << "Please, enter the elements of this array : \n";
	for (int i = 0; i < size; i++)
	{
		cout << "Please, enter the element at index " << i << " : ";
		cin >> arr[i];
	}
	cout << "Your array is [ ";
	for (int i = 0; i < size; i++)
	{
		if (i == size - 1)
			cout << arr[i];
		else
			cout << arr[i] << ",";
	}
	cout << " ]\n";
	cout << "-----------------------------------------\n";
	cout << "-----------------------------------------\n";
	check_sorted_array(arr, size);
}
//Array Operation (end)
//Linked List Operation (start)
node* head = NULL;
int linkedlist_linear_search(int data)
{
	int pos = 0;
	node* currant = head;
	if (head == NULL)
	{
		cout << "linked list is empty\n";
	}
	else
	{
		while (currant->data != data)
		{
			pos++;
			currant = currant->link;
			if (currant->data != data && currant->link == NULL)
			{
				pos = 0;
				break;
			}
		}
		if (pos == 0)
		{
			return -1;
		}
		else
		{
			return pos;
		}
	}
}
void linkedlist_searching()
{
	int data;
	cout << "please, enter the element you want to know it's position : ";
	cin >> data;
	int pos = linkedlist_linear_search(data);
	if (pos != -1)
	{
		cout << "the element ( " << data << " ) in position ( " << pos << " ) in linked list\n";
	}
	else
	{
		cout << "this element is not found in this linked list\n";
	}
}
void delete_node_with_an_entered_value(int data)
{
	node* currant = head;
	node* pre = head;
	if (head == NULL)
	{
		cout << "Linked list is empty\n";
	}
	else if (head->data == data)
	{
		head = currant->link;
		delete(currant);
	}
	else
	{
		while (currant->data != data)
		{
			pre = currant;
			currant = currant->link;
		}
		pre->link = currant->link;
		delete(currant);
	}
}
void delete_value()
{
	int data;
	cout << "please, enter element you want delete : ";
	cin >> data;
	delete_node_with_an_entered_value(data);
	node* p = head;
	cout << "Your linked list is [ ";
	while (p != NULL)
	{
		if (p->link == NULL)
		{
			cout << p->data;
			break;
		}
		else
		{
			cout << p->data << ", ";
		}
		p = p->link;
	}
	cout << " ]\n";
	cout << "-----------------------------------------\n";
	cout << "-----------------------------------------\n";
}
void delete_from_end()
{
	node* currant = head;
	if (head == NULL)
	{
		cout << "Linked list is empty\n";
	}
	else if(head->link==NULL)
	{
		delete(head);
	}
	else
	{
		while (currant->link->link != NULL)
		{
			currant = currant->link;
		}
		node* dcurrant = currant->link->link;
		currant->link = NULL;
		delete(dcurrant);
	}
}
void delete_ending()
{
	delete_from_end();
	node* p = head;
	cout << "Your linked list is [ ";
	while (p != NULL)
	{
		if (p->link == NULL)
		{
			cout << p->data;
			break;
		}
		else
		{
			cout << p->data << ", ";
		}
		p = p->link;
	}
	cout << " ]\n";
	cout << "-----------------------------------------\n";
	cout << "-----------------------------------------\n";
}
void delete_from_beginning()
{
	if (head == NULL)
	{
		cout << "Linked list is empty\n";
	}
	else
	{
		node* pre = head;
		head = pre->link;
		delete(pre);
	}
}
void delete_beginning()
{
	delete_from_beginning();
	node* p = head;
	cout << "Your linked list is [ ";
	while (p != NULL)
	{
		if (p->link == NULL)
		{
			cout << p->data;
			break;
		}
		else
		{
			cout << p->data << ", ";
		}
		p = p->link;
	}
	cout << " ]\n";
	cout << "-----------------------------------------\n";
	cout << "-----------------------------------------\n";
}
void insert_between_twonodes(int data, int after)
{
	node* currant = head;
	node* nnode = new node;
	if (currant->data != after)
	{
		currant = currant->link;
	}
	nnode->data = data;
	nnode->link = currant->link;
	currant->link = nnode;
}
void insert_between_twonodes()
{
	int data, after;
	cout << "please, enter the element you want to inset to the linked list?: ";
	cin >> data;
	cout << "please, enter the element you want to inset after it: ";
	cin >> after;
	insert_between_twonodes(data, after);
	node* p = head;
	cout << "Your linked list is [ ";
	while (p != NULL)
	{
		if (p->link == NULL)
		{
			cout << p->data;
			break;
		}
		else
		{
			cout << p->data << ", ";
		}
		p = p->link;
	}
	cout << " ]\n";
	cout << "-----------------------------------------\n";
	cout << "-----------------------------------------\n";
}
void insert_from_end(int data)
{
	node* currant = head;
	node* nnode = new node;
	if (head == NULL)
	{
		nnode->data = data;
		nnode->link = head;
		head = nnode;
	}
	else
	{

		while (currant->link != NULL)
		{
			currant = currant->link;
		}
		nnode->data = data;
		nnode->link = NULL;
		currant->link = nnode;
	}
}
void insert_end()
{
	int size;
	int data;
	cout << "How many element do you want to inset them to this linked list?: ";
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		cout << "Please, enter the element " << i+1 << " : ";
		cin >> data;
		insert_from_end(data);
	}
	node* p = head;
	cout << "Your linked list is [ ";
	while (p != NULL)
	{
		if (p->link == NULL)
		{
			cout << p->data;
			break;
		}
		else
		{
			cout << p->data << ", ";
		}
		p = p->link;
	}
	cout << " ]\n";
	cout << "-----------------------------------------\n";
	cout << "-----------------------------------------\n";
}
void insert_at_beginning(int data)
{
	node* nnode = new node;
	nnode->data = data;
	nnode->link = head;
	head = nnode;
}
void insert_beginning()
{
	int size;
	int data;
	cout << "How many element do you want to inset them to this linked list?: ";
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		cout << "Please, enter the element " << i + 1 << " : ";
		cin >> data;
		insert_at_beginning(data);
	}
	node* p = head;
	cout << "Your linked list is [ ";
	while (p != NULL)
	{
		if (p->link == NULL)
		{
			cout << p->data;
			break;
		}
		else
		{
			cout << p->data << ", ";
		}
		p = p->link;
		
	}
	cout << " ]\n";
	string option;
	int choice;
	cout << "-----------------------------------------\n";
	cout << "-----------------------------------------\n";
	cout << "Do you want to make anthor operation on this linked list?\n";
	cout << "Type Yes or yes -> for continue\n";
	cout << "Type No or no -> for exit from the linked list  option only !\n";
	cout << "-----------------------------------------\n";
	cin >> option;
	if (option == "Yes" || option == "yes")
	{
		cout << "Type  1-> to insert from end.\n      2-> to insert node between two nodes(after node).\n      3-> to delete from beginning.\n      4-> to delete from end.\n      5-> to delete node with an entered value.\n      6-> to make linear search.\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			insert_end();
			break;
		case 2:
			insert_between_twonodes();
			break;
		case 3:
			delete_beginning();
			break;
		case 4:
			delete_ending();
			break;
		case 5:
			delete_value();
			break;
		case 6:
			linkedlist_searching();
			break;
		}
	}
}
void linked_list_choice()
{
	node* p = head;
	int choice;
	cout << "Linked List is activated successfully ....!\n";
	cout << "Type  1-> to insert from end.\n      2-> to insert from beginning.\n      3-> to insert node between two nodes(after node).\n      4-> to delete from beginning.\n      5-> to delete from end.\n      6-> to delete node with an entered value.\n      7-> to make linear search.\n";
	cout << "-----------------------------------------\n";
	cin >> choice;
	switch (choice)
	{
	case 1:
		insert_end();
		break;
	case 2:
		insert_beginning();
		break;
	case 3:
		insert_between_twonodes();
		break;
	case 4:
		delete_beginning();
		break;
	case 5:
		delete_ending();
		break;
	case 6:
		delete_value();
		break;
	case 7:
		linkedlist_searching();
		break;
	}
}
//Linked List Operation (end)
//Stack Operation (start)
void display_array(int arr[], int size)
{
	cout << "Your stack is after [ ";
	for (int i = 0; i < size; i++)
	{
		if (i == size - 1)
		{
			cout << arr[i] << " ]\n";
		}
		else
		{
			cout << arr[i] << " , ";
		}
	}
}
int peek_in_array(int arr[], int size)
{
	int top = size - 1;
	if (size == 0)
	{
		return -1;
	}
	else
	{
		return arr[top];
	}
}
void peek_array(int arr[], int size)
{
	int peek = peek_in_array(arr, size);
	cout << "the peek (top) is : " << peek << "\n";
}
int pop_in_array(int arr[], int size)
{
	int top = size;
	if (top == 0)
	{
		return 0;
	}
	else
	{
		top--;
		return top;
	}
}
void pop_array(int arr[], int size)
{
	size = pop_in_array(arr, size);
	if (size == 0)
	{
		cout << "stack underflow\n";
	}
	else
	{
		cout << "Your stack is [ ";
		for (int i = 0; i < size; i++)
		{
			if (i == size - 1)
			{
				cout << arr[i] << " ]\n";
			}
			else
			{
				cout << arr[i] << " , ";
			}
		}
	}
}
void push_array(int data, int top, int arr[], int size)
{
	if (top == -1)
	{
		cout << "stack is empty\n";
	}
	else if (top == size)
	{
		cout << "stack is full\n";
	}
	else
	{
		//top++;
		arr[top] = data;
	}
}
void stack_array()
{
	int top = -1, data;
	int size, choice;
	cout << "How many elements that you want to push them to this stack?: ";
	cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		cout << "please, enter element " << i + 1 << " : ";
		top++;
		cin >> data;
		push_array(data, top, arr, size);
	}
	cout << "Your stack is [ ";
	for (int i = 0; i < size; i++)
	{
		if (i == size - 1)
		{
			cout << arr[i] << " ]\n";
		}
		else
		{
			cout << arr[i] << " , ";
		}
	}
	cout << "-----------------------------------------\n";
	cout << "Type  1-> to pop an element from stack.\n      2-> to get the top of this stack (peek).\n      3-> display the stack.\n";
	cin >> choice;
	switch (choice)
	{
		case 1:
			pop_array(arr, size);
			break;
		case 2:
			peek_array(arr, size);
			break;
		case 3:
			display_array(arr, size);
			break;
	}
}
node* top = NULL;
void peek_stack()
{
	if (top == NULL)
	{
		cout << "stack underflow\n";
	}
	else
	{
		cout << "the peek (top) : " << top->data << "\n";
	}
}
void display_stack()
{
	node* temp;
	if (top == NULL)
	{
		cout << "\nStack Underflow";
	}
	else
	{
		cout << "Your stack is [ ";
		temp = top;
		while (temp != NULL)
		{
			if (temp->link == NULL)
			{
				cout << temp->data << " ";
				break;
			}
			else
			{
				cout << temp->data << " , ";
			}
			temp = temp->link;
		}
	}
	cout << " ]\n";
	cout << "-----------------------------------------\n";
	cout << "-----------------------------------------\n";
}
void pop_stack()
{
	if (top == NULL)
	{
		cout << "stack underflow\n";
	}
	else
	{
		node* currant = top;
		top = top->link;
		delete(currant);
	}
	node* temp;
	if (top == NULL)
	{
		cout << "Stack Underflow\n";
	}
	else
	{
		cout << "Your stack is [ ";
		temp = top;
		while (temp != NULL)
		{
			if (temp->link == NULL)
			{
				cout << temp->data << " ";
				break;
			}
			else
			{
				cout << temp->data << " , ";
			}
			temp = temp->link;
		}
		cout << " ]\n";
	}
	cout << "-----------------------------------------\n";
	cout << "-----------------------------------------\n";
}
void push_stack(int data)
{
	node* nnode = new node;
	nnode->data = data;
	nnode->link = top;
	top = nnode;
}
void stack_linked_list()
{
	int size, choice, data;
	cout << "How many elements that you want to push them to this stack with linked list ?: ";
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		cout << "please, enter element " << i + 1 << " : ";
		cin >> data;
		push_stack(data);
	}
	node* temp;
	if (top == NULL)
	{
		cout << "\nStack Underflow";
	}
	else
	{
		cout << "Your stack is [ ";
		temp = top;
		while (temp != NULL)
		{
			if (temp->link == NULL)
			{
				cout << temp->data << " ";
				break;
			}
			else
			{
				cout << temp->data << " , ";
			}
			temp = temp->link;
		}
	}
	cout << " ]\n";
	cout << "-----------------------------------------\n";
	cout << "-----------------------------------------\n";
	cout << "Type  1-> to pop an element from stack with linked list.\n      2-> to get the top of this stack (peek) with linked list.\n      3-> display the stack with linked list.\n";
	cin >> choice;
	switch (choice)
	{
	case 1:
		pop_stack();
		break;
	case 2:
		peek_stack();
		break;
	case 3:
		display_stack();
		break;
	}
}
void stack_choice()
{
	int choice;
	cout << "Stack is activated successfully ....!\n";
	cout << "Type  1-> to implement stack with array.\n      2-> to implement stack with linked list.\n";
	cout << "-----------------------------------------\n";
	cin >> choice;
	switch (choice)
	{
		case 1:
			stack_array();
			break;
		case 2:
			stack_linked_list();
			break;
	}
}
//Stack Operation (end)
//Queue Operation (start)
void queue_display_array(int arr[], int front, int rear)
{
	cout << "Your queue is (display) [ ";
	for (int i = front; i < rear; i++)
	{
		if (i == rear - 1)
		{
			cout << arr[i] << " ]\n";
		}
		else
		{
			cout << arr[i] << " , ";
		}
	}
	cout << "-----------------------------------------\n";
}
void queue_peek_array(int arr[], int front, int rear)
{
	if (front == rear)
	{
		cout << "queue is underflow\n";
	}
	else
	{
		cout << "peek in queue (front) : " << arr[front] << "\n";
	}
}
void queue_pop_array(int arr[], int front, int rear)
{
	if (front == rear)
	{
		cout << "queue underflow\n";
	}
	else
	{
		front++;
		cout << "Your queue is [ ";
		for (int i = front; i < rear; i++)
		{
			if (i == rear - 1)
			{
				cout << arr[i] << " ]\n";
			}
			else
			{
				cout << arr[i] << " , ";
			}
		}
	}
}
void queue_array()
{
	int front = 0, rear = 0, data;
	int size, choice;
	cout << "How many elements that you want to push them to this stack?: ";
	cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		cout << "please, enter element " << i + 1 << " : ";
		top++;
		cin >> data;
		arr[rear] = data;
		rear++;
	}
	cout << "Your queue is [ ";
	for (int i = front; i < rear; i++)
	{
		if (i == rear - 1)
		{
			cout << arr[i] << " ]\n";
		}
		else
		{
			cout << arr[i] << " , ";
		}
	}
	cout << "-----------------------------------------\n";
	cout << "Type  1-> to pop an element from stack.\n      2-> to get the top of this stack (peek).\n      3-> display the stack.\n";
	cin >> choice;
	switch (choice)
	{
	case 1:
		queue_pop_array(arr, front, rear);
		break;
	case 2:
		queue_peek_array(arr, front, rear);
		break;
	case 3:
		queue_display_array(arr, front, rear);
		break;
	}
}
node* front = NULL;
node* rear = NULL;
void peek_queue()
{
	if (front == NULL)
	{
		cout << "queue is underflow\n";
	}
	else
	{
		cout << "peek in queue (front) : " << front->data << "\n";
	}
}
void pop_queue()
{
	if (front == NULL)
	{
		cout << "queue is underflow\n";
	}
	else
	{
		node* currant = front;
		front = front->link;
		delete(currant);
	}
}
void display_queue()
{
	node* temp;
	if (front == NULL)
	{
		cout << "queue Underflow\n";
	}
	else
	{
		cout << "Your queue is [ ";
		temp = front;
		while (temp != NULL)
		{
			if (temp->link == NULL)
			{
				cout << temp->data << " ";
				break;
			}
			else
			{
				cout << temp->data << " , ";
			}
			temp = temp->link;
		}
		cout << " ]\n";
	}
}
void push_queue(int data)
{
	node* nnode = new node;
	nnode->data = data;
	nnode->link = NULL;
	if (front == NULL)
	{
		front = rear = nnode;
	}
	else
	{
		rear->link = nnode;
		rear = nnode;
	}
}
void queue_linked_list()
{
	int size, choice, data;
	cout << "How many elements that you want to push them to this queue with linked list ?: ";
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		cout << "please, enter element " << i + 1 << " : ";
		cin >> data;
		push_queue(data);
	}
	node* temp;
	if (front == NULL)
	{
		cout << "queue Underflow\n";
	}
	else
	{
		cout << "Your queue is [ ";
		temp = front;
		while (temp != NULL)
		{
			if (temp->link == NULL)
			{
				cout << temp->data << " ";
				break;
			}
			else
			{
				cout << temp->data << " , ";
			}
			temp = temp->link;
		}
		cout << " ]\n";
	}
	cout << "-----------------------------------------\n";
	cout << "-----------------------------------------\n";
	cout << "Type  1-> to pop an element from queue with linked list.\n      2-> to get the top of this queue (peek) with linked list.\n      3-> display the queue with linked list.\n";
	cin >> choice;
	switch (choice)
	{
	case 1:
		pop_queue();
		display_queue();
		break;
	case 2:
		peek_queue();
		break;
	case 3:
		display_queue();
		break;
	}
}
void queue_choice()
{
	int choice;
	cout << "Queue is activated successfully ....!\n";
	cout << "Type  1-> to implement queue with array.\n      2-> to implement queue with linked list.\n";
	cout << "-----------------------------------------\n";
	cin >> choice;
	switch (choice)
	{
	case 1:
		queue_array();
		break;
	case 2:
		queue_linked_list();
		break;
	}
}
//Queue Operation (end)
//Tree Operation (start)
//node_tree_structure
struct tnode {
	int data;
	tnode* left;
	tnode* right;
};
void postorder(tnode* root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		postorder(root->left);
		postorder(root->right);
		cout << root->data << " ,";
	}
}
void inorder(tnode* root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		inorder(root->left);
		cout << root->data << " ,";
		inorder(root->right);
	}
}
void preorder(tnode* root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		cout << root->data << " ,";
		preorder(root->left);
		preorder(root->right);
	}
}
int height(tnode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		int lheight = height(root->left);
		int rheight = height(root->right);
		if (lheight > rheight)
			return(lheight + 1);
		else return(rheight + 1);
	}
}
tnode* delete_tree(tnode* root, int data)
{
	if (root == NULL)
	{
		return root;
	}
	if (data < root->data)
	{
		root->left = delete_tree(root->left, data);
	}
	if (data < root->data)
	{
		root->right = delete_tree(root->right, data);
	}
	else
	{
		if (root->left == NULL)
		{
			tnode* temp = root->right;
			delete(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			tnode* temp = root->left;
			delete(root);
			return temp;
		}
		else
		{
			int max = height(root->left);
			root->data = max;
			root->left = delete_tree(root->left, max);
		}
	}
	return root;
}
void deleting(tnode* root)
{
	int data;
	cout << "please ,enter element need to delete :";
	cin >> data;
	tnode* rroot = delete_tree(root, data);
	cout << "tree element [ ";
	preorder(rroot);
	cout << " ] \n";
}
tnode* searching(tnode* root, int data)
{
	if (root == NULL)
	{
		return root;
	}
	else if (data == root->data)
	{
		return root;
	}
	else if (data > root->data)
	{
		return searching(root->left, data);
	}
	else
	{
		return searching(root->right, data);
	}
}
void search(tnode* root)
{
	int data;
	cout << "please, enter element which you want to find : ";
	cin >> data;
	tnode* rroot = searching(root, data);
	if (rroot != NULL)
	{
		cout << "this element exist in tree\n";
	}
	else
	{
		cout << "this element doesn't exist in tree\n";
	}
}
tnode* copy(tnode* root)
{
	if (root == NULL)
	{
		return root;
	}
	else
	{
		tnode* nnode = new tnode;
		nnode->data = root->data;
		nnode->left = copy(root->left);
		nnode->right = copy(root->right);
		return nnode;
	}
}
void copy_tree(tnode* root)
{
	tnode* nroot = copy(root);
	cout << "-----------------------------------------\n";
	cout << "-----------------------------------------\n";
	int choice;
	cout << "to traversing in tree :\n";
	cout << "Type  1-> preorder.\n      2-> inorder.\n      3-> postorder.\n";
	cout << "-----------------------------------------\n";
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "tree element [ ";
		preorder(nroot);
		cout << " ] \n";
		break;
	case 2:
		cout << "tree element [ ";
		inorder(nroot);
		cout << " ] \n";
		break;
	case 3:
		cout << "tree element [ ";
		postorder(nroot);
		cout << " ] \n";
		break;
	}
}
tnode* insert_tree(tnode* root, int data)
{
	if (root == NULL)
	{
		tnode* nnode = new tnode;
		nnode->data = data;
		nnode->left = NULL;
		nnode->right = NULL;
		return nnode;
	}
	else if (data < root->data)
	{
		root->left = insert_tree(root->left, data);
	}
	else
	{
		root->right = insert_tree(root->right, data);
	}
	return root;
}
void inserting()
{
	tnode* root = NULL;
	int size, data;
	cout << "How many elements that you want to insert to this tree ?: ";
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		cout << "please, enter element " << i + 1 << " : ";
		cin >> data;
		if (i == 0)
		{
			root = insert_tree(root, data);
		}
		else
		{
			insert_tree(root, data);
		}
	}
	cout << "-----------------------------------------\n";
	cout << "-----------------------------------------\n";
	int choice;
	cout << "to traversing in tree :\n";
	cout << "Type  1-> preorder.\n      2-> inorder.\n      3-> postorder.\n      4-> copy.\n      5-> get hight.\n      6-> search.\n      7-> deleting.\n";
	cout << "-----------------------------------------\n";
	cin >> choice;
	switch (choice)
	{
		case 1:
			cout << "tree element [ ";
			preorder(root);
			cout << " ] \n";
			break;
		case 2:
			cout << "tree element [ ";
			inorder(root);
			cout << " ] \n";
			break;
		case 3:
			cout << "tree element [ ";
			postorder(root);
			cout << " ] \n";
			break;
		case 4:
			copy_tree(root);
			break;
		case 5:
			cout << "height in tree : "<<height(root) << "\n"; 
				break;
		case 6:
			search(root); 
			break;
		case 7:
			deleting(root);
			break;
	}
}
void tree_choices()
{
	tnode* root = NULL;
	int choice;
	cout << "Tree is activated successfully ....!\n";
	cout << "Type  1-> to insert to tree.\n      2-> to search tree.\n      3-> to delete from tree.\n";
	cout << "-----------------------------------------\n";
	cin >> choice;
	switch (choice)
	{
		case 1:
			inserting();
			break;
		case 2:
			search(root);
			break;
		case 3:
			deleting(root);
			break;
	}
}
//Tree Operation (end)
int main()
{
	int choice;
	//first massege to enter in program
	cout << "Welcome to simple data structure project ! : \n";
	cout << "Do you want to deal with an array , linked list , stack , queue or tree !\n";
	cout << "Type  1-> to enter an array.\n      2-> to enter a linked list.\n      3-> to enter a stack.\n      4-> to enter a queue.\n      5-> to enter a tree.\n";
	cout << "-----------------------------------------\n";
	cin >> choice;
	switch (choice)
	{
		case 1:
			enter_print_array();
			break;
		case 2:
			linked_list_choice();
			break;
		case 3:
			stack_choice();
			break;
		case 4:
			queue_choice();
			break;
		case 5:
			tree_choices();
			break;
	}
}