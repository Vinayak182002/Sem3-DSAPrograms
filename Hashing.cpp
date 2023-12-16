/*
 *	======================================
 * 		Program Name: Hashing.cpp
 *  	Created on: November 25, 2022
 *      Author: Vinayak Shete
 *  ======================================
 */

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;

struct employee
{
	int emp_id;
	string emp_name;
	string emp_address;
	double emp_salary;
};

class EmpTable
{
	int id;
	int current_size=0;
	string name;
	string addr;
	double salary;
	public:
		//calculating the hashkey 
		int calcHashKey(int X,int table_size)
		{
			int hashkey=X%table_size;
			return hashkey;
		}
		
		//function for insertion operation
		void insert(int table_size,struct employee emp[])
		{
			if(current_size>=table_size)
			{
				cout<<"\nEntries exceeded than the size you entered!Insertion Operation failed!";
			}
			else
			{
				
				cout<<"\n========================\nYou are doing Insertion Operation\n========================";
				cout<<"\nEnter the id of an employee:";
				cin>>id;
				cout<<"\nEnter the name of an employee:";
				cin>>name;
				cout<<"\nEnter the address of an employee:";
				cin>>addr;
				cout<<"\nEnter the salary of an employee:";
				cin>>salary;
				int i=calcHashKey(id,table_size);
				//if key index is empty
				if(emp[i].emp_id==-1)
				{	
					emp[i].emp_id=id;
					emp[i].emp_name=name;
					emp[i].emp_address=addr;
					emp[i].emp_salary=salary;
					cout<<"\nThe record is entered successfully at "<<i<<"th location\n";
					current_size++;
					cout<<"Current Size:"<<current_size;
				}
				//if key index is not empty do linear probing
				else
				{	
					cout<<"\nCollision occurred!!The key index "<<i<<" for this record is already filled so doing linear probing...";
					for(int j=i+1;j!=i;j++)
					{
						if(j==table_size)
						{
							j=j%table_size;
						}
						if(emp[j].emp_id==-1)
						{
							emp[j].emp_id=id;
							emp[j].emp_name=name;
							emp[j].emp_address=addr;
							emp[j].emp_salary=salary;
							cout<<"\nThe record is entered successfully at "<<j<<"th location\n";
							current_size++;
							cout<<"Current Size:"<<current_size;
							break;
						}
					}
				}
			}
		}
	
		//delete function
		void deletefun(int tb_size, struct employee emp[])
		{
			if(current_size==0)
			{
				cout<<"\nNo records are present!Deletion Operation failed!";
			}
			else
			{	
				cout<<"\n========================\nYou are doing Deletion Operation\n========================";
				cout<<"\nEnter the id of an employee to be deleted:";
				cin>>id;
				int delkey=calcHashKey(id,tb_size);
				if(id==emp[delkey].emp_id)
				{
					emp[delkey].emp_id=-1;
					emp[delkey].emp_name="NULL";
					emp[delkey].emp_address="NULL";
					emp[delkey].emp_salary=-1;
					cout<<"\nThe record is deleted successfully from "<<delkey<<"th location\n";
					current_size--;
					cout<<"Current Size:"<<current_size;
				}
				else
				{
					cout<<"\nThe record is not present at its key index..May be linear probing done.. Deleting..";
					for(int j=delkey+1;j!=delkey;j++)
					{
						if(j==tb_size)
						{
							j=j%tb_size;
						}
						if(emp[j].emp_id==id)
						{
								emp[j].emp_id=-1;
								emp[j].emp_name="NULL";
								emp[j].emp_address="NULL";
								emp[j].emp_salary=-1;
								cout<<"\nThe record is deleted successfully from "<<j<<"th location\n";
								current_size--;
								cout<<"Current Size:"<<current_size;
								break;
						}
					}
				}
			}		
		}

