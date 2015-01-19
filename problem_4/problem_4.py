'''

Problem 4: largest palindrome from 3-digit products.

Solved with brute force.

'''

import time

LARGEST_INPUT = 999
SMALLEST_INPUT = 100

def palindromes():
	'''Generate palindromes.

	Order is determined by the multiplicands, not the product.
	'''
	for l in multiplicands(SMALLEST_INPUT):
		for r in multiplicands(l):
			product = l * r
			if is_palindrome(product):
				yield product
				continue

def multiplicands(minimum):
	'''Return a generator for the proper inputs to iterate over'''
	return xrange(LARGEST_INPUT, minimum - 1, -1)

def is_palindrome(num):
	'''Determine if a number is a palindrome'''
	str_num = str(num)
	return str_num == str_num[::-1]

def main():
	# This has pretty much exactly the same runtime performance
	#print max(palindromes())
	max_result = 0
	for n in palindromes():
		if is_palindrome(n) and n > max_result:
			max_result = n
	print max_result


if __name__ == '__main__':
	start = time.time()
	main()
	end = time.time()
	print 'Run time: {}'.format(end - start)
