/*
NAME: themicc1
PROG: dualpal
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

using namespace std;

bool isPalindrome( int num ) {
    int temp = num;
    int newNum = 0;
    char a[ 10 ];
    int pos = 10;
    int i;
    for ( i = 0; i < 10; ++i ) {
        a[ i ] = '0';
    }
    while ( num > 0 ) {
        --pos;
        a[ pos ] = num%10 + '0';
        num /= 10;
    }
    for ( i = 9; i >= pos; --i ) {
        newNum *= 10;
        newNum += a[ i ] - '0';
    }
    return newNum == temp;
}   

int convert( int base, int num ) {
    int res = 0;
    char temp[ 10 ];
    int pos = 10;
    int a = num;
    while ( num > 0 ) {
        --pos;
        temp[ pos ] = num%base;
        num /= base;
    }
    while ( pos < 10 ) {
        num *= 10;
        num += temp[ pos ];
        ++pos;
    }
    return num;
}

int i, base, n, s, counters[ 999999 ], count;
FILE *in = fopen( "dualpal.in", "r" ), *out = fopen( "dualpal.out", "w" );
queue< int > palindromes;
bool pal = false;

int main() {
    fscanf( in, "%i %i", &n, &s );
    i = s + 1;
    while ( count < n ) {
        for ( base = 2; base <= 10; ++base ) {
            if ( isPalindrome( convert( base, i ) ) ) {
                pal = true;
                ++counters[ i ];
            }
        }
        if ( pal ) {
            pal = false;
            if ( counters[ i ] >= 2 ) {
                ++count;
                palindromes.push( i );
            }
        }
        ++i;
    }
    while ( !palindromes.empty() ) {
        fprintf( out, "%i\n", palindromes.front() );
        palindromes.pop();
    }
    return 0;
}
