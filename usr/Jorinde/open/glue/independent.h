/* TODO: More stuff should be moved in here */
#ifndef ST_TICKS
# include <status.h>
#endif
# define AssessCost()       (status()[ST_TICKS])
# define GetCost(c)         (c-status()[ST_TICKS])
# define OutputCost(t, c)   (SYSLOG(ralign(t,16)+": "+ralign(pretty_number(c), 12) + " ticks\n"))

/*
 * Define this to enable tests on Phantasmal's objectd. I guess it could
 * easily be modified for other objectd's as well.
 */
# undef __HAVE_OBJECTD__
# define OBJECTD                    USR_SYSTEM+"objectd/sys/objectd"
# define OBJECTD_WRAP               USR_SYSTEM+"objectd/sys/objectdwrap"

/*
 * Define this if you want to test the indexing crap :)
 */
#if 0
# define __TEST_INDEXD__
#endif
