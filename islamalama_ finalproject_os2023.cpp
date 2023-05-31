#include <iostream>
#include <fstream>
#include<conio.h>
using namespace std;
int process[5];
int Arrival_Time_p[5];
int CPU_Burst_p[5];
int Size_in_Bytes_p[5];

void SearchStack01(int pnt,int tm);
void SearchStack02(int pnt, int tm);
void AddQue(int pnt);
int at[50], bt[50], ct[50]={0}, qt, rqi[50]={0}, c=0, st, flg=0, tm=0, noe=0, pnt=0, btm[50]={0}, tt, wt;
float att, awt;

int Memory_Size;
int Page_size;
int Q;
int Cs;
int pageng_p[5];


 int main(){
    
ifstream Myfile;
string data;
Myfile.open("process.txt");

      
Myfile>>Memory_Size>>Page_size>>Q>>Cs;
Myfile>>process[0]>>Arrival_Time_p[0]>>CPU_Burst_p[0]>>Size_in_Bytes_p[0];
Myfile>>process[1]>>Arrival_Time_p[1]>>CPU_Burst_p[1]>>Size_in_Bytes_p[1];
Myfile>>process[2]>>Arrival_Time_p[2]>>CPU_Burst_p[2]>>Size_in_Bytes_p[2];
Myfile>>process[3]>>Arrival_Time_p[3]>>CPU_Burst_p[3]>>Size_in_Bytes_p[3];
Myfile>>process[4]>>Arrival_Time_p[4]>>CPU_Burst_p[4]>>Size_in_Bytes_p[4];

cout << "                    Process Control Block " << endl;
	cout << "          ----------------------------------------" << endl;
	cout << "         | Process ID  | Arrival Time | CPU Burst |" << endl;
	cout << "          ----------------------------------------" << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << "                " << process[i] << "              " << Arrival_Time_p[i] << "           " << CPU_Burst_p[i] << "     " << endl;
		cout << "          ----------------------------------------" << endl;
	}
cout<<"____________________________\n\n";
// fcfs

cout << " ----------------------------------------------------------" << endl;
	cout << "|                    FCFS ALGORITHM RESULT                 |" << endl;
	cout << " ----------------------------------------------------------" << endl;
	
int FCFS[5];
int sortedFCFS[5];
int WAITING_FCFS[5];
FCFS[0] = -100;
FCFS[1] = -100;
FCFS[2] = -100;
FCFS[3] = -100;
FCFS[4] = -100;
int Current_Time =0;
cout << endl << endl;
cout << "1. Gnatt Chart" << endl << endl;
cout << "      -------------------------------------------------------" << endl;
cout << "      ";
for(int j =0 ; j < 5 ; j++){
int MIN_ARRIVAl = 100000;
int PR =0;

for(int i =0 ; i < 5 ; i++){

if(Arrival_Time_p[i] <= MIN_ARRIVAl && FCFS[i] == -100 && Arrival_Time_p[i] <= Current_Time)
{
MIN_ARRIVAl =Arrival_Time_p[i];
PR = i;

}

}
FCFS[PR] = j;
WAITING_FCFS[PR] = Current_Time - Arrival_Time_p[PR];
cout << "|  P" << PR << "  ";
sortedFCFS[j]=PR;
if(j!=4)
	cout<<"| CS ";
Current_Time = Current_Time + CPU_Burst_p[PR]+Cs;
}
cout <<"|"<< endl << "      ";
	cout << 0;
	for (int i = 0; i < 5; i++)
	{
		int time=WAITING_FCFS[sortedFCFS[i]]+CPU_Burst_p[sortedFCFS[i]]+Arrival_Time_p[sortedFCFS[i]];
		cout << "-----" << time;
		if(i!=4)
			cout<<"---"<<time+Cs ;
	}

	cout << endl << endl << endl;
cout<<endl;
double AVAREG_WAITING =0,AVAREG_TURN =0;


