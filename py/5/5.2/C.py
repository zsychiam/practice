class Point:
    def __init__(self, x, y) -> None:
        self.x = x
        self.y = y

    def move(self, new_x, new_y):
        self.x += new_x
        self.y += new_y

    def length(self, point):
        result = ((point.x - self.x) ** 2 + (point.y - self.y) ** 2) ** 0.5
        return round(result, 2)


class PatchedPoint(Point):
    def __init__(self, *args) -> None:
        match len(args):
            case 0:
                self.x = 0
                self.y = 0
            case 1:
                self.x, self.y = args[0]
            case 2:
                self.x, self.y = args

    def __add__(self, other):
        return PatchedPoint(self.x + other[0], self.y + other[1])

    def __iadd__(self, other):
        self.move(other[0], other[1])
        return self

    def __str__(self) -> str:
        string = f'({self.x}, {self.y})'
        return string

    def __repr__(self) -> str:
        string = f'PatchedPoint({self.x}, {self.y})'
        return string
