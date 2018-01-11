#include <stdio.h>

enum { False, True };

void Init( int a[], int end ) {
    for ( int i = 0; i < end; i++ ) { a[ i ] = i + 1; }
}

void Output( int a[], int end ) {
    static int count = 0;
    printf( "%2d : ", ++count );

    for ( int i = 0; i < end; i++ ) { printf( "%3d", a[ i ] ); }
    puts( "" );
}

int Increment( int a[], int idx, int upper ) {
    if ( idx < 0 ) { return False; }

    if ( a[ idx ] < upper ) {
        a[ idx ]++;
        return True;
    }
    else {
        int is_continue = Increment( a, idx - 1, a[ idx ] - 1 );
        a[ idx ] = a[ idx - 1 ] + 1;
        return is_continue;
    }
}

int main() {
    const int n = 20;
    const int m = 10;
    
    int ary[ m ];
    Init( ary, m );

    do {
        Output( ary, m );
    } while ( Increment( ary, m - 1, n ) );

    return 0;
}
