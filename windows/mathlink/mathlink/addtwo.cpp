/* To launch this program from within Mathematica use:
 *   In[1]:= link = Install["addtwo"]
 *
 * Or, launch this program from a shell and establish a
 * peer-to-peer connection.  When given the prompt Create Link:
 * type a port name. ( On Unix platforms, a port name is a
 * number less than 65536.  On Mac or Windows platforms,
 * it's an arbitrary word.)
 * Then, from within Mathematica use:
 *   In[1]:= link = Install["portname", LinkMode->Connect]
 */


extern "C"
{
	int addtwo(int i, int j)
	{
		return i + j;
	}

	int addList(int* list, long j, int k,int m)
	{
		//return 1;
		int sum = 0;
		for (int i = 0; i < j; ++i)
		{
			sum += list[i];
		}
		return sum*k;
	}
}