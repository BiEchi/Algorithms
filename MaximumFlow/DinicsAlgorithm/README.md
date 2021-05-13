# Dinic's Algorithm

Hello, here is the implementation of Dinic's Algorithm (which is extraordinarily sophisticated to implement). The infrastructure of Dinic's Algorithm is the *labeled layered networks*, as mentioned in *slide 534*. I'll go through the basic concepts of Dinic's algorithm first.

## ==Shortest== Augmenting Path Algorithm (SAPA)

### Layer

The shortest path (unweighted) from vertex `src` to vertex `u` is called the **layer** of `u`. The process to mark the layers of *all* the vertices is called **layering**. Shown below is the layers of the network mentioned on *slides 535*.

![Layers](https://tva1.sinaimg.cn/large/008i3skNly1gqe9et6ciej307t05lwei.jpg)

### Layered Network

Assume after some random operations we've got the layered residual network below.

![ResidualNetwork](https://tva1.sinaimg.cn/large/008i3skNly1gqe9shswoej307t05ndfx.jpg)

After layering the *residual network*, delete *all* vertices with same or higher `layer` of `sink` vertex (excluding `sink` itself) and *all* relating edges. We get the result below.

![ResidualNetworkAfterDeleting](https://tva1.sinaimg.cn/large/008i3skNly1gqe9vz5xa9j307t05n74f.jpg)

Then we delete all edges from one vetrex to a vertex with same or lower layer.

![ResidualNetworkAfterDeletingTwice](https://tva1.sinaimg.cn/large/008i3skNly1gqe9z4luy8j307t05odfz.jpg)

Now we get the subnetwork of the residual network, and we call it $G''(V'',E'')$. You can observe now for any edge $<u,v>$ we have $layer(u)+1=layer(v)$. We call these edges **admitted edges** (black ones in the last figure above).

As another observation, we see that if we start from `src`, however we walk, we can always stop at `dest` (not always `sink`) with the shortest path.

### Blocking Flow

Assume we now have the capacity network below.

![CapacityNetwork](https://tva1.sinaimg.cn/large/008i3skNly1gqeade63rxj307t05l3yk.jpg)

Assume an available flow in the capacity network is $f$, then when $G''$ does not contain any augmenting path, we call $f$ a **blocking flow**. The example to the network above is shown below.

![BlockingFlow](https://tva1.sinaimg.cn/large/008i3skNly1gqeaerg05yj307t05nwek.jpg)

### Algorithm Representation

![image-20210511105409471](https://tva1.sinaimg.cn/large/008i3skNly1gqeau5rixcj30vw0hwn7t.jpg)

## Dinic's Algorithm: ==Continuous== Shortest Augmenting Path Algorithm

### Difference with the conventional SAPA Algorithm

The difference between SAPA and Dinic's algorithm is that, **Dinic's Algorithm conducts a DFS search instead of BFS search**, which improves the effeciency of the algorithm by a large factor. Consider the BFS search, you will find that after each loop, BFS has to seach from `src` to `sink` to find another augmenting path; but **if you conduct DFS, one loop indicates multiple times of augmentation**. However, it has not much differences as SAPA because applying whether DFS or BFS for examination of augmenting paths is just a divergence of different prototypes of the Ford-Fulkerson Method.

### Essence

The essence of Dinic's Algorithm is to apply a level graph. Typically we construct the level graph with BFS and find the augmenting paths (or understand as *we augment the flow*) with the Ford-Fulkerson method (using either BFS or DFS).

### Algorithm Representation

![image-20210511110555181](https://tva1.sinaimg.cn/large/008i3skNly1gqeb6eeyirj30wa0ie7f0.jpg)

### Implementation

The implementation part of the `DinicsAlgorithm()` is shown in the code provided.

