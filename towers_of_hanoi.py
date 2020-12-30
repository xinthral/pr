"""
Towers of Hanoi recursive algorithms
"""
def hanoi2(n, start, end):
    '''
    Recursive Solution for Classic Towers of Hanoi problem
    (3 towers). This particular one compliments of YT: Reducible
    n     := number of disk not in final destination
    start := source location of current move
    end   := target destination of current move
    '''
    # If the number of disk to move reaches 1
    # perform the move (print it)
    if n == 1: return(pm(start, end))
    else:
        # Circular Hashing to locate non-target tower
        other = 6 - (start + end)
        # Call leftChild recursively
        hanoi2(n-1, start, other)
        # Print Visited
        pm(start, end)
        # Call rightChild recursively
        hanoi2(n-1, other, end)

def hanoi1(n, start, aux, end):
    '''
    Recursive Solution for Classic Towers of Hanoi problem
    (3 towers). This particular one compliments of geeksforgeeks.org
    n     := number of disk not in final destination
    start := source location of current move
    aux   := auxiliary position to perform intermediate moves
    end   := target destination of current move
    '''
    # If the number of disk to move reaches 1
    # perform the move (print it)
    if n == 1: return(pm(start, end))
    # Call leftChild recursively
    hanoi1(n-1, start, end, aux)
    # Print Visited
    pm(start, end)
    # Call rightChild recursively
    hanoi1(n-1, aux, start, end)

def pm(start, end):
    # Peforms "move" by printing action
    print(f"{start} -> {end}")

def main():
    number, start, aux, end = 3, 1, 2, 3
    print("Hanoi-1\nPerforms task by manually shuffling inputs -> outputs")
    hanoi1(number, start, aux, end)
    print("\nHanoi-2\nPerforms task by utilizing a hashing function")
    hanoi2(number, start, end)

if __name__ == "__main__":
    main()
