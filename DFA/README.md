# The DFA Automata Algorithm

Hello guys, this is the CPP implementation of the Definite Finite Automata algorithm. To use it, you need to change the content in `DFA.txt`. For example, the content in the default `DFA.txt` is:

```text
2 1
1 0
0 1 1
1 1 0
```

Because we enumerate states from 0, and we enumerate alphabet from one, the content means:

```text
number of states is 2 (then the states should be enumerated to 0, 1), size of alphabet is 1 (then the alphabet should be enumerated to 1)
number of final states is 1, the final state is state 0
state transition: ((0,1),1)
state transition: ((1,1),0)
```

Note that we take state 0 as starter state by default.

Thus, the DFA has the illustration below:

![illustration](http://jacklovespictures.oss-cn-beijing.aliyuncs.com/2021-11-01-014409.jpg)

This leads us to the regular language:
$$
\mathcal{L}=\{(11)^*\}
$$
Please try out other cases!

