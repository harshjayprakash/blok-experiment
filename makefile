# Compiler Options -----------------------------------------------------------------------

CC                             = clang
CC_FLAGS                       = -g -Wall -Werror -std=c17
CC_LINK_FLAGS                  = -mwindows -mconsole


# Libraries ------------------------------------------------------------------------------

LIBS                           = lkernel32 -luser32 -lshell32 -lgdi32


# Directories ----------------------------------------------------------------------------

DIR_SOURCE                     = src
DIR_BUILD                      = build
DIR_OUTPUT                     = bin


# Object Files ---------------------------------------------------------------------------

OBJ_FILES                      = $(DIR_BUILD)/main.o


# Output ---------------------------------------------------------------------------------

EXECUTABLE                     = tebp.exe


# Compilation Rules ----------------------------------------------------------------------

ALL: $(DIR_OUTPUT)/$(EXECUTABLE)

$(DIR_OUTPUT)/$(EXECUTABLE): $(OBJ_FILES)
	$(CC) $(CC_FLAGS) -o $@ $^ $(LIBS) $(CC_LINK_FLAGS)

$(DIR_BUILD)/main.o: src/main.c
	$(CC) $(CC_FLAGS) -c $^ -o $@


# Clean ----------------------------------------------------------------------------------
.PHONY: CLEAN
CLEAN:
	del /f /q $(DIR_BUILD)\*
	del /f /q $(DIR_OUTPUT)\*
