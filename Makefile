# Makefile - based off of dpdk-ringping which is based off l3fwd

APP = queuequery
PKGCONF = pkg-config
SRCS-y := queuequery.c

CFLAGS += -O -g -Wall -W

# Build using pkg-config variables if possible
ifneq ($(shell $(PKGCONF) --exists libdpdk && echo 0),0)
$(error "no installation of DPDK found")
endif

all: build/$(APP)

PC_FILE := $(shell $(PKGCONF) --path libdpdk 2>/dev/null)
CFLAGS += -O3 $(shell $(PKGCONF) --cflags libdpdk)
LDFLAGS = $(shell $(PKGCONF) --libs libdpdk)

build/$(APP): $(SRCS-y) Makefile $(PC_FILE) | build
        $(CC) $(CFLAGS) $(SRCS-y) -o $@ $(LDFLAGS)

build:
        @mkdir -p $@

.PHONY: clean
clean:
        rm -f build/$(APP)
        test -d build && rm -r build || true
