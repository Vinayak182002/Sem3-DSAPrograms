#include<iostream>
using namespace std;

struct emp
{
	int id;
//	string name;
	int salary;
};

class MergeSort
{
	public:
		void mergesort(struct emp *ar,int low,int high)
		{
			int mid;
			if(low<high)
			{
				mid=(low+high)/2;
				mergesort(ar,low,mid);
				mergesort(ar,mid+1,high);
				
				merge(ar,low,mid,high);
			}
		}
		
		void merge(struct emp *ar,int low,int mid,int high)
		{
			int i,j,k;
			struct emp temp[high-low+1];
			i=low;
			j=mid+1;
			k=0;
			
			while(i<=mid && j<=high)
			{
				if(ar[i].salary<ar[j].salary)
				{
					temp[k]=ar[i];
					k++;
					i++;
				}
				else
				{
					temp[k]=ar[j];
					k++;
					j++;
				}
			}
			
			while(i<=mid)
			{
				temp[k]=ar[i];
				k++;
				i++;
			}
			
			while(j<=high)
			{
				
				temp[k]=ar[j];
				k++;
				j++;
			}
			
			for(i=low;i<=high;i++)
			{
				ar[i]=temp[i-low];
			}
		}
		
		void display(struct emp *a,int s)
		{
			for(int i=0;i<s;i++)
			{
				cout<<"\n-->"<<a[i].id<<"--->"<<a[i].salary;
			}
		}
	
};

int main()
{
	int n;
	MergeSort m;
	cout<<"\nEnter the number of employees:";
	cin>>n;
	emp arr[n];
	cout<<"Enter details:";
	for(int i=0;i<n;i++)
	{
		cout<<"Employee "<<i+1;
		cout<<"id:";
		cin>>arr[i].id;
		cout<<"salary:";
		cin>>arr[i].salary;
	}
	m.display(arr,n);
	m.mergesort(arr,0,n-1);
	m.display(arr,n);
}
