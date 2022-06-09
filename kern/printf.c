// Simple implementation of cprintf console output for the kernel,
// based on printfmt() and the kernel console's cputchar().

#include <inc/types.h>
#include <inc/stdio.h>
#include <inc/stdarg.h>


static void
putch(int ch, int *cnt)
{
	cputchar(ch);
	*cnt++;
}

int
vcprintf(const char *fmt, va_list ap)
{
	int cnt = 0;

	vprintfmt((void*)putch, &cnt, fmt, ap);
	return cnt;
}

int
cprintf(const char *fmt, ...)
{
	va_list ap;
	int cnt;

	va_start(ap, fmt);
	cnt = vcprintf(fmt, ap);
	va_end(ap);

	return cnt;
}

// cprintf function, but seperate to toggle for logging. 
int
log(const char *fmt, ...)
{
	// va_list ap;
	// int cnt;

	// va_start(ap, fmt);
	// cnt = vcprintf(fmt, ap);
	// va_end(ap);

	return 0;
}

int
log2(const char *fmt, ...)
{
	// va_list ap;
	// int cnt;

	// va_start(ap, fmt);
	// cnt = vcprintf(fmt, ap);
	// va_end(ap);

	return 0;
}


