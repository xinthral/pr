def toFrac(criteria, adj=10, a=0, b=1, c=1, d=1):
    '''
    Converts from Decimal to Fractional by approximating the fractional returns
    using the Farey Method of decimal division.
    :param criteria := The decimal representation you are converting to a fraction
    :param adj      := (Optional) The decimal positions to be estimated; precision.
    '''
    padj = 1/(10**(adj+1))
    numerator = a + c
    denominator = b + d
    pivot = numerator / denominator
    if pivot-padj <= criteria <= pivot+padj:
        return( f'{numerator} / {denominator}' )
    if criteria < pivot-padj:
        return( toFrac(criteria, adj, a, b, numerator, denominator) )
    if criteria > pivot+padj:
        return( toFrac(criteria, adj, numerator, denominator, c, d) )

def main():
    a, b, c, d = (0, 1, 1, 1)
    for _ in range(18):
        print(f'{_} :\t{toFrac(0.1177149964, _)}')
        # print(f'{_} :\t{toFrac(0.22726017562268735, _)}')

if __name__ == "__main__":
    import sys
    sys.setrecursionlimit(2000)
    main()
