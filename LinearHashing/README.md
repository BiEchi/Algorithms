

# Linear Hashing

## Conceptions

**Note.** *Linear hashing* is different from *linear probing*.

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

    -   Hashing with extendible length of hash table (which needs to rehash each time)

        ![image-20210522144945798](http://jacklovespictures.oss-cn-beijing.aliyuncs.com/2021-05-22-064945.png)

    -   Linear Hashing(*Slides 208*)

    ==**Can not understand.**==

    

    ​	tot = 17

    ![image-20210522150221199](http://jacklovespictures.oss-cn-beijing.aliyuncs.com/2021-05-22-070221.png)

    

    

    tot = 17

    ![image-20210522150258569](http://jacklovespictures.oss-cn-beijing.aliyuncs.com/2021-05-22-070259.png)

    

    

    tot = 19

    ![image-20210522150357600](http://jacklovespictures.oss-cn-beijing.aliyuncs.com/2021-05-22-070357.png)

