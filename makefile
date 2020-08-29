# g++ Version 6
ifdef SYSTEMROOT
	COMPILER  = g++
else
	COMPILER = /opt/gcc6/bin/g++
endif
# To use g++ V.6, be sure you have   
#	export LD_LIBRARY_PATH=/opt/gcc6/lib64
# in your .bash_profile

DEBUG  = -g

EXE  = app

HDRS  = WordData.h\
	WordDataList.h\
	WordList.h\
	WordCList.h\
	LinkedList.h\
	WordSTL.h\
	SortSearch.h\

OBJS  = WordData.o\
	WordDataList.o\
	WordCList.o\
	WordSTL.o\
	app.o\

SRC  = 	WordData.cpp\
	WordDataList.cpp\
	WordCList.cpp\
	WordSTL.cpp\
	app.cpp\


##########################################################################
$(EXE): $(OBJS) $(HDRS) $(SRC)
	$(COMPILER) -o $(EXE) $(OBJS) $(DEBUG)

WordData.o:  WordData.cpp WordData.h 
	$(COMPILER) -c WordData.cpp $(DEBUG)

WordDataList.o:  WordData.h WordDataList.cpp WordDataList.h WordList.h SortSearch.h
	$(COMPILER) -c WordDataList.cpp $(DEBUG)

WordCList.o:  WordCList.cpp WordCList.h WordList.h LinkedList.h
	$(COMPILER) -c WordCList.cpp $(DEBUG)

WordSTL.o:  WordSTL.cpp WordSTL.h WordList.h SortSearch.h
	$(COMPILER) -c WordSTL.cpp $(DEBUG)

app.o:  WordDataList.h WordList.h WordCList.h WordSTL.h app.cpp 
	$(COMPILER) -c app.cpp $(DEBUG)


clean:
ifdef SYSTEMROOT
	rm *.o $(EXE)
else
	\rm *.o $(EXE)
endif
