#include "lemon.h"

static VALUE cListGraph;
//static VALUE cListGraphNode;

static void lg_free(void* p) {
	tListGraph_free(p);
}

//static void lgn_free(void* p) {
	// TODO:
//}

static VALUE lg_alloc(VALUE klass) {
	tListGraph* lg;
	VALUE obj;

	lg = tListGraph_new();
	obj = Data_Wrap_Struct(klass, 0, lg_free, lg);

	return obj;
}

static VALUE lg_initialize(VALUE self) {
	return self;
}

/* TODO: Copy and Dup, PickAxe page: 277 */

static VALUE lg_addNode(VALUE self) {
	tListGraph* lg;
	Data_Get_Struct(self, tListGraph, lg);

	tListGraphNode* node;
	node = tListGraph_addNode(lg);
/*
	VALUE obj;
	obj = Data_Wrap_Struct(cListGraphNode, 0, lgn_free, node);
	return obj;
*/
	return self;
}

static VALUE lg_clear(VALUE self) {
	tListGraph* lg;
	Data_Get_Struct(self, tListGraph, lg);
	tListGraph_clear(lg);
	return self;
}

static VALUE graphCountNodes(VALUE self, VALUE graph) {
	tListGraph* lg;
	Data_Get_Struct(graph, tListGraph, lg);

	int nodes = tListGraph_countNodes(lg);
	VALUE result;
	result = INT2NUM(nodes);

	return result;
}

static VALUE mLemon;

void Init_lemon()
{
	mLemon = rb_define_module("Lemon");

	cListGraph = rb_define_class_under(mLemon, "ListGraph", rb_cObject);
	rb_define_alloc_func(cListGraph, lg_alloc);

	rb_define_method(cListGraph, "initialize", lg_initialize, 0);
	rb_define_method(cListGraph, "addNode", lg_addNode, 0);
	rb_define_method(cListGraph, "clear", lg_clear, 0);

	rb_define_module_function(mLemon, "countNodes", graphCountNodes, 1);
}

