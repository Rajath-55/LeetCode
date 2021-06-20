int twoEggDrop(int n)
{
	vector m{0};
	for(auto i{1}; i<=n; ++i) 
	{
		int out{INT_MAX};
		for(auto j{1}; j<=i; ++j)              
			out = min(out, 1+max(m[i-j], j-1));
		m.push_back(out);
	}
	return m.back();    
}
