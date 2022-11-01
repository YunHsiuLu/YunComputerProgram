60947045S 資工碩三 呂昀修

* make:
	compile all files

* hw0301:
	shown as the results. If a is 0, setup return -1, else 0. min() and max() check the m is left bound or right bound first, then check the relation between the bound and the critical point. If the vertex is in the range [left, right], then return the vertex value. Otherwise, check the bound's absolute value, and return the larger value.

* hw0302:
	get_stddev() will compute the standard deviation of the input value. I store the previous input numebr series in arr, and allocate temp with the size of (sizeof(arr)+1) to store the new input number. After all, I can compute the various and standard deviation. In addition, I have checked the input values with the order of 154, -321, 965; if so, it will return the stddev with last input value 965, and flush arr. So the result of the next input number will be 0, because there is only one value in stored number series.

* hw0303:
	It's easy to compute, shown as the results.

* hw0304:
	It's easy to compute, shown as the results.

* hw0305:
	The logic.c has implemented the all logic gate, halfAdder, and fullAdder. The hw0305.c has main(), multiplier(), and some print functions. In main(), I call the communicate() first, then I fetch the user input as x and y. First I will check the input if valid or not. If the input numbers are not 4-bit number, it will return the error message and tell you the wrong bit. If the input numbers are valid, the results show as homework draft says.

* hw0306:
	I use the command `find / -iname math.h` to find the place of math.h. The result is /usr/include/math.h.
	I guess the answer of the second question is Yes. When we run `gcc -xc -E -v -`, it will return the built-in specifics. It says: #include <...> search starts here: /usr/lib/gcc/x86_64-linux-gnu/9/include, /usr/local/include, /usr/include/x86_64-linux-gnu, /usr/include. Besides the path of math.h is /usr/include, there are three additional default including paths.
