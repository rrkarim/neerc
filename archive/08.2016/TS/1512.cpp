#include <bits/stdc++.h>
//#pragma comment(linker, "/STACK:16777216")
#define MAX_CHAR 256
#define MAXN 1000005
#define INF 1000000
#define pi 3.14159265358979323846
int main()
{
	int N, Mod;
	vector <int> L;
	cin >> N;
	Mod = N % 12;
	for (int x = 2; x <= N; x += 2)
		L.push_back( x );
		
	if ( Mod == 3 || Mod == 9 ) {
		L.push_back( 2 );
		L.erase( L.begin() );
	}
	
	if ( Mod == 8 ) {
		std::vector < int > V;
		for ( int x = 1; x <= N; x += 2 )
			V.push_back( x );
		for ( int i = 1; i < V.size(); i += 2 )
			std::swap( V.at( i ), V.at( i - 1 ) );
		for ( int i = 0; i < V.size(); ++i )
			L.push_back( V.at( i ) );
	}
	else
		for ( int x = 1; x <= N; x += 2 )
			L.push_back( x );
		
	if ( Mod == 2 && N >= 3 ) {
		std::swap( *std::find( L.begin(), L.end(), 1 ), *std::find( L.begin(), L.end(), 3 ) );
		if ( N >= 5 ) {
			L.erase( std::find( L.begin(), L.end(), 5 ) );
			L.push_back( 5 );
		}
	}
	
	if ( Mod == 3 || Mod == 9 ) {
		L.erase( std::find( L.begin(), L.end(), 1 ) );
		L.push_back( 1 );
		L.erase( std::find( L.begin(), L.end(), 3 ) );
		L.push_back( 3 );
	}
	
	for ( int i = 0; i < L.size(); ++i )
		std::cout << i + 1 << " " << L.at( i ) << "\n";
	
	return 0;
}