#include<iostream>
//Round Robin Scheduling Algorithm
using namespace std;
int main()
{
int n;
int i,j;
cout<<"Enter no of Processes: ";
cin>>n;
int arr[n];
int new_arr[n];
for(i=0;i<n;i++)
{
cout<<"Enter Arrival Time of Process: "<<i+1<<" ";
cin>>arr[i];
new_arr[i] = arr[i];
}
int b_t[n];
int new_b_t[n];
for(i=0;i<n;i++)
{
cout<<"Enter Burst Time of Process: "<<i+1<<" ";
cin>>b_t[i];
new_b_t[i] = b_t[i];
}
int least_arr=arr[0];
int max_arr=arr[0];
int total_burst=0;
for(i=0;i<n;i++)
{
if(least_arr>arr[i])
least_arr=arr[i];
if(max_arr<arr[i])
max_arr=arr[i];
total_burst +=b_t[i];
}
int queue[max_arr+total_burst+1];
int ind=0;
int comp[n];
for(i=0;i<n;i++)
comp[i]=0;
int w_t[n];
int tat[n];
int cov[n];
for(i=0;i<n;i++)
cov[i]=0;
int tq;
cout<<"Enter Time Quantum: ";
cin>>tq;
int  time_slice=least_arr;
for(i=0;i<n;i++)
{
if(arr[i]==least_arr)
{
if(tq<b_t[i])
{
time_slice+=tq;
comp[i]+=tq+least_arr;
for(j=0;j<n;j++)
{
if(j!=i)
{
comp[j]+=least_arr+tq;
}
}
if(time_slice-tq<max_arr)
{
for(j=0;j<n;j++)
{
if(arr[j]<=time_slice&&j!=i&&cov[j]==0)
{
arr[j] = 9999;
queue[ind] = j;
ind++;
}
}
}
queue[ind] = i;
ind++;
b_t[i] -= tq;
}
else
{
time_slice+=b_t[i];
comp[i]+=b_t[i]+least_arr;
for(j=0;j<n;j++)
{
if(j!=i)
comp[j]+=least_arr+b_t[i];
}
if(time_slice-b_t[i]<max_arr)
{
for(j=0;j<n;j++)
{
if(arr[j]<=time_slice&&j!=i&&cov[j]==0)
{
arr[j] = 9999;
queue[ind] = j;
ind++;
}
}
}
cov[i] = 1;
b_t[i] = 0;
}
break;
}
}
while(1)
{
if(ind==0)
break;
int cnt=0;
for(i=0;i<n;i++)
{
if(cov[i]==1)
cnt++;
}
if(cnt==n)
break;
if(tq<b_t[queue[0]])
{
time_slice+=tq;
comp[queue[0]]+=tq;
for(j=0;j<n;j++)
{
if(j!=queue[0]&&cov[j]==0)
comp[j]+=tq;
}
int queue_temp = queue[0];
for(j=0;j<ind-1;j++)
{
queue[j] = queue[j+1];
}
ind--;
if(time_slice-tq<max_arr)
{
for(j=0;j<n;j++)
{
if(arr[j]<=time_slice&&j!=queue_temp&&cov[j]==0)
{
arr[j] = 9999;
queue[ind] = j;
ind++;
}
}
}
queue[ind] = queue_temp;
ind++;
b_t[queue_temp] -= tq;
}
else
{
time_slice+=b_t[queue[0]];
comp[queue[0]]+=b_t[queue[0]];
for(j=0;j<6;j++)
{
if(j!=queue[0]&&cov[j]==0)
comp[j]+=b_t[queue[0]];
}
if(time_slice-b_t[queue[0]]<max_arr)
{
for(j=0;j<n;j++)
{
if(arr[j]<=time_slice&&j!=i)
{
arr[j] = 9999;
queue[ind] = j;
ind++;
}
}
}
cov[queue[0]] = 1;
b_t[queue[0]] = 0;
int queue_temp = queue[0];
for(j=0;j<ind-1;j++)
{
queue[j] = queue[j+1];
}
ind--;
if(time_slice<=max_arr)
{
for(j=0;j<n;j++)
{
if(arr[j]<=time_slice&&j!=queue_temp&&cov[j]==0)
{
queue[ind] = j;
ind++;
}
}
}
}
}
for(i=0;i<n;i++)
tat[i] = comp[i]-new_arr[i];
for(i=0;i<n;i++)
w_t[i] = tat[i]-new_b_t[i];
cout<<"\tProcess\t\tArrival Time\t\tBurstTime\t\tCompletion Time\t\tWaiting Time\t\tTurn Aroun Time\n";
for(i=0;i<n;i++)
{
cout<<"\t\tP"<<i+1<<"\t\t\t"<<new_arr[i]<<"\t\t"<<new_b_t[i]<<"\t\t\t"<<comp[i]<<"\t\t\t"<<w_t[i]<<"\t\t\t\t"<<tat[i]<<"\n";
}
cout<<"Gantt Chart: \n";
int max_com=comp[0];
for(i=0;i<n;i++)
{
if(comp[i]>max_com)
max_com=comp[i];
}
for(i=0;i<=max_com;i++)
{
if(i==0)
cout<<0<<"___";
int flag = 0;
int k;
for(j=0;j<n;j++)
{
if(comp[j]==i)
{
flag=1;
k=comp[j];
break;
}
}
if(flag==1)
cout<<k<<"___";
else
cout<<"___";
}
cout<<"\n";
for(i=0;i<=max_com;i++)
{
int flag = 0;
int k;
for(j=0;j<n;j++)
{
if(comp[j]==i)
{
flag=1;
k=j+1;
break;
}
}
if(flag==1)
cout<<"   "<<k<<"   ";
else
cout<<"   ";
}
return 0;
}
