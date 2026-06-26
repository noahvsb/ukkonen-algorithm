# Ukkonen's algorithm

A fantastic algorithm that builds a suffix tree in linear time. With this suffix tree, you can do numerous things in linear time. For example sort a string of length n in lexicographical order in O(n).

Currently broken, will revisit.

## run tests

Download the test library acutest.h from https://github.com/mity/acutest:

```sh
mkdir -p test/include && wget -O test/include/acutest.h https://raw.githubusercontent.com/mity/acutest/refs/heads/master/include/acutest.h
```

Then build and run the tests with make:

```sh
make test
```
