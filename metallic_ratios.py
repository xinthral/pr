"""
Generates these Ratios based off given argument and
returns an iterative generator, utilize the next() method to progress
the iteration

Ratios:
- 1 :: Golden Ratio (aka Fibonacci Sequence)
- 2 :: Silver Ratio (aka Pell Sequence)
- 3 :: Bronze Ratio (aka 3-bonacci Sequence)
"""

def ratioGenerator(index, nRatio, debug=0):
    '''
    Returns a python generator object that iterates
    from 0 -> N, adjusting by the input ratio.
    index  := The number of elements in the sequence
    nRatio := Numerical Ratio (listed above)
    '''
    a, b = 0, 1
    for i in range(0, index+1):
        yield(a if (debug == 0) else (i,a))
        a, b = b, (nRatio * b + a)

if __name__ == '__main__':
    # First 10 elements of the Fibonacci Sequence
    # And yes, I do start the sequence with 0,1
    for _ in ratioGenerator(10, 1):
        print(_)