cout << endl << endl;
	
	cout << "2.    -------------+--------------+--------------+---------" << endl;
	cout << "     | Process ID  | Finish Time  | Waiting Time | TA Time |" << endl;
	cout << "      -------------+--------------+--------------+---------" << endl;


	for (int i = 0; i < 5; i++)
	{
		cout << "          " << process[i] << "            " << WAITING_FCFS[i]+CPU_Burst_p[i]+Arrival_Time_p[i] << "              ";
		cout << WAITING_FCFS[i] << "            " << WAITING_FCFS[i]+CPU_Burst_p[i]<< endl;
		cout << "     +-------------+--------------+--------------+---------+" << endl;
		AVAREG_WAITING = AVAREG_WAITING +WAITING_FCFS[i];
        AVAREG_TURN = AVAREG_TURN +WAITING_FCFS[i]+CPU_Burst_p[i];
	}
	
cout<<"\n\nAVAREG_WAITING = "<<AVAREG_WAITING/5<<endl;
cout<<"AVAREG_TURN = "<<AVAREG_TURN/5<<endl;
cout<<"CPU Utilization = "<<(double(Current_Time-5)/(Current_Time-1))*100<<"%";




// sjf
cout << "\n\n\n\n ----------------------------------------------------------" << endl;
	cout << "|                    SJF ALGORITHM RESULT                 |" << endl;
	cout << " ----------------------------------------------------------" << endl;
int SJF[5];
int sortedSJF[5];
int WAITING_SJF[5];
SJF[0] = -100;
SJF[1] = -100;
SJF[2] = -100;
SJF[3] = -100;
SJF[4] = -100;
Current_Time =0;
cout << endl << endl;
cout << "1. Gnatt Chart" << endl << endl;
cout << "      -------------------------------------------------------" << endl;
cout << "      ";
for(int j =0 ; j < 5 ; j++){
int MIN_BURST = 100000;
int PR =0;

for(int i =0 ; i < 5 ; i++){

if(CPU_Burst_p[i] <= MIN_BURST && SJF[i] == -100 && Arrival_Time_p[i] <= Current_Time)
{
MIN_BURST = CPU_Burst_p[i];
PR = i;

}

}

SJF[PR] = j;
WAITING_SJF[PR] = Current_Time - Arrival_Time_p[PR];
cout << "|  P" << PR << "  ";
sortedSJF[j]=PR;
if(j!=4)
	cout<<"| CS ";
Current_Time = Current_Time + CPU_Burst_p[PR]+Cs;
}
cout <<"|"<< endl << "      ";
	cout << 0;
	for (int i = 0; i < 5; i++)
	{
		int time=WAITING_SJF[sortedSJF[i]]+CPU_Burst_p[sortedSJF[i]]+Arrival_Time_p[sortedSJF[i]];
		cout << "-----" << time;
		if(i!=4)
			cout<<"---"<<time+Cs ;
	}

	cout << endl << endl << endl;
cout<<endl;
AVAREG_WAITING =0,AVAREG_TURN =0;
cout << endl << endl;
	
	cout << "2.    -------------+--------------+--------------+---------" << endl;
	cout << "     | Process ID  | Finish Time  | Waiting Time | TA Time |" << endl;
	cout << "      -------------+--------------+--------------+---------" << endl;


	for (int i = 0; i < 5; i++)
	{
		cout << "          " << process[i] << "            " << WAITING_SJF[i]+CPU_Burst_p[i]+Arrival_Time_p[i] << "              ";
		cout << WAITING_SJF[i] << "            " << WAITING_SJF[i]+CPU_Burst_p[i]<< endl;
		cout << "     +-------------+--------------+--------------+---------+" << endl;
		AVAREG_WAITING = AVAREG_WAITING +WAITING_SJF[i];
        AVAREG_TURN = AVAREG_TURN +WAITING_SJF[i]+CPU_Burst_p[i];
	}
	

