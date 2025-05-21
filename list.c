#include "list.h"
#include <assert.h>


//Returnera en tom lista - funktionen är färdig
List create_empty_list(void)
{
    return NULL;
}

//Här skapas nya noder. Denna funktion är den enda som ska använda malloc.
//Denna funktion ska i sin tur bara kallas av add_first och add_last.
//Notera att den är static och inte finns med i interfacet
static Node * create_list_node(const Data data)
{
	//glöm inte att kolla så att malloc inte returnerade NULL
	Node *ptr = (Node*)malloc(sizeof(Node));
	if(ptr == NULL)
	{
		return 0;
	}
	ptr->data = data;
	ptr->next = NULL;
	return ptr;
}	

//Är listan tom?
//Returnerar 1 om listan är tom, annars 0
int is_empty(const List list)
{
	if(list == NULL)
	{
		return 1;
	}
	return 0;
}

//Lägg till en nod först i listan
void add_first(List *list, const Data data)
{
	Node *ptr = create_list_node(data);
	ptr->next = *list;
	*list = ptr;
	
}

//lägg till nod sist i listan
void add_last(List *list, const Data data)
{
	Node *ptr = *list;
	if(ptr == NULL)
	{

		ptr = create_list_node(data);
		ptr->next = NULL;
		*list = ptr;
		
	}
	else
	{
		while(ptr->next != NULL)

		ptr = ptr->next;
	}
	ptr->next = create_list_node(data);
	
}
//Ta bort första noden i listan
//precondition: listan är inte tom (testa med assert)
void remove_first(List *list)
{
	
	Node *ptr = *list;
	*list = (*list)->next;
	ptr->data = NULL;
	free(ptr);
	ptr = NULL;
}

//ta bort sista noden i listan
//precondition: listan är inte tom (testa med assert)
void remove_last(List *list)
{
	Node *ptr = *list;
	Node *prev_ptr = NULL;
	while(ptr->next != NULL)
	{
		prev_ptr = ptr;
		ptr = ptr->next;
	}
	prev_ptr->next = NULL;
	ptr->data = NULL;
	free(ptr);
	ptr = NULL;
	// REKURSIV: remove_last(&(*list)->next); 

}

//töm listan (ta bort alla noder ur listan)
//postcondition: Listan är tom, *list är NULL
void clear_list(List *list)
{
	//alla noder ska frigöras
	while(*list != NULL)
	{
		remove_first(list);
	}

		
}

//Skriv ut listan genom UART
void print_list(const List list)
{
	Node *ptr = list;
	if(ptr != NULL)
	{
		send_int(ptr->data);
		ptr = ptr->next;
		print_list(ptr);
	}
}

//returnera första datat i listan
//precondition: listan är inte tom (testa med assert)
Data get_first_element(const List list)
{
	if(list != NULL)
	{
		return list->data;
	}
	return 0;
	
}

//returnera sista datat i listan. 
//precondition: listan är inte tom (testa med assert)
Data get_last_element(const List list)
{

	Node *ptr = list;
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	return ptr->data;
}

//Returnera hur många noder som finns i listan
int number_of_nodes(const List list)
{
	Node *ptr = list;
	int numbs = 0;
	while(ptr != NULL)
	{
		numbs++;
		ptr = ptr->next;
	}
	return numbs;
}

//Sök efter data i listan, returnera 1 om datat finns, annars 0.
int search(const List list, const Data data)
{
	Node *ptr = list;
	assert(list != NULL);
	while(ptr != NULL)
	{
		if(ptr->data == data)
		{
			return 1;
		}
		ptr = ptr->next;
	}
	return 0;
}

