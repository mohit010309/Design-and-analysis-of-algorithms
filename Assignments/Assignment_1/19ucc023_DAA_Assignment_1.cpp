// Roll No. = 19ucc023
// Name = Mohit Akhouri
// DAA Assignment 1 
// Date submitted = 28/02/2021

#include <bits/stdc++.h>

using namespace std;
void countingSort(int A[],int B[],int n); //function for countingSort
void radixSort(int A[],int B[],int n); //function for radixSort
void bucketSort(float A[],int n); //function for bucket Sort with numbers in range [0,1)
int partition(int arr[],int p,int r); //function to partition array arr according to pivot , elements <= pivot on left side of pivot and elements > pivot on right side
void quickSort(int A[],int p,int r); //function to sort array A using quickSort algo with leftmost index 'p' and rightmost index 'r'
int randomized_partition(int arr[],int p,int r); //function for partitioning array according to random pivot
void randomized_quickSort(int arr[],int p,int r); //function for randomized_QuickSort using random pivot
void HeapSort(int A[],int size); //function for HeapSort using Heap functions ( Build_Max_Heap and Max_Heapify )
void Merge(int A[],int p,int q,int r); //To merge the sorted arrays to create the final sorted Array
void MergeSort(int A[],int p,int r); //function of merge sort using divide and conquer technique, and using Merge function

int countingCheck(int A[],int n); //function for checking and entry of countingSort
void printArray(int arr[],int ind,int s); //function to print Array after sorting
void stableSort(int A[],int n,int dig); //stable sort method same as counting sort but used for radixSort to sort accoding to 'digits'
void printFloatArray(float arr[],int ind,int s); //function to print a floating type array


//Function declarations for Heap data structure implemented as an Array
void HeapDataStruc(); //providing menu for Heap functions

void insert(int arr[],int size,int val); //Insert an element in Max-Heap
void max_heapify(int arr[],int size,int ind); //Max-Heapify the heap , largest value at root node
void min_heapify(int arr[],int size,int ind); //Min-Heapify the heap , smallest value at root node
int peek_max(int arr[],int size); //To peek ( print ) the maximum element of heap
int peek_min(int arr[],int size); //To peek ( print ) the minimum element of heap
void display(int arr[],int size); //To display the Heap elements
int search(int arr[],int size,int val); //search for a node in Heap
int delete_node(int arr[],int size,int val); //Delete a node from Heap with value val
void BuildMaxHeap(int arr[],int size); //Build a Max-Heap out of Array arr


