#include "timeUtils.h"
#include "stdafx.h"

struct tm timeFormat(void)
{
	time_t tick;
	struct tm tm;
	char s[100];//格式化后的时间，2014-02-26 19：45：50

	tick = time(NULL);
	tm = *localtime(&tick);
	strftime(s, sizeof(s), "%Y-%m-%d %H:%M:%S", &tm);
	//printf("%d: %s\n", (int)tick, s);
	//return 0;
	return tm;
}
