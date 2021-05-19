Sometimes it's easy to understand something but hard to memorize something - B/B+ Tree is an example. Here's a review session on these two awesome trees. Welcome for any corrections.

# B Tree

First comes the B-Tree. 

![image-20210518203740214](http://jacklovespictures.oss-cn-beijing.aliyuncs.com/2021-05-18-123740.png)

Here are the rudimentary concepts of the B tree. 

| Attribute  | Illustration                                                 | Value |
| ---------- | ------------------------------------------------------------ | ----- |
| Degree     | Largest degree of all nodes.                                 | 5     |
| Degree(39) | Capacity of children.                                        | 2     |
| Order      | Largest number of child pointers.                            | 5     |
| Height     | (Note. Excl. the omitted leaf nodes.)![image-20210518204449971](http://jacklovespictures.oss-cn-beijing.aliyuncs.com/2021-05-18-124450.png) | 3     |
|            |                                                              |       |
|            |                                                              |       |
|            |                                                              |       |
|            |                                                              |       |
|            |                                                              |       |

Note that in B tree $Degree=Order$ does **not** always holds.

![image-20210518204817021](http://jacklovespictures.oss-cn-beijing.aliyuncs.com/2021-05-18-124817.png)

| Attribute | Illustration                      | Value |
| --------- | --------------------------------- | ----- |
| Degree    | Largest degree of all nodes.      | **4** |
| Order     | Largest number of child pointers. | 5     |

The strict way to represent a B tree is as below. This includes the order of each node (which must be the same).

![image-20210518204616990](http://jacklovespictures.oss-cn-beijing.aliyuncs.com/2021-05-18-124617.png)

The `find()` operation is pretty easy - just search linearly. Go right if larger, go down if first larger then smaller. 

## Insertion

`insert()` is pretty easy too, just call `find()` and use the pointer to the new element to replace the `NULL` pointer (note that insertion always happens on leaf nodes). The case is when you overfill the order, you need to call the `split()` subroutine.

![image-20210518205757286](http://jacklovespictures.oss-cn-beijing.aliyuncs.com/2021-05-18-125757.png)

Such a case leads to

![image-20210518205845395](http://jacklovespictures.oss-cn-beijing.aliyuncs.com/2021-05-18-125845.png)

, whose place is defined by $pos=\left\lceil \frac{m}{2} \right\rceil  $. Similarly, when you obtain

![image-20210518210354543](http://jacklovespictures.oss-cn-beijing.aliyuncs.com/2021-05-18-130355.png)

The `split()` operation should return

![image-20210518210432059](http://jacklovespictures.oss-cn-beijing.aliyuncs.com/2021-05-18-130432.png)

The **most complex** case begins like this (which is called *cascading*):

![image-20210518210619678](http://jacklovespictures.oss-cn-beijing.aliyuncs.com/2021-05-18-130619.png)

![image-20210518210641995](http://jacklovespictures.oss-cn-beijing.aliyuncs.com/2021-05-18-130642.png)

![image-20210518210702181](http://jacklovespictures.oss-cn-beijing.aliyuncs.com/2021-05-18-130702.png)

## Deletion

### Case 1

Now, say, you want to delete 16.

![image-20210518211036886](http://jacklovespictures.oss-cn-beijing.aliyuncs.com/2021-05-18-131037.png)

If you delete something not in the leaf node, you have to refill this element. You can find either the `predecessor` or `successor`. Note that the predecessor cannot be deleted, because it only has 2 elements, but $\left\lfloor \frac{5}{2} \right\rfloor>1$. Thus we get

![image-20210518211422654](http://jacklovespictures.oss-cn-beijing.aliyuncs.com/2021-05-18-131423.png)

### Case 2

In this case you want to delete node 15.

![image-20210518211745769](http://jacklovespictures.oss-cn-beijing.aliyuncs.com/2021-05-18-131746.png)

-   The node with (14,15) is at least number.
-   The successor is also at least number.

Thus, we have to “borrow" an element from the right sibling to the parent node like this.

![image-20210518212011451](http://jacklovespictures.oss-cn-beijing.aliyuncs.com/2021-05-18-132011.png)

![image-20210518212041189](http://jacklovespictures.oss-cn-beijing.aliyuncs.com/2021-05-18-132041.png)

### Case 3







# B+ Tree
