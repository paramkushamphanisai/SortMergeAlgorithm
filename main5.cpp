/* This is a skeleton code for Optimized Merge Sort, you can make modifications as long as you meet 
   all question requirements*/  

#include <bits/stdc++.h>
#include "record_class.h"
#include <string>
#include <iostream>
#include <sstream>
#include <chrono>
#include <thread>
#include <limits.h>
using namespace std;

//defines how many blocks are available in the Main Memory 
#define buffer_size 22

Records buffers[buffer_size]; //use this class object of size 22 as your main memory
Records ram[buffer_size];
fstream files[buffer_size]; 

/***You can change return type and arguments as you want.***/

//Sorting the buffers in main_memory and storing the sorted records into a temporary file (runs) 
void Sort_Buffer(){
    //Remember: You can use only [AT MOST] 22 blocks for sorting the records / tuples and create the runs
    return;
}

void bubbleSort(int n) 
{ 
    int i, j; 
    for (i = 0; i < n-1; i++)     
      
    // Last i elements are already in place 
    for (j = 0; j < n-i-1; j++) 
        if (buffers[j].emp_record.eid > buffers[j+1].emp_record.eid){
			Records tmp=buffers[j];
			buffers[j]=buffers[j+1];
			buffers[j+1]=tmp;
		}
            
}

void bubbleSortDept(int n) 
{ 
    int i, j; 
    for (i = 0; i < n-1; i++)     
      
    // Last i elements are already in place 
    for (j = 0; j < n-i-1; j++) 
        if (buffers[j].dept_record.managerid > buffers[j+1].dept_record.managerid){
			Records tmp=buffers[j];
			buffers[j]=buffers[j+1];
			buffers[j+1]=tmp;
		}
            
}

void Sort_in_Main_Memory(int cur_size){
    cout << "Sorting Implemented" << endl;
	bubbleSort(cur_size);
    return;
}

void Sort_in_Main_MemoryDept(int cur_size){
    cout << "Sorting Implemented Dept" << endl;
	bubbleSortDept(cur_size);
    return;
}

void SortMainDept(int cur_size,int n){
	cout << "Merging Implemented Dept" << endl;
	fstream merge; 
	merge.open("TempEmpSortedDept" + to_string(n) + ".csv",ios::in |ios::out | ios::app);
	
	for (int i = 0; i < cur_size; i++)
	{
		merge << buffers[i].dept_record.did << "," << buffers[i].dept_record.dname << "," << buffers[i].dept_record.budget << "," << buffers[i].dept_record.managerid << endl;
	}
	merge.close();
}

void SortMain(int cur_size,int n){
	cout << "Merging Implemented" << endl;
	fstream merge; 
	merge.open("TempEmpSorted" + to_string(n) + ".csv",ios::in |ios::out | ios::app);
	
	for (int i = 0; i < cur_size; i++)
	{
		merge << buffers[i].emp_record.eid << "," << buffers[i].emp_record.ename << "," << buffers[i].emp_record.age << "," << buffers[i].emp_record.salary << endl;
	}
	merge.close();
}

void Print_Buffers1(int cur_size) {
    for (int i = 0; i < cur_size; i++)
    {
        cout << i << " " << buffers[i].emp_record.eid << " " << buffers[i].emp_record.ename << " " << buffers[i].emp_record.age << " " << buffers[i].emp_record.salary << endl;
    }
}

void Print_Buffers2(int cur_size) {
    for (int i = 0; i < cur_size; i++)
    {
        cout << i << " " << buffers[i].dept_record.did << " " << buffers[i].dept_record.dname << " " << buffers[i].dept_record.budget << " " << buffers[i].dept_record.managerid << endl;
    }
}

void Print_ram(int cur_size) {
	
	cout<<"\n ram \n";
    for (int i = 0; i < cur_size; i++)
    {
        cout << i << " " << ram[i].emp_record.eid << " " << ram[i].emp_record.ename << " " << ram[i].emp_record.age << " " << ram[i].emp_record.salary << endl;
    }
}

void replace(int i){
	Records emp = Grab_Emp_Record(files[i]);
	ram[i]= emp;
	cout <<"replaced "<< i << " " << ram[i].emp_record.eid << " " << ram[i].emp_record.ename << " " << ram[i].emp_record.age << " " << ram[i].emp_record.salary << endl;
}

void replaceDept(int i){
	Records emp = Grab_Dept_Record(files[i]);
	ram[i]= emp;
	cout <<"replaced "<< i << " " << ram[i].dept_record.did << " " << ram[i].dept_record.dname << " " << ram[i].dept_record.budget << " " << ram[i].dept_record.managerid << endl;
}

void opentempfiles(int n){
	cout<<"\n opentempfile "<<n<<"\n";
	    for (int i = 0; i < n; i++)
    {
        files[i].open("TempEmpSorted" + to_string(i) + ".csv",ios::in |ios::out | ios::app);
    }
}

void opentempfilesDept(int n){
	cout<<"\n opentempfile Dept"<<n<<"\n";
	    for (int i = 0; i < n; i++)
    {
        files[i].open("TempEmpSortedDept" + to_string(i) + ".csv",ios::in |ios::out | ios::app);
    }
}

