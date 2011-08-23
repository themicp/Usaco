/*
ID: themicc1
PROG: friday
LANG: C++
*/
#include <cstdio>
#include <cstdlib>

using namespace std;

int week[ 7 ];
int months[ 12 ];
int n;
int month = 0;

int main() {
    FILE *in = fopen( "friday.in", "r" );
    FILE *out = fopen( "friday.out", "w" );
    fscanf( in, "%i", &n );
    int leap = 2100;
    int i;
    int year = 1900;
    int temp = year;
    int wday = 2;
    int mday = 1;
    months[ 0 ] = 31;
    months[ 1 ] = 28;
    months[ 2 ] = 31;
    months[ 3 ] = 30;
    months[ 4 ] = 31;
    months[ 5 ] = 30;
    months[ 6 ] = 31;
    months[ 7 ] = 31;
    months[ 8 ] = 30;
    months[ 9 ] = 31;
    months[ 10 ] = 30;
    months[ 11 ] = 31;

    while ( year <= ( temp + n ) - 1 ) {
        if ( year > leap ) {
            leap += 100;
        }
        while ( month < 12 ) {
            if ( month == 1 ) {
                if ( year != 1900 && year != leap ) {
                    if ( year % 4 == 0 ) {
                        months[ 1 ] = 29;
                    }
                    else {
                        months[ 1 ] = 28;
                    }
                }
                else {
                    months[ 1 ] = 28;
                }
            }
            while ( mday <= months[ month ] ) {
                if ( mday == 13 ) {
                    ++week[ wday ];
                }
                ++mday;
                ++wday;
                if ( wday > 6 ) {
                    wday = 0;
                }
            }
            mday = 1;
            ++month;
        }
        ++year;
        month = 0;
    }

    for ( i = 0; i < 7; ++i ) {
        fprintf( out, "%i", week[ i ] );
        if ( i < 6 ) {
            fprintf( out, " " );
        }
    }
    fprintf( out, "\n" );

    return 0;
}
