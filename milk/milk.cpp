/*
NAME: themicc1
PROG: milk
LANG: C++
*/
#include <cstdio>
#include <cstdlib>

using namespace std;

int N, M, i, cost;

struct Farmer {
    int p;
    int a;
};

int cmp (const void * a, const void * b) {
    return ( ( *( Farmer* )a ).p - ( *( Farmer* )b ).p );
}

int main() {
    FILE *in = fopen( "milk.in", "r" ), *out = fopen( "milk.out", "w" );
    Farmer *f;
    
    fscanf( in, "%i %i", &N, &M );

    f = ( Farmer* )malloc( M * sizeof( Farmer ) );

    for ( i = 0; i < M; ++i ) {
        fscanf( in, "%i %i", &f[ i ].p, &f[ i ].a );
    }

    qsort( f, M, sizeof( Farmer ), cmp );

    for ( i = 0; i < M; ++i ) {
        if ( f[ i ].a > N ) {
            cost += N * f[ i ].p;
            N = 0;
        }
        else {
            N -= f[ i ].a;
            cost += f[ i ].a * f[ i ].p;
        }
    }

    fprintf( out, "%i\n", cost );

    return 0;
}
