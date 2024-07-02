class Rectangle:
    def __init__(self, corner1, corner2) -> None:
        self.left_down = min(corner1[0], corner2[0]), min(corner1[1], corner2[1])
        self.up_right = max(corner1[0], corner2[0]), max(corner1[1], corner2[1])

    def perimeter(self):
        return round((self.up_right[0] - self.left_down[0]) * 2 +
                     (self.up_right[1] - self.left_down[1]) * 2, 2)

    def area(self):
        return round((self.up_right[0] - self.left_down[0]) *
                     (self.up_right[1] - self.left_down[1]), 2)