
__declspec(dllexport) int mycheat()
{
	int *p = (int *)0x282E7FB0;
	while (1)
	{
		if (*p < 10000)
			*p = 10000;
	}
}