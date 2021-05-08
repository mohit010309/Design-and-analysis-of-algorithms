// Roll No. = 19ucc023
// Name = Mohit Akhouri
// DAA Assignment 2 
// Date submitted = 16/4/2021

#include <bits/stdc++.h>
using namespace std;

int Dselect(int arr[],int k,int begin,int end,int size); // selects 'kth' smallest from array arr
int knapsack_recursive(int w[],int p[],int n,int W); // 0-1 Knapsack problem using recursion
int knapsack_dynamic(int w[],int p[],int n,int W); // 0-1 Knapsack problem using Dynamic Programming approach

// Supporting Functions for the Dselect algorithm
void enterArray(int arr[],int size); //entry of Array
void printArray(int arr[],int size); //printing the array arr
int sort_and_find_median(int arr[],int size); //sorting the array arr and finding the median of arr
int partition(int arr[],int b,int e,int pivot); //to partition the array arr according to pivot
void swap(int arr[],int x,int y); //to swap two elements in array reffered as position x and y

//Supporting Functions for the Knapsack problem ( Recursive and DP way )
void enterWeightArray(int arr[],int size); //Entry of array of weights ( w )
void enterPriceArray(int arr[],int size); //Entry of array of Prices ( p )


int main()
{
	// Displaying options
	cout << "1 - Deterministic Linear Time selection algorithm" << endl;
	cout << "2 - 0-1 Knapsack problem by Recursive method" << endl;
	cout << "3 - 0-1 Knapsack problem by Dynamic Programming method" << endl;
	cout << "4 - Exit" << endl;
	cout << endl;
	int ch;
	do
	{
		cout << "Enter choice : ";
		cin >> ch; // entry of choice
		if(ch==1)
		{
			int n;
			cout << "Enter size of array : ";
			cin >> n;
			
			int arr[n];
			enterArray(arr,n);
			int k;
			cout << "Enter kth order statistics : ";
			cin >> k;
			
			if(k>=1 && k<=n)
			{
				int ans=Dselect(arr,k,0,n-1,n);
				cout << "kth order statistics is : " << ans << endl;
			}
			else
			{
				cout << "Enter valid kth order statistics !" << endl;
			}
			cout << endl;	
		}
		else if(ch==2)
		{
			int W,n;
			cout << "Enter total weight of knapsack : ";
			cin >> W;
			
			cout << "Enter number of items in the bag : ";
			cin >> n;
			
			int w[n],p[n];
			enterWeightArray(w,n);
			enterPriceArray(p,n);
			
			int maxProfit = knapsack_recursive(w,p,n,W);
			cout << "Maximum profit : " << maxProfit << endl;
			cout << endl;
			
		}
		else if(ch==3)
		{
			int W,n;
			cout << "Enter total weight of knapsack : ";
			cin >> W;
			
			cout << "Enter number of items in the bag : ";
			cin >> n;
			
			int w[n],p[n];
			enterWeightArray(w,n);
			enterPriceArray(p,n);
			
			int maxProfit = knapsack_dynamic(w,p,n,W);
			cout << "Maximum profit : " << maxProfit << endl;
			cout << endl;
		}
		else if(ch==4)
		{
			cout << "Thank you!" << endl;
		}
		else
		{
			cout << "Wrong choice!" << endl;
		}
	}while(ch!=4);
	return 0;
}
void enterArray(int arr[],int size) // arr=array, size = size of array
{
	int i;
	cout << "enter elements of array : ";
	for(i=0;i<size;i++)
		cin >> arr[i];
}
void printArray(int arr[],int size) // arr=array, size = size of array
{
	cout << "Array elements are : ";
	int i;
	for(i=0;i<size;i++)
		cout << arr[i] << ", ";
	cout << endl;
}
int Dselect(int arr[],int k,int begin,int end,int size) //arr=array, k=kth order statistic ( kth smallest ) , begin = beginning of array, end = end of array, size = length of array
{
	if(size==1)
		return arr[begin]; // if size =1 , then return the 'only element' that is in array ( arr[begin] )
	
	int sz_med; // to store the size of medians array
	if(size%5==0)
		sz_med=size/5; // if size % 5==0 , only size/5 groups possible
	else
		sz_med=size/5+1; // if size % 5==0 , size/5 + 1 ( for last group ) possible
		
	int medians[sz_med]; // creating the medians array to store median of medians
	
	int cn=5,arr1[5],arr1x=0,i,j=begin;
	
	for(i=0;i<sz_med;i++)
	{
		cn=5; // to ensure that each medians array has elements <= 5
		arr1x=0;
		while(cn!=0 && j<=end)
		{
			arr1[arr1x]=arr[j];
			arr1x++;
			j++;
			cn--;
		}
		medians[i]=sort_and_find_median(arr1,5-cn); // storing the median obtained in medians array
	}
	
	//sorting the medians array
	sort(medians,medians+sz_med); // sorting the medians array
	
	int P = medians[(int)ceil((float)(size/10))]; // calculating the pivot value
	
	//partitioning the array
	int pos = partition(arr,begin,end,P); // storing position (index) of pivot in pos
	
	if(k==((pos-begin)+1)) // if 'pos' is required kth order statistic , then return pivot value 'P'
		return P;
	else if(((pos-begin)+1)>k) // if 'pos' is greater than kth order statistic, call Dselect recursively with left side of array and 'k' as order statistic
	{
		return Dselect(arr,k,begin,pos-1,pos-begin);
	}
	else // if 'pos' is smaller than kth order statistic, call Dselect recursively with right side of array and 'k-pos+1' as order statistic
	{
		return Dselect(arr,k-(pos+1),pos+1,end,end-pos);
	}
	
}
int sort_and_find_median(int arr[],int size) // arr=array to be sorted and whose median is to be found , size =size of array
{
	sort(arr,arr+size);
	return arr[size/2]; // return the median of sorted array arr
}
void swap(int arr[],int x,int y) // arr=array, x=first swap position, y=second swap position
{
	int temp;
	temp=arr[x];
	arr[x]=arr[y];
	arr[y]=temp;
}
int partition(int arr[],int b,int e,int pivot) //arr= array to be partitioned, b=beginning index of array, e=end index of array, pivot = for partition
{	
	//finding the position of pivot in array
	int x;
	int pos;
	for(x=b;x<=e;x++)
	{
		if(arr[x]==pivot)
		{
			pos=x;
			break;
		}
	}
	
	//replacing pos with last element
	swap(arr,pos,e);
	
	//main partitioning algorithm starts here
	//with pivot as lastmost element of array
	
	int i=b-1;
	int j;
	for(j=b;j<e;j++)
	{
		if(arr[j]<=pivot)
		{
			i=i+1;
			swap(arr,i,j);
		}
	}
	swap(arr,i+1,e);
	return i+1;
}