int main()
{
	int ch; //for entry of choice
	do
	{
		//displaying menu
		cout << "Enter choice : " << endl;
		cout << "1 - Counting Sort" << endl;
		cout << "2 - Radix Sort" << endl;
		cout << "3 - Bucket Sort" << endl;
		cout << "4 - Quick Sort" << endl;
		cout << "5 - Randomized Quick Sort" << endl;
		cout << "6 - Heap Data structure" << endl;
		cout << "7 - Heap sort" << endl;
		cout << "8 - Merge sort" << endl;
		cout << "9 - Exit" << endl;
		cout << "\n";
		cout << "Enter choice : ";
		cin >> ch;
		if(ch==1)
		{
			//system("cls");
			cout << "COUNTING SORT\n\n";
			int n;
			cout << "Enter number of elements : ";
			cin >> n;
			int A[n+1];
			int B[n+1];
			int flag=countingCheck(A,n);
			if(flag==0)
				cout << "Please enter integer in range (0,k), k>=0" << endl;
			else
			{
				countingSort(A,B,n);
				printArray(B,1,n+1);
			}
			
		}
		else if(ch==2)
		{
			//system("cls");
			cout << "RADIX SORT\n\n";
			int n;
			cout << "Enter number of elements : ";
			cin >> n;
			int A[n+1];
			int B[n+1];
			int flag=countingCheck(A,n);
			if(flag==0)
				cout << "Please enter integer in range (0,k), k>=0" << endl;
			else
			{
				radixSort(A,B,n);
				printArray(B,1,n+1);
			}
		}
		else if(ch==3)
		{
			//system("cls");
			cout << "BUCKET SORT\n\n";
			int n;
			cout << "Enter number of elements : ";
			cin >> n;
			float A[n+1];
			//entry of elements
			int i;
			float d;
			cout << "Enter elements (between 0 and 1 inclusive 0) :\n";
			for(i=1;i<=n;i++)
			{
				cin >> d;
				A[i]=d;
			}
			bucketSort(A,n);
			printFloatArray(A,1,n+1);
		}
		else if(ch==4)
		{
			//system("cls");
			cout << "QUICK SORT\n\n";
			int n;
			cout << "Enter number of elements : ";
			cin >> n;
			int A[n];
			cout << "Enter elements of array : \n";
			int i;
			for(i=0;i<n;i++)
				cin >> A[i];
			quickSort(A,0,n-1);
			printArray(A,0,n);
		}
		else if(ch==5)
		{
			//system("cls");
			cout << "RANDOMIZED QUICK SORT\n\n";
			int n;
			cout << "Enter number of elements : ";
			cin >> n;
			int A[n];
			cout << "Enter elements of array : \n";
			int i;
			for(i=0;i<n;i++)
				cin >> A[i];
			randomized_quickSort(A,0,n-1);
			printArray(A,0,n);
		}
		else if(ch==6)
		{
			system("cls");
			cout << "HEAP DATA STRUCTURE\n\n";
			HeapDataStruc();
		}
		else if(ch==7)
		{
			//system("cls");
			cout << "HEAP SORT\n\n";
			int n;
			cout << "Enter number of elements : ";
			cin >> n;
			int A[n+1];
			cout << "Enter elements of array : \n";
			int i;
			for(i=1;i<=n;i++)
				cin >> A[i];
			HeapSort(A,n);
			printArray(A,1,n+1);
		}
		else if(ch==8)
		{
			//system("cls");
			cout << "MERGE SORT\n\n";
			int n;
			cout << "Enter number of elements : ";
			cin >> n;
			int A[n+1];
			cout << "Enter elements of array : \n";
			int i;
			for(i=1;i<=n;i++)
				cin >> A[i];
			MergeSort(A,1,n);
			printArray(A,1,n+1);
		}
		else if(ch==9)
			cout << "Thank you !\n" << endl;
		else
			cout << "Wrong choice !\n" << endl;
	}while(ch!=9);
	return 0;
}
void printFloatArray(float arr[],int ind,int s) //arr is array to be printed, ind is index from where printing started, s is size of array
{
	int i;
	cout << "\nSorted Array is : \n";
	for(i=ind;i<s;i++)
		cout << arr[i] << " ";
	cout << "\n" << endl;
}
void printArray(int arr[],int ind,int s) //arr is array to be printed, ind is index from where printing started, s is size of array
{
	int i;
	cout << "\nSorted Array is : \n";
	for(i=ind;i<s;i++)
		cout << arr[i] << " " ;
	cout << "\n" << endl;
}
int countingCheck(int A[],int n) //A is input Array, n is size of Array A
{
	int i,d;
	cout << "Enter elements of the array ( >=0 ) : " << endl;
	for(i=1;i<=n;i++)
	{
		cin >> d;
		if(d<0)
			return 0;
		A[i]=d;
	}
	return 1;
}
void countingSort(int A[],int B[],int n) //A is input Array, B is output Array, n is size of input Array A and B
{
	int lb,ub;
	ub=-1;
	
	//finding upper bound ( maximum element )
	int i;
	for(i=1;i<=n;i++)
	{
		ub=max(ub,A[i]);
	}
	//declaring intermediate array C for holding count of elements
	int C[ub+1];
	for(i=0;i<=ub;i++)
	{
		C[i]=0;
	}
	//counting count of each element in A and storing in C
	for(i=1;i<=n;i++)
	{
		C[A[i]]++;
	}
	//modifying count Array C such that number of elements less than 'i' is stored at C[i]
	for(i=1;i<=ub;i++)
	{
		C[i]=C[i]+C[i-1];
	}
	//filling elements in the output array B by using count array C and original Array A
	for(i=n;i>=1;i--)
	{
		B[C[A[i]]]=A[i];
		C[A[i]]--;
	}
}
void stableSort(int A[],int n,int dig) //A is input array, n is Size (number of elements) in A, dig denotes current working place value(one's place,ten's place...)
{
	int B[n+1];
	int C[10]; //initializing count Array C
	int i;
	for(i=0;i<10;i++)
		C[i]=0;
	//determing count of elements and storing in C according to digit at dig place, (one's place, ten's place, ....)
	int rem;
	for(i=1;i<=n;i++)
	{
		rem=(A[i]/dig)%10;
		C[rem]++;
	}
	//modifying Count array C such that number of elements less than 'i' is stored at C[i]
	for(i=1;i<10;i++)
		C[i]=C[i]+C[i-1];
	//filling elements in the output array B by using count array C and original Array A
	for(i=n;i>=1;i--)
	{
		rem=(A[i]/dig)%10; //calculating remainder that is digit at dig's place ( one's place, ten's place....)
		B[C[rem]]=A[i];
		C[rem]--;
	}
	//copying elements of array B to initial array A
	for(i=1;i<=n;i++)
		A[i]=B[i];
}
void radixSort(int A[],int B[],int n) //A is input array, B in output array, n is size of Array A
{
	int i;
	//copying elements from Array A to output array B 
	for(i=1;i<=n;i++)
		B[i]=A[i];
	//determining maximum element in array B by using 'max' function
	
	int maxel=-1; //to store the maximum element calculated
	for(i=1;i<=n;i++)
		maxel=max(maxel,B[i]);
	//counting number of digits in maxel
	int nd=0;
	for(i=maxel;i>0;i/=10)
	{
		nd++;
	}
	//initializing place value (dig) initially to 1 and multiplied by 10 each time in loop given below (one's place,ten's place...)
	int dig=1;
	for(i=1;i<=nd;i++)
	{
		if(i!=1)
			dig=dig*10;
		stableSort(B,n,dig); //calling stableSort (counting sort with digit as input)
	}
}
void bucketSort(float A[],int n) //A is the input float array and 'n' is size of array A
{
	 int j,k;
	 vector<float> B[n]; //declaring 'n' buckets
	 int i;
	 int res; //to store the calculated index where the element from array needs to be stored in bucket
	 for(i=1;i<=n;i++)
	 {
	 	res=floor(n*A[i]);
	 	B[res].push_back(A[i]); //pushing (inserting) elements of A[i] into the required place in bucket
	 }
	 
	 float key; //key to store element to be swapped in Insertion sort
	 
	 //given below is the Insertion sort loop used for sorting elements of the buckets
	 for(i=0;i<n;i++)
	 {
	 	if(B[i].size()!=0) //checking if bucket is not empty
	 	{
	 		for(j=1;j<B[i].size();j++)
	 		{
	 			k=j-1;
	 			key=B[i][j];
	 			while(B[i][k]>key && k>=0) //shifting elements one place to right if it is bigger than key element
	 			{
	 				B[i][k+1]=B[i][k];
	 				k--;
	 			}
	 			B[i][k+1]=key; //storing the key element at correct position
	 		}
	 	}
	 }
	 //given below is the code for the merging of the buckets and storing final result in array A
	 
	 int co=1; //index variable to store index at which elements from buckets to be stored in array A
	 for(i=0;i<n;i++)
	 {
	 	if(B[i].size()!=0)
	 	{
	 		for(j=0;j<B[i].size();j++)
	 		{
	 			A[co]=B[i][j];
	 			co++;
	 		}
	 	}
	 }
}
int partition(int arr[],int p,int r) //arr in input Array, p is leftmost index, r is rightmost index
{
	// partition is done such that :
	// elements <= pivot are on left side of pivot 
	// elements > pivot are on the right side of pivot
	
	int pivot=arr[r]; //choosing pivot to be the rightmost (last) element of array arr
	int i,j;
	int ind; //to choose the partitioning point ( location of pivot fincally ) after doing partition
	i=p-1;
	int temp;
	for(j=p;j<r;j++)
	{
		if(arr[j]<=pivot) //checking if element <= pivot and swapping with element at index 'i' so that it is in correct position
		{
			i++;
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	ind=i+1;
	//swapping last element (pivot) with element at 'i+1' so that :
	//pivot is at its correct position
	temp=arr[ind];
	arr[ind]=arr[r];
	arr[r]=temp;
	return ind; //returning the index of pivot
}
void quickSort(int A[],int p,int r) //A is input array to be sorted, p is leftmost index , r is rightmost index
{
	//using recursion to sort Array, by dividing the array into two halves and sorting them individually 
	//using parition function also
	
	if(p>=r) // Base condition for recursive call to quickSort(int A[],int p,int r) function
		return;
	int ind=partition(A,p,r);
	quickSort(A,p,ind-1); //left partitioned array
	quickSort(A,ind+1,r); //right partitioned array
}
int randomized_partition(int arr[],int p,int r) //arr is input array , p is leftmost index, r is rightmost index
{
	srand(time(0)); //srand() used since for every run of program, different random number generated by rand() function
	int size=r-p+1;
	int random_ind=p+rand()%size; //choosing random index for partition from between p and r ( both inclusive )
	//exchanging last element ( arr[r] ) with ( arr[random index] ) so that we can paritition array arr using random index
	int temp;
	temp=arr[random_ind];
	arr[random_ind]=arr[r];
	arr[r]=temp;
	int ind=partition(arr,p,r); //calling partition function with random index to partition array
	return ind;
}
void randomized_quickSort(int arr[],int p,int r) //arr is input array, p is leftmost index, r is rightmost index
{
	if(p>=r) //base condition for recursive call to function randomized_quickSort()
		return;
	int ind=randomized_partition(arr,p,r);
	randomized_quickSort(arr,p,ind-1); //left partitioned array
	randomized_quickSort(arr,ind+1,r); //right partitioned array
}

//implementing functions for heap data structure
void HeapDataStruc()
{
	int heap[1000]; //Maximum size of heap can be 1000
	int size=0; //To store the size of heap data structure
	int ch; //for entry of choice
	do
	{
		//displaying Menu
		cout << "1  - Insert element into heap ( Max-heap ) \n" ;
		cout << "2  - Display heap \n";
		cout << "3  - Min heapify\n";
		cout << "4  - Max heapify\n";
		cout << "5  - Peek maximum element\n";
		cout << "6  - Peek minimum element\n";
		cout << "7  - Delete a node from heap\n";
		cout << "8  - Search a node in heap\n";
		cout << "9  - Delete Heap\n";
		cout << "10 - exit\n";
		
		cout << "enter choice : ";
		cin >> ch;
		if(ch==1)
		{
			int val;
			cout << "Enter value to insert in heap : ";
			cin >> val;
			insert(heap,size,val);
			size++;
			cout << "\n\n";
		}
		else if(ch==2)
		{
			cout << "Heap array is : \n";
			display(heap,size);
			cout << "\n\n";
		}
		else if(ch==3)
		{
			int i;
			if(size!=0)
			{
				for(i=size/2;i>=1;i--) //running loop from first non-leaf node downto 1
					min_heapify(heap,size,i);
			}
			cout << "\n\n";
		}
		else if(ch==4)
		{
			int i;
			if(size!=0)
			{
				for(i=size/2;i>=1;i--) //running loop from first non-leaf node downto 1
					max_heapify(heap,size,i);
			}
			cout << "\n\n";
		}
		else if(ch==5)
		{
			if(peek_max(heap,size)!=-1)
				cout << "Maximum element : " << peek_max(heap,size) << endl;
			cout << "\n\n";
		}
		else if(ch==6)
		{
			if(peek_min(heap,size)!=-1)
				cout << "Minimum element : " << peek_min(heap,size) << endl;
			cout << "\n\n";
		}
		else if(ch==7)
		{
			int val;
			cout << "Enter element to be deleted : ";
			cin >> val;
			int res=delete_node(heap,size,val);
			if(res==1)
				size--;
			else if(res==0)
				cout << "Element not found\n";
			else
				cout << "Heap is empty\n";
			cout << "\n\n";
		}
		else if(ch==8)
		{
			int sr;
			cout << "Enter value to be searched : " ;
			cin >> sr;
			int res;
			res=search(heap,size,sr);
			if(res==-1)
				cout << "Heap empty\n";
			else if(res==0)
				cout << "Element not found\n";
			else
				cout << "Element found\n";
			cout << "\n\n";
		}
		else if(ch==9)
		{
			size=0;
			cout << "\n";
		}
		else if(ch==10)
		{
			cout << "\nThank you !" << endl;
			cout << "\n\n";
			system("cls");
		}
		else
		{
			cout << "\nwrong choice\n";
			cout << "\n\n";
		}
			
	}while(ch!=10);
}
void insert(int arr[],int size,int val) //arr is input array, size is size of array, val is element to be inserted
{
	if(size==0)
	{
		size++;
		arr[size]=val;
	}
	else
	{
		size++;
		arr[size]=val; //inserting 'val' at last position of array as leaf node
		int i;
		for(i=size/2;i>=1;i--)
		{
			max_heapify(arr,size,i); //restoring the heap property after inserting 'val'
		}
	}
}
void max_heapify(int arr[],int size,int ind) //arr is input array, size is size of array, ind is index at which heap property is to be restored
{
	int lc=2*ind; //left child
	int rc=2*ind+1; //right child
	int l=ind;
	int temp;
	//checking which child node value is greater than node at index ind
	if(lc<=size && arr[lc]>=arr[ind])
	{
		l=lc;
	}
	if(rc<=size && arr[rc]>arr[ind] && arr[rc]>=arr[lc])
	{
		l=rc;
	}
	//replacing the larger of the node value of two childs with node at index ind
	if(l!=ind)
	{
		temp=arr[ind];
		arr[ind]=arr[l];
		arr[l]=temp;
		max_heapify(arr,size,l); //restoring the heap property for child ( recursion call )
	}
}
void min_heapify(int arr[],int size,int ind) //arr is input array, size is size of array, ind is index at which heap property is to be restored
{
	int lc=2*ind; //left child
	int rc=2*ind+1; //right child
	int s=ind;
	int temp;
	//checking which child node value is less than node at index ind
	if(lc<=size && arr[lc]<=arr[ind])
		s=lc;
	if(rc<=size && arr[rc]<arr[ind] && arr[rc]<=arr[lc])
		s=rc;
	//replacing the smaller of the node value of two childs with node at index ind
	if(s!=ind)
	{
		temp=arr[ind];
		arr[ind]=arr[s];
		arr[s]=temp;
		min_heapify(arr,size,s); //restoring the heap property for child ( recursion call )
	}
}		
int peek_max(int arr[],int size) //arr is input array, size is size of array
{
	if(size==0) //if heap is empty
	{
		cout << "Heap is empty\n";
		return -1;
	}
	else if(size==1) //if there is only 1 element return that element ( arr[1] )
		return arr[1];
	else
	{
		if(arr[1]>arr[2]) //in case of Max-Heap return arr[1]
			return arr[1];
		else
		{
			//if no Max-Heap ( that is Min-Heap ) , search for max element in Heap array
			int maxn=-1;
			for(int i=1;i<=size;i++)
				maxn=max(maxn,arr[i]);
			return maxn;
		}
	}
}
int peek_min(int arr[],int size) //arr is input array, size is size of array
{
	if(size==0) //if heap is empty
	{
		cout << "Heap is empty\n";
		return -1;
	}
	else if(size==1) //if there is only 1 element return that element ( arr[1] ) 
		return arr[1];
	else
	{
		if(arr[1]<arr[2]) //in case of Min-Heap return arr[1]
			return arr[1];
		else
		{
			//if no Min-Heap ( that is Max-Heap ) , search for min element in Heap array
			int minn=9999999;
			for(int i=1;i<=size;i++)
				minn=min(arr[i],minn);
			return minn;
		}
			
	}
}
void display(int arr[],int size) //arr is Heap to be displayed, size is size of arr ( Heap )
{
	if(size==0) //if Heap is empty
	{
		cout << "heap empty\n\n";
		return;
	}
	//printing the elements of Heap
	int i;
	for(i=1;i<=size;i++)
		cout << arr[i] << " ";
	cout << endl;
}
int search(int arr[],int size,int val) //arr is Heap (input array), size is size of array arr, val is value to be searched
{
	int i;
	if(size==0) //if Heap empty, return -1
	{
		return -1;
	}
	for(i=1;i<=size;i++) //else search for element in heap
	{
		if(arr[i]==val)
			return i; //if element found, return its index in heap array
	}
	return 0;//if element not found , return 0
}
int delete_node(int arr[],int size,int val) //arr is input array(heap), size is size of array , val is value(node) to be deleted
{
	int res=search(arr,size,val); //searching for value (node) in heap
	if(res==-1) //if heap empty, return -1
		return -1;
	else if(res==0) //if element not found, return 0
		return 0;
	else
	{
		//delete the node if found
		//replace node to be deleted with last node in Heap, and then decrease size by 1
		//Now call Max-heapify on index at which initially node to be deleted was , so as to restore Heap property
		int temp;
		temp=arr[res];
		arr[res]=arr[size];
		arr[size]=temp;
		size=size-1;
		max_heapify(arr,size,res);
		return 1;
	}
}
void BuildMaxHeap(int arr[],int size) //arr is input array for which Max-Heap is to be built, size is size of array
{
	int arr1[size+1]; //declaring temporary array to hold max-heap
	int i;
	int arr1_size=0;
	for(i=1;i<=size;i++)
	{
		insert(arr1,arr1_size,arr[i]); //inserting element into max-heap
		arr1_size++;
	}
	//copying elements to arr from arr1, arr is now Max-Heap
	for(i=1;i<=size;i++)
	{
		arr[i]=arr1[i];
	}
}
void HeapSort(int A[],int size) //A is input array ( to be sorted ) , size is size of array
{
	BuildMaxHeap(A,size); //first build Max-Heap for array A
	int i;
	int temp;
	for(i=size;i>=2;i--) //Now run loop from size of array downto 2 ( arr elements start from index 1 )
	{
		//swapping max element from Max-Heap and last element of array
		//thereby inserting max element at last position of array
		temp=A[1];
		A[1]=A[i];
		A[i]=temp;
		size--;
		max_heapify(A,size,1); //calling max heapify on rest of elements except last element
	}
}
void Merge(int A[],int p,int q,int r) //A is input array, p is leftmost index, q is middle index, r is rightmost index
{
	int sz1=q-p+1; //calculating size of temporary array 1 that is B[]
	int sz2=r-q; //calculating size of temporary array 2 that is C[]
	int B[sz1+1]; //declaring array B[] of size sz1+1
	int C[sz2+1]; //declaring array B[] of size sz2+1
	int i,j;
	i=p;
	//copying first n/2 (A[p...r]) elements of array A[] to array B[]
	for(j=1;j<=sz1;j++)
	{
		B[j]=A[i];
		i++;
	}
	i=q+1;
	//copying second n/2 (A[q+1...r]) elements of array A[] to array C[]
	for(j=1;j<=sz2;j++)
	{
		C[j]=A[i];
		i++;
	}
	//Merging sorted arrays B and C to form sorted array A
	
	//logic used = iterate over both arrays B and C and insert minimum of the element at front of array B and C to array A
	//if one array becomes empty in doing so, copy rest of elements of second array to array A
	i=1;
	j=1;
	int co=p;
	while(i<=sz1 && j<=sz2)
	{
		if(B[i]<C[j]) 
		{
			A[co]=B[i];
			i++;
		}
		else
		{
			A[co]=C[j];
			j++;
		}
		co++;
	}
	while(i<=sz1) //if some elements of B[] left after C[] becomes empty , copy them to A
	{
		A[co]=B[i];
		i++;
		co++;
	}
	while(j<=sz2) //if some elements of C[] left after B[] becomes empty , copy them to A
	{
		A[co]=C[j];
		j++;
		co++;
	}
}
void MergeSort(int A[],int p,int r) //A is input array to be sorted , p is leftmost index, r is rightmost (size of array) index
{
	//using recursion to sort Array A by dividing A into two halves 
	//then sorting the two halves by calling MergeSort() recursively
	//then finally merging the two sorted arrays to form the original array
	if(p>=r)
		return;
	int q=floor((p+r)/2); //calculating the middle point of array A
	MergeSort(A,p,q); //Sorting the left-halve of the array A
	MergeSort(A,q+1,r); //Sorting the right-halve of the array A
	Merge(A,p,q,r); //Merging the two halves
}