//Ta bort data ur listan (första förekomsten), returnera 0 om datat inte finns, annars 1
int remove_element(List *list, const Data data)
{
    assert(list != NULL);
    Node *ptr = *list;
    Node *prev_ptr = NULL;

    while(ptr != NULL)
    {
        if(ptr->data == data)
        {
            if (ptr == *list) {  // Om första noden ska tas bort
                *list = ptr->next;  // så ska huvudpekaren istället peka på nästa nod
            } else {  
                prev_ptr->next = ptr->next;  // Koppla föregående nod till nästa nod
            }
            
            ptr->data = NULL;
            free(ptr);
			ptr = NULL;
            return 1;
        }

        prev_ptr = ptr;
        ptr = ptr->next;
    }

    // Om vi inte hittar noden
    return 0;  // Noden fanns inte i listan

}

/******************************************************************************************* */

// Uppgift 1: is_sorted

int is_sorted_list(List list) 
{
    if(list == NULL) 
    {
        return 1;
    }

    if(list->data > list->next->data) 
    {
        return 0;
    }

	is_sorted_list(list->next); 
}

int is_sorted_array(int* array) 
{
	for(int i = 0; i + 1 < ARRAY_SIZE; i++)
	{
		if(array[i] > array[i + 1])
		{
			return 0;
		}

	}
	return 1;
}

// Uppgift 2: Bubble sort


/******************************************************************************************* */


void bubblesort(List *list)
{
	if(list == NULL) return;
	
	int swapped;
	Node **ptr;
	do
	{
		swapped = 0;
		ptr = list;
		while((*ptr)->next != NULL)	
		{
			Node *first = *ptr; 			//första elementet att bli jämfört med
			Node *second = first->next; 	// vice versa med det andra elementt...
		
			if(first->data > second->data)
			{
				if(ptr == list)
				{
					first->next = second->next;
					second->next = first;
					*list = second;
				}
				else
				{

				
					first->next = second->next;
					second->next = first;
					*ptr = second;
				}
				
				swapped = 1;
			}

		ptr = &((*ptr)->next);
		}
	} while(swapped);
	
}

// Uppgift 3: Quick Sort


/******************************************************************************************* */

int partition(int arr[], int low, int high)
{
	int pivot = arr[low];
	int border = low;
	int temp;

	for(int i = low + 1; i <= high; i++)
	{
		if(arr[i]<= pivot)
		{
			border ++;
			temp = arr[border];
		
			arr[border] = arr[i];
			arr[i] = temp;
	
		}
	}
	temp = arr[border];
	
	arr[border] = arr[low];
	arr[low] = temp;
	return (border);
}


void quick_sort(int arr[], int low, int high)
{
	if(low < high)
	{
		int pivot_index = partition(arr, low, high);

		quick_sort(arr, low, pivot_index - 1);
		quick_sort(arr, pivot_index + 1, high);

	}


}


// Uppgift 4: Merge Sort


/******************************************************************************************* */

void merger(int arr[], int low, int split_point, int high)
{
	int low_size = split_point - low + 1;
	int high_size = high - split_point;

	int temp_low[low_size], temp_high[high_size];

	for (int i = 0; i < low_size; i++)
	{
		temp_low[i] = arr[low + i];
	}
	for (int j = 0; j < high_size; j++)
	{
		temp_high[j] = arr[split_point + 1 + j];
	}

	int i = 0;
	int j = 0;
	int k = low;
	
	while(i < low_size && j < high_size)
	{
		if(temp_low[i] <= temp_high[j])
		{
			arr[k] = temp_low[i];
			i++;
		}
		else
		{
			arr[k] = temp_high[j];
			j++;
		}
		k++;
	}

	while(i < low_size)
	{
		arr[k] = temp_low[i];
		i++;
		k++;
	}
	while(i < high_size)
	{
		arr[k] = temp_high[j];
		j++;
		k++;
	}
}


void merge_sort(int arr[], int low, int high)
{
	if(low < high)
	{
		int split_point = high - low / 2;

		merge_sort(arr, low, split_point);
		merge_sort(arr, split_point + 1, high);

		merger(arr, low, split_point, high);



	}
}