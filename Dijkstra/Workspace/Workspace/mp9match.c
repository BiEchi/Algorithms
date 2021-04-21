#include <stdint.h>
#include <stdio.h>
// #include <time.h>

#include "mp5.h"
#include "mp9.h"


int32_t
match_requests (
		graph_t* g, // a copy of the graph
		pyr_tree_t* p, // the pyramid tree containing all vertices in the graph
		heap_t* h, // the "blank" heap in use of Dijkstra's Algorithm
		request_t* r1, // request for walking partner 1
		request_t* r2, // request for walking partner 2
		// Note: each request consists of two locales, 
		// a starting point and an ending point
		vertex_set_t* src_vs, // source vertex set
		// the vertices in the graph is MAX_IN_VERTEX_SET
		// you need to IDENTIFY up to MAX_IN_VERTEX_SET graph vertices whinin
		// range of the starting point *** for both requests ***
		vertex_set_t* dst_vs, // destination vertex set
		// you need to IDENTIFY graph vertices within range of the ending point
		// for both requests, thses should be written in the dst_vs argument.
		path_t* path
		// after finding the path (incl. both the initial point and the ending point),
		// it is then written into the "path" argument.
		)
{
	// 1. we need to find the nodes first:
	// how many nodes are there in the picture?
	/*  The function find_nodes() is shown as below
	 * 	void
		find_nodes (locale_t* loc, vertex_set_t* vs, pyr_tree_t* p, int32_t nnum)
		{
    		// Do not modify the following line nor add anything above in the function.
    		record_fn_call ();
			}
	 */

	// the count of vertices in the vertex set should be
	// initialized to 0 before calling find_nodes().

	src_vs->count = 0;
	dst_vs->count = 0;

	// place for find_nodes() & trim_nodes for the starting circle
	printf("fn_count is %d.\n",find_nodes_inst(&(r1->from),src_vs,p,0));
	// printf("from, bef trim, %d\n",src_vs->count);
	trim_nodes(g,src_vs,&(r2->from));
	// printf("from, aft trim, %d\n",src_vs->count);
	// place for find_nodes() & trim_nodes for the ending circle
	printf("fn_count is %d.\n",find_nodes_inst(&(r1->to),dst_vs,p,0));
	// printf("to, bef trim, %d\n",dst_vs->count);
	trim_nodes(g,dst_vs,&(r2->to));
	// printf("to, aft trim, %d\n",dst_vs->count);
	// Check the time for the program to run.
	// clock_t start, finish;
	// start = clock();
	// 2. we need to match the closest path for the two points.
	int run = dijkstra(g,h,src_vs,dst_vs,path);
	// note: the above line hasa actually ALREADY called diskstra() !!!

	// Check the time for the program to run.
	// finish = clock();
	// printf("%0.4f\n", (double) (finish - start)/CLOCKS_PER_SEC);

	// 3. it's likely to get some failure cases, so we set return 0 cases.

	// 0) if the disjkstra algorithm returns 0, it means that
	// the path is too long (path > 100), for which situation
	// we need to return 0 immediately.
	if (run > MAX_PATH_LENGTH) { return 0; }

	// 1) if the source node set or the destination node set is empty, return 0.
	if ( (src_vs -> count <= 0) || (dst_vs -> count <= 0) ) { return 0; }
	// if the program ends with error "The program is not being run",
	// then it means that your program is ended with return value 0.
	
	// 2) if the path requires more than MAX_PATH_LENGTH nodes (counting in both the
	// starting and ending nodes), return 0 too.
	// this function is implemented in the funciton dijkstra() in mp9.c,
	// so it's the same as 3.0) !
	if (src_vs->count > MAX_IN_VERTEX_SET || dst_vs->count > MAX_IN_VERTEX_SET)
	{
		return 0;
	}
	// for all other cases, return 1 for success.
    return 1;
}
