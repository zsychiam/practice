def only_positive_even_sum(*args):
    if any([not isinstance(c, int) for c in args]):
        raise TypeError
    elif not all([int(c) > 0 and c % 2 == 0 for c in args]):
        raise ValueError
    else:
        return sum(args)