void closetempfiles(int n){
	cout<<"\n closetempfile \n";
	    for (int i = 0; i < n; i++)
    {
        files[i].close();
		string s="TempEmpSorted" + to_string(i) + ".csv";
		remove(s.c_str());
    }
}

void closetempfilesDept(int n){
	cout<<"\n closetempfile Dept\n";
	    for (int i = 0; i < n; i++)
    {
        files[i].close();
		string s="TempEmpSortedDept" + to_string(i) + ".csv";
		remove(s.c_str());
    }
}

void getValures(int n){
	
	for(int i=0;i<n;i++){
		Records  single_EmpRecord  = Grab_Emp_Record(files[i]);
		ram[i]=single_EmpRecord;
		cout<<single_EmpRecord.emp_record.eid<<endl;
	}
}

void getValuresDept(int n){
	
	for(int i=0;i<n;i++){
		Records  single_DeptRecord  = Grab_Dept_Record(files[i]);
		ram[i]=single_DeptRecord;
		cout<<single_DeptRecord.dept_record.managerid<<endl;
	}
}

//Prints out the attributes from empRecord and deptRecord when a join condition is met 
//and puts it in file Join.csv
void PrintJoin(int i) {
	cout<<buffers[0].emp_record.eid<<","<<buffers[0].emp_record.ename<<","<<buffers[0].emp_record.age<<","<<buffers[0].emp_record.salary;
	cout<<buffers[i].dept_record.did<<","<<buffers[i].dept_record.dname<<","<<buffers[i].dept_record.budget<<","<<buffers[i].dept_record.managerid<<endl;

    
    return;
}

int updateEmp(fstream &emp){
	Records EmpRecord  = Grab_Emp_Record(emp);
	if(EmpRecord.no_values==-1)return -1;
	buffers[0]=EmpRecord;
	return 1;
	
}

int updateDep(fstream &dep){
	Records DepRecord  = Grab_Dept_Record(dep);
	if(DepRecord.no_values==-1)return -1;
	buffers[1]=DepRecord;
	int k=1;
	for(int i=2;i<22;i++){
		DepRecord  = Grab_Dept_Record(dep);
		if(DepRecord.no_values==-1)return k;
		buffers[i]=DepRecord;
		k++;
	}
	return 1;
	
}

//Use main memory to Merge and Join tuples 
//which are already sorted in 'runs' of the relations Dept and Emp 
void Merge_Join_Runs(fstream &joinout, fstream &emp, fstream &dep, int n){
	int i=1;
    while(i < n){
		//cout<<buffers[0].emp_record.eid<<" == "<< buffers[i].dept_record.managerid<<"\n";
		if(buffers[0].emp_record.eid == buffers[i].dept_record.managerid){
			PrintJoin(i);
			joinout<<buffers[0].emp_record.eid<<","<<buffers[0].emp_record.ename<<","<<buffers[0].emp_record.age<<","<<buffers[0].emp_record.salary;
			joinout<<buffers[i].dept_record.did<<","<<buffers[i].dept_record.dname<<","<<buffers[i].dept_record.budget<<","<<buffers[i].dept_record.managerid<<"\n";
			
		}
		if(buffers[0].emp_record.eid < buffers[i].dept_record.managerid){
			if(updateEmp(emp)==-1) return;
			continue;
		}
		i++;
	}
	int k =updateDep(dep);
	if(k==-1) return;
	Merge_Join_Runs(joinout,emp,dep,k);
    //and store the Joined new tuples using PrintJoin() 
    return;
}


int findmin(int n){
	Records min;
	min.emp_record.eid=INT_MAX;
	int loc=INT_MAX;
	for (int i = 0; i < n; i++){
		if(min.emp_record.eid > ram[i].emp_record.eid and ram[i].no_values != -1){
			min = ram[i];
			loc=i;
		}
	}
	return loc;
}

int findminDept(int n){
	Records min;
	min.dept_record.managerid=INT_MAX;
	int loc=INT_MAX;
	for (int i = 0; i <= n; i++){
		if(min.dept_record.managerid > ram[i].dept_record.managerid and ram[i].no_values > -1){
			min = ram[i];
			loc=i;
		}
	}
	return loc;
}

