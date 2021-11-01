

# Linear Hashing

## Preliminary Hashing Techniques

**Note.** *Linear hashing* is different from *linear probing*. I'm not sure whether **Linear Hashing** will be examined again in *CS 374*, but this hashing algorithm provides a breath-taking method to deal with dynamic hashing without conflicts. 

There are multiple types of hashing.

-   open hashing (closed addressing)

    -   chaining method

-   closed hashing (open addressing), all elements are stored in hashtables

    -   linear probing

        -   Original Linear probing method

            ![image-20210522142703081](http://jacklovespictures.oss-cn-beijing.aliyuncs.com/2021-05-22-062703.png)

        -   Linear probing with tombstones (or placeholders) $\bot$

            ![image-20210522144232923](http://jacklovespictures.oss-cn-beijing.aliyuncs.com/2021-05-22-064233.png)

        -   Last-come-first-served Hashing

            ![image-20210522142317039](http://jacklovespictures.oss-cn-beijing.aliyuncs.com/2021-05-22-062317.png)

        -   Robin Hood Hashing

            ![image-20210522142330025](http://jacklovespictures.oss-cn-beijing.aliyuncs.com/2021-05-22-062330.png)

    -   quadratic probing

    -   double hashing

-   Dynamic hashing

    - Hashing with extendible length of hash table (which needs to rehash each time)

        ![image-20210522144945798](http://jacklovespictures.oss-cn-beijing.aliyuncs.com/2021-05-22-064945.png)

        - The definition of *Index structure* is shown below (*Slides 300*).

            ![image-20210526094318456](http://jacklovespictures.oss-cn-beijing.aliyuncs.com/2021-05-26-014318.png)

    -   Linear Hashing(*Slides 208*)

    ![image-20210526094442816](http://jacklovespictures.oss-cn-beijing.aliyuncs.com/2021-05-26-014443.png)

    ## Linear Hashing Process

    We illustrate the initial status of the hash table as

    ![image-20210526094703298](http://jacklovespictures.oss-cn-beijing.aliyuncs.com/2021-05-26-014704.png)

    And the use of $p$ is

    ![image-20210526094812763](http://jacklovespictures.oss-cn-beijing.aliyuncs.com/2021-05-26-014812.png)


Note that the dynamic hash function is shown below.

![image-20210526094839347](http://jacklovespictures.oss-cn-beijing.aliyuncs.com/2021-05-26-014840.png)

From which we conclude that
$$
h_0(k)=k\mod{5} \\
h_1(k)=k\mod{10} \\
h_2(k)=k\mod{20}
$$
This is natural, as in the initial condition we have
$$
h_0(k)=k\mod{5}
$$
and we also have 5 buckets, which is consistent.

Then because elements in bucket 0 is excedding the threshold, we apply the split operation.

![image-20210526095714451](http://jacklovespictures.oss-cn-beijing.aliyuncs.com/2021-05-26-015714.png)

This is due to the hash function
$$
h_1(k)=k\mod{10}
$$
Note that this division is natural because we split the bucket with mod = 5,10 into with mod = 5 and mod = 10. There will not be any conflict in the whole hash table because nothing is repeated due to the hash functions. Let's illustrate this principle using an interesting illustration:

![LinearHashingPrinciples](http://jacklovespictures.oss-cn-beijing.aliyuncs.com/2021-05-26-021028.png)

Yes, the delicious cake is the raw data, the cake divided into parts is the initial hash table, and the last cake is the hash table after one split.

Wish you can understand linear hashing better using the cake! And welcome for any corrections.