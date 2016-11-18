#include <stdio.h>
#include <sys/resource.h>
int main(void)
{
	struct rusage resources;
	double utime, stime, total_time;
	if (getrusage(RUSAGE_SELF,&resources) != 0) {
		perror("getrusage failed\n");
	}
	utime = (double)resources.ru_utime.tv_sec + 1.e-6 * (double) resources.ru_utime.tv_usec;
	stime = (double)resources.ru_stime.tv_sec + 1.e-6 * (double) resources.ru_stime.tv_usec;
	total_time = utime + stime;
	printf("User time %.3lf, System time %.3lf, Total time %.3lf\n",utime,stime,total_time);
	return 0;
}
