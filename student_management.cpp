#include<iostream>
#include<string>
#include<conio.h>
#include<stdlib.h>
using namespace std;

int main();
void show_data(int searchkey);     //function used to show data to end-user.
void get_data(int i);           //function used to obtain data from end-user.
void search_student(int searchkey);
void add_student();      //This function is used to add record of new student.
void edit_student(int idnumber);   //function is used to edit existing record.   
int no_studs;

class student    //Structure student is made to store student attributes.
{ 
  public:
  int rollno; 
  string name;
  string fname;
  string cell;
  string dob;
  string address;
};

student rec[50];  //This is basic array of defined structure to sore data.
//Array of objects
int main()
{
  int choice;
  int idnumber;   
  int searchkey; 
  
  cout<<"\n\t\tWELCOME TO STUDENT PORTAL"<<endl;
  cout<<"\t\t----------------------"<<endl;
  cout<<"\t\t1-Add student"<<endl;
  cout<<"\t\t2-Edit student"<<endl;
  cout<<"\t\t3-Search student"<<endl;
  cout<<"\t\t4-Quit Program"<<endl;
  cout<<"\t\t----------------------"<<endl;
  cout<<"Enter your choice: "<<endl;

  cin>>choice;
  switch(choice)
 {
  case 1:    
    cout<<"Enter The Total Number of Student(s) : ";
    cin>>no_studs;
    while(no_studs-- && no_studs>=0){
    add_student();
  }
    break;
   case 2:         
    if(rec[0].rollno==0)
   {
     cout<<"Please Add sudents first."<<endl;
     main();
   }
    else         
   { 
     cout<<endl;
     cout<<"--------------------------------------------------------------------------------"<<endl;
     cout<<"---------------------------Student record Table---------------------------------"<<endl;
     cout<<"--------------------------------------------------------------------------------"<<endl; 
     cout<<"ID   "<<"Roll   "<<"Name      "<<"Father\tCell no.      "<<"DOB          "<<"Address\n\n";
     cout<<"--------------------------------------------------------------------------------"<<endl; 

     for(int i=0;i<=no_studs;i++)
    {
      show_data(i);    
     }

     cout<<"--------------------------------------------------------------------------------"<<endl;
     cout<<"Which ID number your want to edit: ";
   
     cin>>idnumber;            
       
    if(idnumber>no_studs || idnumber<0)  
    {      
          cout<<"\nInvalid ID Number."<<endl;
       }
       else
    {
          edit_student(idnumber);    
       }
   }
   break;
   
  case 3:
    if(rec[0].rollno==0)     
   {   
     cout<<"Please Add sudents first."<<endl;
     main();         
    }
    else
   {
     cout<<"Enter roll_no of student you want to search: ";
     cin>>searchkey;    
     search_student(searchkey);}
     break;
   case 4:
    return 0;      
    break;
   default:         
    cout<<"Invalid number."<<endl;
  main();
  }
 }
  
void get_data(int i)        
{   
  cout<<"Enter student roll number in  format(1XXX): ";
  cin>>rec[i].rollno;
  cout<<"Enter student name: ";
  cin>>rec[i].name;
  cout<<"Enter student's Father name: ";
  cin>>rec[i].fname;
  cout<<"Enter student's cell phone number: ";
  cin>>rec[i].cell;
  cout<<"Enter student's Date of Birth(dd/mm/yyyy): ";
  cin>>rec[i].dob;
  cout<<"Enter student's Address: ";
  cin>>rec[i].address;
}

void show_data(int searchkey)      
{    
  int i=searchkey;
  cout<<i<<"    ";
  cout<<rec[i].rollno<<"   ";
  cout<<rec[i].name<<"     ";
  cout<<rec[i].fname<<"\t";
  cout<<rec[i].cell<<"   ";
  cout<<rec[i].dob<<"   ";
  cout<<rec[i].address<<"\n\n";
}

void search_student(int searchkey)
{
  for(int i=0;i<=no_studs;i++)       
 { 
   if(rec[i].rollno==searchkey)   
  {   
    cout<<"ID   "<<"Roll   "<<"Name      "<<"Father\tCell no.      "<<"DOB          "<<"Address\n\n";
    show_data(i);       
   }
  } 
}

void add_student()         
{    
  for(int i=0;i<=no_studs;i++)
 {
    get_data(i);          
  }
  cout<<endl;
  cout<<"--------------------------------------------------------------------------------"<<endl;
  cout<<"---------------------------Student record Table---------------------------------"<<endl;
  cout<<"--------------------------------------------------------------------------------"<<endl;
  cout<<"ID   "<<"Roll   "<<"Name      "<<"Father\tCell no.      "<<"DOB          "<<"Address\n\n";
  cout<<"--------------------------------------------------------------------------------"<<endl;

  for(int i=0;i<=no_studs;i++)
 {
    show_data(i);        
  }
  cout<<"--------------------------------------------------------------------------------"<<endl;
  cout<<"---------------------------------FINISH-----------------------------------------"<<endl;
  cout<<"--------------------------------------------------------------------------------"<<endl;
  main();          
}

void edit_student(int idnumber)     
{  
  for(int i=0;i<=no_studs;i++)       
 {  
   if(idnumber==i)       
  {         
    cout<<"\nExisted information about this record.\n\n";
    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout<<"ID   "<<"Roll   "<<"Name      "<<"Father\tCell no.      "<<"DOB          "<<"Address\n\n";
    cout<<"--------------------------------------------------------------------------------"<<endl;
    show_data(i);      
    cout<<"\n\nEnter new data for above shown record.\n\n";
    get_data(i);         
    cout<<"\n\nRecord updated successfully."<<endl;
    cout<<"ID   "<<"Roll   "<<"Name      "<<"Father\tCell no.      "<<"DOB          "<<"Address\n\n";
    show_data(i);
    main();           
   }
  }
}
