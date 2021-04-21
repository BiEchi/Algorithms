#include <stdint.h>
#include <stdio.h>

#include "mp5.h"
#include "mp9.h"

#define MY_INFINITY   1000000000


// find all the nodes in the given circle.
void
find_nodes (locale_t* loc, vertex_set_t* vs, pyr_tree_t* p, int32_t nnum)
{
    record_fn_call ();

    if ( nnum >= p->n_nodes ) { return; }
    if ( ( 4 * nnum + 1 ) > ( p -> n_nodes ) )
    {
        if (in_range(loc,
            ( p -> node + nnum ) -> x,
            ( p -> node + nnum ) -> y_left
            ) == 1 )
        {
            vs->count++;
            if (vs->count > MAX_IN_VERTEX_SET) { return; }
            vs->id[vs->count-1] = (p->node+nnum)->id;
        }
    } else {
    }

    find_nodes(loc,vs,p,4 * nnum + 1);
    find_nodes(loc,vs,p,4 * nnum + 2);
    find_nodes(loc,vs,p,4 * nnum + 3);
    find_nodes(loc,vs,p,4 * nnum + 4);
    
    return;
}

void
trim_nodes (graph_t* g, vertex_set_t* vs, locale_t* loc)

{
    int32_t new_id = 0;
    int32_t new_count = 0;
    int32_t new_vs_id[MAX_IN_VERTEX_SET];

    for (int32_t m = 0; m < vs->count; m++)
    {
        if (in_range(loc,(g->vertex)[vs->id[m]].x,(g->vertex)[vs->id[m]].y))
        {
            new_vs_id[new_id] = vs->id[m];
            new_id++;
            new_count++;
        }
    }
    vs->count = new_count;
    for (int32_t n = 0; n < new_count; n++)
    {
        vs->id[n] = new_vs_id[n];
    }
    return;
}

