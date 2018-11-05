CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		menu.o organizacion.o persona.o myconnection.o

LIBS =		-lmysqlcppconn -lmysqlcppconn-static

TARGET =	2Parcial

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
