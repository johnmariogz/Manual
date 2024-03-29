typedef long long ll;

int primesGenerator( ll m, ll n ){

    vector<int> primes(100001);
    //memset( primes, false, sizeof( primes ) );

    ll cm = m;
    if( cm % 2 != 0 ) cm++;
    for( ll i = cm; i<=n; i += 2 ){
        primes[i-m] = true;
    }

    for( ll it = 3; it*it <=n; it+=2 ){
        if( m >= it*it && m%it == 0 ) primes[ 0 ] = true;
        int pMult = (m-(m%it)) + it;
        for( ll j = pMult ; j<=n; j+=it ){
            if( j >= it*it ) primes[ j-m ] = true;
        }
    }

    for( ll i = 0; i<=n-m; ++i ){
        if( i+m == 1 || i+m == 0 ) primes[ i ] = true;
        if( i+m == 2 ) primes[i] = false;
        if( !primes[i] ) cout << i+m << endl;
    }
}

