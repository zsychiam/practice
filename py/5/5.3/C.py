class MyClass:

    def __repr__(self) -> str:
        raise Exception


a = MyClass()
func(a)