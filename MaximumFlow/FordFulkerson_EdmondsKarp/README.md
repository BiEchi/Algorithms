# Ford Fulkerson's Method

Hello, I’ve just implemented *MFP* using the Ford-Fulkerson Method (with help of some source codes because this is not as easy as the Floyd Algorithm). Note that we use exactly the same case as described in the course by Prof. K.D., so you’ll find it surprising that the result is **23**.

I’d like to share that, when implementing, the toughest problem is: **how to find the augmenting path?** I searched the Internet and it shocked me that we can simply conduct a BFS/DFS on the residual graph to gain the ability to certify the question **“Do we have a path from the source vertex to the sink vertex?”**. If BFS/DFS returns a positive result, the augmenting path is found. Please refer to [my code](https://github.com/BiEchi/Algorithms) for more info. (In my codes I conducted BFS, because DFS may lead to a low effect due to repentances on one path.)

If you have other inspirations, you can contribute to this repo as well, as long as you think it’s interesting. Again, this project is last through CS374 and later algorithm-concerning courses.

## Trace of BFS & DFS

### DFS - Stack Based Search

| Operation  | Stack status | Significance    |
| ---------- | ------------ | --------------- |
| INITIALIZE | $\{/\}$      | Initialization. |



| Operation                | Stack status        | Significance                                                 |
| :----------------------- | ------------------- | ------------------------------------------------------------ |
| PUSH $\{s,a,c,e,d,f,t\}$ | $\{s,a,c,e,d,f,t\}$ | Detect from up to down and go along the last detected vertex. |

![image-20210520203006597](http://jacklovespictures.oss-cn-beijing.aliyuncs.com/2021-05-20-123007.png)



| Operation      | Stack status        | Significance                         |
| -------------- | ------------------- | ------------------------------------ |
| POP $\{t\}$    | $\{s,a,c,e,d\}$     | No augmenting path along $<e,f,t>$.  |
| PUSH $\{b,t\}$ | $\{s,a,c,e,d,b,t\}$ | Augment along $<d,b,t>$ and $<d,t>$. |

![image-20210520203152299](http://jacklovespictures.oss-cn-beijing.aliyuncs.com/2021-05-20-123152.png)



| Operation       | Stack status      | Significance                                                 |
| --------------- | ----------------- | ------------------------------------------------------------ |
| POP $\{b,d,t\}$ | $\{s,a,c,e\}$     | No augmenting path.                                          |
| PUSH $\{b,t\}$  | $\{s,a,c,e,b,t\}$ | $f,e$ have no augmenting path;<br />$d$ has some augmenting paths. |

![image-20210520204733376](http://jacklovespictures.oss-cn-beijing.aliyuncs.com/2021-05-20-124734.png)





| Operation       | Stack status      | Significance                                                 |
| --------------- | ----------------- | ------------------------------------------------------------ |
| POP $\{b,d,t\}$ | $\{s,a,c,e\}$     | No augmenting path.                                          |
| PUSH $\{b,t\}$  | $\{s,a,c,e,b,t\}$ | $f,e$ have no augmenting path;<br />$d$ has some augmenting paths. |

![image-20210520205837810](http://jacklovespictures.oss-cn-beijing.aliyuncs.com/2021-05-20-125837.png)



| Operation       | Stack status      | Significance                                                 |
| --------------- | ----------------- | ------------------------------------------------------------ |
| POP $\{b,d,t\}$ | $\{s,a,c,e\}$     | No augmenting path.                                          |
| PUSH $\{b,t\}$  | $\{s,a,c,e,b,t\}$ | $f,e$ have no augmenting path;<br />$d$ has some augmenting paths. |

![image-20210520205855098](http://jacklovespictures.oss-cn-beijing.aliyuncs.com/2021-05-20-125855.png)

$f\uparrow f_p$

