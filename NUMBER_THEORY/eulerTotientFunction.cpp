//factorization method (time complexity -> O(sqrt(N)))
ll phi(ll n){
    ll answer = n;
    for(ll i = 2; i * i <= n; i++){
        if(n % i == 0){
            while(n % i == 0){
                n = n / i;
            }
            answer = answer - answer/i;
        }
    }
    if(n > 1){
        answer = answer - answer/n;
    }
    return answer;
}

//sieve method (time complexity -> O(nloglogn))
ll const N = 1e6;
ll phi[N+1];

void eulerTotientFunction(){
    for(ll i = 1; i <= N; i++){
        phi[i] = i;
    }
    for(ll i = 2; i <= N; i++){
        if(phi[i] == i){
            for(ll j = i; j <= N; j+=i){
                phi[j] -= phi[j]/i;
            }
        }
    }
}
