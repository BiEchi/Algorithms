# TSP Algorithm

## Differences between Travelling Salesman Problem (*TSP*) & Chinese Postman Problem (*CPP*)

-   Traversal Type
    -   Salesman needs to go through every city once, but not all edges need to be traversed (salesman is point-wise traverse).
    -   Postman needs to go through every street once, but not all points need to be traversed (postman is edge-wise traverse).
-   Direction Availability
    -   Salesman can not “turn his head back”, but postman can go back to one point again.
    -   Salesman needs to go back to the city he starts, but postman doesn’t need to go back to the start vertex.
-   Analogy
    -   Salesman can be mapped to the Hamilton cycle.
    -   Postman can be mapped to the Euler cycle.

These are all pretty reasonable for the salesman and postman!

## Heuristic Search *启发式搜索*

Heuristic search is a kind of informative search, compared to non-informative searches like BFS and DFS, and belongs to Advance Search Method (ASM). 

Heuristic search utilizes auxiliary information (called *heuristic information*) to help to conduct the search in a more effecient way.

**Note** that “heuristic” in *Heuristic Search* is different from “heuristic” in *Heuristic Algorithm*, because the latter refers to an experience-based algorithm that can solve the question in a not necessarily precise but absolutely must faster way.

## Essence

The essence of TSP is to find a lowest-cost Hamilton cycle. Note that in a Hamilton cycle, vertices cannot be duplicated, but edges can. 

## Use Dynamic Programming to implement TSP Algorithm

Refer to the code.

