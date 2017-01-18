#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define temp 0
#define perm 1
#define NIL -1
#define infinity 1000000000

vector < pair<int,int> > arr[100001];
map <pair<int,int>,int> mp;
int predecessor[100001];
int pathlength[100001];
int status[100001];
int v;
ll int sum;
void create_graph()
{
    int edges,s,d,w; //source,destination,weight
    cin>>v>>edges;
    for(int i=0;i<edges;i++)
    {
        cin>>s>>d>>w;
       // s--;d--;
        sum=sum+w;
        arr[s].push_back(make_pair(d,w));
        arr[d].push_back(make_pair(s,w));

    }

}


int min_temp()
{
    int mini=infinity;
    int k=NIL;
    for(int i=0;i<v;i++)
    {
        if(status[i]==temp && pathlength[i]<mini)
        {
         k=i;

         mini=pathlength[i];
        }
    }
    return k;
}

void dijkastra(int s)
{
    int i,current;
   for( i=0;i<v;i++)
   {
       status[i]=temp;
       predecessor[i]=NIL;
       pathlength[i]=infinity;
   }
   pathlength[s]=0;
   while(1)
   {
       current=min_temp();

       if(current==NIL)
        return;
       status[current]=perm;
       for(i=0;i<arr[current].size();i++)
       {
           if((status[arr[current][i].first]==temp))
           {
               if(pathlength[current] + arr[current][i].second  <  pathlength[arr[current][i].first])
               {
                   predecessor[arr[current][i].first]=current;
                   pathlength[arr[current][i].first]=pathlength[current] + arr[current][i].second;
               }
           }
       }

   }
}



int main()
{
    create_graph();
    int source=0;
    dijkastra(source);
    for(int i=0;i<v;i++)
        cout<<pathlength[i]<<" ";
    return 0;
}
