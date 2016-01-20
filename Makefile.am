ACLOCAL_AMFLAGS = -I m4
AUTOMAKE_OPTIONS = subdir-objects
AM_LDFLAGS = -L/usr/lib64 -L/lib64 -lz -lssl -lcrypto 

CIPS_SUBDIRS = client server
SUBDIRS = $(CIPS_SUBDIRS)

dist-hook:
	for subdir in $(CIPS_SUBDIRS); do \
	  tar -c --exclude= "core.*" \
	  --exclude="*.o"  --exclude="*.lo" \
	  --exclude="Makefile" --exclude="config.h" \
	  --exclude="*.spec" --exclude="stamp-h1" --exclude="*-config" \
	  --exclude="autom4te.cache" --exclude="config.status" \
	  --exclude="config.log" --exclude="config.cache" \
	  -f - $$subdir | (cd $(distdir) && tar -xf -)\
	done;
	touch $(distdir)/Makefile.am
	find $(distdir) -exec touch -r $(distdir)/Makefile.am {} \;



