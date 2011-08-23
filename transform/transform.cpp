/*
NAME: themicc1
PROG: transform
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

void rotate90( char a[ 10 ][ 11 ], int len ) { 
    char b[ 10 ][ 11 ];
    int i, o;
    for ( i = 0; i < len; ++i ) {
        for ( o = 0; o < len; ++o ) {
            b[ o ][ len - 1 - i ] = a[ i ][ o ];
        }
    }
    for ( i = 0; i < len; ++i ) {
        for ( o = 0; o < len; ++o ) {
            a[ i ][ o ] = b[ i ][ o ];
        }
    }
}

void rotate180( char a[ 10 ][ 11 ], int len ) {
    rotate90( a, len );
    rotate90( a, len );
}
void rotate270( char a[ 10 ][ 11 ], int len ) {
    rotate180( a, len );
    rotate90( a, len );
}

void reflect( char a[ 10 ][ 11 ], int len ) {
    char b[ 10 ][ 11 ];
    int i, o;
    for ( i = 0; i < len; ++i ) {
        for ( o = 0; o < len; ++o ) {
            b[ i ][ len - 1 - o ] = a[ i ][ o ];
        }
    }
    for ( i = 0; i < len; ++i ) {
        for ( o = 0; o < len; ++o ) {
            a[ i ][ o ] = b[ i ][ o ];
        }
    }
}

void transform( char a[ 10 ][ 11 ], int len, int method ) {
    if ( method == 1 ) {
        rotate90( a, len );
    }
    if ( method == 2 ) {
        rotate180( a, len );
    }
    if ( method == 3 ) {
        rotate270( a, len );
    }
    if ( method == 4 ) {
        reflect( a, len );
    }
    if ( method == 5 ) {
        reflect( a, len );
        rotate90( a, len );
    }
    if ( method == 6 ) {
        reflect( a, len );
        rotate180( a, len );
    }
    if ( method == 7 ) {
        reflect( a, len );
        rotate270( a, len );
    }
}

int i, o, count, n;

int main() {
    FILE *in = fopen( "transform.in", "r" );
    FILE *out = fopen( "transform.out", "w" );
    char a[ 10 ][ 11 ];
    char b[ 10 ][ 11 ];
    char c[ 10 ][ 11 ];
    bool done = false;

    fscanf( in, "%d", &n );

    for ( i = 0; i < n; ++i ) {
        fscanf( in, "%s\n", a[ i ] );
    }
    for ( i = 0; i < n; ++i ) {
        fscanf( in, "%s\n", b[ i ] );
    }
    for ( i = 0; i < 8; ++i ) {
        transform( c, n, i );
        done = true;
        for ( o = 0; o < n; ++o ) {
            if ( strcmp( c[ o ], b[ o ] ) != 0 ) {
                done = false;
                break;
            }
        }
        if ( done ) {
            break;
        }
        for ( o = 0; o < n; ++o ) {
            strcpy( c[ o ], a[ o ] );
        }
    }
    if ( i == 0 ) {
        i = 6;
    }
    if ( i == 6 || i == 7 ) {
        i = 5;
    }
    if ( i == 8 ) {
        i = 7;
    }
    fprintf( out, "%i\n", i );
    return 0;
}
