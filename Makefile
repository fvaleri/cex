SUBDIRS = $(sort $(dir $(wildcard examples/*/Makefile)))

all clean:
	@for dir in $(SUBDIRS); do \
		echo "=== $$dir ==="; \
		$(MAKE) -C $$dir $@ || true; \
	done

.PHONY: all clean
