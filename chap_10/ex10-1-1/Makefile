TARGET			= EX10-1-1

CSRCS			= $(TARGET).C

COBJS			= $(TARGET).OBJ

CC			= BCC
CFLAGS			= -w
LDFLAGS			= -w

.C.OBJ:
	$(CC) $(CFLAGS) -o$@ -c $<

$(TARGET).EXE: $(COBJS)
	$(CC) $(LDFLAGS) -e$(TARGET).EXE $(COBJS) $(LIBS)

all: $(TARGET).EXE

run: $(TARGET).EXE
	$(TARGET).EXE

clean:
	COMMAND /C DEL /Q $(COBJS)
	COMMAND /C DEL /Q $(TARGET).EXE
