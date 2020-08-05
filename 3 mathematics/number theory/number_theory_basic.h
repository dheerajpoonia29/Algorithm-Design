
bool prime(int n) { 
	if (n < 2) 
		return false; 
	for (int x = 2; x*x <= n; x++) { 
		if (n%x == 0) 
			return false; 
	} 
	return true; 
}

vector<int> factors(int n) { 
	vector<int> f; 
	for (int x = 2; x*x <= n; x++) { 
		while (n%x == 0) { 
			f.push_back(x); n /= x; 
		} 
	} 
	if (n > 1) 
		f.push_back(n); 
	return f; 
}

vector<int> p;
vector<int> sieve(int n){
	for (int x = 2; x <= n; x++) { 
		if (p[x]) 
			continue; 
		for (int u = 2*x; u <= n; u += x) { 
			p[u] = x; 
		} 
	}
	return p;
}

/*
	px(prime(10));
	pv(factors(7));
	
	p.resize(10, 0);
	pv(sieve(10));
*/