		//search function
		void search(int tb_size, struct employee emp[])
		{
			if(current_size==0)
			{
				cout<<"\nNo records are present!Search Operation failed!";
			}
			else
			{
				
				cout<<"\n========================\nYou are doing Searching Operation\n========================";
				cout<<"\nEnter the id of an employee to be searched:";
				cin>>id;
				int searchkey=calcHashKey(id,tb_size);
				if(id==emp[searchkey].emp_id)
				{
					cout<<"\nThe record is found successfully at "<<searchkey<<"th location\n";
					cout<<"\n============================================================================================================";
					cout<<"\nIndex\t\t\tEmpID\t\t\tEmpName\t\t\tEmpAddr\t\t\tEmpSalary";
					cout<<"\n"<<searchkey<<"\t\t\t"<<emp[searchkey].emp_id<<"\t\t\t"<<emp[searchkey].emp_name<<"\t\t\t"<<emp[searchkey].emp_address<<"\t\t\t"<<emp[searchkey].emp_salary;
					cout<<"\n============================================================================================================";
				}
				else
				{
					cout<<"\nThe record is not present at its key index..May be linear probing done.. Searching..";
					for(int j=searchkey+1;j!=searchkey;j++)
					{
						if(j==tb_size)
						{
							j=j%tb_size;
						}
						if(emp[j].emp_id==id)
						{
								cout<<"\nThe record is found successfully at "<<j<<"th location\n";
								cout<<"\n============================================================================================================";
								cout<<"\nIndex\t\t\tEmpID\t\t\tEmpName\t\t\tEmpAddr\t\t\tEmpSalary";
								cout<<"\n"<<j<<"\t\t\t"<<emp[j].emp_id<<"\t\t\t"<<emp[j].emp_name<<"\t\t\t"<<emp[j].emp_address<<"\t\t\t"<<emp[j].emp_salary;
								cout<<"\n============================================================================================================";
								break;
						}
					}
				}
			}
		}
		
		
		//display function
		void display(struct employee emp[],int tb_size)
		{
			cout<<"\n=========================HASH TABLE STORING "<<tb_size<<" EMPLOYEE INFORMATION==============================";
			cout<<"\n============================================================================================================";
			cout<<"\nIndex\t\t\tEmpID\t\t\tEmpName\t\t\tEmpAddr\t\t\tEmpSalary";
			for(int l=0;l<tb_size;l++)
			{
				cout<<"\n"<<l<<"\t\t\t"<<emp[l].emp_id<<"\t\t\t"<<emp[l].emp_name<<"\t\t\t"<<emp[l].emp_address<<"\t\t\t"<<emp[l].emp_salary;
			}
			cout<<"\n============================================================================================================";
		}
};

int main()
{
	int size,ch,doch;
	EmpTable obj;
	cout<<"================================Welcome================================================\n";
	cout<<"Enter the number of employees to be stored in a hash table:";
	cin>>size;
	struct employee empArr[size];
	for(int k=0;k<size;k++)
	{
		empArr[k].emp_id=-1;
		empArr[k].emp_name="NULL";
		empArr[k].emp_address="NULL";
		empArr[k].emp_salary=-1;
	}
	do
	{
		cout<<"\n==================================================================================";
		cout<<"\n1.Enter the record in the hash table\n2.Delete the record in the hash table\n3.Search for the record in the hash table\n4.Display the hash table\n5.EXIT\n==>>Enter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
					obj.insert(size,empArr);
					break;
			case 2:
					obj.deletefun(size,empArr);
					break;
			case 3:
					obj.search(size,empArr);
					break;
			case 4:
					obj.display(empArr,size);
					break;
			case 5:
					goto exit;
					break;
			default:
					cout<<"\n======================\nYou have entered wrong choice!\n======================";
		}
		cout<<"\n=============================\nDo you want to continue?Press 1 for YES and Press 0 for NO-->";
		cin>>doch;
	}while(doch==1);
	exit:
	cout<<"=============================Thank You!!============================";
}

