#include <iostream>
 #include <fstream>
#include<string>
using namespace std;
//This program for add student's data and generate in text file 
void AddStudent(string filename, int *studentCount, int *GoaStateFees, int *OtherStateFees){
cout<<endl<<" Add Students details";
getchar();
ofstream file(filename.c_str(), ios::app);
char name[60];
cout<<endl<<"Enter Name of Student : ";
gets(name);
file<<endl<<name;
int state=-1;
cout<<endl<<"Press 1 for Goa-State or 2 for Other State : ";
cin>>state;
if(state==1)
file<<" | Goa-State";
else if(state==2)
file<<" | Other State";
else
file<<" | NA";

int tutionFees;
cout<<endl<<"Enter Tution Fees : ";
cin>>tutionFees;

char choice;
cout<<endl<<"Do you want to subscribe for Health Plan ? y/n : ";
cin>>choice;
int HealthPlan = 0;
if(choice=='Y' || choice=='y')
{
char plan;
cout<<endl<<" Select Optional Health Plan ";
cout<<endl<<"A -> 1000 Rupee";
cout<<endl<<"B -> 3000 Rupee";
cout<<endl<<"C -> 5000 Rupee";
cout<<endl<<"D -> 10000 Rupee";

cout<<endl<<"Select any alphabet ( A, B, C, D ) : ";
cin>>plan;
switch(plan)
{     	
case 'A':
case 'a': HealthPlan = 1000; break;
case 'B':
case 'b': HealthPlan = 3000; break;
case 'C':
case 'c': HealthPlan =  5000; break;
case 'D':
case 'd' : HealthPlan =  10000; break;
default: cout<<endl<<"Invalid Choice..";
}
if(HealthPlan!=0)
file<<" | Health Plan : "<<plan;
else
file<<" | Health Plan : None"<<plan;

file<<" | "<<tutionFees;

if(state==1){
*GoaStateFees = *GoaStateFees + tutionFees + HealthPlan;
}
else if(state==2)
{
*OtherStateFees = *OtherStateFees + tutionFees + HealthPlan;
}
}
*studentCount = *studentCount + 1;
file.close();
}

/*
function generate the final report by adding total fees details
Argument1: filename
Argument2: Pointer to studnetCount
*/
void generateReport(const string filename, const int *studentCount, const int *GoaStateFees, const int *OtherStateFees)
{
if(*studentCount==0){
cout<<endl<<"Error: There should be atleast one record to generate report.";
}
else{
ofstream file(filename.c_str(), ios::app);
file<<endl<<"Total Tuition Paid for all In-State Students : "<<*GoaStateFees;
file<<endl<<"Total Tuition Paid for all Out-of-State Students : "<<*OtherStateFees;
file.close();
cout<<endl<<"Success: "<<filename<<" generated ";		
}
	
}

int main(int argc, char** argv) 
{
int choice = 0;
string fileName = "tuition_report.txt";
int studentCount =0;
int GoaStateFees = 0;
int OtherStateFees =0;

//empty file if it already exist
ofstream file(fileName.c_str(), ios::out);
file.close();

while(choice!=-1)
{
cout<<endl<<"1 Add Student Details";
cout<<endl<<"2 Generate Report";
cout<<endl<<"-1 Exit";
cout<<"\n\n Enter your choice : ";
cin>>choice;

switch(choice){
case 1: AddStudent(fileName, &studentCount, &GoaStateFees, &OtherStateFees);
	break;
case 2: generateReport(fileName, &studentCount, &GoaStateFees, &OtherStateFees);
	break;
case -1: cout<<endl<<"thank you for useing softwer!!";
	break;
default: cout<<endl<<"Invalid Choice.."; getchar();	
}	
}
return 0;
}