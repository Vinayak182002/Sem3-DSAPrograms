/*
 *	======================================
 * 		Program Name: QuickSort.cpp
 *  	Created on: December 23, 2022
 *      Author: Vinayak Shete
 *  ======================================
 */

#include <iostream>

using namespace std;

struct EmpDet
{
	int emp_id;
	string emp_name;
	int emp_salary;
};

int partition(struct EmpDet arr[], int start, int end)
{
    int pivot = arr[start].emp_salary;
    int count = 0;
    for (int i = start + 1; i <= end; i++) 
	{
        if (arr[i].emp_salary <= pivot)
        	count++;
    }
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) 
	{
        while (arr[i].emp_salary <= pivot) 
		{
            i++;
        }
        while (arr[j].emp_salary > pivot) 
		{
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) 
		{
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}
 
void quickSort(struct EmpDet arr[], int start, int end)
{

    if (start >= end)
        return;
 
    int p = partition(arr, start, end);
    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}

//function for displaying employee details
void display(struct EmpDet *a,int size)
{
	cout<<"\n============EMPLOYEE DETAILS==============";
	cout<<"\nID\t\tName\t\tSalary\n";
	for(int i=0;i<size;i++)
    {
        cout<<a[i].emp_id<<"\t\t"<<a[i].emp_name<<"\t\t"<<a[i].emp_salary;
        cout<<"\n";
    }
}

//displaying top 5 employees with highest salary
void top5(struct EmpDet *a, int size)
{
	cout<<"\n====TOP 5 EMPLOYEE DETAILS WITH HIGHEST SALARY====";
	cout<<"\nID\t\tName\t\tSalary\n";
	int z=0;
	for(int i=size-1;z<5;i--)
	{
		cout<<a[i].emp_id<<"\t\t"<<a[i].emp_name<<"\t\t"<<a[i].emp_salary;
        cout<<"\n";
        z++;
	}
}


int main()
{
    int n,i,id,salary,ch,doch;
	string name;
	cout<<"============WELCOME===========";
	cout<<"\nCreating Employee Details Table=>>";
	cout<<"\nHow many employees you want to add?-->";
    cin>>n;
    struct EmpDet empArr[n];
    cout<<"\nEnter "<<n<<" Employees Details:\n";
    for(i=0;i<n;i++)
    {
    	cout<<"\n==================";
    	cout<<"\nEnter details for employee "<<i+1<<"-->";
    	cout<<"\nEnter employee id:";
    	cin>>id;
    	cout<<"\nEnter employee name:";
    	cin>>name;
    	cout<<"\nEnter employee salary:";
    	cin>>salary;
    	empArr[i].emp_id=id;
    	empArr[i].emp_name=name;
    	empArr[i].emp_salary=salary;
    	cout<<"\n==================";
    }
    do
    {
    	cout<<"\n1.Display\n2.Sort using Quick Sort\n3.Display top 5 employees with highest salary\n4.EXIT";
		cout<<"\nEnter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
				display(empArr,n);
				break;
			
			case 2:
				quickSort(empArr,0,n-1);
				cout<<"\nThe employee details have been sorted according to their Salary!==>";
				display(empArr,n);	
				break;
			
			case 3:
				top5(empArr,n);
				break;
			
			case 4:
				goto exit;
				break;
			
			default:
				cout<<"\nPlease enter correct choice!";
		}
		cout<<"\n===\nDo you want to continue?[1 for YES || 0 for NO]-->";
		cin>>doch;
	}while(doch==1);
	exit:
		cout<<"\n=====THANK YOU==========";
   return 0;
}

