/*
NAME: themicc1
PROG: palsquare
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

char alphabet[ 11 ];
int i, base, len;
FILE *in = fopen( "palsquare.in", "r" ), *out = fopen( "palsquare.out", "w" );

bool isPalindrome( char num[ 18 ], int elems ) {
    int j = 0, k = elems - 1;
    while ( j <= k ) {
        if ( num[ j ] != num[ k ] ) {
            return false;
            break;
        }
        ++j;
        --k;
    }
    return true;
}   

int convert( int base, int num, char* dest ) {
    int pos = 18;
    int count = 0;
    int i;
    for ( i = 0; i < 18; ++i ) {
        dest[ i ] = 0 + '0';
    }
    while ( num > 0 ) {
        --pos;
        if ( num%base > 9 ) {
            dest[ pos ] = alphabet[ num%base - 10 ];
        }
        else {
            dest[ pos ] = num%base + '0';
        }
        num = num/base;
        ++count;
    }
    for ( i = 0; i < count; ++i ) {
        dest[ i ] = dest[ i + pos ];
    }
    dest[ count ] = '\0';
    return count;
}

int main() {
    char a[ 18 ];
    char b[ 18 ];
    strcpy( alphabet, "ABCDEFGHIJ" );
    fscanf( in, "%i", &base );
    for ( i = 1; i <= 300; ++i ) {
        len = convert( base, i * i, a );
        convert( base, i, b );
        if ( isPalindrome( a, len ) ) {
            fprintf( out, "%s %s\n", b, a );
        }
    }
    return 0;
}
