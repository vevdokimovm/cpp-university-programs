#lang racket
;(define (even? n) (= (remainder n 2) 0))

(define (square n) (* n n))

(define (modified-expmod base exp m)
  (cond ((= exp 0) 1)
        ((even? exp) 
        (if (and (not (= base 1)) (not (= base (- m 1))) (= (remainder (square (modified-expmod base (/ exp 2) m)) m) 1)
        (else 
         (remainder (* base (modified-expmod base (- exp 1) m )) m))))

(define (prime? n)
  (if (= n 1)
      "This isn't prime number nor composite number"
      (Miller-Rabin-test n)))

(define (Miller-Rabin-test n)
   (define (checker test-num)
     (cond ((= test-num n) #t)
           ((= (expmod test-num (- n 1) n) 0) 
               #f)
           (else (checker (+ test-num 1)))))
  (checker 2))