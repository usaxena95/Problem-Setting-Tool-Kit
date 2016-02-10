#include<bits/stdc++.h>
#include "common/general.h"
#include "common/OutputUtility.h"
#include "common/InputUtility.h"
#include<iostream>
using namespace std;
#define lld signed long long int
#define rep(i,from,to) for(int i=(from);i <= (to); ++i)

InputUtility input("Input","input",OutputUtility("author","Input","input","Output","output"));

void init(){ //flush data used if necessary

}
int A[156][156];
void nextTestFile(int T,int N )
{
    init();
    input.open();

    cout<<T<<endl;
    while(T--){
		cout<<N<<endl;
		for(int i=1;i<=N;++i){
			for(int j=1;j<=N;++j){
				A[i][j] = tossCoin(0.2);
				A[j][i] = 1 - A[i][j];
			}
			A[i][i] = 0;
		}
		for(int i=1;i<=N;++i){
			for(int j=1;j<=N;++j){
				cout<<A[i][j]<<' ';
			}
			cout<<endl;
		}
    }
    input.close();
}
int main()
{
	nextTestFile(250,16);
}
