try:
    func()
except ValueError:
    print('ValueError')
except TypeError:
    print('TypeError')
except SystemError:
    print('SystemError')
except Exception as e:
    print('Unexpected error: {e}')
else:
    print('No Exceptions')