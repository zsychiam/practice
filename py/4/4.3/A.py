def recursive_sum(*args):
    if not args:
        return 0
    return args[0] + recursive_sum(*args[1:])   