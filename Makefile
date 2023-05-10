# ----------------------------
# Program Options
# ----------------------------

NAME         ?= TISH
DESCRIPTION  ?= ""
COMPRESSED   ?= YES
ARCHIVED     ?= YES

# ----------------------------
# Compile Options
# ----------------------------

CFLAGS   ?= -Oz -W -Wall -Wextra -Wwrite-strings
CXXFLAGS ?= -Oz -W -Wall -Wextra -Wwrite-strings

# ----------------------------

include $(shell cedev-config --makefile)