void enterWeightArray(int arr[],int size) // arr=weight array, size=size of array
{
	cout << "Enter weight Array : ";
	int i;
	for(i=0;i<size;i++)
		cin >> arr[i];
}
void enterPriceArray(int arr[],int size) //arr=price array, size=size of array
{
	cout << "Enter price Array : ";
	int i;
	for(i=0;i<size;i++)
		cin >> arr[i];
}

int knapsack_recursive(int w[],int p[],int n,int W) // w=weight array , p=price array, n=total number of items, W=maximum weight of knapsack
{
	// Logic used is as follows :
	// the nth item is taken or not taken, if taken then p[n-1]+recursiveCall on (n-1) items
	// if not taken then 0 + recursiveCall on (n-1) items
	
	if(n==0 || W==0)
		return 0;
	else if(w[n-1]>W)
		return 0;
	else
		return max( p[n-1]+knapsack_recursive(w,p,n-1,W-w[n-1]) , knapsack_recursive(w,p,n-1,W)); // taking max( price of nth item + knapsack(n-1 items) , knapsack(n-1 items) ) = that is either take nth item or dont take it
	
}

int knapsack_dynamic(int w[],int p[],int n,int W) // w=weight array , p=price array, n=total number of items, W=maximum weight of knapsack
{
	// Logic used is as follows :
	// First fill the first row with all zeros
	// fill other rows with the formula : f[i][j]=max(p[i-1]+f[i-1][j-w[i-1]],f[i-1][j]) , where f is DP matrix
	
	int f[n+1][W+1]; // initialing the final (DP) matrix to store the final maximum profit achieved
	int i,j;
	for(i=0;i<=W;i++)
	{
		f[0][i]=0; // initializing the first row of matrix with zeros
	}
	
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=W;j++)
		{
			if(w[i-1]>j)
				f[i][j]=f[i-1][j]; // fill the current cell with value of previous cell
			else
				f[i][j]=max(p[i-1]+f[i-1][j-w[i-1]],f[i-1][j]); // recurrence relation for the current cell 
		}
	}
	return f[n][W]; // return the lastmost element of matrix, this is the final answer = maximum profit achieved
}

