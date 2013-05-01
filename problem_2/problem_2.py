def fibonacci(n):
    current = 1
    last = 1
    while current < n:
        yield(current)
        last, current = current, current + last

if __name__ == '__main__':
    print sum([i for i in fibonacci(4000000) if i % 2 == 0])
