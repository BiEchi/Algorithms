# Implementation of Floyd Algorithm

## Differences between Floyd-Walshall & Dijkstra Algo.

>   Both Floyd’s and Dijkstra’s algorithm may be used for finding the shortest path between vertices. The biggest difference is that **Floyd’s algorithm finds the shortest path between all vertices and Dijkstra’s algorithm finds the shortest path between a single vertex and all other vertices**.
>
>   The space overhead for Dijkstra’s algorithm is considerably more than that for Floyd’s algorithm. If you run Dijkstra’s algorithm n times, on n different vertices, you will have a theoretical time complexity of $O(n\cdot n^2)=O(n^3)$. In other words, if you use Dijkstra’s algorithm to find a path from every vertex to every other vertex you will have the same efficiency and result as using Floyd’s algorithm.
>
>   In addition, Floyd’s algorithm is much easier to implement.

Assume we have this adjacency matrix below.

![image-20210429224208281](../../../../Library/Application%20Support/typora-user-images/image-20210429224208281.png)

This matrix corresponds to the graph:

![image-20210429224300943](../../../../Library/Application%20Support/typora-user-images/image-20210429224300943.png)

Overall, `k` changes and the conditions changes as below.

![image-20210430191113426](../../../../Library/Application%20Support/typora-user-images/image-20210430191113426.png)

We take one epoch of `k` for example.

![image-20210430191148673](../../../../Library/Application%20Support/typora-user-images/image-20210430191148673.png)



We then consider a special case in *Intro to Algorithms*

![image-20210430191219101](../../../../Library/Application%20Support/typora-user-images/image-20210430191219101.png)

For details, please look into the code provided.