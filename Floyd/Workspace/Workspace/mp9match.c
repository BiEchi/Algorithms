#include <stdint.h>
#include <stdio.h>

#include "mp5.h"
#include "mp9.h"

void initializeVertexSets(vertex_set_t* src_vs, vertex_set_t* dst_vs)
{
    src_vs->count = 0;
    dst_vs->count = 0;
}

int32_t
match_requests (graph_t* g, pyr_tree_t* p, heap_t* h,
		request_t* r1, request_t* r2, vertex_set_t* src_vs,
		vertex_set_t* dst_vs, path_t* path)
// standard representation: graph_t* g, not graph_t *g
{
    initializeVertexSets(src_vs, dst_vs);

	printf("fn_count is %d.\n",find_nodes_inst(&(r1->from),src_vs,p,0));
	trim_nodes(g,src_vs,&(r2->from));
	printf("fn_count is %d.\n",find_nodes_inst(&(r1->to),dst_vs,p,0));
	trim_nodes(g,dst_vs,&(r2->to));
	int run = dijkstra(g,h,src_vs,dst_vs,path);
    
	if (run > MAX_PATH_LENGTH)
        return 0;
	if ( (src_vs -> count <= 0) || (dst_vs -> count <= 0) )  return 0;
	if (src_vs->count > MAX_IN_VERTEX_SET || dst_vs->count > MAX_IN_VERTEX_SET)
		return 0;
    
    return 1;
}
