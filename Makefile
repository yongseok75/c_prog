CXX         =cc
CXXFAGS     =-Wall -ansi -pedantic
LIBS        =-lm

SOURCES:= $(wildcard *.c)
TARGETS:= $(SOURCES:.c=)

all: $(TARGETS)

define template
$(i): $(i).c
	@echo "Building $$@... "
	@$(CXX) $(1).c $(CXXFLAGS) -o $$@
endef

$(foreach target,$(TARGETS),$(eval $(call template,$(target))))

clean:
	@-rm -f $(TARGETS)

distclean: clean
	@-rm -f *!
