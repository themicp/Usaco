/*
ID: themicc1
PROG: beads
LANG: C++
*/
#include <cstdio>
#include <cstdlib>

using namespace std;

int collect( char* necklace, int len, int start, int direction ) {
    int sum = 0;
    int i;
    int count;
    if ( direction == 0 ) {
        i = start;
    } else {
        i = start + 1;
    }
    char current, prev;
    current = necklace[ i ];
    prev = current;
    count = 0;
    while ( current == prev && count < len ) {
        printf( "%c ", current );
        ++count;
        ++sum;
        if ( direction == 0 ) {
            --i;
        } else {
            ++i;
        }
        if ( i < 0 ) {
            i = len - 1;
        } else if ( i > len - 1 ) {
            i = 0;
        }
        prev = current;
        current = necklace[ i ];
        if ( prev == 'w' && current != 'w' ) {
            prev = current;
        }
        if ( current == 'w' && prev != 'w' ) {
            current = prev;
        }
    }
    return sum;
}

int i;
char* necklace;
int n;
int colors[ 2 ];
int current;
int max;

int main() {
    FILE *in = fopen( "beads.in", "r" );
    FILE *out = fopen( "beads.out", "w" );
    fscanf( in, "%i\n", &n );
    necklace = ( char* )malloc( n * sizeof( char ) );
    fscanf( in, "%s", necklace );
    for ( i = 0; i < n; ++i ) {
        current = 0;
        current += collect( necklace, n, i, 0 ); 
        printf( "\n" );
        if ( current >= n ) {
            max = current;
            break;
        }
        current += collect( necklace, n, i, 1 ); 
        if ( current > max ) {
            max = current;
        }
    }
    fprintf( out, "%i\n", max );
    return 0;
}
