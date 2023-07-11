def sieve(n : int): # sieve of eratosthenes in linear times
    primes = []
    SPF = [] * (n +1) # smallest prime factor
    isPrime = [True] * (n + 1)
    isPrime[0] = isPrime[1] = False
    for i in range(2, n + 1):
        if isPrime[i]:
            primes.append(i)
            SPF[i] = i
        
        for j in range(len(primes)):
            if i * primes[j] > n or primes[j] > SPF[i]: break
            isPrime[i * primes[j]] = False
            SPF[i * primes[j]] = primes[j]
    return primes
