CXX = g++
CXXFLAGS = -g -Wall -O2 --std=c++11

SOURCES = determinant.cpp
OBJECTS = $(SOURCES:.cpp=.o)
NAME = determinant

%.o:	%.cpp 
	$(CXX) $(CXXFLAGS) -c $<

determinant: $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(NAME)

clean:
	rm -rf *.o *.bin *.a *~ buf tags $(NAME) $(NAME).dSYM
