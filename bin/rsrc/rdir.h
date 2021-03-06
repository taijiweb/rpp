#include "rlist.h"
#include "rfile.h"

class rdir
{
	mac FILE_ATTRIBUTE_DIRECTORY 0x00000010

	static rbuf<rstr> get_file_bfs(rstr path)
	{
		rbuf<rstr> ret
		if(path.count()>4096||0==path.count())//ubuntu's max path len is 4096
		{
			return ret
		}
		str_to_std(path);
		if(path.count()>=1&&path.get(path.count()-1)!=`/)
		{
			path+='/';
		}
		rlist<rstr> queue;
		queue.push(path);
		while(!queue.empty())
		{
			path=queue.pop_front();
			WIN32_FIND_DATAW wfd; 
			int handle=rf.FindFirstFileW(utf16c(path+'*.*'),&wfd); 
			if(handle!=-1)
			{
				for
				{
					rstr name;
					wsize=rf.lstrlenW(&wfd.cFileName)*2
					name.set_size(wsize)
					rf.memcpy(name.begin,&wfd.cFileName,wsize)
					name=rcode.utf16_to_utf8(name)
					str_to_std(name);
					if(rstr(".")!=name&&rstr("..")!=name)
					{
						if(0!=AND(wfd.dwFileAttributes,FILE_ATTRIBUTE_DIRECTORY))
						{
							queue.push(path+name+rstr("/"));
							ret.push(path+name+rstr("/"));
						}
						else
						{
							ret.push(path+name);
							//*r_to_p<int*>(&item.size)=wfd.nFileSizeLow;
							//*(r_to_p<int*>(&item.size)+4)=wfd.nFileSizeHigh;
						}
					}
					ifn(rf.FindNextFileW(handle,&wfd))
						break
				}
				rf.FindClose(handle);
			}
		}
		return ret;
	}

	static void str_to_std(rstr& s)
	{
		for(char* p=s.begin();p!=s.end();++p)
		{
			if(`\==int(*p))
			{
				*p=`/;
			}
			elif(rcode.is_utf8_3(*p))
			{
				p+=2
			}
			elif(rcode.is_utf8_2(*p))
			{
				p++
			}
		}
	}
	
	static rstrw get_real_name(rstrw name)
	{
		rstrw ret;
		wchar ch=`.;
		int pos=name.m_buf.find_last(ch);
		if(pos<name.count())
			ret=name.sub(0,pos);
		return ret;
	}
	
	static rstr get_real_name(rstr name)
	{
		return get_real_name(name.torstrw).torstr
	}
	
	//目录操作最好用utf16
	static rstrw get_suffix(rstrw name)
	{
		rstrw ret;
		wchar ch=`.;
		int pos=name.m_buf.find_last(ch);
		if(pos<name.count())
			ret=name.sub(pos+1);
		return ret;
	}
	
	static rstr get_suffix(rstr name)
	{
		return get_suffix(name.torstrw).torstr
	}
	
	static rstrw get_prev_dir(rstrw path)
	{
		rstrw ret;
		if(path.empty())
			return ret;
		path.m_buf.pop();
		wchar ch=`/;
		int pos=path.m_buf.find_last(ch);
		if(pos>=path.count())
			return ret;
		ret=path.sub(0,pos+1);
		return ret;
	}
	
	static rstr get_prev_dir(rstr name)
	{
		return get_prev_dir(name.torstrw).torstr
	}

	static rstrw get_name(rstrw path)
	{
		rstrw ret;
		if(path.empty())
			return ret;
		wchar ch=`/;
		int pos=path.m_buf.find_last(ch);
		if(pos>=path.count())
			return ret;
		ret=path.sub(pos+1);
		return ret;
	}
	
	static rstr get_name(rstr name)
	{
		return get_name(name.torstrw).torstr
	}
}

struct WIN32_FIND_DATAW
{
    int dwFileAttributes;
    int8 ftCreationTime;
    int8 ftLastAccessTime;
    int8 ftLastWriteTime;
    int nFileSizeHigh;
    int nFileSizeLow;
    int dwReserved0;
    int dwReserved1;
    wchar cFileName[260];
    wchar cAlternateFileName[14];
} 