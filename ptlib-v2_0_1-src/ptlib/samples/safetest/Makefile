#
# Makefile
#
# Makefile for safe_test
#
# Copyright (c) 2003 Equivalence Pty. Ltd.
#
# The contents of this file are subject to the Mozilla Public License
# Version 1.0 (the "License"); you may not use this file except in
# compliance with the License. You may obtain a copy of the License at
# http://www.mozilla.org/MPL/
#
# Software distributed under the License is distributed on an "AS IS"
# basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See
# the License for the specific language governing rights and limitations
# under the License.
#
# The Original Code is Portable Windows Library.
#
# The Initial Developer of the Original Code is Equivalence Pty. Ltd.
#
# Contributor(s): ______________________________________.
#
# $Log: Makefile,v $
# Revision 1.3  2006/02/12 21:42:07  dereksmithies
# Add lots of doxygen style comments, and an introductory page.
#
# Revision 1.2  2006/02/07 02:13:16  dereksmithies
# change prgram name from safe_test to safetest
#
# Revision 1.1  2006/02/07 01:02:56  dereksmithies
# Initial release of code to test the PSafeDictionary structure in pwlib.
# Thanks to Indranet Technologies for supporting this work.
#
#
#
#
#


PROG = safetest
SOURCES := main.cxx precompile.cxx

include $(PTLIBDIR)/make/ptlib.mak

###############################################################################

distclean:
	@rm -f *~;
	@rm -f core*
	@rm -fR obj*
	@rm -fR html
	@rm -f log*
	@echo " "
	@echo "removing all editor backup files, core files, obj files, and doc files"
	@echo " "

docs:
	doxygen docs.cfg



##################################################
