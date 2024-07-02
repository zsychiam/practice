class Fraction():
    def __init__(self, *args) -> None:
        if isinstance(args[0], str):
            self.__num, self.__den = [int(c) for c in args[0].split('/')]
        else:
            self.__num = args[0]
            self.__den = args[1]
        self.__reduction()

    def __gcd(self, a, b):
        while b != 0:
            a, b = b, a % b
        return abs(a)

    def __reduction(self):
        gcd = self.__gcd(self.__num, self.__den)
        self.__num = self.__num // gcd
        self.__den = self.__den // gcd
        return self

    def __str__(self) -> str:
        return f'{self.__num}/{self.__den}'

    def __repr__(self) -> str:
        return f"Fraction({self.__num}, {self.__den})"

    def numerator(self, *args):
        if len(args):
            self.__num = args[0]
            self.__reduction()
        return self.__num

    def denominator(self, *args):
        if len(args):
            self.__den = args[0]
            self.__reduction()
        return self.__den
