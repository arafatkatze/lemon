#include <lemon/list_graph.h>
#include "list_graph_wrap.h"

using namespace lemon;

extern "C" {

struct tListGraph {
	ListGraph lg;
};

struct tListGraphNode {
	ListGraph::Node node;
};

tListGraph* tListGraph_new() {
	tListGraph* graph = new tListGraph;
	return graph;
}

void tListGraph_free(tListGraph* graph) {
	delete graph;
}

tListGraphNode* tListGraph_addNode(tListGraph* graph) {
	tListGraphNode* node = new tListGraphNode; 
	node->node	= graph->lg.addNode();
	return node;
}

size_t tListGraph_countNodes(tListGraph* graph) {
	size_t nodes = countNodes(graph->lg);
	return nodes;
}

};
