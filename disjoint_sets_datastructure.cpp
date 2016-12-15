#include<bits/stdc++.h>
using namespace std;
#define ll long long
int arr[10000];
int parent[10000];
int n;
int rank_set[10000];

void create_set()
{
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
    }
}


int find_set(int x)
{
    if(parent[x]==x)
        return x;
    else
    {
        int result = find_set(parent[x]);

        parent[x]=result;
        return result;
    }

}

void make_union(int x,int y)
{
    int repres1=find_set(x);
    int repres2=find_set(y);

    if(repres1==repres2)     //Both have same representative so no need to recombine them
        return;


    if(rank_set[repres1]>rank_set[repres2])
         parent[repres2]=repres1;

    if(rank_set[repres1]<rank_set[repres2])
         parent[repres1]=repres2;

    if(rank_set[repres1]==rank_set[repres2]) //combine under any1 of them and increase its rank(height under it) by 1
    {
        parent[repres1]=repres2;
        rank_set[repres2]++;
    }



}


int main()
{

    n=5;
    create_set();
    for(int i=0;i<n;i++)
        arr[i]=i;
    for(int i=0;i<n;i++)
        cout<<parent[i]<<" ";
    cout<<endl;
    make_union(1,2);
    make_union(2,4);
    for(int i=0;i<n;i++)
        cout<<parent[i]<<" ";
    cout<<endl;

    return 0;
}
