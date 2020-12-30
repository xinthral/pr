
def levDist(stringa, stringb):
    """
    Levenshtein Distance shows the relative distance between
    two objects, in this case strings which could be used
    to match syllabul patterns which algorithm appears to favor
    vowels (probably because of how we form words)
    :param stringa := The first string acts as a starting position
    :param stringb := The second string is the target position
    :return: The number of changes needed to get from stringa->stringb
    """

    # They've matched til this point, everything extra is the difference
    if len(stringb) == 0: return(len(stringa))
    elif len(stringa) == 0: return(len(stringb))

    # Compare first two characters of each string
    elif stringa[0] == stringb[0]: return(levDist(stringa[1:], stringb[1:]))

    # If a single character diverges, then increment disparaty value
    # and return minimum value of all variant comparisons
    else:
        return(1 + min([
            levDist(stringa[1:], stringb),
            levDist(stringa, stringb[1:]),
            levDist(stringa[1:], stringb[1:])
        ]))

def main(input1="kitten", input2="sitting"):
    print(levDist(input1, input2))

if __name__ == '__main__':
    ''' Takes 2 command line arguments as strings or passes defaults '''
    import sys
    if len(sys.argv) > 1:
        [print(_) for _ in sys.argv]
        input1, input2 = sys.argv[1], sys.argv[2]
        main(input1, input2)
    else: main()
