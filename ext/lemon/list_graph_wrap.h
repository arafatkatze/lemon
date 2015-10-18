#ifndef _LIST_GRAPH_WRAP_H_
#define _LIST_GRAPH_WRAP_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct tListGraph tListGraph;
typedef struct tListGraphNode tListGraphNode;

tListGraph* tListGraph_new();
tListGraphNode* tListGraphNode_new();

void tListGraph_free(tListGraph*);
void tListGraphNode_free(tListGraphNode*);

tListGraphNode* tListGraph_addNode(tListGraph*);

void tListGraph_erase(tListGraph*, tListGraphNode*);
void tListGraph_clear(tListGraph*);

int tListGraph_countNodes(tListGraph*);

#ifdef __cplusplus
}; /* extern "C" */
#endif

#endif /* _LIST_GRAPH_WRAP_H_ */

