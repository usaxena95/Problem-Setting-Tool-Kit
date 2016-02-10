#include<iostream>
using namespace std;
#define lld signed long long int
#define pii pair<int,int>
lld rand64() {
    return (((lld)rand())<<48) | (((lld)rand())<<32) | (((lld)rand())<<16) |(((lld)rand())<<0);
}
lld genRand(lld x,lld y) {
    return  x + rand64()%(y-x+1);
}
lld genRand(int x,int y) {
    return  x + rand64()%(y-x+1);
}
double genRand(double x,double y) {
	lld z = genRand(1LL,100000000000000000LL);
    return  x + (y-x)*genRand(1LL,z)/z;
}
bool tossCoin(double probability){
	lld range = 100000000000000000LL;
	return (genRand(1LL,range) <= range*probability);
}
template<typename T>
string toString(T x) {
    stringstream S;
    S << x;
    string s;
    S >> s;
    return s;
}
class Tree{
public:
	vector<pii>edges;
	vector<pii> randomTree(int N){
		edges.clear();
		for(int i=2;i<=N;++i){
			int p = genRand(1,i-1);
			edges.push_back({i,p});
		}
		random_shuffle(edges.begin(),edges.end());
		return edges;
		//Expected height = Log(N)
	}
	vector<pii> completeBinaryTree(int N){
		edges.clear();
		for(int i=1;i<=N;++i){
			int c1 = 2*i;
			int c2 = c1 + 1;
			if(c1 <= N)
				edges.push_back({i,c1});
			if(c2 <= N)
			edges.push_back({i,c2});
		}
		random_shuffle(edges.begin(),edges.end());
		return edges;
	}
	vector<pii> skewTree(int N,int parentRange/*smaller the value, skewer the tree*/){
		edges.clear();
		for(int i=2;i<=N;++i){
			int p = genRand(max(1,i-parentRange),i-1);
			edges.push_back({i,p});
		}
		random_shuffle(edges.begin(),edges.end());
		return edges;
	}
};
