demo:
	g++ -O2 -std=c++11 binary-tree-visualizer.cpp linked-list-visualizer.cpp demo.cpp -o demo

.PHONY: clean

clean:
	@if [ -f demo ]; then rm demo; fi
	@if [ -f binarytree.gvpr ]; then rm binarytree.gvpr; fi
	@if [ -f tree.dot ]; then rm tree.dot; fi
	@if [ -f tree.png ]; then rm tree.png; fi
	@if [ -f list.dot ]; then rm list.dot; fi
	@if [ -f list.png ]; then rm list.png; fi