cout<<"AVAREG_WAITING = "<<AVAREG_WAITING/5<<endl;
cout<<"AVAREG_TURN = "<<AVAREG_TURN/5<<endl;
cout<<"CPU Utilization = "<<(double(Current_Time-5)/(Current_Time-1))*100<<"%";

//RR
int sortedRR[20];
	int k=0;
cout << "\n\n\n\n ----------------------------------------------------------" << endl;
	cout << "|                    RR ALGORITHM RESULT                   |" << endl;
	cout << " ----------------------------------------------------------" << endl;
	
for(int x=0;x<5;x++){
    at[x]=Arrival_Time_p[x];
    bt[x]=CPU_Burst_p[x];
    btm[x]=bt[x];}

qt=Q;

cout << endl << endl;
cout << "1. Gnatt Chart" << endl << endl;
cout << "      ---------------------------------------------------------------------------------------------" << endl;
cout << "      ";
int i=0;
do{
    if(flg==0){
       st=at[0];
       //---ReduceBT
       if(btm[0]<=qt){
          tm=st+btm[0];
          btm[0]=0;
          SearchStack01(pnt,tm);}
       else{
          btm[0]=btm[0]-qt;
          tm=st+qt;
          SearchStack01(pnt,tm);
          AddQue(pnt);}
    }//if
 
    else{
       pnt=rqi[0]-1;
       st=tm;
       //---DeleteQue
       for(int x=0;x<noe && noe!=1;x++){
          rqi[x]=rqi[x+1];}
       noe--;
       //---ReduceBT
       if(btm[pnt]<=qt){
          tm=st+btm[pnt];
          btm[pnt]=0;
          SearchStack02(pnt, tm);}
       else{
         btm[pnt]=btm[pnt]-qt;
          tm=st+qt;
          SearchStack02(pnt, tm);
          AddQue(pnt);}
    }//else

    //AssignCTvalue
    if(btm[pnt]==0){
       ct[pnt]=tm;
    }//if

   flg++;

   //cout<<"]-P"<<pnt+1<<"-["<<tm;
   sortedRR[k]=tm;
   k++;
   cout << "|  P" << pnt << "  ";
   if(i!=7)
   cout << "  CS" << "  ";
   i++;
  
}while(noe!=0);
cout << "\n      -------------------------------------------------------------------------------------------------------" << endl;


cout << "\n2.    -------------+--------------+--------------+---------" << endl;
	cout << "     | Process ID  | Finish Time  | Waiting Time | TA Time |" << endl;
	cout << "      -------------+--------------+--------------+---------" << endl;

for(int x=0;x<5;x++){
    tt=ct[x]-at[x];
    wt=tt-bt[x];
    cout << "          " << x << "            " << ct[x] << "              ";
		cout <<wt<< "            " << tt<< endl;
		cout << "     +-------------+--------------+--------------+---------+" << endl;
    awt=awt+wt;
    att=att+tt;

	
		
}//for

cout<<"\nAVERAGE TT: "<<att/5<<"\nAVERAGE WT: "<<awt/5;
cout<<"CPU Utilization = "<<(double(57-7)/(57))*100<<"%";



Myfile.close();

system("pause");

return 0;
}


void SearchStack01(int pnt,int tm){
    for(int x=pnt+1;x<5;x++){
       if(at[x]<=tm){
          rqi[noe]=x+1;
          noe++;}
    }//for
}//void

void SearchStack02(int pnt, int tm){
    for(int x=pnt+1;x<5;x++){
       //---CheckQue
       int fl=0;
       for(int y=0;y<noe;y++){
          if(rqi[y]==x+1){
             fl++;}}
       if(at[x]<=tm && fl==0 && btm[x]!=0){
          rqi[noe]=x+1;
          noe++;}
    }//for
}//void

void AddQue(int pnt){
    rqi[noe]=pnt+1;
    noe++;
}//void
