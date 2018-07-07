TARGET := demo
SRCS  := $(wildcard *.cpp)
OBJS   := $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) *.o -o $@

%.o: %.cpp
	$(CXX) -c -O3 -std=c++11 $< -o $@

.PHONY: clean

clean:
	@$(RM) $(TARGET) $(OBJS) binarytree.gvpr tree.dot tree.png list.dot list.png
