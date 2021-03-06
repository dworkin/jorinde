/**
 * Description: Wrapper class for server that's used by LSP's.
 * Version:     $Id$
 * License:     (c)2004 Joakim Romland, see doc/License
 */
# include <kernel/kernel.h>
# include "../../../include/www.h"
# include <type.h>
# include "../include/lsp.h"

inherit LIB_HTTP_STRING;
inherit LIB_LSP_PROPERTY_WRAP;

#ifdef __IGOR__
inherit "/lib/lwo";
#endif

static Request request;
static Response response;
static Application application;
static Httpd server;
static Session session;
static Uri req_uri;
static int expires_in;

void set_related(Request req, Response res, Application app, Httpd ser,
		                Session ses) {
	request = req;
	response = res;
	application = app;
	server = ser;
	session = ses;

	::set_wrapped(ses);
}

static void create(varargs int clone)
{
}

string **get_breadcrumbs()		{ return session->get_breadcrumbs(); }
string  get_id()				{ return session->get_id(); }
int     get_expires()			{ return session->get_expires(); }
int     get_remove()			{ return session->get_remove(); }

/* TODO: set/get properties */
