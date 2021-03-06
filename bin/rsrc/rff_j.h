namespace rff
{
	void* fopen_w(wchar* name,wchar* mode)
	{
		push mode
		push name
		calle "_wfopen"
		add esp,8
		mov s_ret,eax
	}
	
	int remove_w(wchar* name)
	{
		push name
		calle "_wremove"
		mov s_ret,eax
		add esp,4
	}
	
	int rename_w(wchar* oldname,wchar* newname)
	{
		push newname
		push oldname
		calle "_wrename"
		mov s_ret,eax
		add esp,8
	}

	void* fopen(char* name,char* mode)
	{
		push mode
		push name
		calle "fopen"
		add esp,8
		mov s_ret,eax
	}
	
	int fclose(void* fp)
	{
		push fp
		calle "fclose"
		add esp,4
		mov s_ret,eax
	}
	
	int fread(char* data,int size,int count,void* fp)
	{
		push fp
		push count
		push size
		push data
		calle "fread"
		add esp,16
		mov s_ret,eax
	}
	
	int fwrite(char* data,int size,int count,void* fp)
	{
		push fp
		push count
		push size
		push data
		calle "fwrite"
		add esp,16
		mov s_ret,eax
	}
	
	fseek(void* fp,int off,int origin)
	{
		push origin
		push off
		push fp
		calle "fseek"
		add esp,12
	}
	
	fseek8(void* fp,int8 off,int origin)
	{
		fseek(fp,off.toint,origin)
		/*push origin
		push [ebp+(s_off off+4)]
		push off
		push fp
		calle "_fseeki64"
		add esp,16*/
	}
	
	int ftell(void* fp)
	{
		push fp
		calle "ftell"
		mov s_ret,eax
		add esp,4
	}
	
	//fixme jit模式暂时不能使用64位文件
	int8 ftell8(void* fp)
	{
		return ftell(fp)
		/*int8 temp
		push fp
		lea esi,temp
		push esi
		calle "_ftelli64"
		add esp,8
		return temp*/
	}
}