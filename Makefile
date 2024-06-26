AR     := ar
CC     := gcc
CFLAGS := -Wall -O2
OS     := $(shell uname -s)
ARCH   := $(shell uname -m)

ifeq ($(DEBUG), 1)
	CFLAGS += -g -DDEBUG
endif

OBJS := sched.o netpoll.o time.o chan.o net.o hook.o gg.o

ifeq ($(OS), Linux)
	OBJS += netpoll_linux.o time_linux.o
endif

ifeq ($(OS), Darwin)
	OBJS += netpoll_freebsd.o time_freebsd.o
endif

ifeq ($(ARCH), x86_64)
	OBJS += sched_amd64.o
endif

%.o: %.S
	$(CC) $(CFLAGS) -c $<

%.o: %.c
	$(CC) $(CFLAGS) -c $<
	
all: libgg.a

libgg.a: $(OBJS)
	$(AR) rcs $@ $^

.PHONY: clean
clean:
	rm *.o
	rm *.a
