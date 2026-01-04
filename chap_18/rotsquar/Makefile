TARGET			= ROTSQUAR

CSRCS			= $(TARGET).C ../TURTLE/TURTLE.C

COBJS			= $(TARGET).OBJ ../TURTLE/TURTLE.OBJ

CC			= BCC
CFLAGS			= -w -I../TURTLE
LDFLAGS			= -w
LIBS                    = GRAPHICS.LIB

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
