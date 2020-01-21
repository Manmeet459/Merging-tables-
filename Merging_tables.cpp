#include<bits/stdc++.h>

using namespace std;

std::vector<int> row ;
std::vector<int> tab ;
std::vector<int> src ;
std::vector<int> des ;
int max_row=0;

int Find(int x){
    
    if (tab[x]!=x){
        tab[x]=Find(tab[x]);
    }
    
    return tab[x];
    
}

void merge_table(int d, int s){
    
    int final_d=Find(d);
    int final_s=Find(s);
    
    if(final_s!=final_d){
        
        row[final_d]+=row[final_s];
        tab[final_s]=final_d;
        if( row[final_d]>max_row ){
            max_row=row[final_d];    
        }
        
    }
}


void merging_tables(int m){
    
    for(int i=0; i<m; i++){
        
        int s=src[i];
        int d=des[i];
        merge_table(d-1,s-1);
        cout<<max_row<<endl;
    }
}

int main(){
    
    int n, m;
    
    cin>>n;
    cin>>m;
    
    int r, s, d;
    
    for(int i=0; i<n; i++ ){
        cin>>r;
        tab.push_back(i);
        row.push_back(r);
        if( r>max_row ){
            max_row=r;    
        }
    }
    
    for(int i=0; i<m; i++){
        cin>>d>>s;
        des.push_back(d);
        src.push_back(s);
        
    }

    merging_tables(m);
    
    return 0;
    
}