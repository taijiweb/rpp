class uint
{
	rd4 m_in;

	enum
	{
		c_min=0,
		c_max=0xffffffff,
	}

	~uint()
	{
	}

	uint()
	{
	}

	uint(uint a)
	{
		mov esi,this
		mov [esi],a
	}

	uint(uint& a)
	{
		mov edi,this
		mov esi,a
		mov [edi],[esi]
	}

	uint(int a)
	{
		mov esi,this
		mov [esi],a
	}

	uint(char a)
	{
		mov edi,this
		mov [edi],0
		mov1 [edi],a
	}

	TYPE to<TYPE>()
	{
		mov esi,this
		mov s_ret,[esi]
	}

	int toint()
	{
		mov esi,this
		mov s_ret,[esi]
	}

	uint touint()
	{
		mov esi,this
		mov s_ret,[esi]
	}

	rstr torstr()
	{
		rstr ret(this)
		return ret
	}

	operator=(uint a)
	{
		mov esi,this
		mov [esi],a
	}

	operator=(uint& a)
	{
		mov edi,this
		mov esi,a
		mov [edi],[esi]
	}

	friend operator<->(uint& a,uint& b)
	{
		c=a
		a=b
		b=c
	}

	operator+=(uint a)
	{
		mov esi,this
		add [esi],a
	}

	operator-=(uint a)
	{
		mov esi,this
		sub [esi],a
	}

	operator*=(uint a)
	{
		mov esi,this
		imul [esi],a
	}

	operator/=(uint a)
	{
		mov esi,this
		_udiv [esi],a
	}

	operator%=(uint a)
	{
		mov esi,this
		_umod [esi],a
	}

	operator++()
	{
		mov esi,this
		add [esi],1
	}

	operator--()
	{
		mov esi,this
		sub [esi],1
	}

	friend uint operator+(uint a,uint b) 
	{
		add a,b
		mov s_ret,a
	}

	friend uint operator-(uint a,uint b)
	{
		sub a,b
		mov s_ret,a
	}

	friend uint operator*(uint a,uint b)
	{
		imul a,b
		mov s_ret,a
	}

	friend uint operator/(uint a,uint b)
	{
		_udiv a,b
		mov s_ret,a
	}

	friend uint operator%(uint a,uint b)
	{
		_umod a,b
		mov s_ret,a
	}

	friend bool operator<(uint a,uint b)
	{
		_uclsb a,b
		mov s_ret,ebx
	}

	friend bool operator<=(uint a,uint b)
	{
		_uclesb a,b
		mov s_ret,ebx
	}

	friend bool operator==(uint a,uint b)
	{
		cesb a,b
		mov s_ret,ebx
	}

	friend bool operator!=(uint a,uint b)
	{
		cnesb a,b
		mov s_ret,ebx
	}

	friend bool operator>(uint a,uint b)
	{
		return b<a;
	}

	friend bool operator>=(uint a,uint b)
	{
		return b<=a;
	}

	set(uint a)
	{
		mov esi,this
		mov [esi],a
	}

	clear()
	{
		mov esi,this
		mov [esi],0
	}

	bool empty()
	{
		return 0==this
	}

	print()
	{
		rf.print this
	}

	printl()
	{
		rf.printl this
	}
};