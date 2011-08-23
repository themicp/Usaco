/*
USER: themicc1
PROG: milk2
LANG: C++
*/
#include <cstdio>
#include <cstdlib>

using namespace std;

struct Farmers {
    int start;
    int end;
};

int cmp ( const void *a, const void *b ) {
    struct Farmers *aa = ( struct Farmers * )a;
    struct Farmers *bb = ( struct Farmers * )b;
    return aa->start - bb->start;
}

int n, i;
int start, end;
int milking, idle;
int max_milking, max_idle;
struct Farmers *jobs;

int main() {
    FILE *in = fopen( "milk2.in", "r" );
    FILE *out = fopen( "milk2.out", "w" );
    fscanf( in, "%i", &n );
    jobs = (struct Farmers*)malloc( n * sizeof( struct Farmers ) );

    for ( i = 0; i < n; ++i ) {
        fscanf( in, "%i %i", &jobs[ i ].start, &jobs[ i ].end );
    }
    qsort( jobs, n, sizeof( struct Farmers ), cmp );
    start = jobs[ 0 ].start;
    end = jobs[ 0 ].end;
    if ( n == 1 ) {
        milking = end - start;
    }
    for ( i = 0; i < n; ++i ) {
        if ( jobs[ i ].start <= end && jobs[ i ].end > end ) {
            end = jobs[ i ].end;
        } else if ( jobs[ i ].start > end ) {
            max_milking = end - start;
            max_idle = jobs[ i ].start - end;
            if ( max_milking > milking ) {
                milking = max_milking;
            }
            if ( max_idle > idle ) {
                idle = max_idle;
            }
            start = jobs[ i ].start;
            end = jobs[ i ].end;
        }
    }
    if ( milking == 0 ) {
        milking = end - start;
    }
    fprintf( out, "%i %i\n", milking, idle );

    return 0;
}
