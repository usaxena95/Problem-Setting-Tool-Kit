/*
JUST COMPILE AND RUN
-----------------------------------------------------------------------------
Author :            ---------------------------------------------------------
    UTKAR$H $AXENA  ---------------------------------------------------------
    IIT INDORE      ---------------------------------------------------------
-----------------------------------------------------------------------------
*/
#include<bits/stdc++.h>
#include<iostream>
#include "../common/general.h"
#include "../common/OutputUtility.h"
using namespace std;
#define fre 	freopen("0.in","r",stdin);freopen("0.out","w",stdout)
#define abs(x) ((x)>0?(x):-(x))
#define MOD 1000000007
#define lld signed long long int
#define pii pair<int,int>
#define scan(x) scanf("%d",&x)
#define print(x) printf("%d\n",x)
#define scanll(x) scanf("%lld",&x)
#define printll(x) printf("%lld\n",x)
int testCase = 0;
string fileName;

string ParticipantFileName(){
	return "Output\\Output-"+toString(testCase)+".txt";
}
string AuthorFileName(){
	return "..\\Output\\output-"+toString(testCase)+".txt";
}
string checkParticipantOutput(){
	return ("fc "+ParticipantFileName() + " "+AuthorFileName());
}
int main(){
	OutputUtility obj("participant","..\\Input","input","Output","output");
	int T;
	cerr<<"How many test files ?\n";
	cin>>T;
	for(int i=1;i<=T;++i){
			++testCase;
		cerr<<"Working on Test Case = "<<i<<endl;
		obj.GenerateOutput();
		system(checkParticipantOutput().c_str());
	}
}
