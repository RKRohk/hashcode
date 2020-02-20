#include<iostream>
#include <bits/stdc++.h> 
#include<vector>
using namespace std;
int sob[]={1,2,3,6,5,4};
class Library{
    public:
    int index;
    int *books;
    int signup;
    int ship;
    int nob;
    Library(int index,int sgup,int ship,int book[],int nob){
        signup = sgup;
        this->ship = ship;
        books = book;
        score = 0;
        this->nob = nob;
    }
    int score;
};
//sob[]={1,2,3,6,5,4};
//       0,1,2,3,4
void sortScore(Library *l){
   for(int i=0;i<l->nob;++i){
       for(int j=0;j<l->nob-1-i;++j){
           if (sob[l->books[j]]<sob[l->books[j+1]])
           {
               int temp = l->books[j];
               l->books[j] = l->books[j+1];
               l->books[j+1] = temp;
           }
           
       }
   } 
}
void showArray(Library *l){
    for(int i=0;i<l->nob;++i){
        cout<<l->books[i]<<" ";
    }
    cout<<endl;
}
void calcScore(Library *l){
    int noed = 7-l->signup;
    int score =0;
    for(int i=0;i<noed;++i){
        for(int j=0;j<l->ship;++j){
            score+=sob[l->books[j]];
        }
    }
    cout<<score<<endl;
}

int main(){
    int lib0books[] = {0,1,2,3,4};//123654
    int lib1books[] = {3,2,5,0};
    int nob=6,nol=2,nod=7;
    Library lib[] = {Library(0,2,2,lib0books,5),Library(1,3,1,lib1books,4)};
    sortScore(lib);
    sortScore(lib+1);
    showArray(lib);
    showArray(lib+1);
    calcScore(lib);
    calcScore(lib+1);
}