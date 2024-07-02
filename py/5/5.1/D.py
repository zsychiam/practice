
class Programmer:

    def __init__(self, name, position) -> None:
        rank = {
            'Junior': 10,
            'Middle': 15,
            'Senior': 20
        }
        self.name = name
        self.wage = rank[position]
        self.work_time = 0
        self.salary = 0

    def work(self, time):
        self.work_time += time
        self.salary += self.wage * time

    def info(self):
        return f'{self.name} {self.work_time}ч. {self.salary}тгр.'

    def rise(self):
        if self.wage < 20:
            self.wage += 5
        else:
            self.wage += 1