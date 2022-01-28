CC=gcc
PREFIX=/usr
DOCDIR=${PREFIX}/share/doc/papozegar

all:
	${CC} -pthread papozegar.c `xml2-config --libs --cflags` -O2 -o papozegar

debug:
	${CC} -g -pthread papozegar.c `xml2-config --libs --cflags` -O0 -o papozegar

clean:
	-rm *.o papozegar

install:
	install -s papozegar ${PREFIX}/bin
	-mkdir -p ${DOCDIR}
	chmod 755 ${DOCDIR}
	install -m 644 -t ${DOCDIR} LICENSE README

uninstall:
	-rm ${PREFIX}/bin/papozegar

