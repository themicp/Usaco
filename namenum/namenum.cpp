/*
NAME: themicc1
PROG: namenum
LANG: C++
*/
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

long long int reverse( long long int n ) {
    long long int num = 0;
    while ( n != 0 ) {
        num *= 10;
        num += n%10;
        n = n/10;
    }
    return num;
}

void nextComb( int* array, int lenArray ) {
    int i;
    --lenArray;
    ++array[ lenArray ];
    if ( array[ lenArray ] > 2 ) {
        array[ lenArray ] = 0;
        if ( lenArray > 0 ) {
            nextComb( array, lenArray );
        }
    }
}

bool isValid( char word[ 20 ], char valid[ 4617 ][ 20 ] ) {
    bool validName = false;
    int lo = 0;
    int hi = 4616;
    int mid;

    while ( lo <= hi ) {
        mid = ( lo + hi ) / 2;
        if ( strcmp( word, valid[ mid ] ) == 0 ) {
            validName = true;
            break;
        }
        else if ( strcmp( word, valid[ mid ] ) > 0 ) {
            lo = mid + 1;
        }
        else if ( strcmp( word, valid[ mid ] ) < 0 ) {
            hi = mid - 1;
        }
    }
    return validName;
}


char word[ 20 ];
char valid[ 4617 ][ 20 ];
char nums[ 10 ][ 4 ];
char test[] = "KRISTOPHER";

vector< string > names;
vector< string >::iterator it;

int main() {
    FILE *in = fopen( "namenum.in", "r" );
    FILE *out = fopen( "namenum.out", "w" );
    FILE *validNames = fopen( "dict.txt", "r" );

    int i;
    int a[ 12 ]; 
    int count; 
    int len;
    int b[ 12 ];

    for ( i = 0; i < 12; ++i ) {
        a[ i ] = 0;
        b[ i ] = 0;
    }
    len = 0;
    count = 0;

    strcpy( nums[ 2 ], "ABC" );
    strcpy( nums[ 3 ], "DEF" );
    strcpy( nums[ 4 ], "GHI" );
    strcpy( nums[ 5 ], "JKL" );
    strcpy( nums[ 6 ], "MNO" );
    strcpy( nums[ 7 ], "PRS" );
    strcpy( nums[ 8 ], "TUV" );
    strcpy( nums[ 9 ], "WXY" );

    long long int n;
    fscanf( in, "%lli", &n );
    long long int temp = n;

    bool done = false;


    for ( i = 0; i < 4617; ++i ) {
        fscanf( validNames, "%s", valid[ i ] );
    }

    while ( n != 0 ) {
        n = n/10;
        ++len;
    }
    i = 0;
    n = reverse( temp );
    while ( n != 0 ) {
        a[ i ] = n%10;
        n = n/10;
        ++i;
    }

    while ( !done ){
        done = true;
        printf( "%i\n", len );
        for ( i = 0; i < len; ++i ) {
            word[ i ] = nums[ a[ i ] ][ b[ i ] ];
            if ( b[ i ] != 2 ) {
                done = false;
            }
        }
        word[ len ] = '\0';
        if ( isValid( word, valid ) ) {
            count += 1;
            names.push_back( word );
        }
        if ( strcmp( word, test ) == 0 ) {
            printf( "now\n" );
        }
        nextComb( b, len );
    }

    sort( names.begin(), names.end() );

    if ( count == 0 ) {
        fprintf( out, "NONE\n" );
    }
    else {
        for ( it = names.begin(); it < names.end(); ++it ) {
            fprintf( out, "%s\n", ( *it ).c_str() );
        }
    }

    return 0;
}