int main() {

    //Open file streams to read and write
    //Opening out two relations Emp.csv and Dept.csv which we want to join
    fstream empin;
    fstream deptin;
    empin.open("Emp.csv", ios::in);
    deptin.open("Dept.csv", ios::in);
	
	bool flag = true;
	int cur_size = 0;

	int numbuff=0;
	while (flag) {

		Records single_EmpRecord  = Grab_Emp_Record(empin);
		if (single_EmpRecord.no_values == -1) {
			flag = false;
			cout << "Final Records";
			Print_Buffers1(cur_size);
			Sort_in_Main_Memory(cur_size);
			Print_Buffers1(cur_size);
			SortMain(cur_size,numbuff);
			numbuff=numbuff+1;
			cur_size = 0;
			}
		if(cur_size + 1 <= buffer_size){
			//Memory is not full store current record into buffers.
			cout << "middle Records";
			buffers[cur_size] = single_EmpRecord ;
			cur_size += 1;
		}
		else{
			//memory is full now. Sort the blocks in Main Memory and Store it in a temporary file (runs)
			cout << "Main Memory is full. Time to sort and store sorted blocks in a temporary file" <<numbuff<< endl;
			Print_Buffers1(buffer_size);
			Sort_in_Main_Memory(buffer_size);
			Print_Buffers1(buffer_size);

			SortMain(cur_size,numbuff);
			numbuff=numbuff+1;

			cur_size = 0;
		}
      
	}
	
	empin.close();
	fstream sorted_file;  
	sorted_file.open("EmpSorted.csv", ios::out | ios::app);
	opentempfiles(numbuff);
	//K-way merging algorithm
	getValures(numbuff);
	Print_Buffers1(numbuff);//Print the values in the ram buffer
	int loc=0;
	int i=0;
	//psudeo code
	while(true){
		loc = findmin(numbuff);// find the minimun eid element
		if (loc==INT_MAX) break;
		sorted_file<< ram[loc].emp_record.eid << "," << ram[loc].emp_record.ename << "," << ram[loc].emp_record.age << "," << ram[loc].emp_record.salary << endl;//insert the minimum eid tuples in file
		replace(loc);// Update the values in ram
		Print_Buffers1(numbuff);// Print the values in ram
		i++;
	}
	cout<<"\n"<<i<<"\n";
	closetempfiles(numbuff);
  
	sorted_file.close();
	
	
	//Dept Sort
	flag = true;
	cur_size = 0;
	numbuff=0;
	while (flag) {

		Records single_DeptRecord  = Grab_Dept_Record(deptin);
		if (single_DeptRecord.no_values == -1) {
			flag = false;
			cout << "Final Records";
			Print_Buffers2(cur_size);
			Sort_in_Main_MemoryDept(cur_size);
			Print_Buffers2(cur_size);
			SortMainDept(cur_size,numbuff);
			numbuff=numbuff+1;
			cur_size = 0;
			}
		if(cur_size + 1 <= buffer_size){
			//Memory is not full store current record into buffers.
			cout << "middle Records";
			buffers[cur_size] = single_DeptRecord ;
			cur_size += 1;
		}
		else{
			//memory is full now. Sort the blocks in Main Memory and Store it in a temporary file (runs)
			cout << "Main Memory is full. Time to sort and store sorted blocks in a temporary file" <<numbuff<< endl;
			Print_Buffers2(buffer_size);
			Sort_in_Main_MemoryDept(buffer_size);
			Print_Buffers2(buffer_size);

			SortMainDept(cur_size,numbuff);
			numbuff=numbuff+1;

			cur_size = 0;
		}
      
	}
	
	empin.close();
	sorted_file.open("DeptSorted.csv", ios::out | ios::app);
	opentempfilesDept(numbuff);
	//K-way merging algorithm
	getValuresDept(numbuff);
	Print_Buffers2(numbuff);//Print the values in the ram buffer
	loc=0;
	i=0;
	//psudeo code
	while(true){
		loc = findminDept(numbuff);// find the minimun eid element
		if (loc==INT_MAX) break;
		sorted_file<< ram[loc].dept_record.did << "," << ram[loc].dept_record.dname << "," << ram[loc].dept_record.budget << "," << ram[loc].dept_record.managerid << endl;//insert the minimum eid tuples in file
		replaceDept(loc);// Update the values in ram
		Print_Buffers2(numbuff);// Print the values in ram
		i++;
	}
	cout<<"\n"<<i<<"\n";
	closetempfilesDept(numbuff);
  
	sorted_file.close();
	
	
	// Implement the joint
	
   
    //Creating the Join.csv file where we will store our joined results
    fstream joinout,Dept,Emp;
	cout<<"Open Join\n";
    joinout.open("Join.csv", ios::out | ios::app | ios::in);
	
	//opent the files
	cout<<"open Dept and Emp";
	Dept.open("DeptSorted.csv",ios::in);
	Emp.open("EmpSorted.csv",ios::in);
	
	Records EmpRecord  = Grab_Emp_Record(Emp);
	buffers[0]=EmpRecord;
	cout<<buffers[0].emp_record.eid<<","<<buffers[0].emp_record.ename<<","<<buffers[0].emp_record.age<<","<<buffers[0].emp_record.salary<<"\n";
	for(int i=1;i<22;i++){
		Records DepRecord=Grab_Dept_Record(Dept);
		if(DepRecord.no_values==-1) break;
		buffers[i]=DepRecord;
		cout<<buffers[i].dept_record.did<<","<<buffers[i].dept_record.dname<<","<<buffers[i].dept_record.budget<<","<<buffers[i].dept_record.managerid<<endl;
	}
	Merge_Join_Runs(joinout,Emp,Dept,i);;
	joinout.close();
	Dept.close();
	Emp.close();
	fstream pjoint;
	remove("EmpSorted.csv");
	remove("DeptSorted.csv");
    return 0;
}
