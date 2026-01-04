TARGET			= SOMBRERO

CSRCS			= $(TARGET).C ../EXTGRAPH/EXTGRAPH.C

COBJS			= $(TARGET).OBJ ../EXTGRAPH/EXTGRAPH.OBJ

CC			= BCC
CFLAGS			= -w -I../EXTGRAPH
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
