
main: main.o
	g++ $< -lWSTP64i4 -lm -lpthread -lrt -lstdc++ -ldl -luuid -o $@

%.tm.cxx: %.tm
	wsprep $< -o $@

%.o: %.cxx	
	g++ $< -c -lWSTP64i4 -lm -lpthread -lrt -lstdc++ -ldl -luuid -o $@

%.o: %.cpp
	g++ $< -c -lWSTP64i4 -lm -lpthread -lrt -lstdc++ -ldl -luuid -o $@