void swap(int32_t* a,int32_t* b)
{
    // use a temporary variable temp for the swap.
    int32_t temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(graph_t* g, int heap[], int i, int n)
{
    int child;
    int32_t temp;
    // iterate through the whole heap.
    for (temp = heap[i]; 2*i+1 < n; i = child){
        // the child is the left one of the given node.
        child = 2 * i + 1;
        // this is to test the right one of the given code.
        if (child != n - 1 &&
        g->vertex[heap[child + 1]].from_src >
        g->vertex[heap[child]].from_src) { ++child; }
        if (temp < g->vertex[heap[child]].from_src)
        { heap[i] = heap[child]; }
        // for all other possibilities, go out of the iteration.
        else { break; }
    }
    // note that this function goes for only 1 time, so no recursion exists.
    // write back immediately.
    heap[i] = temp;
}

void my_heapsort(graph_t* g, int32_t heap[], int32_t n)
{
    int i;
    // set i at the second last line of the heap.
    for (i = n / 2; i >= 0; --i) { heapify(g, heap, i, n); }
    // set i at the last line of the heap.
    for (i = n - 1 ; i > 0 ; --i)
    {
        swap(&heap[0],&heap[i]);
        heapify(g, heap, 0, i);
    }
}

void not_visited_exe(graph_t* g,heap_t* h,int32_t min_id,int32_t i)
{
    vertex_t* vertex = g->vertex+min_id;
    vertex_t* neighbor = g->vertex+((g->vertex+min_id)->neighbor[i]);

    neighbor->pred = min_id;
    // write the initial pred
    neighbor->from_src = (vertex->from_src) + (vertex->distance[i]);
    // write the initial distance from the source point
    h->elt[h->n_elts] = vertex->neighbor[i];
    // the top of the heap is added by the new id.
    h->n_elts++;
    // the top of the heap is incremented by 1. (push)
}

void visited_exe(graph_t* g,heap_t* h,int32_t min_id,int32_t i)
{
    vertex_t* vertex = g->vertex+min_id;
    vertex_t* neighbor = g->vertex+((g->vertex+min_id)->neighbor[i]);

    if ( vertex->from_src + vertex->distance[i] < neighbor->from_src )
    // if the NEW distance from source is smaller than
    // the INITIAL distance from source
    {
        neighbor->pred = min_id;
        // write in the new pred for the neighbor
        neighbor->from_src = (vertex->from_src) + (vertex->distance[i]);
        // write in the new from_src for the neighbor
    }
}

void initializeAllVerticesToInfinity(graph_t* g)
{
    for (int32_t i = 0; i < g->n_vertices; i++)
        (g->vertex + i)->from_src = MY_INFINITY;
    
    return;
}

void initializeAllSourceVerticesToZero(graph_t* g, vertex_set_t* src)
{
    for (int32_t i = 0; i < src->count; i++) ((g->vertex)+(src->id[i]))->from_src = 0;
    
    return;
}

void initializeHeapByAddingAllSourceVerticesIntoIt(heap_t* h, vertex_set_t* src)
{
    h->n_elts = src->count;
    for (int32_t i = 0; i < h->n_elts; i++)
        h->elt[i] = src->id[i];
    
    return;
}

int heapIsEmpty(heap_t* h)
{
    return (h->n_elts == 0);
}

int finddestinationVertexIdWithMinimalDistance(vertex_set_t* dest, graph_t* g)
{
    int destinationVertexIdWithMinimalDistance = dest->id[0];
    int destinationVertexMinimalDistance = MY_INFINITY;
    for (int32_t i = 0; i < dest->count; i++)
    {
        if (destinationVertexMinimalDistance > (g->vertex+(dest->id[i]))->from_src)
        {
            destinationVertexIdWithMinimalDistance = dest->id[i];
            destinationVertexMinimalDistance = (g->vertex+(dest->id[i]))->from_src;
        }
    }
    
    return destinationVertexIdWithMinimalDistance;
}

void findPath(graph_t* g, int destinationVertexIdWithMinimalDistance, path_t* path)
{
    path->tot_dist = (g->vertex+destinationVertexIdWithMinimalDistance)->from_src;
    path->n_vertices = 0;
    int32_t pred = destinationVertexIdWithMinimalDistance;

    while ((g->vertex[pred]).from_src != 0)
    {
        path->id[path->n_vertices] = pred;
        path->n_vertices++;
        pred = (g->vertex[pred]).pred;
    }
    path->id[path->n_vertices] = pred;
    path->n_vertices++;
    
    return;
}


// goal: use the dijkstra algorithm to find all the distances from the source vertex set.
// input: the graph, the heap. the source vertex set, the destination vertex set, the path.
// output: 1 for success, 0 for failure.
// side effects: write the shortest path into *path*, with arguments g,h,src,dest.
int32_t
dijkstra (graph_t* g, heap_t* h, vertex_set_t* src, vertex_set_t* dest,
          path_t* path)
{
    // initialization
    initializeAllVerticesToInfinity(g);
    initializeAllSourceVerticesToZero(g, src);
    initializeHeapByAddingAllSourceVerticesIntoIt(h, src);

    // main algorithm
    int32_t vertexIdWithSmallestDistance;
    while (!heapIsEmpty(h))
    {
        my_heapsort(g, h->elt, h->n_elts);
        vertexIdWithSmallestDistance = h->elt[0];

        for (int32_t i = 0;
             i < g->vertex[vertexIdWithSmallestDistance].n_neighbors;
             i++) // for each vertex in w adjacent tov
        {
            vertex_t vertex_w =
                g->vertex[g->vertex[vertexIdWithSmallestDistance].neighbor[i]];
            if (vertex_w.from_src == MY_INFINITY)
                not_visited_exe(g,h,vertexIdWithSmallestDistance,i);
            else
                visited_exe(g,h,vertexIdWithSmallestDistance,i);
        }

        for (int32_t m = 1; m < h->n_elts; m++)
            h->elt[m-1] = h->elt[m];
        h->n_elts--;
    }

    // decide destination vertex id
    int destinationVertexIdWithMinimalDistance = finddestinationVertexIdWithMinimalDistance(dest, g);
    
    // decide the path
    findPath(g, destinationVertexIdWithMinimalDistance, path);

    return 1;
}
