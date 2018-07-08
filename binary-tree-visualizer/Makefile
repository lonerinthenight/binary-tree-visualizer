TARGET := demo
SRCS   := $(wildcard *.cpp)
OBJS   := $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) -lgcov --coverage *.o -o $@

%.o: %.cpp
	$(CXX) -c -O3 -std=c++11 -fprofile-arcs -ftest-coverage $< -o $@

.PHONY: clean

clean:
	@$(RM) $(TARGET) $(OBJS) $(SRCS:.cpp=.gcno) $(SRCS:.cpp=.gcda) binarytree.gvpr tree.dot tree.png list.dot list.png
