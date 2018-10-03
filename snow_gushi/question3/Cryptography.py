class Cryptography():
    def encrypt(self, numbers):
        numbers = list(numbers)
        min_number = min(numbers)
        multiply_number = 1 
        once_plus = False
        for number in numbers:
            if number == min_number and once_plus is False:
               number += 1
               once_plus = True
            multiply_number *= number
        return multiply_number 
